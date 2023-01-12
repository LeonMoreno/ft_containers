#include <iostream>
#include <vector>

int	main ()
{
	int	arr[] = {54, 67, 98, 2, 5};
	std::vector<int> vec(arr, &arr[5]);

	std::cout << "vec.end() = " << *(vec.end() - 1) << std::endl;

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;

	std::vector<int>::iterator tp = vec.begin();

	tp++;

	vec.assign(tp, vec.end());
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it << " ";
	std::cout << std::endl;


	return (0);
}
