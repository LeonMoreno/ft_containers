#include <iostream>
#include <vector>

int	digits(int	num) {
	// int	count = 0;

	// while (num != 0)
	// {
	// 	num = num / 10;
	// 	count++;
	// }
	// return (count);
	return(log10(num) + 1);
}

int findNumbers(std::vector<int>& nums) {

	int	answ = 0;
	std::vector<int>::iterator it;

	for (it = nums.begin(); it != nums.end(); it++) {
		int res = digits(*it);
		if (res % 2 == 0)
			answ++;
	}
	return (answ);
}


int	main(void)
{
	int	arr[] = {12, 345, 2, 6, 7896};
	std::vector<int> vec(arr, &arr[5]);
	std::vector<int>::iterator it;

	// for (it = vec.begin(); it != vec.end(); it++) {
	// 	std::cout << *it << std::endl;
	// }

	std::cout << "log = " <<  log10(9) + 1 << std::endl;

	std::cout << "No pares = " <<  findNumbers(vec) << std::endl;

	return (0);
}
