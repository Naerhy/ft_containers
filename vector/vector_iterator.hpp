#ifndef __VECTOR_ITERATOR_HPP__
#define __VECTOR_ITERATOR_HPP__

#include "vector_const_iterator.hpp"

namespace ft
{
	template <typename T>
	class vector_iterator : public vector_const_iterator<T>
	{
		public:
			typedef typename vector_const_iterator<T>::difference_type difference_type;

			vector_iterator(T* ptr) : vector_const_iterator<T>(ptr) {}
			vector_iterator(vector_iterator const& copy) : vector_const_iterator<T>(copy) {}
			virtual ~vector_iterator(void) {}

			vector_iterator& operator=(vector_iterator const& assign)
			{
				if (this != &assign)
					vector_const_iterator<T>::operator=(assign);
				return *this;
			}

			T& operator*(void) { return *vector_const_iterator<T>::_ptr; }
			T* operator->(void) { return vector_const_iterator<T>::_ptr; }
			T& operator[](difference_type n) { return *(this->_ptr + n); }
	};
}

#endif
