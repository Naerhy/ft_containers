#ifndef __ITERATOR_TRAITS__
#define __ITERATOR_TRAITS__

namespace ft
{
	template <typename T>
	struct iterator_traits
	{
		typedef typename T::value_type value_type;
		typedef typename T::difference_type difference_type;
		typedef typename T::iterator_category iterator_category;
		typedef typename T::pointer pointer;
		typedef typename T::reference reference;
	};
}

#endif
