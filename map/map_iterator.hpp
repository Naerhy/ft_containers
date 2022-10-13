#ifndef __MAP_ITERATOR_HPP__
#define __MAP_ITERATOR_HPP__

#include <iterator>
#include <cstddef>
#include "map_const_iterator.hpp"

namespace ft
{
	template <typename N, typename V, typename C, typename A>
	class map_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef BST<V, C, A> tree_type;
			typedef N node_type;
			typedef V value_type;
			typedef V& reference;
			typedef V* pointer;
			typedef std::ptrdiff_t difference_type;

			enum IndexMoves { FORWARD, BACKWARD };

			map_iterator(void) : _tree(NULL), _current(NULL), _lastMove(FORWARD) {}

			explicit map_iterator(tree_type* tree, node_type* node)
				: _tree(tree), _current(node), _lastMove(FORWARD) {}

			map_iterator(map_iterator const& copy)
				: _tree(copy._tree), _current(copy._current), _lastMove(copy._lastMove) {}

			~map_iterator(void) {}

			map_iterator& operator=(map_iterator const& assign)
			{
				if (this != &assign)
				{
					_tree = assign._tree;
					_current = assign._current;
					_lastMove = assign._lastMove;
				}
				return *this;
			}

			// add last move or it will be set to inactive by default...
			// add last move or it will be set to inactive by default...
			// add last move or it will be set to inactive by default...
			operator map_const_iterator<N, V, C, A>(void) const
			{
				return map_const_iterator<N, V, C, A>(_tree, _current);
			}

			reference operator*(void) { return _current->data; }
			pointer operator->(void) { return &(_current->data); }

			bool operator==(map_iterator const& x) const
			{
				return (_tree == x._tree && _current == x._current);
			}

			bool operator!=(map_iterator const& x) const { return !(*this == x); }

			map_iterator& operator++(void)
			{
				if (_current == _tree->getNil()
						&& _tree->minimum(_tree->getRoot()) != _tree->getNil()
						&& _lastMove == BACKWARD)
					_current = _tree->minimum(_tree->getRoot());
				else
					_current = _tree->successor(_tree->getRoot(), _current);
				_lastMove = FORWARD;
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
				if (_current == _tree->getNil()
						&& _tree->maximum(_tree->getRoot()) != _tree->getNil()
						&& _lastMove == FORWARD)
					_current = _tree->maximum(_tree->getRoot());
				else
					_current = _tree->predecessor(_tree->getRoot(), _tree->getNil(),
							_current->data.first);
				_lastMove = BACKWARD;
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
			IndexMoves _lastMove;
	};
}

#endif
