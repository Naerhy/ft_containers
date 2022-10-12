#ifndef __NODE_HPP__
#define __NODE_HPP__

namespace ft
{
	template <typename T>
	class Node
	{
		public:
			T data;
			int level;
			Node* left;
			Node* right;

			Node(void) : data(), level(0), left(NULL), right(NULL) {}
			Node(T data) : data(data), level(1), left(NULL), right(NULL) {}
	};
}

#endif
