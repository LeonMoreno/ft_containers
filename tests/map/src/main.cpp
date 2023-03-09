#include "../../../include/colors.hpp"
#include "test.hpp"
#include <unistd.h>
#include <sys/time.h>
#include <iostream>

template <class C>
void fillMap(ft::map<int, int, C> &mp) {

	mp.insert(ft::make_pair(16, 3));
	mp.insert(ft::make_pair(8, 3));
	mp.insert(ft::make_pair(23, 3));
	mp.insert(ft::make_pair(7, 3));
	mp.insert(ft::make_pair(19, 3));
	mp.insert(ft::make_pair(29, 3));
	mp.insert(ft::make_pair(41, 3));
	mp.insert(ft::make_pair(4, 3));
	mp.insert(ft::make_pair(11, 3));
	mp.insert(ft::make_pair(69, 3));
}

template <class C>
void	print_map(ft::map<int, int, C> &map) {
	std::cout << "The values in the MAP are (via iterator): [ ";
	for (ft::map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
		fflush(stdout);
		usleep(70000);
		std::cout << it->first << " ";
	}
	std::cout << "]" << std::endl << std::endl;
}

void	map_construct(void) {
	std::cout << BRED << "CONSTRUCTOR TEST " << RESET << std::endl;
	std::cout << BLU << "\t Init empty MAP m_01" << RESET << std::endl;
	ft::map<int, int> m_01;
	print_map(m_01);

	std::cout << std::endl << BLU << "\tInserting 10 key->value pairs in m_01: 'm_01.insert(ft::make_pair(num, num))'" << RESET  << std::endl;
	for (int i = 0; i < 10; i++)
		m_01.insert(ft::make_pair(i, 98));
	print_map(m_01);

	std::cout << BLU << "\t Init Range constructor with iterator Map: m_02(m_02.find(5) + 5, m_02.end() - 1)" << RESET << std::endl;
	ft::map<int, int> m_02((m_01.find(5)), (m_01.end()));
	print_map(m_02);

	std::cout << BLU << "\t Copy constructor 'm_03(m_02)'" << RESET  << std::endl;
	ft::map<int, int> m_03(m_02);
	print_map(m_02);

	std::cout << BLU << "\t Init  assignment constructor 'm_04 = m_01'" << RESET  << std::endl;
	ft::map<int, int> m_04 = m_01;
	print_map(m_01);

	std::cout << BLU << "\tInserting elements in m_01: 'm_01.insert(ft::make_pair(num, num))'" << RESET  << std::endl;
	std::cout << "Size before is: " << GRN << m_01.size() << RESET << std::endl;
	fillMap(m_01);
	std::cout << "Size AFter is: " << GRN << m_01.size() << RESET << std::endl;
	print_map(m_01);
	usleep(500000);
}

void	map_varios(void) {
	std::cout << BRED << "TEST FOR ITERATORS  " << RESET << std::endl;
	std::cout << BLU << "\t Init and FillMap m_01" << RESET << std::endl;
	ft::map<int, int> m_01;
	fillMap(m_01);
	print_map(m_01);
	std::cout << BLU << "\t Begin IT" << RESET << std::endl;
	ft::map<int, int>::iterator it = m_01.begin();
	std::cout << "begin IT is: " << GRN << it->first << RESET << std::endl;
	std::cout << "-- end IT is: " << GRN << (--m_01.end())->first << RESET << std::endl;
	std::cout << "Reverse IT rbegin TEST: for(reverse_it rit = m_01.rbegin(); != redn; rit++" << RESET << std::endl;
	std::cout << "The values (via reverse_iterator): [ ";
	ft::map<int, int>::reverse_iterator rit;
	for (rit = m_01.rbegin(); rit != m_01.rend(); rit++) {
		fflush(stdout);
		usleep(70000);
		std::cout << rit->first << " ";
	}
	std::cout << "]" << std::endl << std::endl;
	usleep(500000);

	std::cout << BRED << "TEST FOR CAPACITY AND DUPLICATES  " << RESET << std::endl;
	print_map(m_01);
	std::cout << "Size before is: " << GRN << m_01.size() << RESET << std::endl;
	std::cout << BLU << "\tInserting 10.000 elements in m_01: 'm_01.insert(ft::make_pair(num, num))'" << RESET  << std::endl;
	for (int i = 0; i < 10000; i++)
		m_01.insert(ft::make_pair(i, 98));
	std::cout << "Size AFter is: " << GRN << m_01.size() << RESET << std::endl;

	std::cout << "Is Map empty() ?? : " << GRN << (m_01.empty() ? "TRUE" : "FALSE") << RESET << std::endl;
	usleep(500000);
}

