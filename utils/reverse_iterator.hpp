#ifndef __REVERSE_ITERATOR_HPP__
#define __REVERSE_ITERATOR_HPP__

#include "iterator_traits.hpp"

namespace ft
{
	template <typename Iter>
	class reverse_iterator
	{
		public:
			typedef Iter iterator_type;
			typedef typename iterator_traits<Iter>::iterator_category iterator_category;
			typedef typename iterator_traits<Iter>::value_type value_type;
			typedef typename iterator_traits<Iter>::difference_type difference_type;
			typedef typename iterator_traits<Iter>::pointer pointer;
			typedef typename iterator_traits<Iter>::reference reference;

			reverse_iterator(void) : _base(iterator_type()) {}
			explicit reverse_iterator(iterator_type it) : _base(it) {}

			template <typename U>
			reverse_iterator(reverse_iterator<U> const& rev_it) : _base(rev_it.base()) {}

			iterator_type base(void) const { return _base; }

			reference operator*(void) const { return *(_base - 1); }
			pointer operator->(void) const { return &(operator*()); }
			reference operator[](difference_type n) const { return *(_base - 1 - n); }

			reverse_iterator& operator++(void)
			{
				_base--;
				return *this;
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator temp(*this);
				++(*this);
				return temp;
			}
		
		private:
			iterator_type _base;
	};
}

#endif
