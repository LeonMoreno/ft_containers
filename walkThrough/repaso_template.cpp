#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

template <typename Container>
Container make(const char s[])
{
	return (Container(&s[0], &s[strlen(s)]));
}

int	main(void)
{
	// int myints[] = {16,2,77,29};
	// std::vector<int> vec(myints, myints + sizeof(myints) / sizeof(int) );
	// vec.push_back(42);

	// for (int i = 0; i < 5; i++)
	// 	std::cout << vec[i] << std::endl;

	// std::string  s = "hola mi leo bello";

	// reverse(s.begin(), s.end());

	// std::cout << s << std::endl;

	// std::vector<char> vec = make<std::vector<char> >("hola mi leo");
	// for (int i = 0; i < vec.size(); i++)
	// 	std::cout << vec[i] << " ";
	// std::cout << std::endl;
	// reverse(vec.begin(), vec.end());
	// for (int i = 0; i < vec.size(); i++)
	// 	std::cout << vec[i] << " ";
	// std::cout << std::endl;

	std::map<std::string, long> d;


	d["trujillo"] = 980980980;
	d["leo"] = 4385247278;
	d["andres"] = 3166943134;
	d["moreno"] = 3144432223;

	for (std::map<std::string, long>::iterator it = d.begin(); it != d.end(); it++)
		std::cout << it->first << " = " << it->second << std::endl;
	return(0);
}
