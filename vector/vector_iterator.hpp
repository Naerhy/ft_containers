#ifndef __VECTOR_ITERATOR_HPP__
#define __VECTOR_ITERATOR_HPP__

#include <iterator>
#include <cstddef>
#include "vector_const_iterator.hpp"

namespace ft
{
	template <typename T>
	class vector_iterator
	{
		public:
			typedef std::random_access_iterator_tag iterator_category;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef std::ptrdiff_t difference_type;

			vector_iterator(void) : _ptr(NULL) {}
			explicit vector_iterator(pointer ptr) : _ptr(ptr) {}
			vector_iterator(vector_iterator const& copy) : _ptr(copy._ptr) {}
			virtual ~vector_iterator(void) {}

			vector_iterator& operator=(vector_iterator const& assign)
			{
				if (this != &assign)
					_ptr = assign._ptr;
				return *this;
			}

			operator vector_const_iterator<T>(void) const
			{
				return vector_const_iterator<T>(_ptr);
			}

			reference operator*(void) { return *_ptr; }
			pointer operator->(void) { return _ptr; }
			reference operator[](difference_type n) { return *(_ptr + n); }

			bool operator==(vector_iterator const& x) const { return _ptr == x._ptr; }
			bool operator!=(vector_iterator const& x) const { return _ptr != x._ptr; }
			bool operator<(vector_iterator const& x) const { return _ptr < x._ptr; }
			bool operator>(vector_iterator const& x) const { return _ptr > x._ptr; }
			bool operator<=(vector_iterator const& x) const { return _ptr <= x._ptr; }
			bool operator>=(vector_iterator const& x) const { return _ptr >= x._ptr; }

			vector_iterator& operator++(void)
			{
				_ptr++;
				return *this;
			}

			vector_iterator operator++(int)
			{
				vector_iterator temp(*this);
				++(*this);
				return temp;
			}

			vector_iterator& operator--(void)
			{
				_ptr--;
				return *this;
			}

			vector_iterator operator--(int)
			{
				vector_iterator temp(*this);
				--(*this);
				return temp;
			}

			vector_iterator& operator+=(difference_type i)
			{
				_ptr += i;
				return *this;
			}

			vector_iterator& operator-=(difference_type i)
			{
				_ptr -= i;
				return *this;
			}

			vector_iterator operator+(difference_type i) const
			{
				return vector_iterator(_ptr + i);
			}

			friend vector_iterator operator+(difference_type i,
					vector_iterator const& x)
			{
				return vector_iterator(x + i);
			}

			vector_iterator operator-(difference_type i) const
			{
				return vector_iterator(_ptr - i);
			}

			difference_type operator-(vector_iterator const& x) const
			{
				return _ptr - x._ptr;
			}

		private:
			pointer _ptr;
	};
}

#endif
