#include <iostream>

int	main() {

	#ifdef leo
		std::cout << "Hola Leo\n";
	#else
		std::cout << "Hola Andy\n";
	#endif

	return (0);
}
