#ifndef LEXICOGRAPHICAL_COMPARE
# define LEXICOGRAPHICAL_COMPARE

namespace	ft {
	template <class Iter1, class Iter2>
	bool	lexicographical_compare(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2) {
		while (first1 != last1) {
			if (first2 == last2 || *first1 > *first2) {
				return (false);
			}
			else if (*first1 < *first2) {
				return (true);
			}
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
}

#endif
