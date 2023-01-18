#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "itetator_traits.hpp"
#include "utils.hpp"
#include <cstddef>
#include <iostream>

namespace ft {

	template<typename T, typename Container>
	class vector_iterator {
		public:

			/*---------------VECTOR ITERATOR TYPEDEFS (iterator traits - las propiedades del iterator)-------- */

			typedef	T													iterator_type;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;


			/*---------------Constructor and Destructors ----------------------------------------------------- */

			vector_iterator(void) : _ptr(NULL) { } /* por si aca ??*/

			vector_iterator(pointer ptr) : _ptr(ptr) { } /* default constructor */

			//below added for const/non-const
			template<typename _T>
			vector_iterator(const vector_iterator<_T, typename ft::enable_if<ft::are_same<_T, typename Container::pointer>::value, Container>::type>& copy) : _ptr(copy.base()) {}
			//end addition

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
			// operator const_iterator() const {return const_iterator(_ptr);}


			/* -- Can be dereferenced. deferencia para obtener su valor  */
			reference operator*(void) const { return (*_ptr); }

			pointer operator->(void) const { return (_ptr); }

			reference operator[](const difference_type n ) const { return(*(_ptr + n)); }

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

	template<typename T1, typename T2, typename Container>
	bool operator==(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
				return (lhs.base() == rhs.base());
	}

	template<typename T1, typename T2, typename Container>
	bool operator!=(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
				return (lhs.base() != rhs.base());
	}

	template<typename T1, typename T2, typename Container>
	bool operator>(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
				return (lhs.base() > rhs.base());
	}

	template<typename T1, typename T2, typename Container>
	bool operator>=(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
				return (lhs.base() >= rhs.base());
	}

	template<typename T1, typename T2, typename Container>
	bool operator<(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
				return (lhs.base() < rhs.base());
	}

	template<typename T1, typename T2, typename Container>
	bool operator<=(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
				return (lhs.base() <= rhs.base());
	}

	template<typename T1, typename Container>
	vector_iterator<T1, Container> operator+(typename vector_iterator<T1, Container>::difference_type n, const vector_iterator<T1, Container> &rhs) {
				return (vector_iterator<T1, Container>(rhs.base() + n));
	}

	template<typename T1, typename Container>
	vector_iterator<T1, Container> operator+(const vector_iterator<T1, Container> &lhs, typename vector_iterator<T1, Container>::difference_type n) {
				return (vector_iterator<T1, Container>(lhs.base() + n));
	}

	template<typename T1, typename Container>
	vector_iterator<T1, Container> operator-(typename vector_iterator<T1, Container>::difference_type n, const vector_iterator<T1, Container> &rhs) {
				return (vector_iterator<T1, Container>(rhs.base() - n));
	}

	template<typename T1, typename Container>
	vector_iterator<T1, Container> operator-(const vector_iterator<T1, Container> &lhs, typename vector_iterator<T1, Container>::difference_type n) {
				return (vector_iterator<T1, Container>(lhs.base() - n));
	}

	// Operator overload for insert pos - begin()
	template<typename T1, typename T2, typename Container>
	size_t operator-(const vector_iterator<T1, Container> &lhs, const vector_iterator<T2, Container> &rhs) {
				return (lhs.base() - rhs.base());
	}

//---------------VECTOR ITERATOR OPERATOR OVERLOADS (NON-MEMBER) -> FOR SIZE_TYPE CALCULATIONS----------------------------------------


	template<typename TPtr1, typename TPtr2, typename Container>
	typename ft::iterator_traits<TPtr1>::difference_type operator-(const vector_iterator<TPtr1, Container>& lhs, const vector_iterator<TPtr2, Container>& rhs) {
		return lhs.base() - rhs.base();
	}

	template<typename TPtr, typename Container>
	typename ft::iterator_traits<TPtr>::difference_type operator-(const vector_iterator<TPtr, Container>& lhs, const vector_iterator<TPtr, Container>& rhs) {
		return lhs.base() - rhs.base();
	}

	template<typename TPtr1, typename TPtr2, typename Container>
	typename ft::iterator_traits<TPtr1>::difference_type operator+(const vector_iterator<TPtr1, Container>& lhs, const vector_iterator<TPtr2, Container>& rhs) {
		return lhs.base() + rhs.base();
	}

	template<typename TPtr, typename Container>
	typename ft::iterator_traits<TPtr>::difference_type operator+(const vector_iterator<TPtr, Container>& lhs, const vector_iterator<TPtr, Container>& rhs) {
		return lhs.base() + rhs.base();
	}



} // namespace ft end


#endif
