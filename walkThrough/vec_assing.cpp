#include <iostream>
#include <vector>

int	main ()
{
	int	arr[] = {89, 7, 18, 2, 42, 36, 77, 1, 9};

	std::vector<int> vec1(arr, &arr[9]);

	std::cout << "size = " << vec1.size() << std::endl;
	std::cout << "cap = " << vec1.capacity() << std::endl;
	for (int range = 0; range < vec1.size(); range++)
		std::cout << vec1[range] <<  " ";
	std::cout << std::endl;

	vec1.resize(4);

	std::cout << "size = " << vec1.size() << std::endl;
	std::cout << "cap = " << vec1.capacity() << std::endl;
	for (int range = 0; range < vec1.size(); range++)
	std::cout << vec1[range] <<  " ";
	std::cout << std::endl;

	return (0);
}
