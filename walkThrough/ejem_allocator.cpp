#include <iostream>
#include <memory>
#include <string>

void	alloString()
{
	std::allocator<std::string>	myAlloc;
	std::string* ptr;

	ptr = myAlloc.allocate(3);
	myAlloc.construct(ptr, "Hola ");
	myAlloc.construct(ptr + 1, "como ");
	myAlloc.construct(ptr + 2, "estas ");

	std::cout << ptr[0] << ptr[1] << ptr[2]  << std::endl;

	// destroy these 3 strings
    // myAlloc.destroy(ptr);
    // myAlloc.destroy(ptr + 1);
    // myAlloc.destroy(ptr + 2);

	// deallocate space for 3 strings
	myAlloc.deallocate(ptr, 4);
}


void	alloInt()
{
	std::allocator<int>	myAlloc; // object allocator<int> // aqui solo declaro como la variable MyAlloc

	std::allocator<int>::pointer	ptr; // pointer to int de tipo allocator
	std::allocator<int>::pointer	start;

	ptr = myAlloc.allocate(5); // Aqui me agarro 5 espacios para almacenar int (malloc)
	start = ptr;
	for (int i = 0; i < 5; i++, ptr++)
		myAlloc.construct(ptr, 7); 		// Coloco en essos espacios los ints que quiera --> Lleno de info mis cajas

	ptr = start;
	for (int i = 0; i < 5; i++, ptr++)
		std::cout << *ptr << std::endl;		// Accedo a la info
	std::cout << myAlloc.max_size() << std::endl; // maxima capacidad de myAlloc
	// std::cout << &ptr << std::endl;
	for (int i = 0; i < 5; i++, ptr++) // Destruyo info
		myAlloc.destroy(ptr);

	myAlloc.deallocate(start, 5); // Free
}
/* La palabra clave typename es un especificador de tipo.
Indica justamente eso, que el identificador que la acompaña es un tipo (aunque no se haya definido todavía).
Una especie de declaración adelantada para que el compilador no lo rechace (al identificador) y lo tome como tal.
La sintaxis siguiente se utiliza en sustitución de la palabra clave class en las declaraciones de plantillas */
template <typename T, typename Alloc = std::allocator<T> >
class alloClass {
	public:

		typedef Alloc	type_def;
		typedef T*	pointer;

		type_def	var;
		pointer		ptr;

		alloClass(const type_def& all = type_def()) : var(all) { std::cout << "Contr Def\n"; };
		alloClass(T val, const type_def& all = type_def()) : var(all) {
			 std::cout << "Contr INIT\n";
			pointer	start;

			ptr = var.allocate(12);
			start = ptr;
			for (int i = 0; i < 12; i++, start++)
				var.construct(start, val);

			start = ptr;
			for (int i = 0; i < 12; i++, start++)
				std::cout << *start << std::endl;

		};
};


int	main()
{
	// alloInt();
	alloClass<int> obj(8);
	// alloString();
	return (0);
}
