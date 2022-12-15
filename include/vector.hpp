#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "itetator_traits.hpp"
#include "vector_iterator.hpp"

#include <memory>

namespace ft{

	template <typename T, class Alloc = std::allocator<T> >
	class vector {

		/*---------------Member Types------------------------- */
		typedef 			T									value_type;
		typedef 			Alloc							allocator_type;

		typedef typename 	allocator_type::reference			reference;
		typedef typename 	allocator_type::const_reference 	const_reference;

		typedef typename	allocator_type::pointer				pointer;
		typedef const		allocator_type::const_pointer		const_pointer;

		typedef ft::vector_iterator <pointer>			iterator;
		typedef ft::vector_iterator <const_pointer>			const_iterator;













	}




}


#endif
