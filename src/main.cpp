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

void	map_stl(void) {
	std::cout << "Map STL\n";

	std::map<int, int> mp;
	// std::map<int, int, std::greater<int> > mp2;
    // std::vector<int> v;


	mp.insert(std::make_pair(10, 10));
	// mp2.insert(std::make_pair(10, 10));
	// if (mp.lower_bound(11) == mp.end())
    //     v.push_back(1);
    // if (mp2.lower_bound(1) == mp2.end())
    //     v.push_back(1);
	mp.insert(std::make_pair(20, 20));
    mp.insert(std::make_pair(30, 30));
    mp.insert(std::make_pair(40, 40));
    mp.insert(std::make_pair(50, 50));
    mp.insert(std::make_pair(60, 60));
    // mp2.insert(std::make_pair(20, 20));
    // mp2.insert(std::make_pair(30, 30));
    // mp2.insert(std::make_pair(40, 40));
    // mp2.insert(std::make_pair(50, 50));
    // mp2.insert(std::make_pair(60, 60));




    std::map<int, int>::iterator it;

	for (it = mp.begin(); it != mp.end(); it++)
		std::cout << it->first << " " ;
	std::cout << std::endl;

	it = mp.upper_bound(1);

	std::cout << "Upper = " << it->first << std::endl;

	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator > ret;
	ret =  mp.equal_range(1);


	std::cout << "Equal = " << ret.first->first << std::endl;

	// for (int i = 1; i < 60; i += 10) {
	// 	std::cout << "i = " << i << std::endl;
    //     it = mp.lower_bound(i);
    //     v.push_back(it->first);
    // }

	// std::vector<int>::iterator itv;

	// for (itv = v.begin(); itv != v.end(); itv++)
	// 	std::cout << *itv << " ";
	// std::cout << std::endl;

}

void	map_ft() {

	std::cout << "Map FT\n";

	ft::map<int, int > mp;

	mp.insert(ft::make_pair(10, 10));
	mp.insert(ft::make_pair(20, 20));
    mp.insert(ft::make_pair(30, 30));
    mp.insert(ft::make_pair(40, 40));
    mp.insert(ft::make_pair(50, 50));
    mp.insert(ft::make_pair(60, 60));

	ft::map<int, int>::iterator itm = mp.begin();

	// for ( ; itm != mp.end(); itm++)
	// 	std::cout << itm->first << ' ';

	// std::cout << std::endl;

 	// itm = mp.lower_bound(7);

	mp.erase(20);

}


int	main()
{
	// std::cout << std::endl << BYEL << "######################## FT_MAP ###############################" << RESET << std::endl;
	// usleep(520000);
	// vec_construct();



	// map_stl();

	map_ft();

	// ft::map<int, int> leo;

	// leo.insert(ft::pair<int, int>(37, 98) );
	// leo.insert(ft::pair<int, int>(40, 4) );
	// leo.insert(ft::pair<int, int>(41, 4) );
	// leo.insert(ft::pair<int, int>(38, 4) );
	// leo.insert(ft::pair<int, int>(31, 7) );
	// leo.insert(ft::pair<int, int>(25, 7) );
	// leo.insert(ft::pair<int, int>(34, 7) );
	// leo.insert(ft::pair<int, int>(7, 7) );
	// leo.insert(ft::pair<int, int>(74, 7) );
	// leo.insert(ft::pair<int, int>(93, 7) );
	// leo.insert(ft::pair<int, int>(92, 7) );
	// leo.insert(ft::pair<int, int>(75, 7) );
	// leo.insert(ft::pair<int, int>(99, 7) );
	// leo.insert(ft::pair<int, int>(98, 7) );
	// leo.insert(ft::pair<int, int>(101, 7) );
	// leo.insert(ft::pair<int, int>(105, 7) );

	// leo.prinBTree();
	// leo.TraverseTreeIn();

	// leo.erase(37);



	// leo.prinBTree();
	std::cout << "Map FINITO\n";



	return (0);
}
