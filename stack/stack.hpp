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

			explicit stack(container_type const& ctnr = container_type()) : _ctnr(ctnr) {}

			~stack(void) {}

			stack& operator=(stack const& assign)
			{
				if (this != &assign)
					_ctnr = assign._ctnr;
				return *this;
			}

			bool empty(void) const { return _ctnr.empty(); }

			size_type size(void) const { return _ctnr.size(); }

			value_type& top(void) { return _ctnr.back(); }

			value_type const& top(void) const { return _ctnr.back(); }

			void push(value_type const& val) { _ctnr.push_back(val); }

			void pop(void) { _ctnr.pop_back(); }

			/****************************************
			*     NON-MEMBER FUNCTION OVERLOADS     *
			****************************************/

			friend bool operator==(stack const& lhs, stack const& rhs)
			{
				return (lhs._ctnr == rhs._ctnr);
			}

			friend bool operator!=(stack const& lhs, stack const& rhs)
			{
				return (lhs._ctnr != rhs._ctnr);
			}

			friend bool operator<(stack const& lhs, stack const& rhs)
			{
				return (lhs._ctnr < rhs._ctnr);
			}

			friend bool operator<=(stack const& lhs, stack const& rhs)
			{
				return (lhs._ctnr <= rhs._ctnr);
			}

			friend bool operator>(stack const& lhs, stack const& rhs)
			{
				return (lhs._ctnr > rhs._ctnr);
			}

			friend bool operator>=(stack const& lhs, stack const& rhs)
			{
				return (lhs._ctnr >= rhs._ctnr);
			}

		/***************************
		*     PROTECTED MEMBER     *
		***************************/

		protected:
			container_type _ctnr;
	};
}

#endif
