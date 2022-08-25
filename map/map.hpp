#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <memory>
#include <functional>
#include "../utils/pair.hpp"
#include "../utils/make_pair.hpp"

namespace ft
{
	template <typename Key, typename T, typename Compare = std::less<Key>,
			typename Allocator = std::allocator<pair<Key const, T> > >
	class map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<key_type const, mapped_type> value_type;
			typedef Compare key_compare;

		private:
			struct Node
			{
				value_type value;
				Node* left;
				Node* right;

				Node(value_type value) : value(value), left(NULL), right(NULL) {}
			};

		public:
			typedef typename Allocator::template rebind<Node>::other allocator_type;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			// typedef iterator
			// typedef const_iterator
			// typedef reverse_iterator
			// typedef const_reverse_iterator
			typedef typename Allocator::size_type size_type;
			typedef typename Allocator::difference_type difference_type;

			/*class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				public:
					bool operator()(value_type const& lhs, value_tye const& rhs) const
					{
						return comp(lhs.first, rhs.first);
					}

				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
			};*/

			explicit map(key_compare const& comp = key_compare(),
					allocator_type const& alloc = allocator_type())
				: _allocator(alloc), _comp(comp), _data(NULL) {}

			~map(void)
			{
				destroy();
			}

			// CUSTOM FUNCTIONS TO TEST BINARY TREE IN MAP CLASS:
			void insert(value_type value)
			{
				if (_data)
					_insert(value, _data);
				else
				{
					_data = _allocator.allocate(1);
					_allocator.construct(_data, Node(value));
				}
			}

			void remove(key_type k) { _data = _remove(k, _data); }

			void printInOrder(void) { _printInOrder(_data); }

			void destroy(void) { _destroy(_data); }

			/********************
			*     ALLOCATOR     *
			********************/

			allocator_type get_allocator(void) const { return _allocator; }

		/**************************
		*     PRIVATE MEMBERS     *
		**************************/

		private:
			void _insert(value_type value, Node* node)
			{
				if (value.first < node->value.first)
				{
					if (node->left)
						_insert(value, node->left);
					else
					{
						node->left = _allocator.allocate(1);
						_allocator.construct(node->left, Node(value));
					}
				}
				if (value.first > node->value.first)
				{
					if (node->right)
						_insert(value, node->right);
					else
					{
						node->right = _allocator.allocate(1);
						_allocator.construct(node->right, Node(value));
					}
				}
			}

			Node* _remove(key_type k, Node* node)
			{
				if (!node)
					return NULL;
				else if (k < node->value.first)
					node->left = _remove(k, node->left);
				else if (k > node->value.first)
					node->right = _remove(k, node->right);
				else
				{
					if (!node->left && !node->right)
					{
						_allocator.destroy(node);
						_allocator.deallocate(node, 1);
						node = NULL;
					}
					else if (!node->left)
					{
						Node* temp = node;
						node = node->right;
						_allocator.destroy(temp);
						_allocator.deallocate(temp, 1);
					}
					else if (!node->right)
					{
						Node* temp = node;
						node = node->left;
						_allocator.destroy(temp);
						_allocator.deallocate(temp, 1);
					}
					else
					{
						// Node* temp = _minimum(node->right);
						// node->value = temp->value;
						// node->right = _remove(temp->value.first, node->right);
						Node* min = _minimum(node->right);
						Node* temp = node;
						node = _allocator.allocate(1);
						_allocator.construct(node, min->value);
						node->left = temp->left;
						node->right = _remove(min->value.first, temp->right);
						_allocator.destroy(temp);
						_allocator.deallocate(temp, 1);
					}
				}
				return node;
			}

			Node* _minimum(Node* node)
			{
				while (node->left)
					node = node->left;
				return node;
			}

			void _printInOrder(Node* node)
			{
				if (node)
				{
					_printInOrder(node->left);
					std::cout << node->value.first << " - " << node->value.second << std::endl;
					_printInOrder(node->right);
				}
			}

			void _destroy(Node* node)
			{
				if (node)
				{
					_destroy(node->left);
					_destroy(node->right);
					_allocator.destroy(node);
					_allocator.deallocate(node, 1);
				}
			}

			allocator_type _allocator;
			key_compare _comp;
			Node* _data;
	};
}

#endif
