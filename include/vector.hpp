#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "vector_iterator.hpp" //
#include "reverse_iterator.hpp"
#include "utils.hpp" //
#include <memory> //

namespace ft{

//--------------------------Template parameters ---------------------------------------//

	template <typename T, typename Alloc = std::allocator<T> >
	class vector {
		public:

//---------------------------Member Types -- C++98 ------------------------------------//
			typedef T											value_type;
			typedef Alloc										allocator_type;

			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference 	const_reference;

			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef vector_iterator<pointer>					iterator;
			typedef vector_iterator <const_pointer>				const_iterator;

			typedef	ft::reverse_iterator <iterator>				reverse_iterator;
			typedef	ft::reverse_iterator <const_iterator>		const_reverse_iterator;

			typedef	std::ptrdiff_t								difference_type;
			typedef std::size_t									size_type;

/****************** 			MEMBER functions 							******************/
//---------------------------constructor & Destructor---------------------------------------//
			// default constructor
			// error: identifier ‘nullptr’ is a keyword in C++11
			explicit vector (const allocator_type& alloc = allocator_type())
			: _arr(alloc), _begin(NULL), _size(0), _cap(0)
			{  }

			// fill constructor
			explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()) :
			_arr(alloc), _begin(_arr.allocate(n)), _size(n), _cap(n) {

				// std::cout << "Fill constru" << std::endl;
				for (size_type i = 0; i < n; i++)
					_arr.construct(&(_begin[i]), val);
			}

			// range contruc
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
				: _arr(alloc), _begin(NULL), _size(last - first), _cap(_size) {

				// std::cout << "Range constru" << " cap = "<< _cap << std::endl;
				_begin = _arr.allocate(_size);

				for (size_type i = 0; i < _size; i++)
					_arr.construct(&(_begin[i]), first[i]);
			}

			// copy constructor
			vector (const vector& src)
			: _arr(src._arr), _begin(NULL), _size(src._size), _cap(src._cap) {

				// std::cout << "Copy constru" << std::endl;
				_begin = _arr.allocate(_size);

				for (size_type i = 0; i < _size; i++)
					_arr.construct(&(_begin[i]), src._begin[i]);
			}

			~vector(void) {

				// std::cout << "Destructor size = " << _size << " _cap  = " << _cap << std::endl;
				if (_begin != NULL) {
					for(size_type i = 0; i < _size; i++)
						_arr.destroy(&(_begin[i]));
					this->_arr.deallocate(_begin, _cap);
				}
			}

//---------------------------COPY ASSIGNMENT OPERATOR----------------------------------------//

			vector& operator=(const vector& rhs) {

				if (_begin != NULL)
					_arr.deallocate(_begin, _cap);

				if (rhs._cap > 0)
				{
					_size = rhs._size;
					_cap = rhs._cap;
					_begin = _arr.allocate(_size);
					assign(rhs.begin(), rhs.end());
				}
				return (*this);
			}

//-------------------------------Getters and Setters-----------------------------------------------//

			// Get Alloc
			allocator_type get_allocator(void) const { return _arr; }

//---------------------------Iterator from vector----------------------------------------//

			// Return iterator to beginning
			iterator begin(void) { return (iterator(_begin)); }

			const_iterator begin(void) const { return (const_iterator(_begin)); }

			// Return iterator to end
			iterator end() { return (iterator(_begin + _size)); }

			const_iterator end() const { return (const_iterator(_begin + _size)); }

			// Returns a reverse iterator pointing to the last element in the vector
			reverse_iterator rbegin() { return (reverse_iterator((this->begin() + _size) - 1)); }

			const_reverse_iterator rbegin() const { return (const_reverse_iterator((this->begin() + _size) - 1)); }

			// Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
			reverse_iterator rend() { return (reverse_iterator((this->begin()))); }

			const_reverse_iterator rend() const { return (const_reverse_iterator((this->begin()))); }

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
			 *	https://cplusplus.com/reference/vector/vector/resize/ -- throw exceptions on failure
			 * @param n: new capacity
			 */
			void reserve (size_type n) {

				pointer new_begin = NULL;

				if (n > _arr.max_size())
					throw std::length_error("Reserve: n too big");
				else if (n < _cap)
					return;
				try {
					new_begin = _arr.allocate(n);
				}
				catch (std::bad_alloc &e) {
					throw e;
				}
				for (size_type i = 0; i < _size; i++)
					_arr.construct(&(new_begin[i]), _begin[i]);

				if (_begin != NULL) {
					for (size_type i = 0; i < _size; i++)
						_arr.destroy(&(_begin[i]));
					_arr.deallocate(_begin, _cap);
				}
				_begin = new_begin;
				_cap = n;
			}

