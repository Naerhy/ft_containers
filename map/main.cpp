#include <iostream>
#include <string>
#include "map.hpp"
#include "../utils/make_pair.hpp"

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

	std::cout << "iterator | begin > end" << std::endl;
	ft::map<int, float>::iterator ita = C.begin();
	while (ita != C.end())
	{
		std::cout << "ita = " << ita->first << " - " << ita->second << std::endl;
		ita++;
	}

	ft::map<int, float> D;
	D.insert(ft::make_pair(45, 45.45));
	D.printMinMax();

	ft::map<int, float>::iterator itb = C.begin();
	std::cout << "itb = " << itb->first << " - " << itb->second << std::endl;
	itb--;
	std::cout << "itb = " << itb->first << " - " << itb->second << std::endl;

	std::cout << "=== TEST ERASE WITH ITERATOR ===" << std::endl;
	C.printTree();
	C.erase(C.begin());
	std::cout << "AFTER DELETION:" << std::endl;
	C.printTree();

	std::cout << "TEST INSERT ITERATOR" << std::endl;
	C.insert(C.begin(), C.end());
	C.printTree();

	std::cout << "TEST 2 INSERT ITERATOR" << std::endl;
	ft::map<int, float> E;
	E.insert(ft::make_pair(7, 7.7));
	E.insert(ft::make_pair(14, 14.14));
	E.insert(ft::make_pair(5, 5.5));
	E.insert(ft::make_pair(11, 11.11));
	C.insert(E.begin(), E.end());
	C.printTree();

	std::cout << "RANGE CONSTRUCTOR" << std::endl;
	ft::map<int, float> F(E.begin(), E.end());
	E.printTree();

	std::cout << "COUNT" << std::endl;
	std::cout << E.count(11) << std::endl;
	std::cout << E.count(345) << std::endl;
	return 0;
}
