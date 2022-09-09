#ifndef __MAP_ITERATOR_HPP__
#define __MAP_ITERATOR_HPP__

namespace ft
{
	template <typename T>
	class map_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			typedef std::ptrdiff_t difference_type;

		private:
			pointer _root;
			pointer _node;
	};
}

#endif
