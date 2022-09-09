#include <iostream>
#include <string>
#include "map.hpp"
#include "../../utils/make_pair.hpp"

/*int main(void)
{
	ft::map<int, float> A;
	A.insert(ft::make_pair(3, 30.3));
	A.insert(ft::make_pair(1, 10.1));
	A.insert(ft::make_pair(5, 50.5));
	A.insert(ft::make_pair(2, 20.2));
	A.printInOrder();
	A.remove(3);
	A.remove(1);
	std::cout << "=====" << std::endl;
	A.printInOrder();
	std::cout << "=====" << std::endl;

	ft::map<int, float>::iterator it = A.begin();
	std::cout << it->first << " - " << it->second << std::endl;
	++it;
	std::cout << it->first << " - " << it->second << std::endl;
	//++it;
	//std::cout << it->first << " - " << it->second << std::endl;
	return 0;
}*/

int main(void)
{
	ft::map<int, float> B;
	B.makeTest();
	return 0;
}
