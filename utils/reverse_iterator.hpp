#ifndef __REVERSE_ITERATOR_HPP__
#define __REVERSE_ITERATOR_HPP__

#include "iterator_traits.hpp"

namespace ft
{
	template <typename Iter>
	class reverse_iterator
	{
		public:
			typedef Iter iterator_type;
			typedef typename iterator_traits<Iter>::iterator_category iterator_category;
			typedef typename iterator_traits<Iter>::value_type value_type;
			typedef typename iterator_traits<Iter>::difference_type difference_type;
			typedef typename iterator_traits<Iter>::pointer pointer;
			typedef typename iterator_traits<Iter>::reference reference;

			reverse_iterator(void) : _base(iterator_type()) {}

			explicit reverse_iterator(iterator_type it) : _base(it) {}

			template <typename U>
			reverse_iterator(reverse_iterator<U> const& rev_it) : _base(rev_it.base()) {}

			template <typename U>
			reverse_iterator& operator=(reverse_iterator<U> const& assign)
			{
				if (this != assign)
					_base = assign._base;
				return *this;

			}

			iterator_type base(void) const { return _base; }

			reference operator*(void) const
			{
				Iter temp = _base;
				return *--temp;
			}

			pointer operator->(void) const { return &(operator*()); }

			reference operator[](difference_type n) const { return *(_base - 1 - n); }

			reverse_iterator& operator++(void)
			{
				_base--;
				return *this;
			}

			reverse_iterator& operator--(void)
			{
				_base++;
				return *this;
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator temp = *this;
				++(*this);
				return temp;
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator temp = *this;
				--(*this);
				return temp;
			}

			reverse_iterator operator+(difference_type n) const
			{
				return reverse_iterator(base() - n);
			}

			reverse_iterator operator-(difference_type n) const
			{
				return reverse_iterator(base() + n);
			}

			reverse_iterator& operator+=(difference_type n)
			{
				_base -= n;
				return *this;
			}

			reverse_iterator& operator-=(difference_type n)
			{
				_base += n;
				return *this;
			}

		private:
			iterator_type _base;
	};

	template <typename Iter>
	reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n,
			reverse_iterator<Iter> const& it)
	{
		return reverse_iterator<Iter>(it.base() - n);
	}

	template <typename Iter>
	typename reverse_iterator<Iter>::difference_type operator-(reverse_iterator<Iter> const& lhs,
			reverse_iterator<Iter> const& rhs)
	{
		return rhs.base() - lhs.base();;
	}

	template <typename Iter>
	bool operator==(reverse_iterator<Iter> const& lhs, reverse_iterator<Iter> const& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <typename Iter>
	bool operator!=(reverse_iterator<Iter> const& lhs, reverse_iterator<Iter> const& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename Iter>
	bool operator<(reverse_iterator<Iter> const& lhs, reverse_iterator<Iter> const& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <typename Iter>
	bool operator<=(reverse_iterator<Iter> const& lhs, reverse_iterator<Iter> const& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <typename Iter>
	bool operator>(reverse_iterator<Iter> const& lhs, reverse_iterator<Iter> const& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <typename Iter>
	bool operator>=(reverse_iterator<Iter> const& lhs, reverse_iterator<Iter> const& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
}

#endif
