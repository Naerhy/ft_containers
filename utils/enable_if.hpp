#ifndef __ENABLE_IF_HPP__
#define __ENABLE_IF_HPP__

namespace ft
{
	template <bool condition, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> { typedef T type; };
}

#endif
