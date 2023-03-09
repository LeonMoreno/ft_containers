#include "../../../include/colors.hpp"
#include "test.hpp"
#include <unistd.h>
#include <sys/time.h>
#include <iostream>


void	printStack(ft::stack<int> st) {

	ft::vector<int> vec;

	while (st.size() > 0) {
		vec.push_back(st.top());
		st.pop();
	}

	std::cout << "The values in the vector are (via iterator): [ ";
	for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		fflush(stdout);
		usleep(70000);
		std::cout << *it << " ";
	}
	std::cout << "]" << std::endl << std::endl;
}

void	stack_construct(void) {

	usleep(500000);
	std::cout << RED <<  "CONSTRUCTOR TESTS" << RESET << std::endl;
	// std::cout << BLU << "Initializing vec_01 for underlying container" << RESET << std::endl;
	ft::vector<int> v_01;

	std::cout << BLU << "Initializing stack st1'" << RESET << std::endl;
	ft::stack<int> st1;
	for (int i = 0; i < 10; i++)
		st1.push(i);
	std::cout << "Printing st1: ";
	printStack(st1);

	std::cout << BLU << "Initializing stack st2 copy constructor'st2(st1)'" << RESET  << std::endl;
	ft::stack<int> st2(st1);
	std::cout << "Printing st2: ";
	printStack(st2);

	std::cout << BLU << "Initializing stack st3 assignment 'st3 = st1'" << RESET  << std::endl;
	ft::stack<int> st3 = st1;
	std::cout << "Printing st3: ";
	printStack(st3);
	usleep(500000);

	std::cout << RED <<  "TEST MODIFIER FUNC" << RESET << std::endl;
	std::cout << "Actual size is: " << st1.size() << std::endl;
	std::cout << BLU << "Pushing integers 27 - 40 to st1.push(num)" << RESET;
	for (int i = 0; i < 5; i++)
	{
		std::cout << " .";
		fflush(stdout);
		usleep(300000);
	}
	std::cout << std::endl;
	for (int i = 27; i < 40; i++)
	{
		st1.push(i);
	}
	std::cout << "Printing st1: ";
	printStack(st1);
	std::cout << "Actual size is: " << st1.size() << std::endl;

	std::cout << BLU <<  "POP 10 elements from st.pop()" << RESET;
	for (int i = 0; i < 5; i++)
	{
		std::cout << " .";
		fflush(stdout);
		st1.pop();
		usleep(300000);
	}
	std::cout << std::endl;
	std::cout << "Printing st1: ";
	printStack(st1);
	std::cout << "Actual size is: " << st1.size() << std::endl;
	usleep(500000);
	std::cout << RED <<  "TESTS FOR ELEMENT ACCESS" << RESET << std::endl;
	std::cout << BLU << "Get top value via ' s1.top()'" << RESET << std::endl;
	std::cout << "First value is: " << st1.top() << std::endl;

	usleep(500000);

}

int	main(void) {

	// std::cout << std::endl << BYEL << "######################## FT _stack ###############################" << RESET << std::endl;
	usleep(520000);
	stack_construct();
	return (0);
}
