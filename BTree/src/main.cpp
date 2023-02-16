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

	BTree_InsertNode(&root, std::pair<int, int>(42, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(35, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(84, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(33, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(38, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(74, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(93, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(25, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(31, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(37, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(40, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(92, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(101, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(75, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(34, 4), compare, alloc );
	BTree_InsertNode(&root, std::pair<int, int>(41, 4), compare, alloc );


	BTree_TraverseInOrder(root);
	std::cout << std::endl;

	ft::BTree<std::pair<int, int> > *succesor = inorderSuccessor(root, 35);

	std::cout << "INMain root = " << root << std::endl;

	if (succesor != NULL)
		std::cout << "successor " << succesor->pair.first << std::endl;
	BTree_deleteNode(root, 41, alloc);
	BTree_TraverseInOrder(root);
	std::cout << std::endl;

	std::cout << "End_Main = " << BTree_endInOrder(root)->pair.first << std::endl;

	return (0);
}
