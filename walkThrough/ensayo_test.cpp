#include <iostream>
#include <map>

int	main(void) {

	std::cout << "STL Map Construct\n";

	std::map<int, int> mp;

	std::pair<std::map<int, int>::iterator, bool> pair = mp.insert(std::make_pair(7, 7));

	std::map<int, int>::iterator it = mp.begin();

	std::cout << "pair first= " << it->first << std::endl;
	std::cout << "pair first= " << it->second << std::endl;
	std::cout << "pair Pair = " << pair.first->first << std::endl;
	std::cout << "pair Pair = " << pair.first->second << std::endl;
	std::cout << "pair Pair bool = " << pair.second << std::endl;

	mp.insert(std::make_pair(9, 9));

	std::pair<std::map<int, int>::iterator, bool> pair2 = mp.insert(std::make_pair(9, 9));
	std::map<int, int>::iterator it2 = pair.first;

	std::cout << "it2 first= " << it2->first << std::endl;
	std::cout << "it2 first= " << it2->second << std::endl;
	std::cout << "pair2 Pair = " << pair2.first->first << std::endl;
	std::cout << "pair2 Pair = " << pair2.first->second << std::endl;
	std::cout << "pair2 Pair bool = " << pair2.second << std::endl;

	return (0);

}
