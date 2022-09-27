#ifndef __NODE_HPP__
#define __NODE_HPP__

namespace ft
{
	template <typename T>
	class Node
	{
		public:
			T data;
			Node* left;
			Node* right;
			Node* parent;

			Node(void) : data(), left(NULL), right(NULL), parent(NULL) {}
			Node(T data) : data(data), left(NULL), right(NULL), parent(NULL) {}
	};
}

#endif
