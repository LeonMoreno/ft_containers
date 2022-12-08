#include <iostream>

struct constructThisWay{};
struct constructThatsWay{};

class MyClass {
	public:
		explicit MyClass(constructThatsWay) {std::cout << "That Way\n"; }
		explicit MyClass(constructThisWay) { std::cout << "This Way\n";  };
		MyClass() { std::cout << "Default construct\n"; }
};

int	main(void)
{
	MyClass x((constructThatsWay()));

	return (0);
}
