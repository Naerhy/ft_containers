#ifndef __MAP_ITERATOR_HPP__
#define __MAP_ITERATOR_HPP__

#include <iterator>
#include <cstddef>

namespace ft
{
	template <typename N, typename P, typename Allocator>
	class map_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef N node_type;
			typedef P value_type;
			typedef P& reference;
			typedef P* pointer;
			typedef std::ptrdiff_t difference_type;

			typedef BST<value_type, Allocator> tree_type;

			map_iterator(void) : _current(NULL) {}
			explicit map_iterator(tree_type* tree, node_type* node) : _tree(tree), _current(node) {}

			reference operator*(void) { return _current->data; }
			pointer operator->(void) { return &(_current->data); }

			map_iterator& operator++(void)
			{
				_current = _tree->successor(_current);
				return *this;
			}

		private:
			node_type* _current;
			pointer value;
			tree_type* _tree;
	};
}

#endif
