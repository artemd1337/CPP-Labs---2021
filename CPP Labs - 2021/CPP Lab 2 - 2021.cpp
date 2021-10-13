#include "CPP Lab 2 - 2021.h"
#include "string.h"


int main() {
	string<char> a("artem ", 6);
	string<char> b("danilov" , 7);
	a += b;
	a[0] = 'A';
	std::cout << a << std::endl;
	string<char> c = a(2);
	string<char> g = a(2, 3);
	std::cout << g << std::endl;
	string<char> d = a * 3 + b;
	string<char> f = 3 * a;
	string<char> i = a;
	std::cout << i << std::endl;
	std::cout << f << std::endl;
	std::cout << d << c << std::endl;
}
