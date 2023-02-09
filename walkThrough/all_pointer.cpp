#include <iostream>

void	ft_ensayo(int **arr) {

	std::cout << "\n ** ft_ensayo **" << std::endl;

	std::cout << "ft_ensayo ADRR = " << arr << std::endl; // Accedo a la add PTR
	std::cout << "ft_ensayo PTR Contenid o= " << *arr << std::endl; // Accedo a donde apunta PTR
	std::cout << "Accedo con dobe ptr a var " << **arr << std::endl; // Accedo a la variable q apunta el ptr donde apunta ARR

	for (int i = 0; i < 4; i++)
		std::cout << (*arr)[i] << std::endl;

	std::cout << "(*arr)[2] = 69 " << std::endl;

	(*arr)[2] = 69;

	for (int i = 0; i < 4; i++)
		std::cout << (*arr)[i] << std::endl;
}

int	main(void) {

	std::cout << " ** MAIN **" << std::endl;

	int	arr [] = { 43, 54, 98, 7 };
	int	*ptr = NULL;
	std::cout << "main -- contenido PTR = " << ptr << std::endl;
	std::cout << "main -- ADRR PTR = " << &ptr << std::endl;
	std::cout << "main -- ADRR ARR = " << arr << std::endl;

	ptr = arr;

	std::cout << "main -- PTR = ARR = " << ptr << std::endl;

	for (int i = 0; i < 4; i++)
		std::cout << arr[i] << std::endl;
	ft_ensayo(&ptr);
	return (0);
}

