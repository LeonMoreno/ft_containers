#include <iostream>
#include <functional>

int	main(void) {

	int	a = 19;
	int	b = 45;

	if (std::less<int>()(a, b))
		std::cout << "a es menor" << std::endl;
	else
		std::cout << "a es Mayor" << std::endl;


	return (0);

}
