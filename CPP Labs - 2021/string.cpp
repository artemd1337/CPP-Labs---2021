#include "string.h"

string::string() : data(nullptr), size(0), capacity(0) {}

string::string(const char* str) {
	size = strlen(str);
	capacity = 16;
	while (capacity <= size) {
		capacity *= 2;
	}
	data = new char[capacity] {'\0'};
	for (size_t i = 0; i < size; ++i) {
		data[i] = str[i];
	}
}

string::string(const size_t new_size) {
	data = new char[new_size] {'\0'};
	if (data == nullptr) {
		throw "Bad alloc";
	}
	capacity = new_size;
	size = 0;
}

string::string(const string& rhs) {
	size_t newsize = rhs.size;
	size_t newcapacity = rhs.capacity;
	data = new char[newcapacity] {'\0'};
	if (data == nullptr) {
		throw "Bad alloc";
	}
	size = newsize;
	capacity = newcapacity;
	if (size < capacity) { // to fix warning
		for (size_t i = 0; i < size; ++i) {
			data[i] = rhs.data[i];
		}
	}
}

string::~string() {
	if (data != nullptr) {
		delete[] data;
	}
}

const char string::operator[](const size_t index) const {
	if (index >= size) {
		throw ("Invalid index");
	}
	else {
		return data[index];
	}
}

char& string::operator[](const size_t index) {
	if (index >= size) {
		throw ("Invalid index");
	}
	else {
		return data[index];
	}
}

char* string::GetData() const {
	return data;
}

size_t string::GetSize() const {
	return size;
}

size_t string::GetCapacity() const {
	return capacity;
}

string& string::operator+= (const char rhs) {
	if (size + 1 >= capacity) {
		size_t new_capacity = capacity;
		while (size + 1 >= new_capacity) {
			new_capacity *= 2;
		}
		char* new_data = new char[new_capacity] {'\0'};
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

string& string::operator+= (const string& rhs) {
	if (rhs.data == nullptr) {
		return *this;
	}
	for (size_t i = 0; i < rhs.size; ++i) {
		*this += rhs.data[i];
	}
	return *this;
}

string& string::operator+= (const char* rhs) {
	if (strlen(rhs) == 0)
		return *this;
	size_t rhs_size = strlen(rhs);
	for (size_t i = 0; i < rhs_size; ++i) {
		*this += rhs[i];
	}
	return *this;
}

string string::operator+ (const string& rhs) const {
	string result(*this);
	result += rhs;
	return result;
}

string string::operator+ (const char* rhs) const {
	string result(*this);
	result += rhs;
	return result;
}

string& string::operator* (const int number) {
	if (data == nullptr) {
		return *this;
	}
	if (number <= 0) {
		throw ("Invalid number");
	}
	string first_str(*this);
	for (size_t i = 1; i < number; ++i) { // i = 1 to fix warning
		*this += first_str;
	}
	return *this;
}

string string::SubStr(const size_t index, const size_t len) const {
	if (index >= size || index + len >= size) {
		throw("Invalid index or len");
	}
	string substr(16);
	for (size_t i = 0; i < len; ++i) {
		substr += data[index + i];
	}
	return substr;
}

bool string::operator== (const string& rhs) const {
	return (0 == strcmp(data, rhs.data));
}

bool string::operator!= (const string& rhs) {
	return !(*this == rhs);
}

std::ostream& operator<< (std::ostream& out, const string& str)
{
	out << str.GetData();
	return out;
}

string operator+ (const char* lhs, const string& rhs) {
	return string(lhs) + rhs;
}

string operator+= (const char* lhs, const string& rhs) {
	return string(lhs) += rhs;
}

string& operator* (const int number, string& rhs) {
	if (number < 0) throw "Invalid number";
	return rhs * number;
}