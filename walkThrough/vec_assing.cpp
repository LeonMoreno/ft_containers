#include <iostream>
#include <vector>

int	main ()
{
	int	arr[] = {89, 7, 100, 2, 1, 43, 28, 109};

	// int	arr2[] = {100, 200, 300, 400, 500, 600, 700};
	std::vector<int> vec(arr, &arr[8]);
	std::cout << "sizxe = " << vec.size() << std::endl;
	std::cout << "capaci = " << vec.capacity() << std::endl;

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	// vec.assign(10, 7);
	std::vector<int>::iterator it = vec.begin();
	// vec.insert(it + 1, arr2, &arr2[7]);
	vec.erase(it + 1, it + 2);


	std::cout << "sizxe = " << vec.size() << std::endl;
	std::cout << "capaci = " << vec.capacity() << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it << " ";
	std::cout << std::endl;

	return (0);
}
