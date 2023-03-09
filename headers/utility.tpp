#ifndef UTILITY_TPP
# define UTILITY_TPP

#include <iostream>
// #include <type_traits> // C++11

namespace ft {

/*------------------------ ft::pair ------------------------------------ */
// https://cplusplus.com/reference/utility/pair/

	template <class T1, class T2>
	struct pair {


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
