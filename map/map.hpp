#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <memory>
#include <functional>
#include "../../utils/pair.hpp"
#include "../../utils/make_pair.hpp"
#include "Node.hpp"
#include "BST.hpp"
#include "map_iterator.hpp"

namespace ft
{
	template <typename Key, typename T, typename Compare = std::less<Key>,
			typename Allocator = std::allocator<pair<Key const, T> > >
	class map
	{
		/****************************
		*     PUBLIC PROPERTIES     *
		****************************/

		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<key_type const, mapped_type> value_type;
			typedef Compare key_compare;
			typedef typename Allocator::template rebind<Node<value_type> >::other allocator_type;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;

			typedef map_iterator<Node<value_type>, value_type, allocator_type> iterator;
			// typedef const_iterator
			// typedef reverse_iterator
			// typedef const_reverse_iterator

			typedef typename Allocator::size_type size_type;
			typedef typename Allocator::difference_type difference_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				public:
					bool operator()(value_type const& lhs, value_type const& rhs) const
					{
						return comp(lhs.first, rhs.first);
					}

				protected:
					value_compare(Compare c) : comp(c) {}

					Compare comp;
			};

			/***************************
			*     MEMBER FUNCTIONS     *
			***************************/

			explicit map(key_compare const& comp = key_compare(),
					allocator_type const& alloc = allocator_type())
				: _allocator(alloc), _comp(comp), _bst(_allocator), _size(0) {}

			/*template <typename InputIt>
			map(InputIt first, InputIt last, key_compare const& comp = key_compare(),
					allocator_type const& alloc = allocator_type()) {}*/

			// map(map const& x) {}

			// map& operator=(map const& x) {}

			/********************
			*     ITERATORS     *
			********************/

			iterator begin(void) { return iterator(&_bst, _bst.minimum(_bst.getRoot())); }
			// const_iterator begin(void) const {}
			// iterator end(void) { return iterator(&_bst, _bst.maximum()); }
			/*const_iterator end(void) const {}
			reverse_iterator rbegin(void) {}
			const_reverse_iterator rbegin(void) const {}
			reverse_iterator rend(void) {}
			const_reverse_iterator rend(void) const {}*/

			/*******************
			*     CAPACITY     *
			*******************/

			bool empty(void) const
			{
				if (_size)
					return false;
				return true;
			}

			size_type size(void) const { return _size; }

			size_type max_size(void) const { return _allocator.max_size(); }

			/*************************
			*     ELEMENT ACCESS     *
			*************************/

			mapped_type& operator[](key_type const& k)
			{
				return insert(make_pair(k, T())).first->second;
			}

			/********************
			*     MODIFIERS     *
			********************/

			pair<iterator, bool> insert(value_type const& val)
			{
				Node<value_type>* s = _bst.search(val.first);
				if (s == s->parent)
				{
					_bst.insert(val);
					_size++;
					return pair<iterator, bool>(iterator(&_bst, _bst.search(val.first)), true);
				}
				else
					return pair<iterator, bool>(iterator(&_bst, s), false);
			}

			iterator insert(iterator position, value_type const& val)
			{
				return insert(val).first;
			}

			// template <typename InputIt>
			// void insert(InputIt first, InputIt last) {}

			// void erase(iterator position) {}

			size_type erase(key_type const& k)
			{
				Node<value_type>* s = _bst.search(k);
				if (s == s->parent)
					return 0;
				else
				{
					_bst.remove(k);
					_size--;
					return 1;
				}
			}

			void erase(iterator first, iterator last)
			{
				while (first != last)
				{
					_bst.remove(first->first);
					first++;
				}
			}

			void clear(void)
			{
				_bst.destroy();
				_size = 0;
			}

			// custom function:
			// custom function:
			// custom function:
			void makeTest(void)
			{
				_bst.insert(make_pair(1, 1.1));
				_bst.insert(make_pair(5, 5.5));
				_bst.insert(make_pair(-3, -3.3));
				_bst.insert(make_pair(-6, -6.6));
				_bst.insert(make_pair(6, 6.6));
				_bst.insert(make_pair(4, 4.4));
				_bst.insert(make_pair(9, 9.9));
				_bst.printInOrder();
				std::cout << "==========" << std::endl;
				_bst.remove(-3);
				_bst.remove(5);
				_bst.remove(1);
				_bst.printInOrder();
				std::cout << "==========" << std::endl;
				Node<value_type>* root = _bst.getRoot();
				Node<value_type>* x;

				std::cout << "root = " << root->data.first << " | " << root->data.second << std::endl;

				x = _bst.minimum(root);
				std::cout << "minimum = " << x->data.first << " - " << x->data.second << std::endl;

				x = _bst.successor(x);
				std::cout << "successor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.successor(x);
				std::cout << "successor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.successor(x);
				std::cout << "successor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.successor(x);
				std::cout << "successor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.successor(x);
				std::cout << "successor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.successor(x);
				std::cout << "successor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.successor(x);
				std::cout << "successor = " << x->data.first << " - " << x->data.second << std::endl;

				x = _bst.maximum(root);
				x = _bst.predecessor(x);
				std::cout << "predecessor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.predecessor(x);
				std::cout << "predecessor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.predecessor(x);
				std::cout << "predecessor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.predecessor(x);
				std::cout << "predecessor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.predecessor(x);
				std::cout << "predecessor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.predecessor(x);
				std::cout << "predecessor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.predecessor(x);
				std::cout << "predecessor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.predecessor(x);
				std::cout << "predecessor = " << x->data.first << " - " << x->data.second << std::endl;
				x = _bst.predecessor(x);
				std::cout << "predecessor = " << x->data.first << " - " << x->data.second << std::endl;
			}

			// DELETE AFTER TESTS
			// DELETE AFTER TESTS
			// DELETE AFTER TESTS
			void printTree(void) { _bst.printInOrder(); }

			/********************
			*     OBSERVERS     *
			********************/

			key_compare key_comp(void) const { return _comp; }

			value_compare value_comp(void) const { return value_compare(_comp); }

			/*********************
			*     OPERATIONS     *
			*********************/

			/*iterator find(key_type const& k) {}
			const_iterator find(key_type const& k) const {}
			size_type count(key_type const& k) const {}
			iterator lower_bound(key_type const& k) {}
			const_iterator lower_bound(key_type const& k) const {}
			iterator upper_bound(key_type const& k) {}
			const_iterator upper_bound(key_type const& k) const {}
			pair<const_iterator, const_iterator> equal_range(key_type const& k) const {}
			pair<iterator, iterator> equal_range(key_type const& k) {}*/

			/********************
			*     ALLOCATOR     *
			********************/

			allocator_type get_allocator(void) const { return _allocator; }

		/**************************
		*     PRIVATE MEMBERS     *
		**************************/

		private:
			allocator_type _allocator;
			key_compare _comp;
			BST<value_type, allocator_type> _bst;
			size_type _size;
	};
}

#endif
