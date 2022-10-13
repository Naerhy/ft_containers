#include <iostream>
#include <string>
#include <deque>

#if 1
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "map.hpp"
	#include "stack.hpp"
	#include "vector.hpp"
#endif

template <typename It>
void printVector(It first, It last)
{
	while (first != last)
	{
		std::cout << *first << std::endl;
		first++;
	}
}

template <typename It>
void printMap(It first, It last)
{
	while (first != last)
	{
		std::cout << first->first << " - " << first->second << std::endl;
		first++;
	}
}

int main(void)
{
	std::cout << std::endl;
	std::cout << "\033[31m=== VECTOR ===\033[0m" << std::endl;
	std::cout << std::endl;

	std::cout << "--> Constructing empty vector A and pushing elements 1 by 1:" << std::endl;
	ft::vector<int> A;
	for (int i = 0; i < 5; i++)
		A.push_back(i);
	printVector(A.begin(), A.end());

	std::cout << std::endl;

	std::cout << "--> Constructing vector B with 6 elements (12):" << std::endl;
	ft::vector<int> B(6, 12);
	printVector(B.begin(), B.end());

	std::cout << std::endl;

	std::cout << "--> Constructing vector C from range A:" << std::endl;
	ft::vector<int> C(A.begin(), A.end());
	printVector(C.begin(), C.end());

	std::cout << std::endl;

	std::cout << "--> Constructing vector D with copy constructor from B:" << std::endl;
	ft::vector<int> D(B);
	printVector(D.begin(), D.end());

	std::cout << std::endl;

	std::cout << "--> Testing return values:" << std::endl;
	std::cout << "-> A size = " << A.size() << std::endl;
	std::cout << "-> A max_size = " << A.max_size() << std::endl;
	std::cout << "-> A capacity = " << A.capacity() << std::endl;
	std::cout << "-> A is empty: " << A.empty() << std::endl;

	std::cout << std::endl;

	std::cout << "--> Modifying A capacity and size:" << std::endl;
	A.reserve(123);
	A.resize(3);
	std::cout << "-> A new size = " << A.size() << std::endl;
	std::cout << "-> A new capacity = " << A.capacity() << std::endl;
	std::cout << "-> Printing A to check if values have been updated:" << std::endl;
	printVector(A.begin(), A.end());

	std::cout << std::endl;

	std::cout << "--> Testing access functions:" << std::endl;
	std::cout << "-> C[3] = " << C[3] <<  std::endl;
	std::cout << "-> C at 2nd position = " << C.at(1) << std::endl;
	std::cout << "-> C front position = " << C.front() << std::endl;
	std::cout << "-> C back position = " << C.back() << std::endl;

	std::cout << std::endl;

	std::cout << "--> Assigning C to A:" << std::endl;
	A = C;
	std::cout << "-> Printing A to check assignment:" << std::endl;
	printVector(A.begin(), A.end());

	std::cout << std::endl;

	std::cout << "--> Testing vector reverse iterators:" << std::endl;
	std::cout << "-> Printing reverse A:" << std::endl;
	printVector(A.rbegin(), A.rend());

	std::cout << std::endl;

	std::cout << "--> Testing modifiers functions:" << std::endl;
	std::cout << "-> Assigning 10 elements to B (1234):" << std::endl;
	B.assign(10, 1234);
	std::cout << "-> Printing B:" << std::endl;
	printVector(B.begin(), B.end());
	std::cout << "-> Pushing some elements to B:" << std::endl;
	B.push_back(83);
	B.push_back(-4);
	B.push_back(2098);
	std::cout << "-> Printing B:" << std::endl;
	printVector(B.begin(), B.end());
	std::cout << "-> Deleting last element from B:" << std::endl;
	B.pop_back();
	std::cout << "-> Printing B:" << std::endl;
	printVector(B.begin(), B.end());
	std::cout << "-> Inserting elements to B" << std::endl;
	B.insert(B.begin() + 2, 34);
	B.insert(B.begin() + 4, 3, 42);
	B.insert(B.end() - 2, A.begin(), A.end()); // LEAK
	std::cout << "-> Printing B:" << std::endl;
	printVector(B.begin(), B.end());
	std::cout << "-> Erasing elements" << std::endl;
	B.erase(B.begin() + 1);
	B.erase(B.begin(), B.end() - 5);
	std::cout << "-> Printing B:" << std::endl;
	printVector(B.begin(), B.end());

	std::cout << std::endl;

	std::cout << "--> Swapping B with A" << std::endl;
	B.swap(A);
	std::cout << "-> Printing A:" << std::endl;
	printVector(A.begin(), A.end());
	std::cout << "-> Printing B:" << std::endl;
	printVector(B.begin(), B.end());

	std::cout << std::endl;

	std::cout << "--> Clearing B" << std::endl;
	B.clear();
	std::cout << "-> Printing B:" << std::endl;
	printVector(B.begin(), B.end());
	std::cout << "B size = " << B.size() << std::endl;

	std::cout << std::endl;

	std::cout << "--> Swapping A with B using non-member function" << std::endl;
	ft::swap(A, B);
	std::cout << "-> Printing A:" << std::endl;
	printVector(A.begin(), A.end());
	std::cout << "-> Printing B:" << std::endl;
	printVector(B.begin(), B.end());

	std::cout << std::endl;

	std::cout << "--> Testing relational operators" << std::endl;
	std::cout << "C == D : " << (C == D) << std::endl;
	std::cout << "C != D : " << (C != D) << std::endl;
	std::cout << "C < D : " << (C < D) << std::endl;
	std::cout << "C <= D : " << (C <= D) << std::endl;
	std::cout << "C > D : " << (C > D) << std::endl;
	std::cout << "C >= D : " << (C >= D) << std::endl;

	std::cout << std::endl;
	std::cout << "\033[32m=== STACK ===\033[0m" << std::endl;
	std::cout << std::endl;

	std::cout << "--> Constructing empty stack F and pushing elements into it" << std::endl;
	ft::stack<std::string> F;
	F.push("test de stack");
	F.push("encore un test");
	F.push("et un dernier ?");
	std::cout << "-> Printing last inserted element into F" << std::endl;
	std::cout << "F top = " << F.top() << std::endl;

	std::cout << std::endl;

	std::cout << "--> Constructing stack G from vector C" << std::endl;
	ft::stack<int, ft::vector<int> > G(C);
	std::cout << "-> Printing last inserted element into G" << std::endl;
	std::cout << "G top = " << G.top() << std::endl;

	std::cout << std::endl;

	std::cout << "--> Constructing stack H with std::deque" << std::endl;
	ft::stack<int, std::deque<int> > H;
	std::cout << "-> Pushing elements into H" << std::endl;
	H.push(23);
	H.push(-34);
	std::cout << "-> Printing last element in H" << std::endl;
	std::cout << "H top = " << H.top() << std::endl;

	std::cout << std::endl;

	std::cout << "--> Checking return values" << std::endl;
	std::cout << "G is empty: " << G.empty() << std::endl;
	std::cout << "G size = " << G.size() << std::endl;

	std::cout << std::endl;

	std::cout << "--> Removing elements from F" << std::endl;
	F.pop();
	std::cout << "-> Printing last element in F" << std::endl;
	std::cout << "F top = " << F.top() << std::endl;
	std::cout << "-> Removing another element from F" << std::endl;
	F.pop();
	std::cout << "-> Printing last element in F" << std::endl;
	std::cout << "F top = " << F.top() << std::endl;

	std::cout << std::endl;

	std::cout << "--> Testing relational operators" << std::endl;
	std::cout << "-> Constructing stack I for tests" << std::endl;
	ft::stack<std::string> I;
	I.push("une phrase de test");
	std::cout << "F == I : " << (F == I) << std::endl;
	std::cout << "F != I : " << (F != I) << std::endl;
	std::cout << "F < I : " << (F < I) << std::endl;
	std::cout << "F <= I : " << (F <= I) << std::endl;
	std::cout << "F > I : " << (F > I) << std::endl;
	std::cout << "F >= I : " << (F >= I) << std::endl;

	std::cout << std::endl;
	std::cout << "\033[34m=== MAP ===\033[0m" << std::endl;
	std::cout << std::endl;

	std::cout << "--> Constructing empty map K and filling it" << std::endl;
	ft::map<int, std::string> K;
	K.insert(ft::make_pair(3, "trois"));
	K.insert(ft::make_pair(-45, "moins quarante-cinq"));
	K.insert(ft::make_pair(36, "trente-six"));
	K.insert(ft::make_pair(1000, "mille"));
	K.insert(ft::make_pair(12, "douze"));
	K.insert(ft::make_pair(100, "cent"));
	std::cout << "-> Printing K" << std::endl;
	printMap(K.begin(), K.end());

	std::cout << std::endl;

	std::cout << "--> Constructing map L with range from K" << std::endl;
	ft::map<int, std::string> L(K.lower_bound(12), K.upper_bound(100));
	std::cout << "-> Printing L" << std::endl;
	printMap(L.begin(), L.end());

	std::cout << std::endl;

	std::cout << "--> Constructing map M with copy constructor using L" << std::endl;
	ft::map<int, std::string> M(L);
	std::cout << "-> Printing M" << std::endl;
	printMap(M.begin(), M.end());

	std::cout << std::endl;

	std::cout << "--> Assigning K to M" << std::endl;
	M = K;
	std::cout << "-> Printing M" << std::endl;
	printMap(M.begin(), M.end());

	std::cout << std::endl;

	std::cout << "--> Testing map reverse iterators:" << std::endl;
	std::cout << "-> Printing reverse K:" << std::endl;
	printMap(K.rbegin(), K.rend());

	std::cout << std::endl;

	std::cout << "--> Testing return values" << std::endl;
	std::cout << "K empty: " << K.empty() << std::endl;
	std::cout << "K size: " << K.size() << std::endl;
	std::cout << "K max_size: " << K.max_size() << std::endl;

	std::cout << std::endl;

	std::cout << "--> Accessing map elements" << std::endl;
	std::cout << "K[36] = " << K[36] << std::endl;
	std::cout << "M[-45] = " << M[-45] << std::endl;
	std::cout << "L[100] = " << L[100] << std::endl;

	std::cout << std::endl;

	std::cout << "--> Inserting elements into K" << std::endl;
	K.insert(ft::make_pair(56, "cinquante-six"));
	K.insert(K.find(56), ft::make_pair(60, "soixante"));
	K.insert(L.begin(), L.end());
	std::cout << "-> Printing K" << std::endl;
	printMap(K.begin(), K.end());

	std::cout << std::endl;

	std::cout << "--> Erasing elements from K" << std::endl;
	K.erase(K.find(12));
	std::cout << "-> Printing K" << std::endl;
	printMap(K.begin(), K.end());
	K.erase(-45);
	std::cout << "-> Printing K" << std::endl;
	printMap(K.begin(), K.end());
	K.erase(K.begin(), K.end());
	std::cout << "-> Printing K" << std::endl;
	printMap(K.begin(), K.end());

	std::cout << std::endl;

	std::cout << "--> Swapping map L and M" << std::endl;
	std::cout << "-> Printing L" << std::endl;
	printMap(L.begin(), L.end());
	std::cout << "-> Printing M" << std::endl;
	printMap(M.begin(), M.end());
	L.swap(M);
	std::cout << "-> Printing L" << std::endl;
	printMap(L.begin(), L.end());
	std::cout << "-> Printing M" << std::endl;
	printMap(M.begin(), M.end());

	std::cout << std::endl;

	std::cout << "--> Swapping map L and M with non-member function" << std::endl;
	ft::swap(L, M);
	std::cout << "-> Printing L" << std::endl;
	printMap(L.begin(), L.end());
	std::cout << "-> Printing M" << std::endl;
	printMap(M.begin(), M.end());

	std::cout << std::endl;

	std::cout << "--> Clearing map M" << std::endl;
	M.clear();
	std::cout << "-> Printing M" << std::endl;
	printMap(M.begin(), M.end());

	std::cout << std::endl;

	std::cout << "--> Testing map operations functions on map L" << std::endl;
	std::cout << "find(12) = " << L.find(12)->first << " - " << L.find(12)->second << std::endl;
	std::cout << "count(100) = " << L.count(100) << std::endl;
	std::cout << "count(1000) = " << L.count(1000) << std::endl;
	std::cout << "lower_bound(36) = " << L.lower_bound(36)->first << " - "
			<< L.lower_bound(36)->second << std::endl;
	std::cout << "upper_bound(36) = " << L.upper_bound(36)->first << " - "
			<< L.upper_bound(36)->second << std::endl;
	std::cout << "equal_range(12) = " << L.equal_range(12).first->first << " - "
			<< L.equal_range(12).first->second << " | " << L.equal_range(12).second->first
			<< " - " << L.equal_range(12).second->second << std::endl;

	std::cout << std::endl;

	std::cout << "Testing map relational operators" << std::endl;
	std::cout << "L == K : " << (L == K) << std::endl;
	std::cout << "L != K : " << (L != K) << std::endl;
	std::cout << "L < K : " << (L < K) << std::endl;
	std::cout << "L <= K : " << (L <= K) << std::endl;
	std::cout << "L > K : " << (L > K) << std::endl;
	std::cout << "L >= K : " << (L >= K) << std::endl;

	return 0;
}
