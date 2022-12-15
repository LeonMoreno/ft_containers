#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "itetator_traits.hpp"

namespace ft {

	template <typename T>
	class vector_iterator
		{
		public:

			/*---------------VECTOR ITERATOR TYPEDEFS (iterator traits - las propiedades del iterator)-------- */

			typedef typename ft::itetator_traits<T>::value_type			value_type;
			typedef typename ft::itetator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;

			/*---------------Constructor and Destructors ----------------------------------------------------- */

			vector_iterator(void) : _ptr(NULL) { } /* por si aca ??*/
			vector_iterator(pointer ptr) : _ptr(ptr) { } /* default constructor */
			vector_iterator(const vector_iterator &copy) : _ptr(copy._ptr()) {} /* copy constructor */
			~vector_iterator() { };

			/*--------------- Getters and Setters-------------------------------------------------------------- */

			pointer base() const { return (_ptr); }

			/*---------------OPERADORES-------------------------------------------------------------------------- */

			/* assignment operator */
			vector_iterator& operator=(vector_iterator const &rhs) {
				_ptr = rhs._ptr;
				return (*this);
			}

			/* -- Can be dereferenced. deferencia para obtener su valor  */
			reference operator*(void) const { return (*_ptr); }

			pointer operator->(void) const { return (_ptr); }

			// /* Can be compared for equivalence using the equality/inequality operators */
		 	// bool operator== (const Iterator& a, const Iterator& b) {return a._m_ptr == b._m_ptr; }
			// bool operator!= (const Iterator& a, const Iterator& b) {return a._m_ptr != b._m_ptr; }

		protected:
			pointer		_ptr;

		};


} // namespace ft end


#endif
