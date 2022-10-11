#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <cstddef>
#include "../vector/vector.hpp"

namespace ft
{
	template <typename T, typename Container = vector<T> >
	class stack
	{

		/****************************
		*     PUBLIC PROPERTIES     *
		****************************/

		public:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;

			/***************************
			*     MEMBER FUNCTIONS     *
			***************************/

			explicit stack(container_type const& c = container_type()) : c(c) {}

			~stack(void) {}

			stack& operator=(stack const& assign)
			{
				if (this != &assign)
					c = assign.c;
				return *this;
			}

			bool empty(void) const { return c.empty(); }

			size_type size(void) const { return c.size(); }

			value_type& top(void) { return c.back(); }

			value_type const& top(void) const { return c.back(); }

			void push(value_type const& val) { c.push_back(val); }

			void pop(void) { c.pop_back(); }

			/****************************************
			*     NON-MEMBER FUNCTION OVERLOADS     *
			****************************************/

			friend bool operator==(stack const& lhs, stack const& rhs)
			{
				return (lhs.c == rhs.c);
			}

			friend bool operator!=(stack const& lhs, stack const& rhs)
			{
				return (lhs.c != rhs.c);
			}

			friend bool operator<(stack const& lhs, stack const& rhs)
			{
				return (lhs.c < rhs.c);
			}

			friend bool operator<=(stack const& lhs, stack const& rhs)
			{
				return (lhs.c <= rhs.c);
			}

			friend bool operator>(stack const& lhs, stack const& rhs)
			{
				return (lhs.c > rhs.c);
			}

			friend bool operator>=(stack const& lhs, stack const& rhs)
			{
				return (lhs.c >= rhs.c);
			}

		/***************************
		*     PROTECTED MEMBER     *
		***************************/

		protected:
			container_type c;
	};
}

#endif
