#include <iostream>
#include <iterator>
#include <cstddef>
#include <algorithm>
#include <vector>

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

		typedef T* 				pointer	;

		typedef value_type&					reference;

		/* Constructor & Destruc */

		Iterator(void) : _m_ptr(NULL) { std::cout << "Default Construct\n"; } /* por si aca ??*/
		Iterator(pointer ptr) : _m_ptr(ptr) {   }
		~Iterator() { };

		/* Operators */
		/* deferencia para obtener su valor */
		reference	operator*() const { return *_m_ptr; }
		pointer		operator->() {return _m_ptr; }

		Iterator& operator=(Iterator &rhs) {
				_m_ptr = rhs._m_ptr;
				return (*this);
			}

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
} // end ft

template< typename T, class Alloc = std::allocator<T> >
class vector
{
public:
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef std::size_t											size_type;
			typedef std::ptrdiff_t										difference_type;
			typedef T&													reference;
			typedef const T&											const_reference;
			typedef T*													pointer;
			typedef const T*											const_pointer;
			typedef ft::Iterator<pointer>			iterator;
			typedef ft::Iterator<const_pointer >	const_iterator;
			// typedef reverse_vector_iterator<iterator>					reverse_iterator;
			// typedef reverse_vector_iterator<const_iterator>				const_reverse_iterator;

private:
	T	_m_data[10];
public:
	vector (/* args */);
	~vector();


	ft::Iterator<int> begin() { return ft::Iterator<int> (&_m_data[0]); }
	ft::Iterator<int> end() { return ft::Iterator<int> (&_m_data[5]); }

};

template< class T, class Alloc>
vector<T, Alloc> ::vector(/* args */)
{
	std::cout <<"Default construc " << std::endl;

}

template< class T, class Alloc>
vector<T, Alloc>::~vector()
{
	std::cout <<" Destruc " << std::endl;

}

void	ft_ensayo()
{
	std::vector<int> vec;

	std::vector<int>::iterator it;
}


int	main(void)
{

	ft_ensayo();
	vector<int> ap;

	vector<int>::iterator it = ap.begin();

	for (int i = 0; it != ap.end(); it++, i++)
		*it = i;

	// std::fill(ap.begin(), ap.end(), 7);



	for (it = ap.begin(); it != ap.end(); ++it)
		std::cout << *it << std::endl;


	std::cout <<"todo funciona " << std::endl;
	return (0);
}
