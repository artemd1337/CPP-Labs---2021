#include "CPP Lab 1 - 2021.h"
#include "string.h"

int main() {
	string a("artem ");
	string b("danilov");
	string c = a.SubStr(2,3);
	string d = 3 * a + b;
	std::cout << d << c << std::endl;
}
