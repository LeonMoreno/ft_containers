#include "vector.hpp"
#include <vector>
#include <iterator>


void	ejem_std()
{
	std::cout << "++++++++++++++++++ STD " << std::endl;

	std::vector<int> vex;
	std::vector<int>::iterator it;

	std::cout << "size = " << vex.size() << std::endl;
	std::cout << "capacity = " << vex.capacity() << std::endl;

	for (int i = 0; i < 10; i++)
		vex.push_back(i);

	std::cout << "size = " << vex.size() << std::endl;
	std::cout << "capacity = " << vex.capacity() << std::endl;

	for (it = vex.begin(); it != vex.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;


}

void	ejem_unitialized_copy()
{
	int	arr[] = {43, 6, 62, 98,};
	int	arr_2[] = {2, 3, 44, 54};

	std::uninitialized_copy(arr, &arr[4], arr_2);
	for (int i = 0; i < 4; i++)
		std::cout << arr_2[i] << std::endl;

}

int	main()
{
	int	arr[] = {43, 54, 65, 7};
	ft::vector<int> vec(arr, &arr[4]);

	ft::vector<int>::iterator it;

	// ft::vector<int>::iterator it;
	// // // // ft::vector<int>::reverse_iterator itr = vec.rbegin();

	// std::cout << "ft_vec size = " << vec.size() << std::endl;
	// std::cout << "ft_vec capacite = " << vec.capacity() << std::endl;
	// vec.resize(6);

	// std::cout << "size = " << vec.size() << std::endl;
	// std::cout << "Max_size = " << vec.max_size() << std::endl;


	// it = vec.begin();
	// for (it; it != vec.end(); it++)
	// 	std::cout << *it << std::endl;

	// fd::vector<int> vec1(4, 1);
	// std::vector<int> vec;

	// std::cout << "vec size = " << vec.size() << std::endl;

	// ejem_std();
	// ejem_unitialized_copy();

	return (0);
}
