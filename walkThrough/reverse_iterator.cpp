#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#include <numeric>

int	main()
{
	std::cout << "Demostracion del algoritmo generico accumulate ";
	std::cout << "un iterator en revsersa." << std::endl;
	std::cout.precision(10);

	float	small = static_cast<float>(1.0) / (1 << 26);
	std::cout << "small = " << small << std::endl;
	float x[5] = {1.0, 3*small, 2*small, small, small};

	// inicializo el vector
	std::vector<float>	vector1(x, &x[5]);

	// recorro el vector
	std::vector<float>::iterator i(vector1.begin());

	for ( ; i != vector1.end(); i++)
		std::cout << *i << std::endl;

	float sum = std::accumulate(vector1.begin(), vector1.end(), static_cast<float>(0.0));
	std::cout << "ssum = " << sum << std::endl;

	float sum1 = std::accumulate(vector1.rbegin(), vector1.rend(), static_cast<float>(0.0));
	std::cout << "ssum1 = " << (double)sum1 << std::endl;

	return (0);

}
