#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>

namespace fd {
/**
 * @brief
 *	El 1er parametro es el tipo de dato to be stored
 *	the second is the type of storage allocator to be used
	*/
	template <typename T, typename Allocator = std::allocator<T> >
	class vector {

	public :
		/* Member Types */

		// Todos estos typedef son requisito de Allocator
		// 	The first template parameter (T)
		// value_type: tipo de elemtos que el container stores (T)
		typedef		T						value_type;

		// The second template parameter (Alloc)
		typedef		Allocator				allocator_type;

		// for the default allocator: value_type&
		typedef		value_type&				reference;

		// 	for the default allocator: const value_type&
		typedef		const value_type&		const_reference;

		// for the default allocator: value_type*
		typedef		value_type*				pointer;

		// for the default allocator: const value_type*
		typedef		const value_type*		const_pointer;

		// a random access iterator to value_type
		typedef		pointer					iterator;

		// a random access iterator to const value_type
		typedef		const_pointer			const_iterator;


		/* Member functions */

		//********* Constructor & Destructor *************//
		vector<T, Allocator>(){}
		// vector<T, Allocator>(int n, T arg){
		// 	std::allocator<T>	myalloc;
		// 	pointer				ptr = myalloc.allocate(n);

		// 	ptr = myalloc.allocate(n);
		// 	for (int i = 0; i < n; i++)
		// 		ptr[i] = arg;

		// }

		explicit vector(size_t n, const T& value = value_type(),
			const allocator_type& alloc = allocator_type())
			:	_arr(alloc),
				_start(nullptr),
				_end(nullptr),
				_end_capacity(nullptr)
			{
				_start	= _arr.allocate(n);
				_end_capacity = _start + n;
				while (n--)
				{
					_arr.construct(_end, value);
				std::cout << "INiT Constructor" << std::endl;
					_end++;
				}
				std::cout << std::endl;
			}

		// Vector(T arr) : value_type(arr) {

		// }

		~vector(){}
	private:
		allocator_type		_arr;
		pointer				_start;
		pointer				_end;
		pointer				_end_capacity;
	};

}

# endif
