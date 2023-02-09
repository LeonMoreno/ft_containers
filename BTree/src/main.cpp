#include <iostream>
#include "BTree.hpp"

template <class T>
struct key_compare {

	std::less<int> comp;

	key_compare() : comp(std::less<int>()) { }

	bool operator() (T& x, T& y) {
		return comp(x.first, y.first);
	}
};

void	test(key_compare<std::pair<int, int> >& compare) {
	std::pair<int, int> *a = new std::pair<int, int>(43, 56);
	std::pair<int, int> *b = new std::pair<int, int>(32, 8);

	if (compare(*a, *b))
		std::cout << "a es menor \n";
	else
		std::cout << "a es mayor \n";

}

int	main(void) {

	key_compare<std::pair<int, int> > compare;
	// test(compare); // Test obj compare funciona.
	std::allocator< ft::BTree<std::pair<int, int> > > alloc;

	ft::BTree<std::pair<int, int> > *root = NULL;

	std::pair<int, int> b(32, 8);

	BTree_InsertNode(&root, b, compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(43, 4), compare, alloc );


	std::cout << root->pair.second << std::endl;

	return (0);
}
