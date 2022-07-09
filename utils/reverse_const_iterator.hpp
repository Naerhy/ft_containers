#ifndef __REVERSE_CONST_ITERATOR_HPP__
#define __REVERSE_CONST_ITERATOR_HPP__

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

			// reverse_iterator(void);
			explicit reverse_iterator(iterator_type it) { _base = it; }
			// template <typename Iter>
			// reverse_iterator(const reverse_iterator<Iter>& rev_it);

			iterator_type base(void) const { return _base; }

			reference operator*(void) const { return *(base - 1); }
			pointer operator->(void) const { return &(operator*()); }
			reference operator[](difference_type n) const { 
		
		private:
			iterator_type _base;
	};
}

#endif
