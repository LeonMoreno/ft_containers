#include <iostream>
#include <vector>

int	main ()
{
	int	arr[] = {89, 7, 100, 2, 1};
	std::vector<int> vec(arr, &arr[5]);

	// std::vector<int> vec;
	std::cout << "sizxe = " << vec.size() << std::endl;
	std::cout << "capaci = " << vec.capacity() << std::endl;

	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	// std::cout << "#### PushBack ###" << std::endl;

	for (int i = 0; i < 1000000; i++)
		vec.push_back(i);

	// vec.reserve(8);
	std::cout << "sizxe = " << vec.size() << std::endl;
	std::cout << "capaci = " << vec.capacity() << std::endl;

	// for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	// std::cout << *it << " ";
	// std::cout << std::endl;


	return (0);
}