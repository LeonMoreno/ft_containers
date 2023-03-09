#include <iostream>
#define HOLA "HOla Mi LEo"


int	main() {

	#ifdef leo
		std::cout << "Hola Leo\n";
	#else
		#define ft std
		ft::cout << "Hola Andy\n";
	#endif

	ft::cout << HOLA << ft::endl;

	return (0);
}
