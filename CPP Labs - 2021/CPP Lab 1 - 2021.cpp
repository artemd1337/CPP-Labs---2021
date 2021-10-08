#include "CPP Lab 1 - 2021.h"
#include "string.h"


int main() {
	string a("artem ");
	string b("danilov");
	a += b;
	std::cout << a << std::endl;
	string c = a.SubStr(2,3);
	
	string d = a * 3 + b;
	string f = 3 * a;
	std::cout << f << std::endl;
	std::cout << d << c << std::endl;
}
