#include "CPP Lab 1 - 2021.h"

class string {
private:
	char* data;
	size_t size;
	size_t capacity;
public:

	string() : data(nullptr), size(0), capacity(0) {}

	string(const char* str) {
		size = strlen(str);
		capacity = 16;
		while (capacity <= size) {
			capacity *= 2;
		}
		data = new char[capacity];
		strncpy(data, str, size);
		data[size] = '\0';
		
	}

	string(const string& rhs) {
		size = rhs.size;
		capacity = rhs.capacity;
		data = new char[capacity];
		if (size < capacity) { // to fix warning
			for (size_t i = 0; i < size; ++i) {
				data[i] = rhs.data[i];
			}
		}
		if (size < capacity) {
			data[size] = '\0'; // to fix warning
		}
	}

	~string() {
		if (data != nullptr) {
			delete[] data;
		}
	}

	void Print() const {
		std::cout << data << "\n";
	}

	const char operator[](const size_t index) const {
		if (index >= size) {
			throw ("Invalid index");
		}
		else {
			return data[index];
		}
	}

	char& operator[](const size_t index) {
		if (index >= size) {
			throw ("Invalid index");
		}
		else {
			return data[index];
		}
	}
	
	const char* GetData() const{
		return data;
	}

	const size_t GetSize() const{
		return size;
	}

	const size_t GetCapacity() const {
		return capacity;
	}

	string& operator+= (const string& rhs) {
		if (rhs.data == nullptr) {
			return *this;
		}
		while (size + rhs.size >= capacity) {
			capacity *= 2;
		}
		char* new_data = new char[capacity];
		for (size_t i = 0; i < size; ++i) {
			new_data[i] = data[i];
		}
		for (size_t i = 0; i < rhs.size; ++i) {
			new_data[size + i] = rhs.data[i];
		}
		new_data[size + rhs.size] = '\0';
		size = size + rhs.size;
		delete data;
		data = new_data;
		return *this;
	}

	string& operator+= (const char* rhs) {
		if (strlen(rhs) == 0) 
			return *this;
		size_t rhs_size = strlen(rhs);
		while (size + rhs_size >= capacity) {
			capacity *= 2;
		}
		char* new_data = new char[capacity];
		for (size_t i = 0; i < size; ++i) {
			new_data[i] = data[i];
		}
		for (size_t i = 0; i < rhs_size; ++i) {
			new_data[size + i] = rhs[i];
		}
		new_data[size + rhs_size] = '\0';
		size = size + rhs_size;
		delete data;
		data = new_data;
		return *this;
	}

	string operator+ (const string& rhs) const {
		string result(*this);
		result += rhs;
		return result;
	}

	string operator+ (const char* rhs) const {
		string result(*this);
		result += rhs;
		return result;
	}

	string& operator* (const int number) {
		if (data == nullptr) {
			return *this;
		}
		if (number <= 0) {
			throw ("Invalid number");
		}
		string first_str(*this); // bad?
		for (size_t i = 1; i < number; ++i) { // i = 1 to fix warning
			*this += first_str;
		}

		return *this;
	}

	string SubStr(const size_t index, const size_t len) const {
		if (index >= size || index + len >= size) {
			throw("Invalid index or len");
		}
		char* tmp_str = new char[len + 1];
		for (size_t i = 0; i < len; ++i) {
			tmp_str[i] = data[index + i];
		}
		tmp_str[len] = '\0';
		string substr(tmp_str);
		delete[] tmp_str;
		return substr;
	}

	bool operator== (const string& rhs) const{
		return (0 == strcmp(data , rhs.data));
	}

	bool operator!= (const string& rhs) {
		return !(*this == rhs);
	}

	friend std::ostream& operator<< (std::ostream& out, const string& string);
};

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

std::ostream& operator<< (std::ostream& out, const string& str)
{
	out << str.GetData();
	return out;
}

int main() {
	string a("artem ");
	string b("danilov");
	string c = a.SubStr(2,3);
	string d = 3 * a + b;
	std::cout << d << c << std::endl;
}
