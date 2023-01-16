#include "vector.hpp"
#include "utils.hpp"
#include "colors.hpp"
#include <unistd.h>
#include <vector>
#include <iterator>

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

void	vec_construct(void)
{
	std::cout << BRED << "CONSTRUCTOR TEST " << RESET << std::endl;
	std::cout << BLU << "\t Init empty vector v_01" << RESET << std::endl;
	ft::vector<int> v_01;
	ft_print_vec(v_01);

	std::cout << BLU << "\t Init Fill constructor vector v_02(5, 7)" << RESET << std::endl;
	ft::vector<int> v_02(5, 7);
	ft_print_vec(v_02);

	std::cout << BLU << "\t Init Range constructor with iterator vector v_03(v_02.begin() + 1, v_02.end() - 1)" << RESET << std::endl;
	ft::vector<int> v_03(v_02.begin() +1, v_02.end() - 1);
	ft_print_vec(v_03);

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

	int	arr[] = {89, 7, 100, 2, 1, 43, 28, 109};
	// int	arr2[] = {100, 200, 300, 400, 500, 600, 700};
	ft::vector<int> vec(arr, &arr[8]);
	// ft::vector<int> vec;
	ft::vector<int>::iterator pos = vec.begin();
	std::cout << "sizee = " << vec.size() << std::endl;
	std::cout << "capaci = " << vec.capacity() << std::endl;
	ft_print_vec(vec);

	// // for (int i = 0; i < 100000; i++)
	// // 	vec.push_back(i);

	// 	vec.push_back(98);
	// 	vec.push_back(43);
	// 	vec.push_back(100);
	// 	vec.push_back(200);

	// vec.insert(pos + 1, 7, 69);
	// vec.insert(pos + 1, arr2, &arr2[1]);
	// vec.erase(pos + 2);
	vec.erase(pos + 1, pos + 2);



	// vec.assign(3, 7);

	std::cout << "size = " << vec.size() << std::endl;
	std::cout << "capaci = " << vec.capacity() << std::endl;
	ft_print_vec(vec);





	return (0);
}
