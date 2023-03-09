#include "../../../include/colors.hpp"
#include "test.hpp"
#include <unistd.h>
#include <sys/time.h>
#include <iostream>

void fillVec(ft::vector<int> &vec, int range) {

	for (int i = 0; i < range; i++)
		vec.push_back(i);
}

void	ft_print_vec(ft::vector<int> &vec) {
	std::cout << "The values in the vector are (via iterator): [ ";
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		fflush(stdout);
		usleep(70000);
		std::cout << *it << " ";
	}
	std::cout << "]" << std::endl << std::endl;
}

void	vec_construct(void)
{
	std::cout << BRED << "CONSTRUCTOR TEST " << RESET << std::endl;
	std::cout << BLU << "\t Init empty vector v_01" << RESET << std::endl;
	ft::vector<int> v_01;
	ft_print_vec(v_01);

	std::cout << BLU << "\t Init Fill constructor vector v_02(5, 7)" << RESET << std::endl;
	ft::vector<int> v_02(5, 7);
	ft_print_vec(v_02);

	std::cout << BLU << "\t Init Range constructor with ptr_arry vector v_04(arr, &arr[5])" << RESET << std::endl;
	int	arr[] = {89, 7, 100, 2, 1};
	ft::vector<int> v_04(arr, &arr[5]);
	ft_print_vec(v_04);


	std::cout << BLU << "\t Copy constructor v_05  'v_05(v_02)'" << RESET  << std::endl;
	ft::vector<int> v_05(v_02);
	ft_print_vec(v_05);

	std::cout << BLU << "\t Init  assignment constructor v_06 'v_06 = v_02'" << RESET  << std::endl;
	ft::vector<int> v_06 = v_02;
	ft_print_vec(v_06);
	usleep(500000);
}

void	vec_modificadores(void)
{
	std::cout << BRED << "TEST CAPACITY & ELEM ACCESS AND MODIFIERS " << RESET << std::endl;
	std::cout << BLU << "\t Init empty vector v_01" << RESET << std::endl;
	ft::vector<int> v_01;
	ft_print_vec(v_01);
	std::cout << "Current capacity is: " << v_01.capacity() << " | current size is: " << v_01.size() << std::endl;
	std::cout << RED <<  "PUSH TO V_01 range(0 - 14) v_01.push_back(num)" << RESET << std::endl;
	fillVec(v_01, 14);
	ft_print_vec(v_01);
	std::cout << "Current capacity is: " << v_01.capacity() << " | current size is: " << v_01.size() << std::endl;
	std::cout << RED <<  "POP TO V_01 v_01.pop_back(); " << RESET << std::endl;
	v_01.pop_back();
	ft_print_vec(v_01);
	std::cout << RED <<  "RESIZE V_01 v_01.resize(50, 7); " << RESET << std::endl;
	v_01.resize(50, 7);
	ft_print_vec(v_01);
	std::cout << "Current capacity is: " << v_01.capacity() << " | current size is: " << v_01.size() << std::endl;
	std::cout  <<  "ELEMENT ACCESS V_01[5]: " << GRN << v_01[5] << RESET << std::endl;
	std::cout  <<  "ELEMENT AT V_01[2]: " << GRN << v_01.at(2) << RESET << std::endl;
	std::cout  <<  "ELEMENT FRONT V_01[2]: " << GRN << v_01.front() << RESET << std::endl;
	std::cout << RED <<  "ASSING v_01.resize(10, 1); " << RESET << std::endl;
	v_01.assign(10, 1);
	ft_print_vec(v_01);
	std::cout << "Current capacity is: " << v_01.capacity() << " | current size is: " << v_01.size() << std::endl;
	std::cout << RED <<  "ERASE v_01.erase(0, 5); " << RESET << std::endl;
	std::cout << BLU <<  "Popping half of the values from v_01" << RESET;
	for (int i = 0; i < 5; i++)
	{
		std::cout << " .";
		fflush(stdout);
		v_01.pop_back();
		usleep(200000);
	}
	std::cout << std::endl;
	std::cout << "Current capacity is: " << v_01.capacity() << " | current size is: " << v_01.size() << std::endl;
	ft_print_vec(v_01);
	usleep(500000);
}

void	vec_relope(void) {
	usleep(500000);
	std::cout << RED <<  "TESTS FOR RELATIONAL OPERATORS" << RESET << std::endl;
	std::cout << BLU << "Compare v_01 and v_02" << RESET << std::endl;
	std::cout << BLU << "\t Init empty vector v_01" << RESET << std::endl;
	ft::vector<int> v_01;
	fillVec(v_01, 14);
	std::cout << "Printing v_01: ";
	ft_print_vec(v_01);
	std::cout << "Printing v_02: ";
	ft::vector<int> v_02;
	fillVec(v_02, 5);
	ft_print_vec(v_02);
	int arr[] = {43, 2 , 42, 98, 54, 87, 7, 23};
	ft::vector<int> v_05(arr, &arr[8]);
	std::cout << "Printing v_05: ";
	ft_print_vec(v_05);
	std::cout << BLU << "Compare v_01 and v_02" << RESET << std::endl;
	std::cout << "Is 'v_01 == v_02' (should return false)? " << BLU << ((v_01 == v_02) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'v_01 != v_02' (should return true)? " << BLU << ((v_01 != v_02) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'v_01 < v_02' (should return false)? " << BLU << ((v_01 < v_02) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'v_01 <= v_02' (should return false)? " << BLU << ((v_01 <= v_02) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'v_01 > v_02' (should return true)? " << BLU << ((v_01 > v_02) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'v_01 >= v_02' (should return true)? " << BLU << ((v_01 >= v_02) ? "true" : "false") << RESET << std::endl;

	std::cout << BLU << "Compare v_02 and v_05" << RESET << std::endl;
	std::cout << "Is 'v_02 == v_05' (should return false)? " << BLU << ((v_02 == v_05) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'v_02 != v_05' (should return true)? " << BLU << ((v_02 != v_05) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'v_02 < v_05' (should return true)? " << BLU << ((v_02 < v_05) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'v_02 <= v_05' (should return true)? " << BLU << ((v_02 <= v_05) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'v_02 > v_05' (should return false)? " << BLU << ((v_02 > v_05) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'v_02 >= v_05' (should return false)? " << BLU << ((v_02 >= v_05) ? "true" : "false") << RESET << std::endl  << std::endl;
	usleep(500000);
}


int	main(void) {
	// std::cout << std::endl << BYEL << "######################## FT _MAP ###############################" << RESET << std::endl;
	usleep(520000);
	vec_construct();
	vec_modificadores();
	vec_relope();

}
