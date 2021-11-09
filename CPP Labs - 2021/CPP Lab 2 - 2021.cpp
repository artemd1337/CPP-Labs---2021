#include "CPP Lab 2 - 2021.h"
#include "string.h"


int main() {
	/*string<char> a("artem ", 6);
	string<char> b("danilov" , 7);
	a = b;
	std::cout << a << std::endl << b << std::endl;
	a += b;
	a[0] = 'A';
	std::cout << a << std::endl;
	string<char> c = a(a.begin() + 2, a.end());
	string<char> g = a(a.begin() + 2,a.begin() + 4);
	std::cout << g << std::endl;
	string<char> d = a * 3 + b;
	string<char> f = 3 * a;
	std::cout << f << std::endl;
	std::cout << d << c << std::endl;
	
	int vector[10] = { 0,1,2,3,4,5,6,7,8,9 };
	string<int> a_i(vector, 7);
	std::cout << a_i << std::endl;*/
	string<char>  test1("test123", 7);
	string<char> test2;
	test2 = test1;
	std::cout << strcmp(test1.GetData(), test2.GetData()) << std::endl;
	std::cout << test1.GetData() << std::endl << test2.GetData() << std::endl;
	auto data = test1.GetData();
}
