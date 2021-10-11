#include "CPP Lab 1 - 2021.h"
#include "string.h"


int main() {
	string<char> a("artem ", 6);
	string<char> b("danilov" , 7);
	a += b;
	a[0] = 'A';
	std::cout << a << std::endl;
	string<char> c = a(2);
	
	string<char> d = a * 3 + b;
	string<char> f = 3 * a;
	std::cout << f << std::endl;
	std::cout << d << c << std::endl;
}
