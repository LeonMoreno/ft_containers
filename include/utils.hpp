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
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1; ++first2;
		}
		if (first2 != last2)
			return (true);

		// std::cout << "LLego aqui " << std::endl;

		return (false);
	}

/*------------------------ ft::pair ------------------------------------ */
// https://cplusplus.com/reference/utility/pair/

	template <class T1, class T2>
	struct pair {
		public:

			typedef T1	first_type;
			typedef T2	second_type;

		// private: // Creo que no es privado !!
			first_type	first;
			second_type	second;

			// def constructor
			pair() : first(T1()), second(T2()) { } //std::cout << "default constru pair\n"; }

			// copy constructor
			template<class U, class V>
			pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {}

			// init constructor
			pair (const first_type& a, const second_type& b) : first(a), second(b) {  } //std::cout << "INIT constru pair\n"; }

			// COPY ASSIGNMENT OPERATOR
			pair& operator= (const pair& pr) {
				this->first = pr.first;
				this->second = pr.second;

				return (*this);
			}
	};
//---------------------------Non-Member Functions ft::pair----------------------------//
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		// std::cout << "viene por estos lados ??" << std::endl;
		if (lhs.first < rhs.first)
			return (true);
		if(rhs.first < lhs.first)
		return (false);
		if (lhs.second < rhs.second)
			return (true);

		return (false);

		// return ((lhs.first < rhs.first) && (lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(rhs < lhs));
	}

	template <class T1, class T2>
	bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return (!(lhs < rhs));
	}

/*------------------------ ft::make_pair ------------------------------------ */
// https://cplusplus.com/reference/utility/pair/

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair (T1 x, T2 y) {
		return ( ft::pair<T1, T2>(x, y) );
	}

} // namespace ft end

#endif
