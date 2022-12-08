#include "vector.hpp"
#include <vector>
#include <iterator>


void	ejem_std()
{
	std::cout << "++++++++++++++++++ STD " << std::endl;

	int	arr[] = {43, 87, 24, 7};
	std::vector<int> vex(arr, &arr[4]);

	std::vector<int>::reverse_iterator itr = vex.rbegin();;

	std::cout << "ITR = " << *itr << std::endl;

}

int	main()
{
	ft::vector<int> vec(8, 7);
	ft::vector<int>::iterator it;
	// ft::vector<int>::reverse_iterator itr = vec.rbegin();

	std::cout << "size = " << vec.size() << std::endl;

	// it = vec.begin();
	// for (it; it != vec.end(); it++)
	// 	std::cout << *it << std::endl;

	// fd::vector<int> vec1(4, 1);
	// std::vector<int> vec;

	// std::cout << "vec size = " << vec.size() << std::endl;

	// ejem_std();

	return (0);
}
