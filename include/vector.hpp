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
			: _arr(alloc), _begin(nullptr), _size(0), _cap(0)
			{ }

			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()) :
			_arr(alloc), _begin(_arr.allocate(n)), _size(n), _cap(n) {

				for (size_type i = 0; i < n; i++)
					_arr.construct(&(_begin[i]), val);
			}

			// range contruc
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename std::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
				: _arr(alloc), _begin(nullptr), _size(0), _cap(0) {

				InputIterator tmp = first;

				while (tmp != last)
				{
					_size++;
					tmp++;
				}
				_begin = _arr.allocate(_size);

				for (size_type i = 0; i < _size; i++)
					_arr.construct(&(_begin[i]), first[i]);
				_cap = _size;
			}

			// copy constructor
			vector (const vector& src)
			: _arr(src._arr), _begin(nullptr), _size(src._size), _cap(src._cap) {

				_begin = _arr.allocate(_size);

				for (size_type i = 0; i < _size; i++)
					_arr.construct(&(_begin[i]), src._begin[i]);
			}


			~vector(void) {

				for(size_type i = 0; i < _size; i++)
					_arr.destroy(&(_begin[i]));

				this->_arr.deallocate(_begin, _size);
			}

//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//

			vector& operator= (const vector& rhs) {
				if (_begin != rhs.begin())
				{
					_arr = rhs._arr;
					// assign(x.begin(), x.end()); // PILAS !!!! FALTA AUN
				}
				return (*this);
			}

//-------------------------------Getters and Setters-----------------------------------------------//

			// Get Alloc
			allocator_type get_arrator(void) const { return _arr; }  // NO SE

			size_type sileo() const { return (_size); }

			size_type capleo() const { return (_cap); }


//---------------------------Iterator from vector----------------------------------------//

			iterator begin() { return (iterator(_begin)); }
			iterator end() { return (iterator(_begin + _size)); }

			const_iterator begin() const { return (const_iterator(_begin)); }
			const_iterator end() const { return (const_iterator(_begin + _size)); }

//---------------------------CAPACITY----------------------------------------//

			size_type size() const { return (_size); }

			size_type max_size() const {
				return (_arr.max_size());
			}

			bool empty() const {
				return (_size == 0);
			}

			size_type capacity() const { return (_cap); }

			/**
			 * @brief Requests that the vector capacity be at least enough to contain n elements.
			 *
			 * @param new_cap: new capacity
			 */
			void reserve (size_type n) {

				pointer new_begin = nullptr;

				if (n > _arr.max_size())
					throw std::length_error("Reserve: n too big");
				else if (n < _cap)
					return;
				// try {
					new_begin = _arr.allocate(n);
				// }
				// catch (std::bad_alloc &e) {
				// 	throw e;
				// }

				for (size_type i = 0; i < _size; i++)
					_arr.construct(&(new_begin[i]), _begin[i]);

				for (size_type i = 0; i < _size; i++)
					_arr.destroy(&(_begin[i]));
				_arr.deallocate(_begin, _cap);

				_begin = new_begin;
				_cap = n;
			}

//---------------------------ELEMENT ACCESS----------------------------------------//

			reference operator[] (size_type n) { return *(_begin + n); }

			const_reference operator[] (size_type n) const { return *(_begin + n); }

			reference at (size_type n) {

				if (n >= _size)
					throw std::out_of_range("out of range");
				return *(_begin + n);
			}

			const_reference at (size_type n) const {

				if (n >= _size)
					throw std::out_of_range("out of range");
				return *(_begin + n);
			}

			reference front() { return *(_begin); }

			const_reference front() const { return *(_begin); }

			reference back() { return (_begin[_size - 1]); }

			const_reference back() const { return (_begin[_size - 1]); }

			value_type* data() { return (_begin); }

			const value_type* data() const { return (_begin); }

