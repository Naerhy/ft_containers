#ifndef __MAP_ITERATOR_HPP__
#define __MAP_ITERATOR_HPP__

#include <iterator>
#include <cstddef>

namespace ft
{
	template <typename N, typename V, typename A>
	class map_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag iterator_category;

			typedef BST<V, A> tree_type;
			typedef N node_type;
			typedef V value_type;

			map_iterator(void) : _current(NULL) {}
			explicit map_iterator(tree_type* tree, node_type* node) : _tree(tree), _current(node) {}
			map_iterator(map_iterator const& copy) : _tree(copy._tree), _current(copy._current) {}
			~map_iterator(void) {}

			map_iterator& operator=(map_iterator const& assign)
			{
				if (this != &assign)
				{
					_tree = assign._tree;
					_current = assign._current;
				}
				return *this;
			}

			value_type& operator*(void) { return _current->data; }
			value_type* operator->(void) { return &(_current->data); }

			bool operator==(map_iterator const& x) const
			{
				return (_tree == x._tree && _current == x._current);
			}

			bool operator!=(map_iterator const& x) const { return !(*this == x); }

			map_iterator& operator++(void)
			{
				_current = _tree->successor(_current);
				return *this;
			}

			map_iterator operator++(int)
			{
				map_iterator temp(*this);
				++(*this);
				return temp;
			}

			map_iterator& operator--(void)
			{
				_current = _tree->predecessor(_current);
				return *this;
			}

			map_iterator operator--(int)
			{
				map_iterator temp(*this);
				--(*this);
				return temp;
			}

		private:
			tree_type* _tree;
			node_type* _current;
	};
}

#endif
