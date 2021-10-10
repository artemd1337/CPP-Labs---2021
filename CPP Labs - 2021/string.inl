template <typename T>
string<T>::string() : data(nullptr), size(0), capacity(0) {}

template <typename T>
string<T>::string(const T* new_data,const size_t new_size) {
	capacity = 16;
	size = 0;
	while (capacity <= new_size) {
		capacity *= 2;
	}
	data = new T[capacity];
	for (size_t i = 0; i < new_size; ++i) {
		data[i] = new_data[i];
	}
	size = new_size;
}

template <typename T>
string<T>::string(const size_t new_size) {
	data = new T[new_size];
	if (data == nullptr) {
		throw "Bad alloc";
	}
	capacity = new_size;
	size = 0;
}

template <typename T>
string<T>::string(const string<T>& rhs) {
	size_t newsize = rhs.size;
	size_t newcapacity = rhs.capacity;
	data = new T[newcapacity];
	if (data == nullptr) {
		throw "Bad alloc";
	}
	size = newsize;
	capacity = newcapacity;
	if (size < capacity) {
		for (size_t i = 0; i < size; ++i) {
			data[i] = rhs.data[i];
		}
	}
}

template <typename T>
string<T>::~string() {
	if (data != nullptr) {
		delete[] data;
	}
}

template <typename T>
T string<T>::operator[](const size_t index) const {
	if (index >= size) {
		throw ("Invalid index");
	}
	else {
		return data[index];
	}
}

template <typename T>
T& string<T>::operator[](const size_t index) {
	if (index >= size) {
		throw ("Invalid index");
	}
	else {
		return data[index];
	}
}

template <typename T>
T* string<T>::GetData() const {
	return data;
}

template <typename T>
size_t string<T>::GetSize() const {
	return size;
}

template <typename T>
size_t string<T>::GetCapacity() const {
	return capacity;
}

template <typename T>
string<T>& string<T>::operator+= (const T rhs) {
	if (size + 1 >= capacity) {
		size_t new_capacity = capacity;
		while (size + 1 >= new_capacity) {
			new_capacity *= 2;
		}
		T* new_data = new T[new_capacity];
		if (new_data == nullptr) {
			throw "Bad alloc";
		}
		else {
			capacity = new_capacity;
		}
		for (size_t i = 0; i < size; ++i) {
			new_data[i] = data[i];
		}
		new_data[size] = rhs;
		size++;
		delete[] data;
		data = new_data;
		return *this;
	}
	else {
		data[size] = rhs;
		size++;
		return *this;
	}
}

template <typename T>
string<T>& string<T>::operator+= (const string<T>& rhs) {
	if (rhs.data == nullptr) {
		return *this;
	}
	for (size_t i = 0; i < rhs.size; ++i) {
		*this += rhs.data[i];
	}
	return *this;
}

template <typename T>
string<T> string<T>::operator+ (const string<T>& rhs) const {
	string<T> result(*this);
	result += rhs;
	return result;
}

template <typename T>
string<T>& string<T>::operator*= (const int number) {
	if (data == nullptr) {
		return *this;
	}
	if (number <= 0) {
		throw ("Invalid number");
	}
	string<T> first_str(*this);
	for (size_t i = 1; i < (size_t)number; ++i) { // i = 1 to fix warning
		*this += first_str;
	}
	return *this;
}

template <typename T>
string<T> string<T>::operator* (const int num) const {
	string<T> result(*this);
	result *= num;
	return result;
}

template <typename T>
string<T> string<T>::SubStr(const size_t index, const size_t len) const {
	if (index >= size || index + len >= size) {
		throw("Invalid index or len");
	}
	string<T> substr(16);
	for (size_t i = 0; i < len; ++i) {
		substr += data[index + i];
	}
	return substr;
}

template <typename T>
string<T> string<T>::operator() (const size_t start, const size_t stop) const {
	if (stop < start) {
		throw "Invalid operands operator(). Stop must be >= start";
	}
	if (stop > size) {
		throw "Invalid index, stop must be <= size";
	}
	if (start > size) {
		throw "Invalid index, stop must be <= size and >= 0";
	}
	else
	{
		size_t len = stop - start;
		return SubStr(start, len + 1);
	}
}

template <typename T>
bool string<T>::operator== (const string<T>& rhs) const {
	if (size != rhs.size) {
		return false;
	}
	for (size_t i = 0; i < size; ++i) {
		if (data[i] != rhs.data[i]) {
			return false;
		}
	}
	return true;
}

template <typename T>
bool string<T>::operator!= (const string<T>& rhs) {
	return !(*this == rhs);
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const string<T>& str){
	for (size_t i = 0; i < str.GetSize(); ++i) {
		out << str[i];
	}
	return out;
}

template <typename T>
string<T> operator+= (const char* lhs, const string<T>& rhs) {
	return string(lhs) += rhs;
}

template <typename T>
string<T> operator* (const int num, const string<T>& rhs) {
	return rhs * num;
}