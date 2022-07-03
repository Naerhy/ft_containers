#ifndef __VECTOR_ITERATOR_HPP__
#define __VECTOR_ITERATOR_HPP__

#include "vector_const_iterator.hpp"

namespace ft
{
	template <typename T>
	class vector_iterator : public vector_const_iterator<T>
	{
		public:

			typedef T& reference;
			typedef T* pointer;

			vector_iterator(pointer ptr) : vector_const_iterator<T>(ptr) {}
			vector_iterator(vector_iterator const& copy) : vector_const_iterator<T>(copy) {}
			~vector_iterator(void) {}

			vector_iterator& operator=(vector_iterator const& assign)
			{
				if (this != &assign)
					vector_const_iterator<T>::operator=(assign);
				return *this;
			}

			reference operator*(void) const { return *vector_const_iterator<T>::_ptr; }
			pointer operator->(void) const { return vector_const_iterator<T>::_ptr; }
	};
}

#endif
