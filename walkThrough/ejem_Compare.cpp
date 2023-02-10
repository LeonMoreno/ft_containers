#include <functional>
#include <iostream>

template <typename T1, class T>
class value_compare {

	public:
		std::less<T1> comp;

		value_compare (void) : comp(std::less<T1>()) { std::cout << "Const Def\n" ; }

		bool operator() (const T& x, const T& y) const {
			return comp(x.first, y.first);
		}
};


int	main(void) {

	std::pair<int, int> *a = new std::pair<int, int>(7, 3);
	std::pair<int, int> *b= new std::pair<int, int>(15, 3);

	value_compare<int, std::pair<int, int> > compara;

	if (compara(*a, *b))
		std::cout << "a es Menor q" << std::endl;
	else
		std::cout << "a es Mayor q" << std::endl;

	// int a = 7;
	// int b = 15;

	// if (std::less<int>()(a, b))
	// 	std::cout << "a es Menor q" << std::endl;
	// else
	// 	std::cout << "a es mayor q" << std::endl;



	return (0);

}
