#include <cstdio>

template <typename T>
string<T>::string(const T* new_data,const size_t new_size) {
	for (size_t i = 0; i < new_size; ++i) {
		data.push_back(new_data[i]);
	}
}

template <typename T>
auto string<T>::begin() const {
	return data.begin();
}

template <typename T>
auto string<T>::end() const {
	return data.end();
}

template <typename T>
T string<T>::operator[](const size_t index) const {
	return data.at(index);
}

template <typename T>
T& string<T>::operator[](const size_t index) {
	return data.at(index);
}

template <typename T>
size_t string<T>::GetSize() const {
	return data.size();
}

template <typename T>
const T* string<T>::GetData() const {
	return data.data();
}

template <typename T>
string<T>& string<T>::operator+= (const T rhs) {
	data.push_back(rhs);
	return *this;
}

template <typename T>
string<T>& string<T>::operator+= (const string<T>& rhs) {
	for (size_t i = 0; i < rhs.GetSize(); ++i) {
		*this += rhs[i];
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
	if (data.empty()) {
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
	if (data.empty()) {
		return *this;
	}
	if (num <= 0) {
		throw ("Invalid number");
	}
	string<T> result(*this);
	result *= num;
	return result;
}

template <typename T>
string<T> string<T>::SubStr(const size_t index, const size_t len) const { 
	if (index >= data.size() || index + len > data.size()) {
		throw("Invalid index or len");
	}
	string<T> substr;
	for (size_t i = 0; i < len; ++i) {
		substr += data[index + i];
	}
	return substr;
}

template <typename T>
string<T> string<T>::SubStr(typename std::vector<T>::const_iterator start, typename std::vector<T>::const_iterator stop) const {
	if (start > stop) {
		throw std::out_of_range("Start iterator > then stop iterator");
	}
	string<T> substr;
	while (start != stop) {
		substr += *start;
		start++;
	}
	return substr;
}

template <typename T>
string<T> string<T>::operator() (const size_t start, const size_t stop) const {
	if (stop == std::string::npos) {
		return SubStr(start, data.size() - start);
	}
	if (stop < start) {
		throw "Invalid operands operator(). Stop must be >= start";
	}
	if (stop > data.size()) {
		throw "Invalid index, stop must be <= size";
	}
	if (start > data.size()) {
		throw "Invalid index, stop must be <= size and >= 0";
	}
	size_t len = stop - start + 1;
	return SubStr(start, len);
}

template<typename T>
string<T> string<T>::operator() (typename std::vector<T>::const_iterator start, typename std::vector<T>::const_iterator stop) const {
	return this->SubStr(start, stop);
}

template <typename T>
bool string<T>::operator== (const string<T>& rhs) const {
	return data == rhs.data;
}

template <typename T>
bool string<T>::operator!= (const string<T>& rhs) const{
	return !(*this == rhs);
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const string<T>& string){
	for (size_t i = 0; i < string.GetSize(); ++i) {
		out << string[i];
	}
	return out;
}

template <typename T>
string<T> operator+= (const char* lhs, const string<T>& rhs) {
	return string<T>(lhs) += rhs;
}

template <typename T>
string<T> operator* (const int num, const string<T>& rhs) {
	return rhs * num;
}