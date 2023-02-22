#include <iostream>
#include <functional>

template <class T2>
class Compare {
	public:
		std::less<int> cmp;

		Compare () : cmp(std::less<int>())  { }

		bool operator() (const T2& x, const T2& y) const {
			return cmp(x.first, y.first);
		}
};

void	ensayo(Compare<std::pair<int, int> >& com) {

	std::pair<int, int> *a = new std::pair<int, int>(8, 99);
	std::pair<int, int> *b = new std::pair<int, int>(7, 99);

	if (com(*a, *b))
		std::cout << "a es menor \n";
	else
		std::cout << "a es mayor\n";

}

int	main(void) {

	Compare<std::pair<int, int> > com;

	ensayo(com);

	std::pair<int, int> a = std::make_pair<int, int>(42, 1000);
	std::pair<int, int> b = std::make_pair<int, int>(45, 65);

	std::cout << std::less<std::pair<int, int> >()(a, b) << std::endl;

	return (0);

}
