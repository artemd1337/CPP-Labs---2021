#include "CPP Labs - 2021.h"

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
		while (capacity < size) {
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
		for (size_t i = 0; i < size; ++i) {
			data[i] = rhs.data[i];
		}
		data[size] = '\0';
	}

	~string() {
		std::cout << "DESTRUCTOR FOR " << data << "\n";
		delete data;
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

	string& operator+= (const string& rhs) {
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

	string operator+ (const string& rhs) const {
		string result(*this);
		result += rhs;
		return result;
	}
};


int main() {
	string a("artem ");
	a.Print();
	string b("danilov");
	b.Print();
	string c = a + b;
	c.Print();
}
