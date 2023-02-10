#include <iostream>
#include <map>
#include <vector>

// struct ciudades
// {
// 	std::string	name;
// 	int		population;

// };


int	main()
{
	// std::vector<ciudades> city;
	std::map<char, int> mp;

	mp['A'] = 7;
	mp['B'] = 9;
	mp['C'] = 11;
	mp['A'] = 25;

	// city.emplace_back("jamundi", 100);
	// city.emplace_back("cali", 500);
	// city.emplace_back("santander", 700);

	// for (std::vector<ciudades>::iterator it = city.begin(); it != city.end(); it++) {
	// 	if (it->name == "jamundi")
	// 		std::cout << " Bingo\n";
	// }

	// std::map<std::string, ciudades> mp;

	// mp["jamundi"] = ciudades{"Jamundi", 100};

	std::cout << mp['A'] << std::endl;

	return (0);
}
