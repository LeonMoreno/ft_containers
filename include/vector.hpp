#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>

namespace fd {

	/**
	 * @brief
	 *
	 * @tparam T: parametro es el tipo de dato to be stored
	 * @tparam Allocator: the type of storage allocator to be used
	 */
	template <typename T, typename Allocator = std::allocator<T> >
	class vector {

	public :
		/* Member Types */

		// Todos estos typedef son requisito de Allocator
		// 	The first template parameter (T)
		// value_type: tipo de elemtos que el container stores (T)
		typedef		T						value_type;

		// The second template parameter (Allocator)
		typedef		Allocator				allocator_type;

		// for the default allocator: value_type&
		typedef		value_type&				reference;

		// 	for the default allocator: const value_type&
		typedef		const value_type&		const_reference;

		// for the default allocator: value_type*
		typedef		value_type*				pointer;

		// for the default allocator: const value_type*
		typedef		const value_type*		const_pointer;

		// a random access iterator to value_type // Le falta asi no es
		typedef		value_type*				iterator;

		// a random access iterator to const value_type // Le falta asi no es
		typedef		const value_type*		const_iterator;

		// an unsigned integral type that can represent any non-negative value
		typedef		size_t					size_type;

		// a signed integral type  identical to:
		// iterator_traits<iterator>::difference_type
		typedef		ptrdiff_t				difference_type;


		/* Member functions */
		//********* Constructor & Destructor *************//

		/**
		 * @brief Creates a %vector with no elements.
		 * @param alloc An allocator object.
		 *
		 */
		// vector()
		// : _arr(allocator_type()), _start(nullptr), _end(nullptr), _end_of_storage(nullptr)
		// 	{ std::cout << "Default constructor\n"; }

		/**
		 * @brief Default constructor - Creates a %vector with no elements.
		 * @param alloc An allocator object.
		 *
		 */
		explicit vector (const allocator_type& alloc = allocator_type())
		: _arr(allocator_type(alloc)), _start(nullptr), _end(nullptr), _end_of_storage(nullptr)
			{ std::cout << "Default constructor\n"; }

		/**
		 * @brief Fill Construct a new vector object
		 *
		 * @param n
		 * @param val
		 * @param alloc An allocator object.
		 */

		explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type())
		: _arr(alloc), _start(nullptr), _end(nullptr), _end_of_storage(0)
			{
				std::cout << "Fill Constructor" << std::endl;

				_start = _arr.allocate(n);
				_end = _start + n + 1;

				for (size_type i = 0; i < n; i++, _start++)
				{
					_start[i] = val;
					std::cout << _start[i] << std::endl;
				}
				std::cout << "end = " << *(_end) << std::endl;
			}

		~vector(){}
	private:
		allocator_type		_arr;
		pointer				_start;
		pointer				_end;
		pointer				_end_of_storage;
	};

}

# endif
