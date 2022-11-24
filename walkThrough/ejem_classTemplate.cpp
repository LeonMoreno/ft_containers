#include <iostream>
#include <string>
#include <memory>

template <typename T, typename Allocator = std::allocator<T> >
class ejem_classTemplate
{

public:

		// Todos estos typedef son requisito de Allocator
		// 	The first template parameter (T)
		// value_type: tipo de elemtos que el container stores (T)
		typedef		T						value_type;

		// The second template parameter (Alloc)
		typedef		Allocator				allocator_type;

		// for the default allocator: value_type&
		typedef		value_type&				reference;

		// 	for the default allocator: const value_type&
		typedef		const value_type&		const_reference;

		// for the default allocator: value_type*
		typedef		value_type*				pointer;

		// for the default allocator: const value_type*
		typedef		const value_type*		const_pointer;

		// a random access iterator to value_type
		typedef		pointer					iterator;

		// a random access iterator to const value_type
		typedef		const_pointer			const_iterator;




	// explicit ejem_classTemplate(const allocator_type& alloc ) : _allo(alloc) { std::cout << "Default constructor \n"; }
	explicit ejem_classTemplate(T data, const allocator_type&  alloc = allocator_type() ) : _data(data) { std::cout << "INIt constructor \n"; }
	~ejem_classTemplate() { }

	T	getData() {
		return	(this->_data);
	}

	private:
		allocator_type	_allo;
		T	_data;
};


int	main(void)
{
	ejem_classTemplate<std::string> eje(7);

	// std::cout << eje.getData() << std::endl;

	return (0);
}

