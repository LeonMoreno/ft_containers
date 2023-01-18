#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "itetator_traits.hpp"

namespace ft {

	template<typename T>
	class vector_iterator {
		public:

			/*---------------VECTOR ITERATOR TYPEDEFS (iterator traits - las propiedades del iterator)-------- */

			typedef	vector_iterator<T>				iterator;
			typedef ft::random_access_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::ptrdiff_t					difference_type;
			typedef vector_iterator<const T>		const_iterator;


			/*---------------Constructor and Destructors ----------------------------------------------------- */

			vector_iterator(void) : _ptr(NULL) { } /* por si aca ??*/

			explicit vector_iterator(pointer ptr) : _ptr(ptr) { } /* default constructor */

			vector_iterator(const vector_iterator &copy) : _ptr(copy.base()) { } /* copy constructor */

			~vector_iterator() { };

			/*--------------- Getters and Setters-------------------------------------------------------------- */

			pointer base() const { return (_ptr); }

			/*---------------Assignment OPERADORES-------------------------------------------------------------------------- */

			vector_iterator& operator=(vector_iterator const &rhs) {
				_ptr = rhs._ptr;
				return (*this);
			}

			/*--------------- OPERADORES overload-------------------------------------------------------------------------- */

			// convertion to const if needed
			operator const_iterator() const {return const_iterator(_ptr);}


			/* -- Can be dereferenced. deferencia para obtener su valor  */
			reference operator*(void) const { return (*_ptr); }

			pointer operator->(void) const { return (_ptr); }

			reference operator[]( difference_type n ) const { return(*(_ptr + n)); }

			vector_iterator  operator+( difference_type n ) const {
				return (vector_iterator(_ptr + n));
			}

			vector_iterator  operator-( difference_type n ) const {
				return (vector_iterator(_ptr - n));
			}

			vector_iterator& operator+=( difference_type n ) {
				_ptr += n;
				return (*this);
			}

			vector_iterator& operator-=( difference_type n ) {
				_ptr -= n;
				return (*this);
			}

			vector_iterator& operator++( void ) {
				_ptr++;
				return (*this);
			}
			vector_iterator  operator++( int ) {
				vector_iterator temp(*this);
				_ptr++;
				return (temp);
			}

			vector_iterator& operator--( void ) {
				_ptr--;
				return (*this);
			}

			vector_iterator  operator--( int ) {
				vector_iterator temp(*this);
				_ptr--;
				return (temp);
			}

		protected:
			pointer		_ptr;
		};

	/* *******************************************************************************/
	/* 			Non-Member Functions Overloads	vector_iterator						 */
	/* *******************************************************************************/

	template<typename T1, typename T2>
	bool operator==(const vector_iterator<T1> &lhs, const vector_iterator<T2> &rhs) {
				return (lhs.base() == rhs.base());
	}

	template<typename T1, typename T2>
	bool operator!=(const vector_iterator<T1> &lhs, const vector_iterator<T2> &rhs) {
				return (lhs.base() != rhs.base());
	}

	template<typename T1, typename T2>
	bool operator>(const vector_iterator<T1> &lhs, const vector_iterator<T2> &rhs) {
				return (lhs.base() > rhs.base());
	}

	template<typename T1, typename T2>
	bool operator>=(const vector_iterator<T1> &lhs, const vector_iterator<T2> &rhs) {
				return (lhs.base() >= rhs.base());
	}

	template<typename T1, typename T2>
	bool operator<(const vector_iterator<T1> &lhs, const vector_iterator<T2> &rhs) {
				return (lhs.base() < rhs.base());
	}

	template<typename T1, typename T2>
	bool operator<=(const vector_iterator<T1> &lhs, const vector_iterator<T2> &rhs) {
				return (lhs.base() <= rhs.base());
	}

	template<typename T1>
	vector_iterator<T1> operator+(typename vector_iterator<T1>::difference_type n, const vector_iterator<T1> &rhs) {
				return (vector_iterator<T1>(rhs.base() + n));
	}

	template<typename T1>
	vector_iterator<T1> operator+(const vector_iterator<T1> &lhs, typename vector_iterator<T1>::difference_type n) {
				return (vector_iterator<T1>(lhs.base() + n));
	}

	template<typename T1>
	vector_iterator<T1> operator-(typename vector_iterator<T1>::difference_type n, const vector_iterator<T1> &rhs) {
				return (vector_iterator<T1>(rhs.base() - n));
	}

	template<typename T1>
	vector_iterator<T1> operator-(const vector_iterator<T1> &lhs, typename vector_iterator<T1>::difference_type n) {
				return (vector_iterator<T1>(lhs.base() - n));
	}

	// Operator overload for insert pos - begin()
	template<typename T1, typename T2>
	size_t operator-(const vector_iterator<T1> &lhs, const vector_iterator<T2> &rhs) {
				return (lhs.base() - rhs.base());
	}

} // namespace ft end


#endif
