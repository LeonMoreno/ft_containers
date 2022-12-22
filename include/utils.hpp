#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <type_traits>

namespace ft {

/*------------------------ is_integer------------------------------------ */
	template <typename T>
	struct is_integral : public std::false_type { };

	// Specializaciones para otros tipos de datos integrale
	template<> struct is_integral<bool> : public std::true_type { };
	template<> struct is_integral<char> : public std::true_type { };
	template<> struct is_integral<char16_t> : public std::true_type { };
	template<> struct is_integral<char32_t> : public std::true_type { };
	template<> struct is_integral<wchar_t> : public std::true_type { };
	template<> struct is_integral<signed char> : public std::true_type { };
	template<> struct is_integral<short int> : public std::true_type { };
	template<> struct is_integral<int> : public std::true_type { };
	template<> struct is_integral<long int> : public std::true_type { };
	template<> struct is_integral<long long int> : public std::true_type { };

	template<> struct is_integral<unsigned char> : public std::true_type { };
	template<> struct is_integral<unsigned short int> : public std::true_type { };
	template<> struct is_integral<unsigned int> : public std::true_type { };
	template<> struct is_integral<unsigned long int> : public std::true_type { };
	template<> struct is_integral<unsigned long long int> : public std::true_type { };

} // namespace ft end


#endif
