#ifndef __MAP_CONST_ITERATOR_HPP__
#define __MAP_CONST_ITERATOR_HPP__

#include <iterator>
#include <cstddef>

namespace ft
{
	template <typename N, typename V, typename C, typename A>
	class map_const_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag iterator_category;

			typedef BST<V, C, A> const tree_type;
			typedef N node_type;
			typedef V const value_type;
			typedef V const & reference;
			typedef V const* pointer;
			typedef std::ptrdiff_t difference_type;

			enum IndexMoves { FORWARD, BACKWARD };

			map_const_iterator(void) : _tree(NULL), _current(NULL), _lastMove(FORWARD) {}

			explicit map_const_iterator(tree_type* tree, node_type* node)
				: _tree(tree), _current(node), _lastMove(FORWARD) {}

			map_const_iterator(map_const_iterator const& copy)
				: _tree(copy._tree), _current(copy._current), _lastMove(copy._lastMove) {}

			~map_const_iterator(void) {}

			map_const_iterator& operator=(map_const_iterator const& assign)
			{
				if (this != &assign)
				{
					_tree = assign._tree;
					_current = assign._current;
					_lastMove = assign._lastMove;
				}
				return *this;
			}

			reference operator*(void) { return _current->data; }
			pointer operator->(void) { return &(_current->data); }

			bool operator==(map_const_iterator const& x) const
			{
				return (_tree == x._tree && _current == x._current);
			}

			bool operator!=(map_const_iterator const& x) const { return !(*this == x); }

			map_const_iterator& operator++(void)
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

			map_const_iterator operator++(int)
			{
				map_const_iterator temp(*this);
				++(*this);
				return temp;
			}

			map_const_iterator& operator--(void)
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

			map_const_iterator operator--(int)
			{
				map_const_iterator temp(*this);
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
