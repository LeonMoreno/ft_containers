#include <type_traits>
#include <iostream>

template <typename T>
struct is_integral : public std::false_type { };

// Specializaciones para otros tipos de datos integrale
template<> struct is_integral<int> : public std::true_type { };
template<> struct is_integral<float> : public std::false_type { };
template<> struct is_integral<bool> : public std::true_type { };
template<> struct is_integral<char> : public std::true_type { };
template<> struct is_integral<int64_t> : public std::true_type { };


template <int num1, int num2>
struct add {
	 static const int val = (num1 + num2);
};


class A {};

int	main()
{
	std::cout << std::boolalpha;

	std::cout << is_integral<int>::value << std::endl;
	std::cout << is_integral<float>::value << std::endl;
	std::cout << is_integral<char>::value << std::endl;
	std::cout << is_integral<bool>::value << std::endl;
	std::cout << is_integral<int64_t*>::value << std::endl;
	std::cout << is_integral<A>::value << std::endl;

	std::cout << add<42, 4>::val << std::endl;

	return (0);
	}
