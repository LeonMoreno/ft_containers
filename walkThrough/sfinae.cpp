#include <iostream>
#include <type_traits>

// template <typename T, typename U>
// T plantilla(U argu) { return static_cast<T>(argu); }

// template <typename T, typename U>
// T plantilla(typename U::value_type argu) { return static_cast<T>(argu); }

template<class T, typename std::enable_if_t<std::is_integral_v<T>>* = nullptr>
void	f(T argu) { std::cout << " es entero\n";}

template <class T, typename std::enable_if_t<std::is_floating_point_v<T>>* = nullptr>
void	f(T argu) { std::cout << " es FLoat\n";}



int	main(void)
{
	// Asi una substitucion en la instanciacion falle, no es un error.
	// std::cout << plantilla<int, float>(123.456) << std::endl;

	f<int>(42);
	f(1u);
	f(43.54);
	f(42);


	return(0);
}
