#ifndef __MAKE_PAIR_HPP__
#define __MAKE_PAIR_HPP__

namespace ft
{
	template <typename T1, typename T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return pair<T1, T2>(x, y);
	}
}

#endif
