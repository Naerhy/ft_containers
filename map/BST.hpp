#ifndef __BST_HPP__
#define __BST_HPP__

#include <iostream>
#include <utility>

#include "Node.hpp"

namespace ft
{
	template <typename Pair, typename Allocator>
	class BST
	{
		public:
			typedef Node<Pair> node_type;
			typedef typename Pair::first_type key_type;
			typedef typename Pair::second_type mapped_type;
			typedef Allocator allocator_type;

			BST(allocator_type const& alloc)
				: _allocator(alloc), _nil(_allocator.allocate(1)), _root(_nil)
			{
				_allocator.construct(_nil, node_type());
				_nil->left = _nil;
				_nil->right = _nil;
				_nil->parent = _nil;
			}

			~BST(void)
			{
				destroy();
				_allocator.destroy(_nil);
				_allocator.deallocate(_nil, 1);
			}

			void insert(Pair pair)
			{
				node_type* new_node = _allocator.allocate(1);
				_allocator.construct(new_node, node_type(pair));
				new_node->left = _nil;
				new_node->right = _nil;
				new_node->parent = _nil;
				_insert(new_node, _root);
			}

			void remove(key_type key) { _root = _remove(key, _root); }

			node_type* search(key_type key) const { return _search(_root, key); }

			void printInOrder(void) { _printInOrder(_root); }

			void destroy(void) {
				_destroy(_root);
				_root = _nil;
			}

			node_type* minimum(node_type* node)
			{
				while (node->left != _nil)
					node = node->left;
				return node;
			}

			node_type* maximum(node_type* node)
			{
				while (node->right != _nil)
					node = node->right;
				return node;
			}

			node_type* predecessor(node_type* node)
			{
				if (node->left != _nil)
					return maximum(node->left);
				node_type* temp = node->parent;
				while (temp != _nil && node == temp->left)
				{
					node = temp;
					temp = temp->parent;
				}
				return temp;
			}

			node_type* successor(node_type* node)
			{
				if (node->right != _nil)
					return minimum(node->right);
				node_type* temp = node->parent;
				while (temp != _nil && node == temp->right)
				{
					node = temp;
					temp = temp->parent;
				}
				return temp;
			}

			node_type* getRoot(void) { return _root; }

			node_type* getNil(void) const { return _nil; }

		private:
			void _insert(node_type* new_node, node_type* node)
			{
				node_type* temp = _nil;
				while (node != _nil)
				{
					temp = node;
					if (new_node->data.first < node->data.first)
						node = node->left;
					else
						node = node->right;
				}
				new_node->parent = temp;
				if (temp == _nil)
					_root = new_node;
				else if (new_node->data.first < temp->data.first)
					temp->left = new_node;
				else
					temp->right = new_node;
			}

			node_type* _remove(key_type key, node_type* node)
			{
				if (node == _nil)
					return node;
				else if (key < node->data.first)
					node->left = _remove(key, node->left);
				else if (key > node->data.first)
					node->right = _remove(key, node->right);
				else
				{
					if (node->left == _nil && node->right == _nil)
					{
						_allocator.destroy(node);
						_allocator.deallocate(node, 1);
						node = _nil;
					}
					else if (node->left == _nil)
					{
						node_type* temp = node;
						node = node->right;
						node->parent = temp->parent; // TEST
						_allocator.destroy(temp);
						_allocator.deallocate(temp, 1);
					}
					else if (node->right == _nil)
					{
						node_type* temp = node;
						node = node->left;
						node->parent = temp->parent; // TEST
						_allocator.destroy(temp);
						_allocator.deallocate(temp, 1);
					}
					else
					{
						node_type* min = minimum(node->right);
						node_type* temp = node;
						node = _allocator.allocate(1);
						_allocator.construct(node, node_type(min->data));
						temp->left->parent = node;
						temp->right->parent = node;
						node->left = temp->left;
						node->right = _remove(min->data.first, temp->right);
						node->parent = temp->parent;
						_allocator.destroy(temp);
						_allocator.deallocate(temp, 1);

						/*node_type* temp = minimum(node->right);
						node->data = temp->data;
						node->right = _remove(temp->data.first, node->right);*/
					}
				}
				return node;
			}

			node_type* _search(node_type* node, key_type key) const
			{
				if (node == _nil || key == node->data.first)
					return node;
				if (key < node->data.first)
					return _search(node->left, key);
				else
					return _search(node->right, key);
			}

			void _printInOrder(node_type* node)
			{
				if (node != _nil)
				{
					_printInOrder(node->left);
					std::cout << node->data.first << " - " << node->data.second << std::endl;
					_printInOrder(node->right);
				}
			}

			void _destroy(node_type* node)
			{
				if (node != _nil)
				{
					_destroy(node->left);
					_destroy(node->right);
					_allocator.destroy(node);
					_allocator.deallocate(node, 1);
				}
			}

			allocator_type _allocator;
			node_type* _nil;
			node_type* _root;
	};
}

#endif
