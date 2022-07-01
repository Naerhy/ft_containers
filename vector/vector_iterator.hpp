#ifndef __VECTOR_ITERATOR_HPP
#define __VECTOR_ITERATOR_HPP

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

			/******************************************************************************
			*            CONSTRUCTORS                                                     *
			******************************************************************************/

			vector_iterator(pointer ptr) : _ptr(ptr) {}
			vector_iterator(vector_iterator const& copy) : _ptr(copy._ptr); {}
			~vector_iterator(void) {}

			/**********************************************************
			*            OPERATORS OVERLOAD                           *
			**********************************************************/

			vector_iterator& operator=(vector_iterator const& assign)
			{
				if (this != &assign)
					_ptr = assign._ptr;
				return *this;
			}

			reference operator*(void) const { return *_ptr; }
			pointer operator->(void) const { return _ptr; }

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

			vector_iterator operator+(difference_type i) { return vector_iterator(_ptr + i); }

			vector_iterator operator-(difference_type i) { return vector_iterator(_ptr - i); }

			difference_type operator-(vector_iterator const& x) const { return _ptr - x._ptr; }

		private:
			pointer _ptr;
	};
}

#endif
