#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "vector_iterator.hpp" //
#include "utils.hpp" //

#include <memory> //
#include <iostream> //


namespace ft{

	template <typename T, class Alloc = std::allocator<T> >
	class vector {
		public:

//---------------------------Member Types---------------------------------------//
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

//---------------------------constructor & Destructor---------------------------------------//
			// default constructor
			explicit vector (const allocator_type& alloc = allocator_type())
			: _arr(alloc), _begin(nullptr), _size(0), _capacity(0)
			{ }

			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()) :
			_arr(alloc), _begin(_arr.allocate(n)), _size(n),
			_capacity(n) {

				// std::cout << "Fill construc\n";
				for (size_type i = 0; i < n; i++)
					_arr.construct(&(_begin[i]), val);

				// Comprobando que funciono el constructor.
				// for (size_type i = 0; i < _size; i++)
				// 	std::cout << _begin[i] << std::endl;
			}

			// range contruc
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename std::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
				: _arr(alloc), _begin(nullptr), _size(0), _capacity(0) {

				// std::cout << "Range construc\n";

				InputIterator	tmp = first;
				size_type		size = 0;

				while (tmp != last)
				{
					size++;
					tmp++;
				}
				_begin = _arr.allocate(size);
				_size = size;
				_capacity = size;
				for (size_type i = 0; i < size; i++)
					_arr.construct(&(_begin[i]), first[i]);

				// // Comprobando que funciono el constructor.
				// for (size_type i = 0; i < size; i++)
				// 	std::cout << _begin[i] << std::endl;
				// std::cout << "_begin = " << _begin << std::endl;

			}

			// // copy constructor
			vector (const vector& src)
			: _arr(src._arr), _begin(nullptr), _size(src._size), _capacity(src._capacity) {

				// std::cout << "Copy construc\n";

				_begin = _arr.allocate(src._size);
				for (size_type i = 0; i < _size; i++)
					_arr.construct(&(_begin[i]), src._begin[i]);

				// Comprobando que funciono el constructor.
				// for (size_type i = 0; i < _size; i++)
				// 	std::cout << _begin[i] << std::endl;
			}


			~vector(void) {
				// std::cout << "Destructor Vector\n";

				for (size_type i = 0; i < _size; i++)
					this->_arr.destroy(&(_begin[i]));
				this->_arr.deallocate(this->_begin, _size);
				}

//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//

			vector& operator= (const vector& rhs) {
				if (this->_begin != rhs._begin)
				{
					this->_arr = rhs.alloc;
					// assign(x.begin(), x.end()); // PILAS !!!! FALTA AUN
				}
				return (*this);
			}

// //-------------------------------Getters and Setters-----------------------------------------------//

// 			// Get Alloc
			allocator_type get_allocator(void) const { return this->_arr; }


// //---------------------------Iterator from vector----------------------------------------//

			iterator begin() { return (iterator(_begin)); }
			iterator end() { return (iterator(_begin + this->_size)); }

			const_iterator begin() const { return (const_iterator(_begin)); }
			const_iterator end() const { return (const_iterator(_begin + this->_size)); }

// //---------------------------CAPACITY----------------------------------------//

			size_type size() const { return (this->_size); }

			size_type max_size() const { return (_arr.max_size()); }

			bool empty() const { return (this->size() == 0); }

			size_type capacity() const { return (_capacity); }

			void reserve (size_type new_cap) {

				pointer new_begin = nullptr;

				if (new_cap > _arr.max_size())
					throw std::length_error("Reserve: new_cap too big");
				else if (new_cap < this->capacity())
					return;
				try {
					new_begin = _arr.allocate(new_cap);
				}
				catch (std::bad_alloc &e) {
					throw e;
				}

				for (size_type i = 0; i < this->_size; i++)
					_arr.construct(&(new_begin[i]), _begin[i]);

				for (size_type i = 0; i < this->_size; i++)
					_arr.destroy(&(_begin[i]));
				_arr.deallocate(_begin, this->_capacity);

				_begin = new_begin;
				_capacity = new_cap;
				}

// //---------------------------ELEMENT ACCESS----------------------------------------//

			reference operator[] (size_type n) { return *(this->_begin + n); }

			const_reference operator[] (size_type n) const { return *(this->_begin + n); }

			reference at (size_type n) {

				if (n >= this->size())
					throw std::out_of_range("out of range");
				return *(this->_begin + n);
			}

			const_reference at (size_type n) const {

				if (n >= this->size())
					throw std::out_of_range("out of range");
				return *(this->_begin + n);
			}


			reference front() { return *(this->_begin); }

			const_reference front() const { return *(this->_begin); }

// 			reference back() { return *(this->_end - 1); }

// 			const_reference back() const { return *(this->_end - 1); }

// 			value_type* data() { return (this->_begin); }

// 			const value_type* data() const { return (this->_begin); }

// //---------------------------Modifiers----------------------------------------//

// 			/**
// 			 * @brief assing range version
// 			 *
// 			 * @tparam InputIterator
// 			 * @param first
// 			 * @param last
// 			 */
// 			template <class InputIterator>
// 			void assign (InputIterator first, InputIterator last,
// 			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {

// 				size_type		new_size = 0;
// 				InputIterator	tmp = first;

// 				for (pointer tmp = this->_begin; tmp != this->_end; tmp++)
// 					this->_arr.destroy(tmp);
// 				while (tmp++ != last)
// 					new_size++;
// 				std::cout << "Nex size = " << new_size << std::endl;
// 				if (new_size > this->capacity())
// 					_ft_realloc(new_size);
// 				for (pointer tmp = _begin; tmp != _end; tmp++)
// 					_arr.construct(tmp, *first++);
// 				if (new_size < this->size())
// 				{
// 					size_t new_end = this->size();
// 					for (size_t i = new_size; i < new_end; i++, _end--)
// 						std::cout << "valor = " << *_end << std::endl;
// 						this->_arr.destroy(_end);
// 				}
// 			}

// 			void assign (size_type n, const value_type& val) {

// 				for (pointer tmp = this->_begin; tmp != this->_end; tmp++)
// 					this->_arr.destroy(tmp);
// 				if (this->size() < n)
// 					_ft_realloc(n);
// 				pointer new_end = _begin;

// 				for (size_type i = 0; i < n; i++, new_end++)
// 					_arr.construct(new_end, val);
// 				_end = new_end;
// 			}

// 			void push_back (const value_type& val) {

// 				size_t temp = this->size();

// 				if (!this->capacity())
// 					_ft_realloc(1);
// 				if (this->size() == this->capacity())
// 					reserve(this->capacity() * 2);
// 				_arr.construct(_begin + temp, val);
// 				_end = _begin + temp + 1;
// 			}


		private:
			allocator_type	_arr;
			pointer			_begin;
			size_type		_size;
			size_type		_capacity;

			// void	_ft_realloc(size_type new_cap, value_type val = value_type()) {

			// 	pointer new_begin = _arr.allocate(new_cap);
			// 	pointer new_end = new_begin;
			// 	for (pointer tmp = _begin; tmp != _end; tmp++, new_end++)
			// 		_arr.construct(new_end, *tmp);
			// 	for (size_type i = this->size(); i < new_cap; i++, new_end++)
			// 		_arr.construct(new_end, val);
			// 	for (pointer tmp = _begin; tmp != _end; tmp++)
			// 		_arr.destroy(tmp);
			// 	this->_arr.deallocate(this->_begin, this->capacity());
			// 	this->_begin = new_begin;
			// 	this->_end = new_end;
			// 	this->_capacity = _begin + new_cap;
			// }


	};




} // namespace ft end


#endif
