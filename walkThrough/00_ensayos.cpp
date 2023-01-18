#include <iostream>
#include <vector>
#include <stack>

int	main ()
{
	// int	arr[] = {100, 200, 300, 400};
	// std::vector<int> vec(arr, &arr[4]);
	// std::vector<int> vec2(2, 7);
	// std::cout << "size = " << vec.size() << " cap = " << vec.capacity() << std::endl;
	// for (int range = 0; range < vec.size(); range++)
	// 	std::cout << vec[range] <<  " ";
	// std::cout << std::endl;

	std::stack<int> s;
	s.push(7);
	s.push(9);
	s.push(20);

	std::cout << s.top() << std::endl;

	s.pop();
	std::cout << s.top() << std::endl;





	// int	arr2[] = {54, 65, 98, 2, 7, 90, 900, 4, 874};
	// vec.insert(vec.begin() + 1, arr2, &arr2[9]);
	// std::cout << "size = " << vec.size() << " cap = " << vec.capacity() << std::endl;
	// for (int range = 0; range < vec.size(); range++)
	// 	std::cout << vec[range] <<  " ";
	// std::cout << std::endl;


	return (0);
}
