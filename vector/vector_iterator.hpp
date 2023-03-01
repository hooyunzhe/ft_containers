#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "../utils/remove_const.hpp"

namespace	ft
{
	struct	random_access_iterator_tag {};

	template <class T>
	struct	vector_iterator {
		typedef random_access_iterator_tag	iterator_category;
		typedef std::ptrdiff_t				difference_type;
		typedef T							value_type;
		typedef T*							pointer;
		typedef T&							reference;

		vector_iterator();
		vector_iterator(typename remove_const<T>::type *ptr);
		vector_iterator(const vector_iterator<typename remove_const<T>::type> &vector_iterator_var);
		~vector_iterator();
		vector_iterator	&operator = (const vector_iterator<typename remove_const<T>::type> &vector_iterator_var);

		vector_iterator	&operator ++ (void);
		vector_iterator	&operator -- (void);
		vector_iterator	operator ++ (int);
		vector_iterator	operator -- (int);
		vector_iterator	&operator += (difference_type val);
		vector_iterator	&operator -= (difference_type val);
		reference		operator * (void);
		pointer			operator -> (void);
		reference		operator [] (difference_type index);
		
		pointer	_ptr;
	};
}

# include "vector_iterator.tpp"

#endif