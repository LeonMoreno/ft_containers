#include <iostream>

class temp {
	private:
		int	_num;

	public:
		temp();
		temp(int n);
		// temp(const temp &src);
		~temp();

		int	getNum();
};

temp::temp() {
	std::cout << "Contructor" << std::endl;
}

temp::temp(int n) : _num(n) {
	std::cout << "Contructor INi" << std::endl;
}

// temp::temp(const temp &src) : _num(src._num) {
// 	std::cout << "COpy Contructor" << std::endl;
// }

temp::~temp() {
	std::cout << "Destructor" << std::endl;
}

int	temp::getNum() {
	return (this->_num);
}

int	main()
{
	temp l(7);

	temp toto(l);

	std::cout << toto.getNum() << std::endl;

	return (0);
}
