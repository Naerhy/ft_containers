#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <memory>
#include <functional>
#include "pair.hpp"
#include "make_pair.hpp"
#include "Node.hpp"
#include "BST.hpp"
#include "map_iterator.hpp"
#include "map_const_iterator.hpp"
#include "reverse_iterator.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

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

			typedef map_iterator<Node<value_type>, value_type, key_compare, allocator_type> iterator;
			typedef map_const_iterator<Node<value_type>, value_type, key_compare, allocator_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

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
				: _allocator(alloc), _comp(comp),
					_bst(new BST<value_type, key_compare, allocator_type>(_comp, _allocator)), _size(0) {}

			template <typename InputIt>
			map(InputIt first, InputIt last, key_compare const& comp = key_compare(),
					allocator_type const& alloc = allocator_type())
				: _allocator(alloc), _comp(comp),
					_bst(new BST<value_type, key_compare, allocator_type>(_comp, _allocator)), _size(0)
			{
				insert(first, last);
			}

			map(map const& copy)
				: _allocator(copy._allocator), _comp(copy._comp),
					_bst(new BST<value_type, key_compare, allocator_type>(_comp, _allocator)),
					_size(copy._size)
			{
				insert(copy.begin(), copy.end());
			}

			~map(void) { delete _bst; }

			map& operator=(map const& x)
			{
				if (this != &x)
				{
					clear();
					insert(x.begin(), x.end());
				}
				return *this;
			}

			/********************
			*     ITERATORS     *
			********************/

			iterator begin(void) { return iterator(_bst, _bst->minimum(_bst->getRoot())); }

			const_iterator begin(void) const
			{
				return const_iterator(_bst, _bst->minimum(_bst->getRoot()));
			}

			iterator end(void)
			{
				return iterator(_bst, _bst->successor(_bst->getRoot(), _bst->maximum(_bst->getRoot())));
			}

			const_iterator end(void) const
			{
				return const_iterator(_bst, _bst->successor(_bst->getRoot(), _bst->maximum(_bst->getRoot())));
			}

			reverse_iterator rbegin(void) { return reverse_iterator(end()); }

			const_reverse_iterator rbegin(void) const { return const_reverse_iterator(end()); }

			reverse_iterator rend(void) { return reverse_iterator(begin()); }

			const_reverse_iterator rend(void) const { return const_reverse_iterator(begin()); }

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
				return insert(ft::make_pair(k, mapped_type())).first->second;
			}

			/********************
			*     MODIFIERS     *
			********************/

			pair<iterator, bool> insert(value_type const& val)
			{
				Node<value_type>* s = _bst->search(val.first);
				if (s == _bst->getNil())
				{
					_bst->insert(val);
					_size++;
					return pair<iterator, bool>(iterator(_bst, _bst->search(val.first)), true);
				}
				else
					return pair<iterator, bool>(iterator(_bst, s), false);
			}

			iterator insert(iterator position, value_type const& val)
			{
				(void)position;
				return insert(val).first;
			}

			template <typename InputIt>
			void insert(InputIt first, InputIt last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			void erase(iterator position) { erase(position->first); }

			size_type erase(key_type const& k)
			{
				Node<value_type>* s = _bst->search(k);
				if (s == _bst->getNil())
					return 0;
				else
				{
					_bst->remove(k);
					_size--;
					return 1;
				}
			}

			void erase(iterator first, iterator last)
			{
				iterator temp;
				while (first != last)
				{
					temp = first;
					first++;
					erase(temp->first);
				}
			}

			void swap(map& x)
			{
				std::swap(_allocator, x._allocator);
				std::swap(_comp, x._comp);
				std::swap(_bst, x._bst);
				std::swap(_size, x._size);
			}

			void clear(void)
			{
				_bst->destroy();
				_size = 0;
			}

			/********************
			*     OBSERVERS     *
			********************/

			key_compare key_comp(void) const { return _comp; }

			value_compare value_comp(void) const { return value_compare(_comp); }

			/*********************
			*     OPERATIONS     *
			*********************/

			iterator find(key_type const& k)
			{
				Node<value_type>* s = _bst->search(k);
				if (s == _bst->getNil())
					return end();
				else
					return iterator(_bst, s);
			}

			const_iterator find(key_type const& k) const
			{
				Node<value_type>* s = _bst->search(k);
				if (s == _bst->getNil())
					return end();
				else
					return const_iterator(_bst, s);
			}

			size_type count(key_type const& k) const
			{
				if (_bst->search(k) == _bst->getNil())
					return 0;
				else
					return 1;
			}

			iterator lower_bound(key_type const& k)
			{
				for (const_iterator cit = begin(); cit != end(); cit++)
				{
					if (!(_comp(cit->first, k)))
						return iterator(_bst, _bst->search(cit->first));
				}
				return end();
			}

			const_iterator lower_bound(key_type const& k) const
			{
				for (const_iterator cit = begin(); cit != end(); cit++)
				{
					if (!(_comp(cit->first, k)))
						return const_iterator(_bst, _bst->search(cit->first));
				}
				return end();
			}

			iterator upper_bound(key_type const& k)
			{
				for (const_iterator cit = begin(); cit != end(); cit++)
				{
					if (_comp(k, cit->first))
						return iterator(_bst, _bst->search(cit->first));
				}
				return end();
			}

			const_iterator upper_bound(key_type const& k) const
			{
				for (const_iterator cit = begin(); cit != end(); cit++)
				{
					if (_comp(k, cit->first))
						return const_iterator(_bst, _bst->search(cit->first));
				}
				return end();
			}

			pair<iterator, iterator> equal_range(key_type const& k)
			{
				return ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
			}

			pair<const_iterator, const_iterator> equal_range(key_type const& k) const
			{
				return ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
			}

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
			BST<value_type, key_compare, allocator_type>* _bst;
			size_type _size;
	};

	/*******************************
	*     NON-MEMBER FUNCTIONS     *
	*******************************/

	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator==(map<Key, T, Comp, Alloc> const& lhs, map<Key, T, Comp, Alloc> const& rhs)
	{
		typedef typename map<Key, T, Comp, Alloc>::const_iterator it_type;
		if (lhs.size() == rhs.size())
			return ft::equal<it_type, it_type>(lhs.begin(), lhs.end(), rhs.begin());
		return false;
	}

	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator!=(map<Key, T, Comp, Alloc> const& lhs, map<Key, T, Comp, Alloc> const& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator<(map<Key, T, Comp, Alloc> const& lhs, map<Key, T, Comp, Alloc> const& rhs)
	{
		typedef typename map<Key, T, Comp, Alloc>::const_iterator it_type;
		return ft::lexicographical_compare<it_type, it_type>(lhs.begin(), lhs.end(),
				rhs.begin(), rhs.end());
	}

	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator<=(map<Key, T, Comp, Alloc> const& lhs, map<Key, T, Comp, Alloc> const& rhs)
	{
		return !(rhs < lhs);
	}

	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator>(map<Key, T, Comp, Alloc> const& lhs, map<Key, T, Comp, Alloc> const& rhs)
	{
		return rhs < lhs;
	}

	template <typename Key, typename T, typename Comp, typename Alloc>
	bool operator>=(map<Key, T, Comp, Alloc> const& lhs, map<Key, T, Comp, Alloc> const& rhs)
	{
		return !(lhs < rhs);
	}

	template <typename Key, typename T, typename Compare, typename Alloc>
	void swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs) { lhs.swap(rhs); }
}

#endif
