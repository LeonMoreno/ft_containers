#include <iostream>
#include <iterator>
#include <typeinfo>

namespace ft {
	 ///  Marking input iterators.
  struct input_iterator_tag {};
  ///  Marking output iterators.
  struct output_iterator_tag {};
  /// Forward iterators support a superset of input iterator operations.
  struct forward_iterator_tag : public input_iterator_tag {};
  /// Bidirectional iterators support a superset of forward iterator
  /// operations.
  struct bidirectional_iterator_tag : public forward_iterator_tag {};
  /// Random-access iterators support a superset of bidirectional iterator
  /// operations.
  struct random_access_iterator_tag : public bidirectional_iterator_tag {};
  //@}

     template <class T>
    struct iterator_traits {
        typedef typename T::value_type            value_type;
        typedef typename T::difference_type       difference_type;
        typedef typename T::iterator_category     iterator_category;
        typedef typename T::pointer               pointer;
        typedef typename T::reference             reference;
    };

template <class T>
	struct iterator_traits<T*> {
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T*								pointer;
		typedef T&								reference;
	};
}

int	main()
{
	typedef ft::iterator_traits<int*> traits;

	if (typeid(traits::iterator_category ) == typeid(std::input_iterator_tag))
		std::cout << "voila\n";
	return (0);
}
