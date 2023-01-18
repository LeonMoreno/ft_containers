#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef> // ptrdiff_t
#include <iterator> // para std::random_access_iterator_tag

// Intro iterators traits :
// https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits

namespace ft {

	/**
	 * @brief The point of this is that, by creating several tags (so several types),
	 *  we can use them to route the execution through various overloads of a function.
	 *	https://www.fluentcpp.com/2018/04/27/tag-dispatching/
	 */
	struct input_iterator_tag { };

	struct forward_iterator_tag : public input_iterator_tag { };

	struct bidirectional_iterator_tag : public forward_iterator_tag { };

	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	/**
	 * @brief the C++ standard library provides a special template structure to define the iterator traits
	 * 	This structure contains all relevant information regarding an iterator.
	 *  It is used as a common interface for all the type definitions an iterator should have
	 * 	(the category, the type of the elements, and so on):
	 *	https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits
	 *	https://en.cppreference.com/w/cpp/iterator/iterator_traits -- A la final aqui esta todo
	 */

	// generic
	template <class Iter>
	struct iterator_traits
	{
		typedef	typename	Iter::difference_type		difference_type;
		typedef	typename	Iter::value_type			value_type;
		typedef	typename	Iter::pointer				pointer;
		typedef	typename	Iter::reference				reference;
		typedef typename	Iter::iterator_category		iterator_category;
	};

	// spezialization pointer
	// which makes it possible to use all iterator-based algorithms with raw pointers.
	template <typename T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T* 									pointer;
		typedef T&									reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};

	// spezialization const pointer
	template <typename T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef const T* 							pointer;
		typedef	const T& 							reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};

} // end namespace ft


#endif
