#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include <cstddef>

namespace ft {

	/**
	 * @brief
	 *
	 * @tparam T: parametro es el tipo de dato to be stored
	 * @tparam Allocator: the type of storage allocator to be used
	 */
	template <typename T, typename Allocator = std::allocator<T> >
	class vector {

	public :
		/* varios --- falta aclaracion */

		// The next Member types de std::allocator
		// 	The first template parameter (T)
		// value_type: tipo de elemtos que el container stores (T)
		typedef T											value_type;

		// The second template parameter (Allocator)
		typedef Allocator									allocator_type;

		// typename lo exige gcc en linux.
		// for the default allocator: value_type&
		typedef typename allocator_type::reference			reference;

		// 	for the default allocator: const value_type&
		typedef typename allocator_type::const_reference	const_reference;

		// for the default allocator: value_type*
		typedef typename  allocator_type::pointer			pointer;

		// for the default allocator: const value_type*
		typedef typename allocator_type::const_pointer		const_pointer;

		// a random access iterator to value_type // Le falta asi no es
		typedef value_type*									iterator;

		// a random access iterator to const value_type // Le falta asi no es
		typedef const value_type*							const_iterator;

		// an unsigned integral type that can represent any non-negative value
		typedef size_t										size_type;

		// a signed integral type  identical to:
		// iterator_traits<iterator>::difference_type
		typedef ptrdiff_t									difference_type;


		/* Member functions */
		//********* Constructor & Destructor *************//

		/**
		 * @brief Default constructor - Creates a %vector with no elements.
		 * @param alloc An allocator object.
		 */
		explicit vector (const allocator_type& alloc = allocator_type())
		: _arr(allocator_type(alloc)), _start(0), _end(0), _end_cap(0)
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
		: _arr(alloc), _start(0), _end(0), _end_cap(0)
			{
				std::cout << "Fill Constructor" << std::endl;

				_start = _arr.allocate(n);
				_end_cap = _start + n;
				_end = _start;

				for (size_type i = 0; i < n; i++, _end++)
					_arr.construct(_end, val);
					// _start[i] = val;
				std::cout << "end = " << *(_end - 1) << std::endl;
			}

		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())


		~vector(){}

		//********* Iterators *************//
		iterator begin() { return (_start); }
		const_iterator begin() const { return (_start); }
		// reverse_iterator rbegin() { return (_end - 1); }

		iterator end() { return (_end); }

		//********* Capacity *************//
		/**
		 * @brief Returns the number of elements in the vector.
		 */
		size_type size() const {
			pointer begin = _start;
			pointer end = _end;
			size_type	count = 0;

			for ( ; begin != end; begin++)
				count++;
			return count;
		}

		/**
		 * @brief Returns the maximum number of elements that the vector can hold.
		 */
		size_type max_size() const { return _arr.max_size(); }

		/**
		 * @brief Resizes the container so that it contains n elements.
		 *
		 * @param n New container size, expressed in number of elements.
		 * @param val
		 */
		void resize (size_type n, value_type val = value_type()) {
			(void) val;
			if (n < this->size()) {
				std::cout << "n es menor\n";
				erase_end(_start + n);
				std::cout << "end in resize() = " << *(_end) << std::endl;
			}
			else
			{
				std::cout << "n es mayor\n";
				size_type temp = _end - _end_cap;
				std::cout << "temp = " << temp << std::endl;
				// this->insert(this->end(), n - this->size(), val);
			}

		}
		void	erase_end(pointer new_end) {
			while (_end != new_end)
			{
				std::cout << "entre\n";
				_end--;
				this->_arr.destroy(_end);
			}
		}
		/**
		 * @brief Returns the size of the storage space currently allocated for the vector.
		 *		 This capacity is not necessarily equal to the vector size.
		 *
		 * @return size_type capacity
		 */
		size_type capacity() const {
			return (_end - _start);
		}

		bool empty() const {
			if (this->size() > 0)
				return (false);
			return (true);
		}

	private:
		allocator_type		_arr;
		pointer				_start;
		pointer				_end;
		pointer				_end_cap;
	};



} // end ::ft

# endif
