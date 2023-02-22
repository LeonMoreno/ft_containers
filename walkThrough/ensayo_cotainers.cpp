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
	std::map<int, int> mp;
	std::map<int, int>::iterator it;

	mp.insert(std::pair<int, int>(42, 100));
	mp.insert(std::pair<int, int>(54, 100));
	mp.insert(std::pair<int, int>(36, 100));
	mp.insert(std::pair<int, int>(38, 100));
	mp.insert(std::pair<int, int>(7, 100));
	mp.insert(std::pair<int, int>(64, 100));

	// city.emplace_back("jamundi", 100);
	// city.emplace_back("cali", 500);
	// city.emplace_back("santander", 700);

	for (it = mp.begin(); it != mp.end(); it++) {
			std::cout << it->first << " ";
	}
	std::cout << std::endl;

	it = mp.begin();
	it++;
	it++;
	std::cout << it->first << std::endl;

	it--;
	std::cout << it->first << std::endl;


	// std::map<std::string, ciudades> mp;

	// mp["jamundi"] = ciudades{"Jamundi", 100};


	return (0);
}
