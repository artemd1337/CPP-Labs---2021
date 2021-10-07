#include <cstdio>
#include <cstring>
#include <iostream>

class string {
private:
	char* data;
	size_t size;
	size_t capacity;
public:

	string();
	string(const char* str);
	string(const string& rhs);
	~string();

	const char operator[](const size_t index) const;
	char& operator[](const size_t index);
	char* GetData() const; 

	size_t GetSize() const;
	size_t GetCapacity() const;

	string& operator+= (const string& rhs);

	string& operator+= (const char* rhs);
	string operator+ (const string& rhs) const;
	string operator+ (const char* rhs) const;

	string& operator* (const int number);
	string SubStr(const size_t index, const size_t len) const;
	bool operator== (const string& rhs) const;
	bool operator!= (const string& rhs);
	friend std::ostream& operator<< (std::ostream& out, const string& string);


};

string operator+ (const char* lhs, const string& rhs);
string operator+= (const char* lhs, const string& rhs);
string& operator* (const int number, string& rhs);