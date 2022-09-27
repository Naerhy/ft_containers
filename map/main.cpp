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
	// B.makeTest();

	ft::map<int, float> C;
	std::cout << C.insert(ft::make_pair(12, 12.12)).second << std::endl;
	std::cout << C.insert(ft::make_pair(-3, -3.3)).second << std::endl;
	std::cout << C.insert(ft::make_pair(34, 34.34)).second << std::endl;
	std::cout << C.insert(ft::make_pair(5, 5.5)).second << std::endl;
	std::cout << C.insert(ft::make_pair(34, 34.34)).second << std::endl;

	ft::map<int, float>::iterator it = C.insert(C.begin(), ft::make_pair(9, 9.9));
	std::cout << "it = " << it->first << " - " << it->second << std::endl;
	it++;
	std::cout << "it = " << it->first << " - " << it->second << std::endl;
	std::cout << "===== =====" << std::endl;
	C.printTree();
	std::cout << "===== =====" << std::endl;
	// C.erase(12);
	C.printTree();

	ft::map<int, float>::iterator itt = C.begin();
	std::cout << "it = " << it->first << " - " << it->second << std::endl;
	std::cout << "itt = " << itt->first << " - " << itt->second << std::endl;
	std::cout << (it == itt) << std::endl;

	std::cout << "[] = " << C[5] << std::endl;
	return 0;
}
