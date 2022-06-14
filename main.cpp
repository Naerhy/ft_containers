#include <iostream>
#include <vector>
#include "vector.hpp"

int main(void)
{
	std::vector<int> vect(4, 23);
	ft::vector<int> ft_vect(4, 23);

	vect.push_back(34);
	vect.push_back(35);
	vect.push_back(36);
	ft_vect.push_back(34);
	ft_vect.push_back(35);
	ft_vect.push_back(36);
	std::cout << vect.size() << " - " << vect.capacity() << std::endl;
	std::cout << ft_vect.size() << " - " << ft_vect.capacity() << std::endl;

	std::cout << vect.at(3) << " " << vect[5] << std::endl;
	std::cout << ft_vect.at(3) << " " << ft_vect[5] << std::endl;

	std::cout << "Looping..." << std::endl;
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "Looping... (ft)" << std::endl;
	for (ft::vector<int>::iterator it = ft_vect.begin(); it != ft_vect.end(); it++)
		std::cout << *it << std::endl;
	return 0;
}
