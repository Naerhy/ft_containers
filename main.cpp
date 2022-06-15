#include <iostream>
#include <vector>
#include "vector/vector.hpp"

int main(void)
{
	std::vector<int> vect;
	std::vector<int> vect2;

	ft::vector<int> ft_vect;
	ft::vector<int> ft_vect2;

	for (int i = 0; i < 9; i++)
		vect.push_back(i);
	for (int i = 10; i < 19; i++)
		vect2.push_back(i);

	for (int i = 0; i < 9; i++)
		ft_vect.push_back(i);
	for (int i = 10; i < 19; i++)
		ft_vect2.push_back(i);

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

	std::cout << "Swapping..." << std::endl;
	vect.swap(vect2);
	ft_vect.swap(ft_vect2);

	std::cout << "Looping..." << std::endl;
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "Looping... (ft)" << std::endl;
	for (ft::vector<int>::iterator it = ft_vect.begin(); it != ft_vect.end(); it++)
		std::cout << *it << std::endl;

	return 0;
}
