#ifndef __PAIR_HPP__
#define __PAIR_HPP__

namespace ft
{
	template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		pair(void) : first(), second() {}

		template <typename U, typename V>
		pair(pair<U, V> const& pr) : first(pr.first), second(pr.second) {}

		pair(first_type const& a, second_type const& b) : first(a), second(b) {}

		pair& operator=(pair const& assign)
		{
			if (this != &assign)
			{
				first = assign.first;
				second = assign.second;
			}
			return *this;
		}

		T1 first;
		T2 second;
	};

	template <typename T1, typename T2>
	bool operator==(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <typename T1, typename T2>
	bool operator!=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T1, typename T2>
	bool operator<(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <typename T1, typename T2>
	bool operator<=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return !(rhs < lhs);
	}

	template <typename T1, typename T2>
	bool operator>(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return (rhs < lhs);
	}

	template <typename T1, typename T2>
	bool operator>=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs)
	{
		return !(lhs < rhs);
	}

}

#endif
