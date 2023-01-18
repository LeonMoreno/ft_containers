#include <iostream>
#include <type_traits>
#include <limits.h>
#include <cmath>

// template<bool, class T>    //i give it two parameters, up to you to give more or less
// struct enable_if
// {};

// template <class T>
// struct enable_if<true, T>
// {
//     typedef T value;     //if true define the T type value
// };

// template <class T, T v>
// struct integral_constant   //integral C++ struct in C++98 manner
// {
//     typedef T value_type;
//     typedef integral_constant<T,v> type;
//     static const T value = v;
//     operator T() { return value; }
// };

// typedef integral_constant<bool,true> true_type;
// typedef integral_constant<bool,false> false_type;

// template<typename T>
// struct is_integral : public false_type{};

// template<>
// struct is_integral<char> : public true_type{};

// S_F_I_N_A_E Substitution Failure Is Not An Error.
template <typename T, typename U>
T plantilla(U argu) { return static_cast<T>(argu); }

template <typename T, typename U>
T plantilla(typename U::value_type argu) { return static_cast<T>(argu); } // SFINAE


// Esto generaria un error de ambiguedad - error: call to 'f' is ambiguous
/* void	f(int) { std::cout << "Es INT \n"; }
void	f(float) { std::cout << "Es FloAT \n"; } */

// Aprovechando el SFINAE para saber el tipo en tiempo de compilacion.
// template<class T, typename enable_if<is_integral<T>::value, T>::type* = nullptr>
// void f(T) { std::cout << "entero\n"; }


// template<class T, typename std::enable_if<std::is_floating_point<T>::value, T>::type* = nullptr>
// void f(T) { std::cout << "flotante\n"; }


//Pequeno ejemplo
template <typename T, typename std::enable_if<std::is_integral<T>::value>::type, T> >
void	f(T argu) { std::cout << "Aqui toyu\n"; }


int	main(void)
{
	std::cout << plantilla<int, float>(42.4233) << std::endl;

	f(42);

	fmax()

	return (0);
}
