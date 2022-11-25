#include <iostream>
#include <iterator>
#include <cstddef>
#include <algorithm>

class Integers
{
private:
	int	_m_data[200];
public:
	Integers(/* args */);
	~Integers();
	struct Iterator
	{

		/* Tags definitions -- las propiedades del iterator */

		using iterator_category	= std::forward_iterator_tag;

		/* ptrdiff_t : Result of pointer subtraction
		 difference_type : a signed integer type that can be used to
			identify distance between iterator steps. */
		using difference_type	= std::ptrdiff_t;

		using value_type 		= int;

		using pointer			=	value_type*;

		using reference			= value_type&;

		/* Constructor & Destruc */

		Iterator(pointer ptr) : _m_ptr(ptr) {   }

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

	Iterator begin() { return (&_m_data[0]); }
	Iterator end() { return (&_m_data[200]); }

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

	Integers::Iterator begin(in.begin());

	// for (int i = 0; begin != in.end(); begin++, i++)
	// 	*begin = i;

	std::fill(in.begin(), in.end(), 7);

	Integers::Iterator begin2(in.begin());


	for (; begin2 != in.end(); ++begin2)
		std::cout << *begin2 << std::endl;


	std::cout <<"todo funciona " << std::endl;
	return (0);
}
