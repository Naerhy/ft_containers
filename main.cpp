#include <iostream>
#include <vector>
#include "vector/vector.hpp"

int main(void)
{
	std::cout << "Creating empty vector" << std::endl;
	std::vector<int> A;
	ft::vector<int> Aa;
	std::cout << std::endl;

	std::cout << "Pushing elements into vector" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		A.push_back(i * 10);
		Aa.push_back(i * 10);
	}
	std::cout << std::endl;

	std::cout << "Printing values" << std::endl;
	for (std::vector<int>::const_iterator cit = A.begin(); cit != A.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	for (ft::vector<int>::const_iterator cit = Aa.begin(); cit != Aa.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "creating vector of 12 elements" << std::endl;
	std::vector<int> B(12, 5);
	ft::vector<int> Bb(12, 5);
	std::cout << std::endl;

	std::cout << "Creating vector by copy" << std::endl;
	std::vector<int> C(A);
	ft::vector<int> Cc(Aa);

	std::cout << "Printing value at index 3" << std::endl;
	std::cout << C.at(3) << std::endl;
	std::cout << Cc.at(3) << std::endl;
	return 0;
}
