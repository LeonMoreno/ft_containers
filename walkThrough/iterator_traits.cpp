#include <iostream>
#include <iterator>
#include <typeinfo>

int	main()
{
	typedef std::iterator_traits<int*> traits;
	if (typeid(traits::iterator_category) == typeid(std::random_access_iterator_tag))
		std::cout << "voila\n";
	return (0);
}
