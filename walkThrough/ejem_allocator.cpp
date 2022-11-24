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
    myAlloc.destroy(ptr);
    myAlloc.destroy(ptr + 1);
    myAlloc.destroy(ptr + 2);

	// deallocate space for 3 strings
	myAlloc.deallocate(ptr, 4);
}

void	alloInt()
{
	std::allocator<int>	myAlloc;
	int*	ptr;

	ptr = myAlloc.allocate(5);
	ptr[0] = 7;
	ptr[3] = 42;

	std::cout << ptr[0] << std::endl;
	std::cout << ptr[3] << std::endl;
	std::cout << myAlloc.max_size() << std::endl;
	std::cout << &ptr << std::endl;

	myAlloc.deallocate(ptr, 5);
}

int	main()
{
	alloInt();
	alloString();
	return (0);
}
