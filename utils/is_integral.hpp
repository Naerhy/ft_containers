#ifndef __IS_INTEGRAL_HPP__
#define __IS_INTEGRAL_HPP__

namespace ft
{
	template <typename T>
	struct is_integral
	{
		static bool const value = false;
	};

	template <>
	struct is_integral<bool>
	{
		static bool const value = true;
	};

	template <>
	struct is_integral<char>
	{
		static bool const value = true;
	};

	template <>
	struct is_integral<signed char>
	{
		static bool const value = true;
	};

	template <>
	struct is_integral<short int>
	{
		static bool const value = true;
	};

	template <>
	struct is_integral<int>
	{
		static bool const value = true;
	};

	template <>
	struct is_integral<long int>
	{
		static bool const value = true;
	};

	template <>
	struct is_integral<long long int>
	{
		static bool const value = true;
	};

	template <>
	struct is_integral<unsigned char>
	{
		static bool const value = true;
	};

	template <>
	struct is_integral<unsigned short int>
	{
		static bool const value = true;
	};

	template <>
	struct is_integral<unsigned int>
	{
		static bool const value = true;
	};

	template <>
	struct is_integral<unsigned long int>
	{
		static bool const value = true;
	};

	template <>
	struct is_integral<unsigned long long int>
	{
		static bool const value = true;
	};
}

#endif
