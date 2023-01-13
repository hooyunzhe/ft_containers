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
# include "reverse_iterator.hpp"
# include "is_integral.hpp"

namespace	ft
{	
	template <class T, class Alloc = std::allocator<T> >
	class	vector {
		public:
			typedef T									value_type;
			typedef Alloc								allocator_type;
			typedef size_t								size_type;
			typedef ptrdiff_t							difference_type;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef value_type*							pointer;
			typedef const value_type*					const_pointer;
			typedef vector_iterator<T>					iterator;
			typedef vector_iterator<const T>			const_iterator;
			typedef reverse_iterator<iterator>			reverse_iterator;
			typedef reverse_iterator<const_iterator>	const_reverse_iterator;

			explicit vector(allocator_type &alloc = allocator_type());
			explicit vector(size_type n, const_reference value = value_type(), allocator_type &alloc = allocator_type());
			vector(iterator first, iterator last, allocator_type &alloc = allocator_type());
			vector(const vector &vector_var);
			~vector();
			vector	&operator = (const vector &vector_var);

			void	assign(size_type count, const_reference value);
			void	assign(iterator first, iterator last);
			allocator_type	get_allocator(void) const;

			reference	at(size_type index);
			const_reference	at(size_type index) const;
			reference	operator [] (size_type index);
			const_reference	operator [] (size_type index) const;
			reference	front(void);
			const_reference	front(void) const;
			reference	back(void);
			const_reference	back(void) const;
			pointer	data(void);
			const_pointer	data(void) const;

			iterator	begin(void);
			const_iterator	begin(void) const;
			iterator	end(void);
			const_iterator	end(void) const;
			reverse_iterator	rbegin(void);
			const_reverse_iterator	rbegin(void) const;
			reverse_iterator	rend(void);
			const_reverse_iterator	rend(void) const;

			bool	empty(void) const;
			size_type	size(void) const;
			size_type	max_size(void) const;
			void	reserve(size_type new_capacity);
			size_type	capacity(void) const;
			
			void	clear(void);
			iterator	insert(iterator pos, const_reference value);
			void	insert(iterator pos, size_type count, const_reference value);
			template <class Iter>
			void	insert(iterator pos, Iter first, Iter last);
			iterator	erase(iterator pos);
			iterator	erase(iterator first, iterator last);
			void	push_back(const_reference value);
			void	pop_back(void);
			void	resize(size_type new_size, value_type value = value_type());
			void	swap(vector &vector_var);

		private:
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;

	};
}

# include "vector.tpp"

#endif