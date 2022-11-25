#include <iostream>
#include <iterator>
#include <cstddef>
#include <algorithm>

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


	Iterator<int> begin() { return (&_m_data[0]); }
	Iterator<int> end() { return (&_m_data[5]); }

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
	Integers in;

	Iterator<int> begin(in.begin());

	// for (int i = 0; begin != in.end(); begin++, i++)
	// 	*begin = i;

	std::fill(in.begin(), in.end(), 7);

	Iterator<int> begin2(in.begin());


	for (; begin2 != in.end(); ++begin2)
		std::cout << *begin2 << std::endl;


	std::cout <<"todo funciona " << std::endl;
	return (0);
}
