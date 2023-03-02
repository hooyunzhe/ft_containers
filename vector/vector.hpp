#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::size_t;
using std::ptrdiff_t;

# include "vector_iterator.hpp"
# include "../utils/reverse_iterator.hpp"
# include "../utils/is_integral.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/lexicographical_compare.hpp"
# include "../utils/equal.hpp"

namespace	ft
{
	template <class T, class Alloc = std::allocator<T> >
	class	vector {
		public:
			typedef T										value_type;
			typedef Alloc									allocator_type;
			typedef size_t									size_type;
			typedef ptrdiff_t								difference_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef vector_iterator<T>						iterator;
			typedef vector_iterator<const T>				const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			explicit vector(const allocator_type &alloc = allocator_type());
			explicit vector(size_type n, const_reference value = value_type(), const allocator_type &alloc = allocator_type());
			template <class Iter>
			vector(Iter first, Iter last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<Iter>::value>::type * = 0);
			vector(const vector &vector_var);
			~vector();
			vector	&operator = (const vector &vector_var);

			void			assign(size_type count, const_reference value);
			template <class Iter>
			void			assign(Iter first, Iter last, typename ft::enable_if<!ft::is_integral<Iter>::value>::type * = 0);
			allocator_type	get_allocator(void) const;

			reference		at(size_type index);
			const_reference	at(size_type index) const;
			reference		operator [] (size_type index);
			const_reference	operator [] (size_type index) const;
			reference		front(void);
			const_reference	front(void) const;
			reference		back(void);
			const_reference	back(void) const;
			pointer			data(void);
			const_pointer	data(void) const;

			iterator				begin(void);
			const_iterator			begin(void) const;
			iterator				end(void);
			const_iterator			end(void) const;
			reverse_iterator		rbegin(void);
			const_reverse_iterator	rbegin(void) const;
			reverse_iterator		rend(void);
			const_reverse_iterator	rend(void) const;

			bool		empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;
			void		reserve(size_type new_capacity);
			size_type	capacity(void) const;

			void		clear(void);
			iterator	insert(iterator pos, const_reference value);
			void		insert(iterator pos, size_type count, const_reference value);
			template <class Iter>
			void		insert(iterator pos, Iter first, Iter last, typename ft::enable_if<!ft::is_integral<Iter>::value>::type * = 0);
			iterator	erase(iterator pos);
			iterator	erase(iterator first, iterator last);
			void		push_back(const_reference value);
			void		pop_back(void);
			void		resize(size_type new_size, value_type value = value_type());
			void		swap(vector &vector_var);

		private:
			allocator_type	_alloc;
			pointer			_ptr;
			size_type		_size;
			size_type		_capacity;
	};
}

# include "vector.tpp"

#endif
