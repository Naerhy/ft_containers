#ifndef __BST_HPP__
#define __BST_HPP__

#include <iostream>
#include <utility>

#include "Node.hpp"

namespace ft
{
	template <typename Pair, typename Compare, typename Allocator>
	class BST
	{
		public:
			typedef Node<Pair> node_type;
			typedef typename Pair::first_type key_type;
			typedef typename Pair::second_type mapped_type;
			typedef Allocator allocator_type;

			BST(Compare comp, allocator_type const& alloc)
				: _comp(comp), _allocator(alloc), _nil(_allocator.allocate(1)), _root(_nil)
			{
				_allocator.construct(_nil, node_type());
				_nil->left = _nil;
				_nil->right = _nil;
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
				_root = _insert(_root, new_node);
			}

			void remove(key_type key) { _root = _remove(_root, key); }

			node_type* search(key_type key) const { return _search(_root, key); }

			void printInOrder(void) const { _printInOrder(_root); }

			void destroy(void) {
				_destroy(_root);
				_root = _nil;
			}

			node_type* minimum(node_type* node) const
			{
				while (node->left != _nil)
					node = node->left;
				return node;
			}

			node_type* maximum(node_type* node) const
			{
				while (node->right != _nil)
					node = node->right;
				return node;
			}

			node_type* predecessor(node_type* node, node_type* pred, key_type key) const
			{
				if (node == _nil)
					return pred;
				if (!(_comp(key, node->data.first)) && !(_comp(node->data.first, key)))
				{
					if (node->left != _nil)
						return maximum(node->left);
				}
				else if (_comp(key, node->data.first))
					return predecessor(node->left, pred, key);
				else
				{
					pred = node;
					return predecessor(node->right, pred, key);
				}
				return pred;
			}

			node_type* successor(node_type* root, node_type* x) const
			{
				node_type* parent = _nil;
				node_type* node = root;
				while (node != _nil && node != x)
				{
					if (_comp(x->data.first, node->data.first))
					{
						parent = node;
						node = node->left;
					}
					else
						node = node->right;
				}
				if (node == _nil)
					return _nil;
				if (node->right != _nil)
				{
					node_type* successor = node->right;
					while (successor->left != _nil)
						successor = successor->left;
					return successor;
				}
				else
					return parent;
			}

			node_type* getRoot(void) const { return _root; }

			node_type* getNil(void) const { return _nil; }

		private:
			node_type* _insert(node_type* node, node_type* new_node)
			{
				if (node == _nil)
					node = new_node;
				else
				{
					if (_comp(node->data.first, new_node->data.first))
						node->right = _insert(node->right, new_node);
					else
						node->left = _insert(node->left, new_node);
					node = _skew(node);
					node = _split(node);
				}
				return node;
			}

			node_type* _remove(node_type* node, key_type key)
			{
				if (node != _nil)
				{
					if (!(_comp(key, node->data.first)) && !(_comp(node->data.first, key)))
					{
						if (node->left != _nil && node->right != _nil)
						{
							node_type* heir = node->left;
							while (heir->right != _nil)
								heir = heir->right;
							node_type* x = node;
							node = _allocator.allocate(1);
							_allocator.construct(node, node_type(heir->data));
							node->level = x->level;
							node->left = x->left;
							node->right = x->right;
							node->left = _remove(node->left, node->data.first);
							_allocator.destroy(x);
							_allocator.deallocate(x, 1);
						}
						else
						{
							node_type* temp = node;
							if (node->left != _nil)
								node = node->left;
							else
								node = node->right;
							delete temp;
						}
					}
					else
					{
						if (_comp(node->data.first, key))
							node->right = _remove(node->right, key);
						else
							node->left = _remove(node->left, key);
					}
				}
				if (node->left->level < node->level - 1 || node->right->level < node->level - 1)
				{
					if (node->right->level > --node->level)
						node->right->level = node->level;
					node = _skew(node);
					node = _split(node);
				}
				return node;
			}

			node_type* _skew(node_type* node)
			{
				if (node->level)
				{
					if (node->left->level == node->level)
					{
						node_type* temp = node;
						node = node->left;
						temp->left = node->right;
						node->right = temp;
					}
					node->right = _skew(node->right);
				}
				return node;
			}

			node_type* _split(node_type* node)
			{
				if (node->right->right->level == node->level && node->level)
				{
					node_type* temp = node;
					node = node->right;
					temp->right = node->left;
					node->left = temp;
					node->level++;
					node->right = _split(node->right);
				}
				return node;
			}

			node_type* _search(node_type* node, key_type key) const
			{
				if (node == _nil
						|| (!(_comp(key, node->data.first)) && !(_comp(node->data.first, key))))
					return node;
				if (_comp(key, node->data.first))
					return _search(node->left, key);
				else
					return _search(node->right, key);
			}

			void _printInOrder(node_type* node) const
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

			Compare _comp;
			allocator_type _allocator;
			node_type* _nil;
			node_type* _root;
	};
}

#endif
