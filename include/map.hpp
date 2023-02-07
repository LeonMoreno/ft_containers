#ifndef MAP_HPP
# define MAP_HPP

#include <functional>


namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> >
	> //class map;
	class map
	{
		public:

		/* member types -- Definitions */

		/*  Each element in a map is uniquely identified by its key value.
		 Each element in a map is uniquely identified by its key value. */
		typedef Key											key_type;

		/* Each element in a map stores some data as its mapped value.
		 Aliased as member type map::mapped_type.*/
		typedef T											mapped_type;

		typedef ft::pair<const Key, T>						value_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef Compare										key_compare;
		typedef Alloc										allocator_type;

		typedef value_type&									reference;
		typedef const value_type&							const_reference;

		typedef typename Alloc::pointer						pointer;
		typedef typename Alloc::const_pointer				const_pointer;

		// typedef std::bidirectional_iterator_tag<value_type>		iterator;
		// typedef const std::bidirectional_iterator_tag	<const value_type>	const_iterator;

		// typedef	reverse_vector_iterator <iterator>				reverse_iterator;
		// typedef	reverse_vector_iterator <const_iterator>		const_reverse_iterator;

		// map(/* args */) { std::cout << "def constructor" << std::endl; }
		// explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {

		// }

		explicit map (	const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()):
			_size(0),
			_compare(comp),
			_node(alloc) {}



		~map() { std::cout << " destructor " << std::endl; }

		private:

			size_type				_size;
			key_compare				_compare;
			allocator_type			_node;

	};

} // namespace ft




#endif
