#include <iostream>
#include <vector>
#include <stack>
#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include "map/map.hpp"

#include "utils/make_pair.hpp"

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

	std::vector<int>::const_reverse_iterator rcit = B.rbegin();
	std::cout << *rcit << std::endl;
	ft::vector<int>::const_reverse_iterator rcitt = Bb.rbegin();
	std::cout << *rcitt << std::endl;
	rcit++;
	rcitt++;
	std::cout << *rcit << std::endl;
	std::cout << *rcitt << std::endl;
	rcit--;
	rcitt--;
	std::cout << *rcit << std::endl;
	std::cout << *rcitt << std::endl;
	rcit += 2;
	rcitt += 2;
	std::cout << *rcit << std::endl;
	std::cout << *rcitt << std::endl;
	std::cout << *(rcit - 2) << std::endl;
	std::cout << *(rcitt - 2) << std::endl;

	std::cout << std::endl;

	std::cout << "Creating stack G with std/ft vector" << std::endl;
	std::stack<int> G;
	ft::stack<int> Gg;

	std::cout << "Push number 123 into stacks" << std::endl;
	G.push(123);
	Gg.push(123);

	std::cout << "Print top element from G:" << std::endl;
	std::cout << G.top() << std::endl;
	std::cout << Gg.top() << std::endl;

	std::cout << std::endl;






	ft::map<int, float> Tt;
	Tt.insert(ft::make_pair(12, 234.4));
	Tt.insert(ft::make_pair(1, 4895.3));
	Tt.insert(ft::make_pair(5, 34.1));
	Tt.insert(ft::make_pair(59673, 39457.9));
	Tt.printInOrder();
	Tt.remove(5);
	Tt.remove(12);
	Tt.remove(1);
	Tt.remove(59673);
	std::cout << "===" << std::endl;
	Tt.printInOrder();

	return 0;
}
