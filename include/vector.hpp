#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "itetator_traits.hpp"
#include "vector_iterator.hpp"

#include <memory>
#include <iostream>


namespace ft{

	template <typename T, class Alloc = std::allocator<T> >
	class vector {
		public:

			/*---------------Member Types------------------------- */
			typedef 					T										value_type;
			typedef 					Alloc									allocator_type;

			// typename lo exige gcc en linux.
			typedef typename 			allocator_type::reference				reference;
			typedef typename 			allocator_type::const_reference 		const_reference;

			typedef typename			allocator_type::pointer					pointer;
			typedef const typename		allocator_type::const_pointer			const_pointer;

			typedef 					ft::vector_iterator <pointer>			iterator;
			typedef 					ft::vector_iterator <const_pointer>		const_iterator;

			typedef						std::ptrdiff_t							difference_type;
			typedef 					std::size_t								size_type;



			/*--------------- constructor & Destructor ------------------------- */
			// default constructor
			explicit vector (const allocator_type& alloc = allocator_type()) :
			_arr(alloc), _begin(nullptr), _end(nullptr), _capacity(nullptr)
			{std::cout << "default construc\n"; }

			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()) :
			_arr(alloc), _begin(_arr.allocate(n)), _end(_begin),
			_capacity(_begin + n)
			{
				std::cout << "Fill construc\n";
				while (n--)
					_arr.construct(_end++, val);
			}

			~vector() { std::cout << "Destructor\n"; }

		private:
			allocator_type	_arr;
			pointer			_begin;
			pointer			_end;
			pointer			_capacity;


	};




} // namespace ft end


#endif
