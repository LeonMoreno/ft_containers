#include "vector.hpp"
#include "stack.hpp"
#include "utils.hpp"
#include "colors.hpp"
#include <unistd.h>
#include <vector>
#include "map.hpp"
#include <iterator>
#include <cstdio> // (stdout)
// #include <sys/time.h>
#include <map>

#define _ratio 10000
// volatile static time_t g_start2;


// time_t timer() {
// 	struct timeval start = {};
// 	gettimeofday(&start, nullptr);
// 	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
// 	return msecs_time;
// }


void	ft_print_vec(ft::vector<int> &vec)
{
	std::cout << "The values in the vector are (via iterator): [ ";
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		fflush(stdout);
		usleep(70000);
		std::cout << *it << " ";
	}
	std::cout << "]" << std::endl << std::endl;
}

void	std_print_vec(std::vector<int> &vec)
{
	std::cout << "The values in the vector are (via iterator): [ ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
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

	// std::cout << BLU << "\t Init Range constructor with iterator vector v_03(v_02.begin() + 1, v_02.end() - 1)" << RESET << std::endl;
	// ft::vector<int> v_03((v_02.begin() +1), (v_02.end() - 1)); // PILAS ERROR EN LiNUX
	// ft::vector<int> v_03(v_02.begin(), v_02.end());  // Ya se problema con los isintegral
	// ft_print_vec(v_03);

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

void	map_construct(void) {
	std::cout << "Map Construct\n";

	ft::map<int, int> mp;

	for (int i = 0, j = 10; i < 30 * _ratio; i++, j++)
		mp.insert(ft::make_pair(i, j));
	std::cout << "Map Fini\n";


	// mp.TraverseTreeIn();
	// std::cout << std::endl;

	// mp.prinBTree();


}

void	map_test() {

	std::map<int, int> leo;

	leo.insert(std::pair<int, int>(98, 98) );
	leo.insert(std::pair<int, int>(38, 4) );
	leo.insert(std::pair<int, int>(74, 4) );
	leo.insert(std::pair<int, int>(93, 4) );
	leo.insert(std::pair<int, int>(25, 4) );
	leo.insert(std::pair<int, int>(31, 4) );
	leo.insert(std::pair<int, int>(37, 4) );
	leo.insert(std::pair<int, int>(40, 4) );
	leo.insert(std::pair<int, int>(92, 4) );
	leo.insert(std::pair<int, int>(101, 4) );
	leo.insert(std::pair<int, int>(75, 4) );
	leo.insert(std::pair<int, int>(34, 4) );
	leo.insert(std::pair<int, int>(41, 4) );
	leo.insert(std::pair<int, int>(99, 4) );
	leo.insert(std::pair<int, int>(105, 4) );
	leo.insert(std::pair<int, int>(7, 4) );


	std::map<int, int>::iterator	it;

	it = leo.find(25);

	std::cout << "begin stl_map = " << (it--)->first << std::endl;


	// it = leo.begin();


	// for (; it != leo.end(); it++)
	// 	std::cout << "STL = " << it->first << std::endl;


}


int	main()
{
	// std::cout << std::endl << BYEL << "######################## FT_MAP ###############################" << RESET << std::endl;
	// usleep(520000);
	// vec_construct();
	map_test();
	// map_construct();

	ft::map<int, int> leo;

	leo.insert(ft::pair<int, int>(98, 98) );
	leo.insert(ft::pair<int, int>(38, 4) );
	leo.insert(ft::pair<int, int>(74, 4) );
	leo.insert(ft::pair<int, int>(93, 4) );
	leo.insert(ft::pair<int, int>(25, 4) );
	leo.insert(ft::pair<int, int>(31, 4) );
	leo.insert(ft::pair<int, int>(37, 4) );
	leo.insert(ft::pair<int, int>(40, 4) );
	leo.insert(ft::pair<int, int>(92, 4) );
	leo.insert(ft::pair<int, int>(101, 4) );
	leo.insert(ft::pair<int, int>(75, 4) );
	leo.insert(ft::pair<int, int>(34, 4) );
	leo.insert(ft::pair<int, int>(41, 4) );
	leo.insert(ft::pair<int, int>(99, 4) );
	leo.insert(ft::pair<int, int>(105, 4) );
	leo.insert(ft::pair<int, int>(7, 4) );


	ft::map<int, int>::iterator		it;


	it = leo.find(25);


	std::cout << "begin ft_map = " << (it--)->first << std::endl;

	// for (; it != leo.end(); it++)
	// 	std::cout << "FT = " << it->first << std::endl;



	// it = leo.end();
	// std::cout << "end ft_map = " << it.get_node()->parent->pair->first << std::endl;




	// leo.TraverseTreeIn();
	// std::cout << std::endl;

	// leo.prinBTree();





	return (0);
}