//---------------------------Modifiers----------------------------------------//

			/**
			 * @brief assing range version
			 *
			 * @tparam InputIterator
			 * @param first
			 * @param last
			 */
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {

				size_type		new_size = 0;
				InputIterator	tmp = first;

				for (size_type i = 0; i < _size; i++)
					_arr.destroy(&(_begin[i]));
				while (tmp++ != last)
					new_size++;
				if (new_size > _cap)
					_ft_realloc(new_size);
				for (size_type i = 0; i < new_size; i++)
					_arr.construct(&(_begin[i]), first[i]);
				if (new_size < _size)
				{
					for (size_t i = new_size; i < _size; i++)
						this->_arr.destroy(&(_begin[i]));
				}
				_size = new_size;
			}

			void assign (size_type n, const value_type& val) {

				for (size_type i = 0; i < _size; i++)
					_arr.destroy(&(_begin[i]));
				if (_size < n)
					_ft_realloc(n);
				for (size_type i = 0; i < n; i++)
					_arr.construct(&(_begin[i]), val);
				_size = n;
			}

			void push_back (const value_type& val) {

				if (_cap == 0)
					reserve(1);
				if (_size == _cap)
					reserve(_cap * 2);
				_arr.construct(_begin + _size, val);
				_size++;
			}

			void pop_back() {
				_arr.destroy(&(_begin[_size - 1]));
				_size--;
			}

			iterator insert (iterator position, const value_type& val) {

				size_type	pos = position - begin();

				if (pos > _size)
					throw std::out_of_range("out of range");
				if (_cap == 0)
					reserve(1);
				if (_size == _cap)
					reserve(_cap * 2);
				for (size_type i = _size; i > pos; i--)
					_arr.construct(&(_begin[i]), *(_begin + (i - 1)));
				_arr.construct(&(_begin[pos]), val);
				_size++;
				return (iterator(&(_begin[pos])));
			}

			void insert (iterator position, size_type n, const value_type& val) {

				size_type	pos = position - begin();

				if (_cap == 0)
					reserve(n);
				if (pos > _size)
					throw std::out_of_range("out of range");
				if (_size + n >= _cap)
					reserve(_size + n);
				for (size_type i = (_size + n) - 1; i > n; i--)
					_arr.construct(&(_begin[i]), *((_begin + (i - n))));
				for (size_type i = pos; i <= n; i++)
					_arr.construct(&(_begin[i]), val);
				_size = _size + n;
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			 typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {

				size_type		pos = position - begin();
				size_type		n = last - first;

				 if (first == last)
					return ;
				if (_size + n >= _cap) {
					if (_cap == 0)
						reserve(n);
					else {
						if (_size + n > _cap * 2)
							reserve(_size + n);
						else
							reserve(_cap * 2);
					}
				}
				for (size_type i = (_size + n) - 1; i > n; i--) {
					_arr.construct(&(_begin[i]), *((_begin + (i - n))));
					_arr.destroy(&_begin[i - n]);
				}
				for (size_type i = pos; i <= n; i++)
					_arr.construct(&(_begin[i]), *first++);
				_size = _size + n;
			}


			void clear() {

				for (size_type i = 0; i < _size; i++)
					_arr.destroy(&(_begin[i]));
				_size = 0;
			}

		private:
			allocator_type	_arr;
			pointer			_begin;
			size_type		_size;
			size_type		_cap;

			void	_ft_realloc(size_type new_cap, value_type val = value_type()) {

				pointer new_begin = _arr.allocate(new_cap);

				for (size_type i = 0; i < _size; i++)
					_arr.construct(&(new_begin[i]), _begin[i]);
				for (size_type i = _size; i < new_cap; i++)
					_arr.construct(&(new_begin[i]), val);
				for (size_type i = 0; i < _size; i++)
					_arr.destroy(&(_begin[i]));
				_arr.deallocate(_begin, _cap);

				_begin = new_begin;
				_cap = new_cap;
			}

	};


} // namespace ft end


#endif
