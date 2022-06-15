#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <cstddef>
#include <iterator>
#include <memory>

#include "vector_iterator.hpp"
#include "../utils.hpp"

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T>>
	class vector
	{
		public:
			typedef Allocator allocator_type;
			typedef typename Allocator::value_type value_type;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			typedef typename Allocator::size_type size_type;
			typedef typename Allocator::difference_type difference_type;

			typedef vector_iterator<T> iterator;
			// typedef const_iterator
			// typedef reverse_iterator
			// typedef const_reverse_iterator

			/******************************************************************
			*            CONSTRUCTORS                                         *
			******************************************************************/

			explicit vector(allocator_type const& alloc = allocator_type())
			{
				_allocator = alloc;
				_size = 0;
				_capacity = 0;
				_data = _allocator.allocate(0);
			}

			explicit vector(size_type n, value_type const& val = value_type(),
					allocator_type const& alloc = allocator_type())
			{
				_allocator = alloc;
				_size = n;
				_capacity = n;
				_data = _allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					_allocator.construct(_data + i, val);
			}

			/*template <typename InputIterator>
			vector(InputIterator first, InputIterator last,
					allocator_type const& alloc = allocator_type(),
					typename enable_if< > = )
			{
				_allocator = alloc;
				_size = 0;
				_capacity = 0;
				_data = _allocator.allocate(0);
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}*/

			vector(vector const& copy)
			{
				_allocator = copy._allocator;
				_size = copy._size;
				_capacity = copy._capacity;
				_data = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.constructor(_data + i, *(copy + i));
			}

			/******************************************************************
			*            DESTRUCTOR                                           *
			******************************************************************/

			~vector(void)
			{
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_data + i);
				_allocator.deallocate(_data, _capacity);
			}

			/******************************************************************
			*            OPERATORS OVERLOAD                                   *
			******************************************************************/

			vector& operator=(vector const& copy)
			{
				if (&copy != this)
				{
					for (size_type i = 0; i < _size; i++)
						_allocator.destroy(_data + i);
					if (_capacity < copy._size)
					{
						_allocator.deallocate(_data, _capacity);
						_capacity = copy._size;
						_data = _allocator.allocate(_capacity);
					}
					_size = copy._size;
					for (size_type i = 0; i < _size; i++)
						_allocator.construct(_data + i, *(copy + i));
				}
				return *this;
			}

			/******************************************************************
			*            ITERATORS                                            *
			******************************************************************/

			iterator begin(void) { return iterator(_data); }
			iterator end(void) { return iterator(_data + _size); }

			void resize(size_type n, value_type val = value_type())
			{
				if (n <= _size)
				{
					while (_size > n)
						pop_back();
				}
				else
				{
					while (_size < n)
						push_back(val);
				}
			}

			// THROW EXCEPTION
			// THROW EXCEPTION
			// THROW EXCEPTION
			void reserve(size_type n)
			{
				if (n > _capacity)
				{
					pointer new_data = _allocator.allocate(n);
					for (size_type i = 0; i < _size; i++)
					{
						_allocator.construct(new_data + i, _data[i]);
						_allocator.destroy(_data + i);
					}
					_allocator.deallocate(_data, _capacity);
					_capacity = n;
					_data = new_data;
				}
			}

			void push_back(value_type const& val)
			{
				if (_size == _capacity)
					reserve(_calculate_next_capacity());
				_allocator.construct(_data + _size, val);
				_size++;
			}

			void pop_back(void)
			{
				// undefined behaviour if called on empty vector
				// add a condition if size > 0 ??
				_allocator.destroy(_data + _size - 1);
				_size--;
			}

			void swap(vector& x)
			{
				ft::swap(_allocator, x._allocator);
				ft::swap(_size, x._size);
				ft::swap(_capacity, x._capacity);
				ft::swap(_data, x._data);
			}

			void clear(void)
			{
				while (_size)
					pop_back();
			}

			reference operator[](size_type n) { return *(_data + n); }
			const_reference operator[](size_type n) const { return *(_data + n); }

			reference at(size_type n)
			{
				// throw exception if out of rangeA
				return *(_data + n);
			}

			const_reference at(size_type n) const
			{
				// throw exception if out of range
				return *(_data + n);
			}

			reference front(void) { return *_data; }
			const_reference front(void) const { return *_data; }

			reference back(void) { return *(_data + _size - 1); }
			const_reference back(void) const { return *(_data + _size - 1); }

			/******************************************************************
			*            GETTERS                                              *
			******************************************************************/

			size_type size(void) const { return _size; }

			size_type max_size(void) const { return _allocator.max_size(); }

			size_type capacity(void) const { return _capacity; }

			bool empty(void) const
			{
				if (_size)
					return false;
				return true;
			}

			allocator_type get_allocator(void) const { return _allocator; }

		private:
			pointer _data;
			allocator_type _allocator;
			size_type _size;
			size_type _capacity;

			size_type _calculate_next_capacity(void) const
			{
				if (!_capacity)
					return 1;
				return _capacity * 2;
			}
	};
}

#endif
