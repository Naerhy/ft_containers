#ifndef __VECTOR_CONST_ITERATOR_HPP__
#define __VECTOR_CONST_ITERATOR_HPP__

#include <iterator>
#include <cstddef>

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

			vector_const_iterator(void) : _ptr(NULL) {}
			explicit vector_const_iterator(pointer ptr) : _ptr(ptr) {}
			vector_const_iterator(vector_const_iterator const& copy) : _ptr(copy._ptr) {}
			virtual ~vector_const_iterator(void) {}

			vector_const_iterator& operator=(vector_const_iterator const& assign)
			{
				if (this != &assign)
					_ptr = assign._ptr;
				return *this;
			}

			reference operator*(void) const { return *_ptr; }
			pointer operator->(void) const { return _ptr; }
			reference operator[](difference_type n) const { return *(_ptr + n); }

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

			vector_const_iterator operator+(difference_type i) const
			{
				return vector_const_iterator(_ptr + i);
			}

			friend vector_const_iterator operator+(difference_type i,
					vector_const_iterator const& x)
			{
				return vector_const_iterator(x + i);
			}

			vector_const_iterator operator-(difference_type i) const
			{
				return vector_const_iterator(_ptr - i);
			}

			difference_type operator-(vector_const_iterator const& x) const
			{
				return _ptr - x._ptr;
			}

		private:
			pointer _ptr;
	};
}

#endif
