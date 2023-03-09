#include "../../../include/colors.hpp"
#include "test.hpp"
#include <unistd.h>
#include <sys/time.h>
#include <iostream>

int	main(void) {

	// std::cout << std::endl << BYEL << "######################## FT _MAP ###############################" << RESET << std::endl;
	usleep(520000);

	ft::map<int, int> leo;

	for (int i = 0; i < 10; i++)
		leo.insert(ft::make_pair(i, 98));

	ft::map<int, int>::iterator it = leo.begin();

	for (; it != leo.end(); it++)
		std::cout << it->first << ' ';
	std::cout << std::endl;

}
