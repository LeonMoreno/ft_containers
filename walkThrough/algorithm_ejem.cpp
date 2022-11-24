#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cassert>
#include <map>
#include <numeric>
#include <regex>
#include <cstdlib>



void	ejem_char()
{
	char s[] = "Hola mi leo bello";
	int	len = strlen(s);
	char* f;

	// Busqueda por la 1ra ocurrencia de l
	f = std::find(&s[0], &s[len], 'l');
	assert(*f == 'l' && *(f + 1) == 'a');
	std::cout << "--- ok." << std::endl;
}

template <typename Container>
Container	ft_make(const char s[])
{
	return (Container(&s[0], &s[strlen(s)]));
}

void	ejem_vector()
{
	std::vector<char> v = ft_make <std::vector<char> >("Hola mi leo bello");
	std::vector<char>::iterator f;
	f = find(v.begin(), v.end(), 'l');
	assert(*f == 'l' && *(f + 1) == 'a');
	std::cout << "--- ok." << std::endl;

}

void	ejem_accumulate()
{
	int	arr[] = {1, 2};
	// inicializo vecotr a arr[0] hasta arr[1]
	std::vector<int> v(arr, &arr[2]);

	int sum = std::accumulate(v.begin(), v.end(), 0);

	std::cout << "sum = " << sum << std::endl;
}

void	ejem_accumulate1()
{
	int	arr[] = {1, 2};
	// inicializo vecotr a arr[0] hasta arr[1]
//	std::vector<int> v(arr, &arr[2]);

	int sum = std::accumulate(arr, &arr[2], 0);

	std::cout << "sum = " << sum << std::endl;
}

void	ejem_accumulate2()
{
	std::vector<char> v = ft_make <std::vector<char> >("hola");

	int sum = std::accumulate(v.begin(), v.end(), 0);

	std::cout << "sum = " << sum << std::endl;
}

int	mult(int x, int y) { return (x * y); }

void	ejem_accumulate3()
{
	int	arr[] = {1, 2, 3};
	std::vector<int> v(arr, &arr[3]);

	int sum = std::accumulate(v.begin(), v.end(), 1, mult);

	std::cout << "sum accumu3 = " << sum << std::endl;
}

void	ejem_find()
{
	int	arr[6] = {5, 53, 98, 7, 43, 22};

	int	*ptr = std::find(arr, &arr[6], 7);
	assert(*ptr == 7 && *(ptr + 1) == 43);
	std::cout << "--- ok." << std::endl;

	std::list<int> list1(arr, &arr[6]);

	std::list<int>::iterator i = find(list1.begin(), list1.end(), 7);
	assert(*i == 7 && *(++i) == 43);
	std::cout << "--- ok." << std::endl;
}


void	ejem_copy()
{
	int	arr[5] = {34, 43, 98, 87, 7};
	int	copy[5];

	std::copy(arr, &arr[5], copy);
	for (int i = 0; i < 5; i++)
		std::cout << copy[i] << ", ";
	std::cout << std::endl;

	std::vector<int> vec(arr, &arr[5]);
	std::vector<int> cp2(5);

	std::copy(vec.begin(), vec.end(), cp2.begin());
	std::vector<int>::iterator i(cp2.begin());
	// std::random_shuffle ( cp2.begin(), cp2.end() ); // funcion loca LoL
	for( ; i != cp2.end(); i++)
		std::cout << *i << ", ";
	std::cout << std::endl;
}

void	ejem_replace()
{
	std::string s = "hola mi leo bello";

	std::string out = std::regex_replace(s, std::regex("l"), "R");

	std::cout << out << std::endl;
}

void	ejem_replace2()
{
	int	a[5] = {4, 7, 8, 9, 7};

	std::replace(a, &a[5], 7, 42);
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << ", ";
	std::cout << std::endl;
}

void	ejem_reverse_copy()
{
	int	a[5] = {4, 7, 8, 9, 42};
	int cp[5];

	std::reverse_copy(a, &a[5], cp);
	for (int i = 0; i < 5; i++)
		std::cout << cp[i] << ", ";
	std::cout << std::endl;
}

void	ejem_reverse_copy_list()
{
	int	a[5] = {4, 7, 8, 9, 42};
	std::list<int> li(a, &a[5]);

	li.push_back(19);
	li.push_back(98);
	li.push_back(9);

	std::list<int>::iterator i = li.begin();
	for (; i != li.end(); i++)
		std::cout << *i << ", ";
		std::cout << std::endl;
	std::reverse(li.begin(), li.end());
	i = li.begin();
	for (; i != li.end(); i++)
		std::cout << *i << ", ";
		std::cout << std::endl;
}


int	main(void)
{
	// ejem_char();
	// ejem_vector();
	// ejem_accumulate();
	// ejem_accumulate1(); // paso directamente las direcciones del array
	// ejem_accumulate2();
	// ejem_accumulate3(); // Funciones objeto
	// ejem_find();
	// ejem_copy();
	// ejem_replace(); // es de la STL. jeje pero no era el q esta buscando.
	// ejem_replace2();
	// ejem_reverse_copy();
	// ejem_reverse_copy_list();

	std::vector<int>	vec;

	assert(vec.size() == 0);
	std::cout << "--OK" << std::endl;

	return (0);
}
