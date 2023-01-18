#ifndef REVERSE_VECTOR_ITERATOR
# define REVERSE_VECTOR_ITERATOR

#include "itetator_traits.hpp"

namespace ft {

	/*		https://cplusplus.com/reference/iterator/reverse_vector_iterator/				*/

	template <typename T>
	class reverse_vector_iterator
	{
		public:
			/*---------------VECTOR ITERATOR TYPEDEFS (iterator traits - las propiedades del iterator)-------- */

			// typedef	T													iterator_type;
			// typedef typename ft::iterator_traits<T>::value_type			value_type;
			// typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			// typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			// typedef typename ft::iterator_traits<T>::pointer			pointer;
			// typedef typename ft::iterator_traits<T>::reference			reference;

			typedef T									iterator_type;
			typedef typename T::iterator_category		iterator_category;
			typedef typename T::value_type			value_type;
			typedef typename T::difference_type		difference_type;
			typedef typename T::pointer				pointer;
			typedef typename T::reference				reference;

			/*---------------Constructor and Destructors ----------------------------------------------------- */

			reverse_vector_iterator(void) : _reverse_ptr() {  } /* por si aca ??*/

			explicit reverse_vector_iterator(iterator_type it) : _reverse_ptr(it) {   } /* default constructor */

			reverse_vector_iterator(const reverse_vector_iterator &copy) : _reverse_ptr(copy.base()) { } /* copy constructor */

			template <class Iter>
			reverse_vector_iterator (const reverse_vector_iterator<Iter>& rev_it) : _reverse_ptr(rev_it.base()) { }

			~reverse_vector_iterator() { };

			/*--------------- Getters and Setters-------------------------------------------------------------- */

			iterator_type base() const { return (_reverse_ptr); } // Revisar.

			/*---------------Assignment OPERADORES-------------------------------------------------------------------------- */

			reverse_vector_iterator& operator=(reverse_vector_iterator const &rhs) {

				_reverse_ptr = rhs.base();
				return (*this);
			}

			/*--------------- Vector MEMBER OPERADORES overload REVERSE ITERATOR--------------------------------------------- */

			/* -- Can be dereferenced. deferencia para obtener su valor  */
			reference operator*(void) const { return *iterator_type(_reverse_ptr); }

			pointer operator->() const { return (_reverse_ptr); }

			reverse_vector_iterator operator+(difference_type n) const {

				_reverse_ptr - n;
				 return (*this);
			}

			reverse_vector_iterator& operator++(void) {
				_reverse_ptr--;
				 return (*this);
			}

			reverse_vector_iterator& operator++(int) {

				reverse_vector_iterator ti = *this;
				_reverse_ptr--;
				 return (*this);
			}

			reverse_vector_iterator& operator+= (difference_type n)  {

				_reverse_ptr -= n;
				 return (*this);
			}

			reverse_vector_iterator operator- (difference_type n) const {

				_reverse_ptr + n;
				 return (*this);
			}

			reverse_vector_iterator& operator--() {
				_reverse_ptr++;
				 return (*this);
			}

			reverse_vector_iterator  operator--(int) {

				reverse_vector_iterator temp = *this;
				_reverse_ptr++;
				 return (*this);
			}

			reverse_vector_iterator& operator-= (difference_type n) {

				_reverse_ptr += n;
				 return (*this);
			}

			reference operator[] (difference_type n) const { return (_reverse_ptr - n - 1); }



			protected:
				iterator_type		_reverse_ptr;

	};

} // namespace ft end

#endif
