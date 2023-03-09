#ifndef REVERSE_ITERATOR
# define REVERSE_ITERATOR

#include "../headers/iterator.tpp"

namespace ft {

	/*		std::reverse_iterator is an iterator adaptor that reverses the direction of a given iterator,
			which must be at least a LegacyBidirectionalIterator or model bidirectional_iterator (since C++20).
			In other words, when provided with a bidirectional iterator, std::reverse_iterator produces a
			new iterator that moves from the end to the beginning of the sequence defined by the underlying bidirectional
			iterator.

			https://en.cppreference.com/w/cpp/iterator/reverse_iterator		*/

	template <class T>
	class reverse_iterator
	{
		public:
			/*---------------VECTOR ITERATOR TYPEDEFS (iterator traits - las propiedades del iterator)-------- */

			// (until C++20)
			typedef	T													iterator_type;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;

			// typedef T									iterator_type;
			// typedef typename T::iterator_category		iterator_category;
			// typedef typename T::value_type			value_type;
			// typedef typename T::difference_type		difference_type;
			// typedef typename T::pointer				pointer;
			// typedef typename T::reference				reference;

			/*---------------Constructor and Destructors ----------------------------------------------------- */

			reverse_iterator(void) : _reverse() {  } /* por si aca ??*/

			explicit reverse_iterator(iterator_type it) : _reverse(it) {   } /* default constructor */

			reverse_iterator(const reverse_iterator &copy) : _reverse(copy._reverse) { } /* copy constructor */

			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _reverse(rev_it.base()) { }

			~reverse_iterator() { };

			/*--------------- Getters and Setters-------------------------------------------------------------- */

			iterator_type base() const { return (_reverse); } // Revisar.

			/*---------------Assignment OPERADORES-------------------------------------------------------------------------- */

			reverse_iterator& operator=(reverse_iterator const &rhs) {

				_reverse = rhs.base();
				return (*this);
			}

			/*--------------- Vector MEMBER OPERADORES overload REVERSE ITERATOR--------------------------------------------- */

			/* -- Can be dereferenced. deferencia para obtener su valor  */
			reference operator*(void) const {
				iterator_type tmp = this->_reverse;

				return *(tmp);
			}

			pointer operator->() const { return &(operator*()); }

			reverse_iterator operator+(difference_type n) const {

				_reverse - n;
				 return (*this);
			}

			reverse_iterator operator- (difference_type n) const {

				_reverse + n;
				 return (*this);
			}

			reverse_iterator& operator+= (difference_type n)  {

				_reverse -= n;
				 return (*this);
			}

			reverse_iterator& operator-= (difference_type n) {

				_reverse += n;
				 return (*this);
			}

			reverse_iterator& operator++(void) {
				_reverse--;
				 return (*this);
			}

			reverse_iterator operator++(int) {

				reverse_iterator ti = *this;
				this->_reverse--;
				 return (ti);
			}

			reverse_iterator& operator--() {
				_reverse++;
				 return (*this);
			}

			reverse_iterator  operator--(int) {

				reverse_iterator ti = *this;
				_reverse++;
				 return (ti);
			}

			reference operator[] (difference_type n) const { return (_reverse - n - 1); }

			protected:
				iterator_type		_reverse;

	};


	/* *******************************************************************************/
	/* 			Non-Member Functions Overloads	reverse_iterator					 */
	/* *******************************************************************************/

	template<typename T1, typename T2>
	bool operator==(const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs) {
				return (lhs.base() == rhs.base());
	}

	template<typename T1, typename T2>
	bool operator!=(const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs) {
		return (lhs.base() != rhs.base());
	}

	template<typename T1, typename T2>
	bool operator<(const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs) {
		return (lhs.base() > rhs.base());
	}

	template<typename T1, typename T2>
	bool operator<=(const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs) {
		return (lhs.base() >= rhs.base());
	}

	template<typename T1, typename T2>
	bool operator>(const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs) {
		return (lhs.base() < rhs.base());
	}

	template<typename T1, typename T2>
	bool operator>=(const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	template<typename T1>
	reverse_iterator<T1> operator+(const reverse_iterator<T1> &lhs, typename reverse_iterator<T1>::difference_type offset) {

		return (reverse_iterator<T1>(lhs.base() - offset));
	}

	template<typename T2>
	reverse_iterator<T2> operator+(typename reverse_iterator<T2>::difference_type offset, const reverse_iterator<T2> &rhs) {

		return (reverse_iterator<T2>(rhs.base() - offset));
	}

	template<typename T2>
	reverse_iterator<T2> operator-(typename reverse_iterator<T2>::difference_type offset, const reverse_iterator<T2> &rhs) {

		return (reverse_iterator<T2>(rhs.base() + offset));
	}

	template<typename T1>
	reverse_iterator<T1> operator-(const reverse_iterator<T1> &lhs, typename reverse_iterator<T1>::difference_type offset) {

		return (reverse_iterator<T1>(lhs.base() + offset));
	}

	template<typename Iterator1, typename Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) {
		return (rhs.base() - lhs.base());
	}

} // namespace ft end

#endif
