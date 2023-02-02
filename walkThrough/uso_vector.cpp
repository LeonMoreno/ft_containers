#include <vector>
#include <iostream>
#include <map>

struct ciudad
{
	std::string	name;
	long		populacion;
	std::string	depa;
};

int	main(void) {

	std::map<std::string, ciudad> cityMap;

	cityMap["Cali"] = ciudad { "Cali", 1000, "valle" };
	cityMap["Jamundi"] = ciudad { "Jamundi", 544, "valle" };

	std::cout << "populacion jaundi = " << cityMap["Jamundi"].populacion << std::endl;

	return (0);
}