			/**
			 * @brief Resizes the container so that it contains n elements.
			 *
			 * @param n: New container size
			 * @param val: Object whose content is copied to the added elements
			 *  in case that n is greater than the current container size.
			 */
			void resize (size_type n, value_type val = value_type()) {

				if (n < _size) {
					for (size_type range = n; range < _size; range++)
						_arr.destroy(&(_begin[range]));
				}
				else if (n > _size) {
					if (n > _cap)
						_ft_evalCap(n - _size);
					for (size_type range = _size; range < n; range++)
						_arr.construct(&(_begin[range]), val);
				}
				_size = n;
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
			 * @brief Assigns new contents to the vector, replacing its current contents,
			 * 	and modifying its size accordingly. -- range
			 * @tparam InputIterator
			 * @param first
			 * @param last
			 */
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {

				size_type		new_size = last - first;

				clear();
				if (new_size > _cap)
					reserve(new_size);
				for (size_type i = 0; i < new_size; i++)
					_arr.construct(&(_begin[i]), first[i]);
				_size = new_size;
			}

			// assing fill version - the new contents are n elements, each initialized to a copy of val.
			void assign (size_type n, const value_type& val) {

				clear();
				if (_size < n)
					reserve(n);
				for (size_type i = 0; i < n; i++)
					_arr.construct(&(_begin[i]), val);
				_size = n;
			}

			// Add element at the end
			void push_back (const value_type& val) {

				_ft_evalCap(1);
				_arr.construct(&(_begin[_size]), val);
				_size++;
			}

			// 	Delete last element
			void pop_back() {
				if (_begin == NULL || _size == 0)
					return ;
				_arr.destroy(&(_begin[_size - 1]));
				_size--;
			}

			// insert -- single element
			iterator insert (iterator position, const value_type& val) {

				size_type	pos = position - begin();

				if (pos > _size)
					throw std::out_of_range("out of range");
				_ft_evalCap(1);
				for (size_type i = _size; i > pos; i--)
					_arr.construct(&(_begin[i]), *(_begin + (i - 1)));
				_arr.construct(&(_begin[pos]), val);
				_size++;
				return (iterator(&(_begin[pos])));
			}

			// insert -- fill  // Probada
			void insert (iterator position, size_type n, const value_type& val) {

				size_type	pos = position - begin();

				if (pos > _size)
					throw std::out_of_range("out of range");
				_ft_evalCap(n);
				for (size_type i = ((_size + n) - 1); i >= pos + n; i--)
					_arr.construct(&(_begin[i]), *((_begin + (i - n))));
				for (size_type i = pos; i < n + pos; i++)
					_arr.construct(&(_begin[i]), val);
				_size = _size + n;
			}


			// insert range -- begin to end // falta hacer hard test
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {

				size_type		pos = position - begin();
				size_type		n = last - first;
				pointer			new_begin;
				size_type		new_cap = 0;

				if (_size + n >= _cap) {
					if (_size + n > _cap * 2)
						new_cap = _size + n;
					else
						new_cap = _cap * 2;
					new_begin = _arr.allocate(new_cap);
					try {
						for (size_type range = 0; range < pos; range++)
							_arr.construct(&(new_begin[range]), _begin[range]);
						for (size_type range = pos; range < n + pos; range++)
							_arr.construct(&(new_begin[range]), *first++);
						for (size_type range = pos; range < _size; range++)
							_arr.construct(&(new_begin[range + n]), _begin[range]);
					}
					catch (...) {
						for (size_type range = 0; range < new_cap; range++)
							_arr.destroy(&new_begin[range]);
						_arr.deallocate(new_begin, new_cap);
						throw;
					}
					if (_begin != NULL) {
						_arr.destroy(_begin);
						_arr.deallocate(_begin, _cap);
					}
					_begin = new_begin;
					_cap = new_cap;
				}
				else {
					for (size_type i = (_size + n - 1); i >= n + pos; i--) {
						_arr.construct(&(_begin[i]), *((_begin + (i - n))));
						_arr.destroy(&_begin[i - n]);
				}
					for (size_type i = pos; i < n + pos; i++)
						_arr.construct(&(_begin[i]), *first++);
				}
				_size = _size + n;
			 }

			void clear() {

				if (_begin == NULL)
				 	return ;
				if (_size > 0) {
					_arr.destroy(_begin);
					_size = 0;
				}
			}

			// Removes from the vector single element (position)
			iterator erase (iterator position) {

				size_type pos = position - begin();

				for (size_type i = pos; i < _size; i++)
					_arr.construct(&(_begin[i]), _begin[i + 1]);
				_size--;
				return (iterator(&_begin[pos]));
			}

			// Removes from the vector either a range of elements ([first,last)).
			iterator erase (iterator first, iterator last) {

				size_type size_range = last - first;
				size_type start = first - begin();

				for (size_type i = start + size_range; i < _size; i++) {
					_arr.construct(&(_begin[start++]), _begin[i]);
					_arr.destroy(&_begin[i]);
				}

				_size = _size - size_range;
				return (first);
			}

			void swap (vector& x) {

				pointer			temp_begin = _begin;
				size_type		temp_size = _size;
				size_type		temp_cap = _cap;
				allocator_type	temp_arr = _arr;

				_begin = x._begin;
				x._begin = temp_begin;

				_size = x._size;
				x._size = temp_size;

				_cap = x._cap;
				x._cap = temp_cap;

				_arr = x._arr;
				x._arr = temp_arr;
			}

		private:

			// Evalua la capacidad para hacer reserva.
			void	_ft_evalCap(size_type new_cap) {

				if (_size + new_cap <= _cap)
					return ;
				if (_size == 0)
					reserve(1);
				else if (_size + new_cap > _cap * 2)
					reserve(_size + new_cap);
				else
					reserve(_cap * 2);
			}
/****************** 			MEMBER Attributes			******************/
			allocator_type	_arr;
			pointer			_begin;
			size_type		_size;
			size_type		_cap;
	};

	/* *******************************************************************************/
	/* 								Non-member function 							 */
	/* *******************************************************************************/

//---------------------------relational operators (vector (overloads)----------------//

	template< class T, class Alloc >
	bool operator==( const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs ) {

		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class T, class Alloc >
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

		return (!(lhs == rhs));
	}

	template< class T, class Alloc >
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}


	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(rhs < lhs));
	}


	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(lhs < rhs));
	}

} // namespace ft end

namespace std {

	template< class T, class Alloc >
	void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs ) {

		lhs.swap(rhs);
	}
} // namespace std


#endif
