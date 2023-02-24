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

std::pair<int, int>	*new_pair(int x, int y) {

	std::pair<int, int> *a = new std::pair<int, int>(x, y);

	return (a);
}

int	main(void) {

	key_compare<std::pair<int, int> > compare;
	// test(compare); // Test obj compare funciona.
	std::allocator< ft::BTree<std::pair<int, int> > > alloc;

	ft::BTree<std::pair<int, int> > *root = NULL;

	// BTree_InsertNode(&root, new_pair(30, 98), compare, alloc );

	// BTree_InsertNode(&root, new_pair(60, 4), compare, alloc );

	// BTree_InsertNode(&root, new_pair(90, 4), compare, alloc );


	// BTree_InsertNode(&root, new_pair(98, 98), compare, alloc );
	// BTree_InsertNode(&root, new_pair(38, 4) , compare, alloc);
	// BTree_InsertNode(&root, new_pair(74, 4) , compare, alloc);
	// BTree_InsertNode(&root, new_pair(105, 4) , compare, alloc);
	// BTree_InsertNode(&root, new_pair(25, 4) , compare, alloc);
	// BTree_InsertNode(&root, new_pair(31, 4) , compare, alloc);
	// BTree_InsertNode(&root, new_pair(37, 4) , compare, alloc);
	// BTree_InsertNode(&root, new_pair(76, 4) , compare, alloc);
	// BTree_InsertNode(&root, new_pair(71, 4) , compare, alloc);
	// BTree_InsertNode(&root, new_pair(101, 4), compare, alloc );
	// BTree_InsertNode(&root, new_pair(100, 4), compare, alloc );
	// BTree_InsertNode(&root, new_pair(99, 4), compare, alloc );
	// BTree_InsertNode(&root, new_pair(107, 4), compare, alloc );
	// BTree_InsertNode(&root, new_pair(180, 4), compare, alloc );



	BTree_Print(root, "", false);


	// BTree_TraverseInOrder(root);
	// std::cout << std::endl;

	// ft::BTree<std::pair<int, int> > *succesor = inorderSuccessor(root, 93);

	// std::cout << "INMain root = " << root << std::endl;

	// if (succesor != NULL)
	// 	std::cout << "successor " << succesor->pair->first << std::endl;
	// BTree_deleteNode(root, 41, alloc);
	// BTree_TraverseInOrder(root);
	// std::cout << std::endl;

	// std::cout << "End_Main = " <<	 BTree_endInOrder(root)->pair.first << std::endl;

	return (0);
}
