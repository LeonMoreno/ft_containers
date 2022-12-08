#include <iostream>
#include <iterator>
#include <cstddef>
#include <algorithm>

namespace ft {
	 ///  Marking input iterators.
  struct input_iterator_tag {};
  ///  Marking output iterators.
  struct output_iterator_tag {};
  /// Forward iterators support a superset of input iterator operations.
//   struct forward_iterator_tag : public input_iterator_tag {};
  struct forward_iterator_tag {};

  /// Bidirectional iterators support a superset of forward iterator
  /// operations.
  struct bidirectional_iterator_tag {};
  /// Random-access iterators support a superset of bidirectional iterator
  /// operations.
  struct random_access_iterator_tag {};
  //@}


 template <bool is_valid, typename T>
        struct valid_iterator_tag_res { typedef T type; const static bool value = is_valid; };

















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

template <typename T>
class Iterator
	{
	public:

		/* Tags definitions -- las propiedades del iterator */

		// Aqui defino que tipo de iterator es.
		typedef	std::forward_iterator_tag	iterator_category;

		/* ptrdiff_t : Result of pointer subtraction
		difference_type : a signed integer type that can be used to
		identify distance between iterator steps. */
		typedef std::ptrdiff_t				difference_type;


		typedef T 						value_type ;

		typedef value_type* 				pointer	;

		typedef value_type&					reference;

		/* Constructor & Destruc */

		Iterator(pointer ptr) : _m_ptr(ptr) {   }
		~Iterator() { };

		/* Operators */
		/* deferencia para obtener su valor */
		reference	operator*() const { return *_m_ptr; }
		pointer		operator->() {return _m_ptr; }

		// Prefix increment
		Iterator& operator++() { _m_ptr++; return *this; }

		// Postfix incremental
		Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

		// Comparation operators
		friend bool operator== (const Iterator& a, const Iterator& b) {return a._m_ptr == b._m_ptr; }
		friend bool operator!= (const Iterator& a, const Iterator& b) {return a._m_ptr != b._m_ptr; }


	private:
		pointer	_m_ptr;
	};


class Integers
{
private:
	int	_m_data[10];
public:
	Integers (/* args */);
	~Integers();


	Iterator<int> begin() { return Iterator<int> (&_m_data[0]); }
	Iterator<int> end() { return Iterator<int> (&_m_data[5]); }

};

Integers::Integers(/* args */)
{
	std::cout <<"Default construc " << std::endl;

}

Integers::~Integers()
{
	std::cout <<" Destruc " << std::endl;

}


int	main(void)
{
	Integers ap;

	// Iterator<int> begin(ap.begin());

	// for (int i = 0; begin != in.end(); begin++, i++)
	// 	*begin = i;

	std::fill(ap.begin(), ap.end(), 7);

	// for (int i = 0; begin != ap.end(); begin++, i++)
	// 	*begin = i;


	// for (begin = ap.begin(); begin != ap.end(); ++begin)
	// 	std::cout << *begin << std::endl;


	std::cout <<"todo funciona " << std::endl;
	return (0);
}
