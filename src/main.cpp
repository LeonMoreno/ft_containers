#include "vector.hpp"
#include "stack.hpp"
#include "utils.hpp"
#include "colors.hpp"
#include <unistd.h>
#include <vector>
#include <iterator>
#include <cstdio> // (stdout)
#include <sys/time.h>

#define _ratio 10000
// volatile static time_t g_start2;


time_t timer() {
	struct timeval start = {};
	gettimeofday(&start, nullptr);
	time_t msecs_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return msecs_time;
}


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

int	main()
{
	// std::cout << std::endl << BYEL << "######################## VECTOR ###############################" << RESET << std::endl;
	// usleep(520000);
	// vec_construct();
	// int	arr[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 100};
// {
// 	std::cout << std::endl << BYEL << "######################## STD::VECTOR ###############################" << RESET << std::endl;
// 	std::vector<int> vec;
// 	std::cout << "pop _size = " << vec.size() << " cap = " << vec.capacity() << std::endl;

// 	for (int i = 0; i < 4 * _ratio; i ++) {
// 		vec.push_back(i);
// 		// std::cout << "pop _size = " << vec.size() << " cap = " << vec.capacity() << std::endl;
// 	}
// 	std::cout << "pop _size = " << vec.size() << " cap = " << vec.capacity() << std::endl;
// 	vec.resize(5, 7);
// 	std::cout << "pop _size = " << vec.size() << " cap = " << vec.capacity() << std::endl;
// 	std_print_vec(vec);
// 	vec.assign(arr, &(arr[5]));
// 	std::cout << "pop _size = " << vec.size() << " cap = " << vec.capacity() << std::endl;
// 	std_print_vec(vec);
// 	for (int i = 0; i < 1 * _ratio; i ++) {
// 		vec.pop_back();
// 		std::cout << "pop _size = " << vec.size() << " cap = " << vec.capacity() << std::endl;
// 	}
// 	std_print_vec(vec);
// 	vec.insert(vec.end(), 7);
// 	std_print_vec(vec);
// 	std::cout << "pop _size = " << vec.size() << " cap = " << vec.capacity() << std::endl;
// 	vec.erase(vec.begin() + 1, vec.begin() + 3);
// 	std_print_vec(vec);
// 	std::cout << "pop _size = " << vec.size() << " cap = " << vec.capacity() << std::endl;


// }

	// ft::stack<int> stk;

	ft::vector<int> deque;
	// for (int i = 0; i < 100 * _ratio; i++)
	// 	deque.push_back(i);

	// // for (int i = 100 * _ratio; i < 200 * _ratio; ++i)
	// // 	stk.push(i);
	// // g_start2 = timer();
	// // ft::stack<int> stack(deque);
	// // ft::stack<int> stack2(stk);
	// // ft::stack<int> stack3;
	// // stack3 = stack2;
	ft::vector<int> vec2;

	vec2 = deque;




	return (0);
}
