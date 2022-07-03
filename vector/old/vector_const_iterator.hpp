#ifndef __VECTOR_CONST_ITERATOR_HPP
#define __VECTOR_CONST_ITERATOR_HPP

#include "vector_iterator.hpp"

namespace ft
{
	template <typename T>
	class vector_const_iterator
	{
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef T value_type;
			typedef T const& reference;
			typedef T const* pointer;
			typedef std::ptrdiff_t difference_type;

			/******************************************************************************
			*            CONSTRUCTORS                                                     *
			******************************************************************************/

			vector_const_iterator(pointer ptr) : _ptr(ptr) {}
			vector_const_iterator(vector_const_iterator const& copy) : _ptr(copy._ptr) {}
			vector_const_iterator(vector_iterator<T> const& copy) : _ptr(copy.operator->()) {}
			~vector_const_iterator(void) {}

			/**********************************************************
			*            OPERATORS OVERLOAD                           *
			**********************************************************/

			vector_const_iterator& operator=(vector_const_iterator const& assign)
			{
				if (this != &assign)
					_ptr = assign._ptr;
				return *this;
			}

			reference operator*(void) const { return *_ptr; }
			pointer operator->(void) const { return _ptr; }

			bool operator==(vector_const_iterator const& x) const { return _ptr == x._ptr; }
			bool operator!=(vector_const_iterator const& x) const { return _ptr != x._ptr; }
			bool operator<(vector_const_iterator const& x) const { return _ptr < x._ptr; }
			bool operator>(vector_const_iterator const& x) const { return _ptr > x._ptr; }
			bool operator<=(vector_const_iterator const& x) const { return _ptr <= x._ptr; }
			bool operator>=(vector_const_iterator const& x) const { return _ptr >= x._ptr; }

			vector_const_iterator& operator++(void)
			{
				_ptr++;
				return *this;
			}

			vector_const_iterator operator++(int)
			{
				vector_const_iterator temp(*this);
				++(*this);
				return temp;
			}

			vector_const_iterator& operator--(void)
			{
				_ptr--;
				return *this;
			}

			vector_const_iterator operator--(int)
			{
				vector_const_iterator temp(*this);
				--(*this);
				return temp;
			}

			vector_const_iterator& operator+=(difference_type i)
			{
				_ptr += i;
				return *this;
			}

			vector_const_iterator& operator-=(difference_type i)
			{
				_ptr -= i;
				return *this;
			}

			vector_const_iterator operator+(difference_type i) { return vector_const_iterator(_ptr + i); }

			vector_const_iterator operator-(difference_type i) { return vector_const_iterator(_ptr - i); }

			difference_type operator-(vector_const_iterator const& x) const { return _ptr - x._ptr; }

		private:
			pointer _ptr;
	};
}

#endif
