#include <iostream>
#include <vector>
#include "vector/vector.hpp"

int main(void)
{
	std::cout << "Creating empty vector (A)" << std::endl;
	std::vector<int> A;
	ft::vector<int> Aa;
	std::cout << std::endl;

	std::cout << "Pushing elements into vector A" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		A.push_back(i * 10);
		Aa.push_back(i * 10);
	}
	std::cout << std::endl;

	std::cout << "Printing values from A" << std::endl;
	for (std::vector<int>::const_iterator cit = A.begin(); cit != A.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	for (ft::vector<int>::const_iterator cit = Aa.begin(); cit != Aa.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "creating vector of 12 elements (B)" << std::endl;
	std::vector<int> B(12, 5);
	ft::vector<int> Bb(12, 5);
	std::cout << std::endl;

	std::cout << "Creating vector by copy (C, from A)" << std::endl;
	std::vector<int> C(A);
	ft::vector<int> Cc(Aa);
	std::cout << std::endl;

	std::cout << "Printing value at index 3 of vector C" << std::endl;
	std::cout << C.at(3) << std::endl;
	std::cout << Cc.at(3) << std::endl;
	std::cout << std::endl;

	std::cout << "Creating vector D of size 234 and assigning B to D" << std::endl;
	std::vector<int> D(234, 1);
	ft::vector<int> Dd(234, 1);
	D = B;
	Dd = Bb;
	std::cout << std::endl;

	std::cout << "Printing values from D" << std::endl;
	for (std::vector<int>::const_iterator cit = D.begin(); cit != D.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	for (ft::vector<int>::const_iterator cit = Dd.begin(); cit != Dd.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << "Testing operators on vectors" << std::endl;
	std::cout << "A == B : " << (A == B) << " | " << (Aa == Bb) << std::endl;
	std::cout << "A != B : " << (A != B) << " | " << (Aa != Bb) << std::endl;
	std::cout << "A < B : " << (A < B) << " | " << (Aa < Bb) << std::endl;
	std::cout << "A <= B : " << (A <= B) << " | " << (Aa <= Bb) << std::endl;
	std::cout << "A > B : " << (A > B) << " | " << (Aa > Bb) << std::endl;
	std::cout << "A >= B : " << (A >= B) << " | " << (Aa >= Bb) << std::endl;

	std::cout << std::endl;

	std::cout << "Swapping A with B" << std::endl;
	std::cout << "Printing values from A: " << std::endl;
	for (std::vector<int>::const_iterator cit = A.begin(); cit != A.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	for (ft::vector<int>::const_iterator cit = Aa.begin(); cit != Aa.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	std::cout << "Printing values from B: " << std::endl;
	for (std::vector<int>::const_iterator cit = B.begin(); cit != B.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	for (ft::vector<int>::const_iterator cit = Bb.begin(); cit != Bb.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	std::cout << "Swapping..." << std::endl;
	swap(A, B);
	swap(Aa, Bb);
	std::cout << "Printing values from A: " << std::endl;
	for (std::vector<int>::const_iterator cit = A.begin(); cit != A.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	for (ft::vector<int>::const_iterator cit = Aa.begin(); cit != Aa.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	std::cout << "Printing values from B: " << std::endl;
	for (std::vector<int>::const_iterator cit = B.begin(); cit != B.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	for (ft::vector<int>::const_iterator cit = Bb.begin(); cit != Bb.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;

	std::cout << std::endl;

	std::cout << "Creating object E from range constructor (using B iterators)" << std::endl;
	std::vector<int> E(B.begin(), B.end());
	ft::vector<int> Ee(Bb.begin(), Bb.end());
	std::cout << "Printing values from E: " << std::endl;
	for (std::vector<int>::const_iterator cit = E.begin(); cit != E.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;
	for (ft::vector<int>::const_iterator cit = Ee.begin(); cit != Ee.end(); cit++)
		std::cout << *cit << " ";
	std::cout << std::endl;


	return 0;
}
