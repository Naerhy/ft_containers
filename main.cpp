#include <iostream>
#include "Vector.hpp"

int main(void)
{
	ft::Vector<int> vect;

	std::cout << vect.size() << " - " << vect.capacity() << std::endl;
	return 0;
}
