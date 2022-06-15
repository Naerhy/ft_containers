#ifndef __UTILS_HPP__
#define __UTILS_HPP__

namespace ft
{
	template <typename T>
	void swap(T& a, T& b)
	{
		T temp(a);
		a = b;
		b = temp;
	}

	template <bool Condition, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> { typedef T type; };
}
#endif
