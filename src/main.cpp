#include "vector.hpp"
#include <vector>
#include <iterator>


void	ejem_std()
{
	std::cout << "++++++++++++++++++ STD " << std::endl;

	std::vector<int> vex(4, 7);
	std::vector<int>::iterator it;

	std::cout << "size = " << vex.size() << std::endl;
	for (it = vex.begin(); it != vex.end(); it++)
		std::cout << *it << std::endl;
	vex.resize(7, 8);
	std::cout << "size = " << vex.size() << std::endl;
	for (it = vex.begin(); it != vex.end(); it++)
		std::cout << *it << std::endl;


	// std::vector<int>::reverse_iterator itr = vex.rbegin();;

	// std::cout << "ITR = " << *itr << std::endl;

}

int	main()
{
	ft::vector<int> vec(4, 7);
	ft::vector<int>::iterator it;
	// ft::vector<int>::reverse_iterator itr = vec.rbegin();

	std::cout << "size = " << vec.size() << std::endl;
	vec.resize(2);

	std::cout << "size = " << vec.size() << std::endl;


	it = vec.begin();
	for (it; it != vec.end(); it++)
		std::cout << *it << std::endl;

	// fd::vector<int> vec1(4, 1);
	// std::vector<int> vec;

	// std::cout << "vec size = " << vec.size() << std::endl;

	// ejem_std();

	return (0);
}
