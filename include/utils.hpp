/*
	"SFINAE" (substitution failure is not an error)
*/

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
// #include <type_traits> // C++11

namespace ft {

/*------------ENABLE_IF--------------------------------------*/


	template<bool, typename T = void>
	struct enable_if {};

	template<typename T>
	struct enable_if<true, T> {
		typedef T type;
	};


/*------------------------ is_integer------------------------------------ */
	// template <typename T>
	// struct is_integral : public std::false_type { };

	// // Specializaciones para otros tipos de datos integrales
	// template<> struct is_integral<bool> : public std::true_type { };
	// template<> struct is_integral<char> : public std::true_type { };
	// template<> struct is_integral<char16_t> : public std::true_type { };
	// template<> struct is_integral<char32_t> : public std::true_type { };
	// template<> struct is_integral<wchar_t> : public std::true_type { };
	// template<> struct is_integral<signed char> : public std::true_type { };
	// template<> struct is_integral<short int> : public std::true_type { };
	// template<> struct is_integral<int> : public std::true_type { };
	// template<> struct is_integral<long int> : public std::true_type { };
	// template<> struct is_integral<long long int> : public std::true_type { };

	// template<> struct is_integral<unsigned char> : public std::true_type { };
	// template<> struct is_integral<unsigned short int> : public std::true_type { };
	// template<> struct is_integral<unsigned int> : public std::true_type { };
	// template<> struct is_integral<unsigned long int> : public std::true_type { };
	// template<> struct is_integral<unsigned long long int> : public std::true_type { };

	//Default case
	template<class T>
	struct is_integral { static const bool value = false; };

	//Specializaciones para cada caso de int
	template<>
	struct is_integral<bool> { static const bool value = true;};
	template<>
	struct is_integral<char> { static const bool value = true;};

	// template<>
	// struct is_integral<char16_t>{ static const bool value = true;};
	// template<>
	// struct is_integral<char32_t>{ static const bool value = true;};
	template<>
	struct is_integral<wchar_t> { static const bool value = true;};
	template<>
	struct is_integral<short int> { static const bool value = true;};
	template<>
	struct is_integral<int> { static const bool value = true;};
	template<>
	struct is_integral<long int> { static const bool value = true;};
	template<>
	struct is_integral<long long int> { static const bool value = true;};

	template<>
	struct is_integral<unsigned char> { static const bool value = true;};
	template<>
	struct is_integral<unsigned short int> { static const bool value = true;};
	template<>
	struct is_integral<unsigned int> { static const bool value = true;};
	template<>
	struct is_integral<unsigned long int> { static const bool value = true;};
	template<>
	struct is_integral<unsigned long long int> { static const bool value = true;};

/*------------------------ equal------------------------------------ */

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {

		while (first1 != last1) 	{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return (true);
	}

/*------------------------ lexicographical_compare------------------------------------ */
// https://www.fluentcpp.com/2019/12/20/how-to-compare-cpp-containers/

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2) {
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

/*------------------------ ft::pair ------------------------------------ */
// https://cplusplus.com/reference/utility/pair/

	template <class T1, class T2>
	class pair {
		public:

			typedef T1	first_type;
			typedef T2	second_type;

			// def constructor
			pair() : first(0), second(0) { std::cout << "default pair\n"; }

			// copy constructor
			template<class U, class V>
			pair (const pair<U,V>& pr) {
				this->first = pr.first;
				this->second = pr.second;

				// return (*this);
			};

			// init constructor
			pair (const first_type& a, const second_type& b) : first(a), second(b) { }

		// private:
			first_type	first;
			second_type	second;

	};

} // namespace ft end

#endif
