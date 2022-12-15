#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef> // ptrdiff_t

// Intro iterators traits :
// https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits

namespace ft {

	/**
	 * @brief The point of this is that, by creating several tags (so several types),
	 *  we can use them to route the execution through various overloads of a function.
	 *	https://www.fluentcpp.com/2018/04/27/tag-dispatching/
	 */
	///  Marking input iterators.
	struct input_iterator_tag {};
	 ///  Marking output iterators.
	struct output_iterator_tag {};
	/// Forward iterators support a superset of input iterator operations.
	struct forward_iterator_tag : public input_iterator_tag {};
	/// Bidirectional iterators support a superset of forward iterator oper.
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	/// Random-access iterators support a superset of bidirectional iterator oper.
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


	/**
	 * @brief the C++ standard library provides a special template structure to define the iterator traits
	 * 	This structure contains all relevant information regarding an iterator.
	 *  It is used as a common interface for all the type definitions an iterator should have
	 * 	(the category, the type of the elements, and so on):
	 *	https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
	 */

	// generic
	template <typename T>
	struct itetator_traits
	{
		typedef	typename	T::value_type			value_type;
		typedef	typename	T::difference_type		difference_type;
		typedef typename	T::iterator_category	iterator_category;
		typedef	typename	T::pointer				pointer;
		typedef	typename	T::reference			reference;
	};

	// spezialization pointer
	template <typename T>
	struct iterator_traits<T*> {
		typedef		T								value_type;
		typedef		ptrdiff_t						difference_type;
		typedef		random_access_iterator_tag		iterator_category;
		typedef		T* 								pointer;
		typedef		T&								reference;
	};

	// spezialization const pointer
	template <typename T>
	struct iterator_traits<const T*> {
		typedef			T								value_type;
		typedef			ptrdiff_t					difference_type;
		typedef			random_access_iterator_tag		iterator_category;
		typedef const 	T const*								pointer; // verificar el const
		typedef const 	T const&								reference; // verificar el const
	};

} // end namespace ft


#endif
