#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace	ft
{
	template <class Iter>
	class	reverse_iterator {
		public:
			typedef Iter													iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef typename ft::iterator_traits<Iter>::reference			reference;

			reverse_iterator();
			explicit reverse_iterator(iterator_type it);
			template <class U>
			reverse_iterator(const reverse_iterator<U> &reverse_iterator_var);
			~reverse_iterator();
			template <class U>
			reverse_iterator<Iter>	&operator = (const reverse_iterator<U> &reverse_iterator_var);

			reverse_iterator	&operator ++ (void);
			reverse_iterator	&operator -- (void);
			reverse_iterator	operator ++ (int);
			reverse_iterator	operator -- (int);
			reverse_iterator	&operator += (difference_type val);
			reverse_iterator	&operator -= (difference_type val);
			reference			operator * (void);
			pointer				operator -> (void);
			reference			operator [] (difference_type index);

			iterator_type		base(void) const;
		
		private:
			iterator_type	_iterator;
	};
}

# include "reverse_iterator.tpp"

#endif