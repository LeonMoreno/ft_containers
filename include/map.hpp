#ifndef MAP_HPP
# define MAP_HPP

#include <functional>


namespace ft
{
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> >
	> //class map;
	class map
	{
		public:

		/* member types -- Definitions */
		typedef Key								key_type;
		typedef T								mapped_type;
		typedef std::pair<const Key, T>			value_type;
		typedef std::size_t						size_type;
		typedef std::ptrdiff_t					difference_type;
		typedef Compare							key_compare;
		typedef Allocator						allocator_type;
		typedef value_type&						reference;
		typedef const value_type&				const reference;
		typedef Allocator::pointer				pointer;
		typedef Allocator::const_pointer		const_pointer;
		typedef bidirectional_iterator<pointer> iterator;
		typedef 								const_iterator;
		typedef									reverse_iterator;
		typedef									const_reverse_iterator;


	private:
		/* data */
	public:
		map(/* args */);
		~map();
	};


} // namespace ft




#endif
