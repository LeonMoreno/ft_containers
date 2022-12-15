#include <iostream>

// Esta es una funcion unaria, que solo recibe un argumento y devuelve 1 resultado
// basado en ese argumento.
// Una función unaria se puede definir como una función que tiene una sola entrada y una sola salida.
// int	op_increment (int x) {
// 	std::cout << "aqui toy x = " << x << std::endl;
// 	return (x + 1); }


/** Remplazando la funcion unaria con un functor -- function + object */

struct op_increment{
	private:
		int	_num;
	public:
		op_increment(int n) : _num(n) { std::cout << "Default constructor\n"; };

		// This operator overloading enables calling
		// operator function () on objects of increment
		int	operator () (int arr_num) const {
			std::cout << "aqui toy arr_num = " << arr_num << std::endl;
			return _num + arr_num;
		}
};

int	main()
{
	int	arr[] = {1, 2, 3, 4, 5};
	int	n = sizeof(arr) / sizeof(arr[0]);
	// op_increment obj(5);

	// std::transform(arr, arr+n, arr, obj);
	std::transform(arr, arr+n, arr, op_increment(5)); // es lo mismo que las dos lineas de arriba

	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	return (0);
}
