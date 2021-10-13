#include <cstdio>
#include <cstring>
#include <iostream>

template <typename T>
class string {
private:
	T* data;
	size_t size;
	size_t capacity;
public:
	string();
	string(const T* new_data, const size_t new_size);
	string(const size_t size);
	string(const string& rhs);
	~string();

	T operator[](const size_t index) const;
	T& operator[](const size_t index);
	T* GetData() const; 

	size_t GetSize() const;
	size_t GetCapacity() const;

	string& operator= (const string& rhs);

	string& operator+= (const string& rhs);
	string& operator+= (const T rhs);

	string operator+ (const string& rhs) const;

	string& operator*= (const int number);
	string operator* (const int num) const;

	string SubStr(const size_t index, const size_t len) const;
	string operator() (const size_t start, const size_t finish = 0, const bool to_end = true) const; // 

	bool operator== (const string& rhs) const;
	bool operator!= (const string& rhs);
};

template <typename T>
std::ostream& operator<< (std::ostream& out, const string<T>& string);

template <class T>
string<T> operator* (const int num, const string<T>& rhs);

#include "string.inl"