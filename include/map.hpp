#ifndef MAP_HPP
# define MAP_HPP

#include <functional>


namespace ft
{
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<std::pair<const Key, T> >
	> //class map;
	class map
	{
		public:

		/* member types -- Definitions */
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef std::pair<const Key, T>						value_type;
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


	private:
		/* data */
	public:
		map(/* args */) { std::cout << "def constructor" << std::endl; }
		~map() { std::cout << " destructor " << std::endl; }
	};

} // namespace ft




#endif
