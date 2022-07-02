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

	std::cout << "Looping..." << std::endl;
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << "Looping... (ft)" << std::endl;
	for (ft::vector<int>::iterator it = ft_vect.begin(); it != ft_vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	/*std::cout << "Multiplying by 2 before printing:" << std::endl;
	for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); it++)
	{
		*it *= 2;
		std::cout << *it << " ";
	}
	std::cout << std::endl;*/

	/*std::cout << "Multiplying by 2 before printing: (ft)" << std::endl;
	for (ft::vector<int>::const_iterator it = ft_vect.begin(); it != ft_vect.end(); it++)
	{
		*it *= 2;
		std::cout << *it << " ";
	}
	std::cout << std::endl;*/

	/*std::cout << "Erasing..." << std::endl;

	vect.erase(vect.end() - 5, vect.end() - 2);
	ft_vect.erase(ft_vect.end() - 5, ft_vect.end() - 2);

	std::cout << "Looping..." << std::endl;
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "Looping... (ft)" << std::endl;
	for (ft::vector<int>::iterator it = ft_vect.begin(); it != ft_vect.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "Inserting..." << std::endl;

	vect.insert(vect.begin() + 2, vect2.begin(), vect2.end());
	ft_vect.insert(ft_vect.begin() + 2, ft_vect2.begin(), ft_vect2.end());

	std::cout << "Looping..." << std::endl;
	for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Looping... (ft)" << std::endl;
	for (ft::vector<int>::iterator it = ft_vect.begin(); it != ft_vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;*/

	return 0;
}
