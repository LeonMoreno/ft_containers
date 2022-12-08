
// In C++, an iterator is a class that provides a way to traverse through the elements of a container, such as a vector or list.
// The std::iterator class is a base class that defines several typedefs that are commonly used by iterators, such as iterator_category, value_type, difference_type, and pointer.
// The std::iterator_traits class is a template that allows you to obtain the typedefs of an iterator, even if the iterator class does not derive from std::iterator.
// Here is an example of how you can use std::iterator_traits to define a function that takes an iterator and prints out the type of iterator it is:

// In this example, print_iterator_type() is a function template that takes an iterator as a parameter. The function uses std::iterator_traits to obtain the iterator_category of the iterator,
// and then uses std::is_same to check if the iterator is of a specific type (such as std::input_iterator_tag or std::forward_iterator_tag). If the iterator is of the specified type,
// the function prints out a message indicating the type of iterator.

// In the main() function, we create a vector of integers and call print_iterator_type() with both the vector's begin() and cbegin() iterators.
// Because std::vector is a container that provides random access iterators, the function prints out "Random access iterator" for both iterators.

#include <iostream>
#include <iterator>
#include<vector>
#include <type_traits>

template <typename Iterator>
void print_iterator_type(const Iterator& it) {
  using iterator_category = typename std::iterator_traits<Iterator>::iterator_category;
  if (std::is_same<iterator_category, std::input_iterator_tag>::value) {
    std::cout << "Input iterator" << std::endl;
  } else if (std::is_same<iterator_category, std::output_iterator_tag>::value) {
    std::cout << "Output iterator" << std::endl;
  } else if (std::is_same<iterator_category, std::forward_iterator_tag>::value) {
    std::cout << "Forward iterator" << std::endl;
  } else if (std::is_same<iterator_category, std::bidirectional_iterator_tag>::value) {
    std::cout << "Bidirectional iterator" << std::endl;
  } else if (std::is_same<iterator_category, std::random_access_iterator_tag>::value) {
    std::cout << "Random access iterator" << std::endl;
  }
}

int main() {
  std::vector<int> v{1, 2, 3, 4, 5}; // -std=c++11
  print_iterator_type(v.begin());  // Outputs "Random access iterator"
  print_iterator_type(v.cbegin());  // Outputs "Random access iterator"

  return 0;
}
