#ifndef __MAP_HPP__
#define __MAP_HPP__

namespace ft
{
	template <typename Key, typename T, typename Compare = less<Key>,
			typename Allocator = allocator<pair<Key const, T> > >
	class map
	{
		/****************************
		*     PUBLIC PROPERTIES     *
		****************************/

		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef pair<key_type const, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Allocator allocator_type;
			typedef typename Allocator::reference reference;
			typedef typename Allocator::const_reference const_reference;
			typedef typename Allocator::pointer pointer;
			typedef typename Allocator::const_pointer const_pointer;
			// typedef iterator
			// typedef const_iterator
			// typedef reverse_iterator
			// typedef const_reverse_iterator
			typedef typename Allocator::size_type size_type;
			typedef typename Allocator::difference_type difference_type;

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				public:
					bool operator()(value_type const& lhs, value_tye const& rhs) const
					{
						return comp(lhs.first, rhs.first);
					}

				protected:
					Compare comp;
					value_compare(Compare C) : comp(c) {}
			};

			/********************
			*     ALLOCATOR     *
			********************/

			allocator_type get_allocator(void) const { return _allocator; }

		/**************************
		*     PRIVATE MEMBERS     *
		**************************/

		private:
			allocator_type _allocator;
	};
}

#endif
