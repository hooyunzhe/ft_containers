#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>
# include <ostream>

using std::ostream;

namespace	ft {
	template <class T1, class T2>
	struct	pair {
		typedef T1	first_type;
		typedef T2	second_type;

		pair();
		pair(const first_type &first_val, const second_type &second_val);
		template <class U, class V>
		pair(const pair<U, V> &pair_var);
		pair	&operator = (const pair &pair_var);

		void	swap(pair &pair_var);

		first_type	first;
		second_type	second;
	};

	# include "pair.tpp"
}

#endif