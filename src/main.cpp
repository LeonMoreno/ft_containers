// #include "vector.hpp"
// #include "stack.hpp"
// #include "utils.hpp"
// #include "colors.hpp"
// #include <unistd.h>
// #include <vector>
#include "map.hpp"
// #include <iterator>
// #include <cstdio> // (stdout)
// #include <sys/time.h>
// #include <map>

#define _ratio 10000
// volatile static time_t g_start2;


// time_t timer() {
// 	struct timeval start = {};
// 	gettimeofday(&start, nullptr);
// 	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
// 	return msecs_time;
// }


// void	ft_print_vec(ft::vector<int> &vec)
// {
// 	std::cout << "The values in the vector are (via iterator): [ ";
// 	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
// 		fflush(stdout);
// 		usleep(70000);
// 		std::cout << *it << " ";
// 	}
// 	std::cout << "]" << std::endl << std::endl;
// }

// void	std_print_vec(std::vector<int> &vec)
// {
// 	std::cout << "The values in the vector are (via iterator): [ ";
// 	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
// 		fflush(stdout);
// 		usleep(70000);
// 		std::cout << *it << " ";
// 	}
// 	std::cout << "]" << std::endl << std::endl;
// }

// void	vec_construct(void)
// {
// 	std::cout << BRED << "CONSTRUCTOR TEST " << RESET << std::endl;
// 	std::cout << BLU << "\t Init empty vector v_01" << RESET << std::endl;
// 	ft::vector<int> v_01;
// 	ft_print_vec(v_01);

// 	std::cout << BLU << "\t Init Fill constructor vector v_02(5, 7)" << RESET << std::endl;
// 	ft::vector<int> v_02(5, 7);
// 	ft_print_vec(v_02);

// 	// std::cout << BLU << "\t Init Range constructor with iterator vector v_03(v_02.begin() + 1, v_02.end() - 1)" << RESET << std::endl;
// 	// ft::vector<int> v_03((v_02.begin() +1), (v_02.end() - 1)); // PILAS ERROR EN LiNUX
// 	// ft::vector<int> v_03(v_02.begin(), v_02.end());  // Ya se problema con los isintegral
// 	// ft_print_vec(v_03);

// 	std::cout << BLU << "\t Init Range constructor with ptr_arry vector v_04(arr, &arr[5])" << RESET << std::endl;
// 	int	arr[] = {89, 7, 100, 2, 1};
// 	ft::vector<int> v_04(arr, &arr[5]);
// 	ft_print_vec(v_04);


// 	std::cout << BLU << "\t Copy constructor v_05  'v_05(v_02)'" << RESET  << std::endl;
// 	ft::vector<int> v_05(v_02);
// 	ft_print_vec(v_05);

// 	std::cout << BLU << "\t Init  assignment constructor v_06 'v_06 = v_02'" << RESET  << std::endl;
// 	ft::vector<int> v_06 = v_02;
// 	ft_print_vec(v_06);
// 	usleep(500000);
// }


// template <class C>
// void	fillMap(ft::map<int, int, C> &mp) {

// 	mp.insert(ft::make_pair(16, 3));
// 	mp.insert(ft::make_pair(8, 3));
// 	mp.insert(ft::make_pair(23, 3));
// 	mp.insert(ft::make_pair(7, 3));
// 	mp.insert(ft::make_pair(19, 3));
// 	mp.insert(ft::make_pair(29, 3));
// 	mp.insert(ft::make_pair(41, 3));
// 	mp.insert(ft::make_pair(4, 3));
// 	mp.insert(ft::make_pair(11, 3));
// }


// void	map_ft() {

// 	std::cout << "\n Map FT\n";

// 	ft::map<int, int> leo;

// 	fillMap(leo);
// 	std::cout << " Map_0 std::less (default) FT \n";

// 	for (ft::map<int, int>::iterator it = leo.begin(); it != leo.end(); it++)
// 		std::cout << it->first << ' ';
// 	std::cout << std::endl;
// 	for (ft::map<int, int>::iterator it = --leo.end(); it != leo.begin(); it--)
// 		std::cout << it->first << ' ';
// 	std::cout << std::endl;

// 	// leo.prinBTree();


// 	ft::map<int, int, std::greater<int> > mp1;
// 	fillMap(mp1);

// 	std::cout << " Map_1 std::greater STL \n";
// 	for (ft::map<int, int>::iterator it = mp1.begin(); it != mp1.end(); it++)
// 		std::cout << it->first << ' ';
// 	std::cout << std::endl;

// 	std::cout << mp1.begin()->first << std::endl;
// 	mp1.erase(41);
// 	std::cout << mp1.begin()->first << std::endl;
// 	mp1.erase(29);
// 	std::cout << mp1.begin()->first << std::endl;

// 	std::cout << " Map_2 std::greater STL \n";

// 	ft::map<int, int, std::greater<int> > mp2;
// 	mp2.insert(ft::make_pair(3, 3));
// 	std::cout << mp2.begin()->first << std::endl;
// 	mp2.erase(3);
// 	if (mp2.begin() == mp2.end())
// 		std::cout << "por que ?? " << mp2.begin().get_node() << std::endl;

// 	std::cout << " Map_3 std::plus FT \n";
//     ft::map<int, int, std::minus<int> > mp3;
//     fillMap(mp3);
// 	for (ft::map<int, int>::iterator it = mp3.begin(); it != mp3.end(); it++)
// 		std::cout << it->first << ' ';
// 	std::cout << std::endl;

// 	// mp3.prinBTree();

// 	/* situacion compare
// 		-- Falla con --
// 	- std::plus
// 	- std::minus
// 	- std::multiples
// 	- std::bit_xor
// 	- std::logical_and

// 		-- BiEn con --
// 	- std::greater
// 	- std::less
// 	- std::greater_equal

// 	*/


// }

int	main()
{
	// std::cout << std::endl << BYEL << "######################## FT_MAP ###############################" << RESET << std::endl;
	// usleep(520000);
	// vec_construct();

	ft::map<int, int> leo;

	leo.insert(ft::make_pair(2, 9));
	leo.insert(ft::make_pair(897, 2));

	ft::map<int, int>::iterator it;

	it = leo.begin();

	for (; it != leo.end(); it++)
		std::cout << it->first << std::endl;

	return (0);
}
