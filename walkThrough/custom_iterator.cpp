#include <iostream>

template <typename T>
struct Iterator {
	typedef	std::forward_iterator_tag	iterator_category;
	typedef	std::ptrdiff_t				difference_type;
	typedef	T							value_type;
	typedef	T*							pointer;
	typedef	T&							reference;

	Iterator(pointer ptr) : m_ptr(ptr) {}

	reference	operator*() const { return *m_ptr; }
	pointer		operator->() { return m_ptr; }

	// prefizx increment
	Iterator& operator++() { m_ptr++; return *this; }

	// postfix increment
	Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

	friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; }
	friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; }

	private:
		pointer	m_ptr;
};

class Integers
{
	private:
		int	_data[10];

	public:
		Iterator<int> begin() { return Iterator<int>(&_data[0]); }
		Iterator<int> end() { return Iterator<int>(&_data[10]); }
};

int	main(void)
{
	Integers ap;
	Iterator<int> it = ap.begin();

	for (int i = 0; it != ap.end(); it++, i++)
		*it = i;

	for (it = ap.begin() ; it != ap.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;

	return (0);
}