void	map_modifiers(void) {
	std::cout << BRED << "\nTEST FOR MODIFIERS  " << RESET << std::endl;
	std::cout << BLU << "\t Init and FillMap m_01" << RESET << std::endl;
	ft::map<int, int> m_01;
	fillMap(m_01);
	std::cout << BLU << "\t Init and FillMap m_01" << RESET << std::endl;
	print_map(m_01);
	std::cout << BLU << "\t clear the map m_01 map.clear()" << RESET << std::endl;
	m_01.clear();
	std::cout << "Size AFter is: " << GRN << m_01.size() << RESET << std::endl;
	std::cout << "Is Map empty() ?? : " << GRN << (m_01.empty() ? "TRUE" : "FALSE") << RESET << std::endl;
	std::cout << BLU << "\t insert 15 Values  m_01:  m_01.insert(ft::make_pair(num, num))" << RESET << std::endl;
	fillMap(m_01);
	m_01.insert(ft::make_pair(98, 3));
	m_01.insert(ft::make_pair(87, 3));
	m_01.insert(ft::make_pair(32, 3));
	m_01.insert(ft::make_pair(241, 3));
	m_01.insert(ft::make_pair(199, 3));
	print_map(m_01);
	std::cout << "Size AFter is: " << GRN << m_01.size() << RESET << std::endl;
	std::cout << BLU << "\t Erase  2 Values  m_01:  m_01.erase(num)" << RESET << std::endl;
	m_01.erase(98);
	m_01.erase(7);
	std::cout << "Size AFter is: " << GRN << m_01.size() << RESET << std::endl;
	print_map(m_01);

	std::cout << BRED << "\nTEST FOR SWAP  " << RESET << std::endl;
	std::cout << BLU << "\t Init and FillMap m_01" << RESET << std::endl;
	print_map(m_01);
	std::cout << "Size m_01 before is: " << GRN << m_01.size() << RESET << std::endl;

	std::cout << BLU << "\t Init and FillMap m_02" << RESET << std::endl;
	ft::map<int, int> m_02;
	for (int i = 0; i < 10; i++)
		m_02.insert(ft::make_pair(i, 98));
	print_map(m_02);
	std::cout << "Size m_02 before is: " << GRN << m_02.size() << RESET << std::endl;
	std::cout << RED << "making m_01.swap(m_02)" << RESET << std::endl;
	m_01.swap(m_02);
	std::cout << RED << "NOW The values in the m_01" << RESET << std::endl;
	print_map(m_01);
	std::cout << "Size m_01 AFTER is: " << GRN << m_01.size() << RESET << std::endl;
	std::cout << RED << "NOW The values in the m_02" << RESET << std::endl;
	print_map(m_02);
	std::cout << "Size m_01 AFTER is: " << GRN << m_02.size() << RESET << std::endl;
	usleep(500000);
}

void	map_compareClass(void) {
	std::cout << BRED << "\nTEST FOR COMPARE CLASS  " << RESET << std::endl;
	std::cout << BLU << "\t Init and FillMap m_01 with defaul std::less" << RESET << std::endl;
	std::cout << BLU << "\t ft::map<int, int> m_01" << RESET << std::endl;
	ft::map<int, int> m_01;
	fillMap(m_01);
	print_map(m_01);
	std::cout << BLU << "\t Init and FillMap m_01 with defaul std::greater" << RESET << std::endl;
	std::cout << BLU << "\t ft::map<int, int, std::greater> m_01" << RESET << std::endl;
	ft::map<int, int, std::greater<int> > m_02;
	fillMap(m_02);
	print_map(m_02);
	std::cout << BLU << "\t Init and FillMap m_01 with defaul std::plus" << RESET << std::endl;
	std::cout << BLU << "\t ft::map<int, int, std::plus> m_01" << RESET << std::endl;
	ft::map<int, int, std::plus<int> > m_03;
	fillMap(m_03);
	print_map(m_03);
	std::cout << BLU << "\t Init and FillMap m_01 with defaul std::bit_xor" << RESET << std::endl;
	std::cout << BLU << "\t ft::map<int, int, std::bit_xor> m_01" << RESET << std::endl;
	ft::map<int, int, std::bit_xor<int> > m_04;
	fillMap(m_04);
	print_map(m_04);
	usleep(500000);
}

void	map_relatinalOpe(void) {
	std::cout << BRED << "\nTEST FOR RELATIONAL OPERATORS  " << RESET << std::endl;
	std::cout << BLU << "\t Init and FillMap m_01" << RESET << std::endl;
	ft::map<int, int> m_01;
	fillMap(m_01);
	print_map(m_01);
	std::cout << BLU << "\t Init and FillMap m_02" << RESET << std::endl;
	ft::map<int, int> m_02;
	for (int i = 0; i < 10; i++)
		m_02.insert(ft::make_pair(i, 98));
	print_map(m_02);
	std::cout << BLU << "Compare m1 and m2" << RESET << std::endl;
	std::cout << "Is 'm_01 == m_02'? " << BLU << ((m_01 == m_02) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'm_01 != m_02'? " << BLU << ((m_01 != m_02) ? "true" : "false") << RESET << std::endl;
	std::cout << "Is 'm_01 < m_02'? " << BLU << ((m_01 < m_02) ? "true" : "false") << RESET << std::endl;
}


int	main(void) {

	// std::cout << std::endl << BYEL << "######################## FT _MAP ###############################" << RESET << std::endl;
	usleep(520000);

	map_construct();
	map_varios();
	map_modifiers();
	map_compareClass();
	map_relatinalOpe();
}
