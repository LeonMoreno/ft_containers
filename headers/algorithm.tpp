#ifndef ALGORITHM_TPP
# define ALGORITHM_TPP

namespace ft {

	/*------------------------ equal------------------------------------ */

	/**
	 * @brief Compares the elements in the range [first1,last1) with those in the range beginning at first2,
	 *  and returns true if all of the elements in both ranges match.
	 *
	 * @param Ite first1
	 * @param Ite last1
	 * @param Ite first2
	 * @return true
	 * @return false
	 */

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {

		while (first1 != last1) 	{

			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return (true);
	}

/*------------------------ lexicographical_compare------------------------------------ */
// https://www.fluentcpp.com/2019/12/20/how-to-compare-cpp-containers/

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1; ++first2;
		}
		if (first2 != last2)
			return (true);

		// std::cout << "LLego aqui " << std::endl;

		return (false);
	}


} // end ft


#endif
