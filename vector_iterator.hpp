#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace	ft
{
	struct	random_access_iterator_tag {};

	template <class T>
	struct	vector_iterator {
		public:
			typedef random_access_iterator_tag	iterator_category;
			typedef std::ptrdiff_t				difference_type;
			typedef T							value_type;
			typedef T*							pointer;
			typedef T&							reference;

			vector_iterator(pointer ptr);
			vector_iterator(const vector_iterator &vector_iterator_var);
			~vector_iterator();
			vector_iterator	&operator = (const vector_iterator &vector_iterator_var);

			vector_iterator	&operator ++ (void);
			vector_iterator	&operator -- (void);
			vector_iterator	operator ++ (int);
			vector_iterator	operator -- (int);
			vector_iterator	&operator += (difference_type);
			vector_iterator	&operator -= (difference_type);
			bool			operator < (vector_iterator &vector_iterator_var);
			bool			operator > (vector_iterator &vector_iterator_var);
			bool			operator <= (vector_iterator &vector_iterator_var);
			bool			operator >= (vector_iterator &vector_iterator_var);
			reference		operator * (void);
			pointer			operator -> (void);
			reference		operator [] (difference_type index);
		
		private:
			pointer	_ptr;
	};
}

#endif