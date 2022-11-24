#include <memory>
#include <iostream>

template <typename T, typename Alloc = std::allocator<T> >
class ejem {
	public :

		// The second template parameter (Alloc)
		typedef		Alloc					allocator_type;

		// Todos estos typedef son requisito de std::allocator
		// 	The first template parameter (T)
		// value_type: tipo de elemtos que el container stores (T)
		typedef		T						value_type;

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

		ejem() {
			std::cout << "Construc\n";
			 }
		ejem(int n, const T& dato = value_type(),
		 const allocator_type& a = allocator_type() ) : _data(dato), _alloc(a) {
			std::cout << "Construc alloc\n";
			_start = _alloc.allocate(n);
			_end = _start + n;
			for (int i = 0; i < 5; i++)
			{
				_start[i] = _data;
				std::cout << _start[i] << std::endl;
			}
			std::cout << "end = " << *(_end -1) << std::endl;

		}
		~ejem() {std::cout << "Destruc\n"; }

		private :
			value_type		_data;
			allocator_type	_alloc;
			pointer			_start;
			pointer			_end;
};

int	main()
{
	std::allocator<int> MyAlloc;

	ejem<int>	e(5, 1);

	return (0);
}
