#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

template <typename T>
class string {
private:
	std::vector<T> data;

public:
	string() = default;
	string(const T* new_data, const size_t new_size);

	auto begin() const;
	auto end() const;

	T operator[](const size_t index) const;
	T& operator[](const size_t index);

	size_t GetSize() const;
	const T* GetData() const;
	string& operator+= (const string& rhs);
	string& operator+= (const T rhs);

	string operator+ (const string& rhs) const;

	string& operator*= (const int number);
	string operator* (const int num) const;

	string SubStr(const size_t index, const size_t len) const;
	string SubStr(typename std::vector<T>::const_iterator start, typename std::vector<T>::const_iterator stop) const;
	string operator() (const size_t start, const size_t finish = std::string::npos) const; 
	string operator() (typename std::vector<T>::const_iterator start, typename std::vector<T>::const_iterator stop) const;

	bool operator== (const string& rhs) const;
	bool operator!= (const string& rhs) const;
};

template <typename T>
std::ostream& operator<< (std::ostream& out, const string<T>& string);

template <class T>
string<T> operator* (const int num, const string<T>& rhs);

#include "string.inl"