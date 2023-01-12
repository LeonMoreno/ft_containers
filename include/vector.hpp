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
			: _arr(alloc), _begin(nullptr), _end(nullptr), _capacity(nullptr)
			{ }

			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()) :
			_arr(alloc), _begin(_arr.allocate(n)), _end(_begin),
			_capacity(_begin + n) {

				// std::cout << "Fill construc\n";
				while (n--)
					_arr.construct(_end++, val);

			// Comprobando que funciono el constructor.
			// for (pointer tmp = _begin; tmp != _end; tmp++)
			// 	std::cout << *tmp << std::endl;
			}

			// range contruc

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename std::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
				: _arr(alloc), _begin(nullptr), _end(nullptr), _capacity(nullptr) {

				// std::cout << "Range construc\n";

				InputIterator tmp = first;
				size_type	size = 0;

				while (tmp != last)
				{
					size++;
					tmp++;
				}
				_begin = _arr.allocate(size);
				_end = _begin;
				_capacity = _begin + size;
				for ( ;first != last; _end++, first++)
					_arr.construct(_end, *first);

				// Comprobando que funciono el constructor.
				// for (tmp = _begin; tmp != _end; tmp++)
				// 	std::cout << *tmp << std::endl;
				// std::cout << "_begin = " << _begin << std::endl;

			}

			// copy constructor
			vector (const vector& src)
			: _arr(src._arr), _begin(nullptr), _end(nullptr), _capacity(nullptr) {

				// std::cout << "Copy construc\n";

				pointer	tmp = src._begin;
				size_type	size = 0;
				while (tmp != src._end)
				{
					size++;
					tmp++;
				}
				_begin = _arr.allocate(size);
				_end = _begin;
				_capacity = _begin + size;
				for (tmp = src._begin; tmp != src._end; tmp++, _end++)
					_arr.construct(_end, *tmp);

				// Comprobando que funciono el constructor.
				// for (tmp = _begin; tmp != _end; tmp++)
				// 	std::cout << *tmp << std::endl;
			}


			~vector(void) {
				// std::cout << "Destructor Vector\n";

				size_type n = 0;
				for (pointer tmp = this->_begin; tmp != this->_end; tmp++, n++)
					this->_arr.destroy(tmp);
				this->_arr.deallocate(this->_begin, n);
				}

//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//

			vector& operator= (const vector& x) {
				if (this->_begin != x.begin())
				{
					this->_arr = x.alloc;
					// assign(x.begin(), x.end()); // PILAS !!!! FALTA AUN
				}
				return (*this);
			}

//-------------------------------Getters and Setters-----------------------------------------------//

			// Get Alloc
			// allocator_type get_allocator(void) const { return _alloc; }  // NO SE


//---------------------------Iterator from vector----------------------------------------//

			iterator begin() { return (iterator(_begin)); }
			iterator end() { return (iterator(_end)); }

			const_iterator begin() const { return (const_iterator(_begin)); }
			const_iterator end() const { return (const_iterator(_end)); }

//---------------------------CAPACITY----------------------------------------//

			size_type size() const {
				size_type siz = 0;

				for (pointer temp = _begin; temp != _end; temp++)
					siz++;
				return (siz);
			}

			size_type max_size() const {
				return (_arr.max_size());
			}

			bool empty() const {
				return (this->size() == 0);
			}

			size_type capacity() const { return (_end - _begin); }

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

				pointer new_end = new_begin;
				for (pointer tmp = _begin; tmp != _end; tmp++, new_end++)
					_arr.construct(new_end, *tmp);

				for (pointer tmp = _begin; tmp != _end; tmp++)
					_arr.destroy(tmp);
				_arr.deallocate(_begin, this->capacity());

				_begin = new_begin;
				_end = new_end;
				_capacity = _begin + new_cap;
				}

//---------------------------ELEMENT ACCESS----------------------------------------//

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

			reference back() { return *(this->_end - 1); }

			const_reference back() const { return *(this->_end - 1); }

			value_type* data() { return (this->_begin); }

			const value_type* data() const { return (this->_begin); }

//---------------------------Modifiers----------------------------------------//




		private:
			allocator_type	_arr;
			pointer			_begin;
			pointer			_end;
			pointer			_capacity;




	};




} // namespace ft end


#endif
