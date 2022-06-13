#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <cstddef>
#include <iterator>
#include <memory>

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T>>
	class Vector
	{
		public:
			typedef Allocator allocator_type;
			typedef typename Allocator::value_type value_type;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef Iterator iterator;
			// typedef const_iterator
			// typedef reverse_iterator
			// typedef const_reverse_iterator
			typedef typename Allocator::size_type size_type;
			typedef typename Allocator::difference_type difference_type;

			class Iterator
			{
				public:
					typedef std::random_access_iterator_tag iterator_category;
					typedef T value_type;
					typedef T& reference;
					typedef T* pointer;
					typedef std::ptrdiff_t difference_type;

					// constructor, destructor and co':
					Iterator(pointer ptr) : _ptr(ptr) {}
					~Iterator() {}
					// operators:
					reference operator*() const { return *_ptr; }
					pointer operator->() const { return _ptr; }
					Iterator& operator++()
					{
						_ptr++;
						return *this;
					}
					Iterator operator++(int)
					{
						Iterator temp = *this;
						++(*this);
						return temp;
					}
					Iterator& operator--()
					{
						_ptr--;
						return *this;
					}
					Iterator operator--(int)
					{
						Iterator temp = *this;
						--(*this);
						return temp;
					}

				private:
					pointer _ptr;
			};

			// class ConstIterator
			// {
			// };

			Vector(allocator_type const& alloc = allocator_type())
			{
				_allocator = alloc;
				_data = _allocator.allocate(0);
				_size = 0;
				_capacity = 0;
			}

			~Vector(void)
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_data + i);
				_allocator.deallocate(_data, _capacity);
			}

			iterator begin() { return iterator(_data); }
			iterator end() { return iterator(_data + _size); }

			size_type size(void) const { return _size; }

			size_type max_size(void) const { return _allocator.max_size(); }

			size_type capacity(void) const { return _capacity; }

		private:
			pointer _data;
			allocator_type _allocator;
			size_type _size;
			size_type _capacity;
	};
}

#endif
