/*
	"SFINAE" (substitution failure is not an error)
*/

#ifndef TYPE_TRAITS_TPP
# define TYPE_TRAITS_TPP

#include <iostream>

namespace ft {

/*------------ENABLE_IF--------------------------------------*/
// Enable type if condition is met (class template)


	template<bool, typename T = void>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

/*------------------------ is_integer------------------------------------ */

	// //Default case
	template <typename T>
	struct is_integral : std::false_type { };

	// Specializaciones para otros tipos de datos integrales
	template<> struct is_integral<bool> : std::true_type { };
	template<> struct is_integral<char> : std::true_type { };
	template<> struct is_integral<char16_t> : std::true_type { };
	template<> struct is_integral<char32_t> : std::true_type { };
	template<> struct is_integral<wchar_t> : std::true_type { };
	template<> struct is_integral<signed char> : std::true_type { };
	template<> struct is_integral<short int> : std::true_type { };
	template<> struct is_integral<int> : std::true_type { };
	template<> struct is_integral<long int> : std::true_type { };
	template<> struct is_integral<long long int> : std::true_type { };

	template<> struct is_integral<unsigned char> : std::true_type { };
	template<> struct is_integral<unsigned short int> : std::true_type { };
	template<> struct is_integral<unsigned int> : std::true_type { };
	template<> struct is_integral<unsigned long int> : std::true_type { };
	template<> struct is_integral<unsigned long long int> : std::true_type { };

	// //Default case
	// template<class T>
	// struct is_integral { static const bool value = false; };

	// //Specializaciones para cada caso de int
	// template<>
	// struct is_integral<bool> { static const bool value = true;};
	// template<>
	// struct is_integral<char> { static const bool value = true;};

	// template<>
	// struct is_integral<char16_t>{ static const bool value = true;};
	// template<>
	// struct is_integral<char32_t>{ static const bool value = true;};
	// template<>
	// struct is_integral<wchar_t> { static const bool value = true;};
	// template<>
	// struct is_integral<short int> { static const bool value = true;};
	// template<>
	// struct is_integral<int> { static const bool value = true;};
	// template<>
	// struct is_integral<long int> { static const bool value = true;};
	// template<>
	// struct is_integral<long long int> { static const bool value = true;};

	// template<>
	// struct is_integral<unsigned char> { static const bool value = true;};
	// template<>
	// struct is_integral<unsigned short int> { static const bool value = true;};
	// template<>
	// struct is_integral<unsigned int> { static const bool value = true;};
	// template<>
	// struct is_integral<unsigned long int> { static const bool value = true;};
	// template<>
	// struct is_integral<unsigned long long int> { static const bool value = true;};




} // namespace ft end

#endif
