#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>

using std::cout;
using std::endl;
using std::string;
using std::size_t;
using std::ptrdiff_t;

# include "vector_iterator.tpp"
# include "is_integral.hpp"

namespace	ft
{	
	template <class T, class Alloc = std::allocator<T> >
	class	vector {
		public:
			typedef T								value_type;
			typedef Alloc							allocator_type;
			typedef size_t							size_type;
			typedef ptrdiff_t						difference_type;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer	const_pointer;
			typedef vector_iterator<T>				iterator;
			typedef vector_iterator<const T>		const_iterator;

			explicit vector(allocator_type &alloc = allocator_type());
			explicit vector(size_type n, const reference value = value_type(), allocator_type &alloc = allocator_type());
			vector(iterator first, iterator last, allocator_type &alloc = allocator_type());
			vector(const vector &vector_var);
			~vector();
			vector	&operator = (const vector &vector_var);

		private:
			allocator_type	_alloc;
			size_t			_size;
			pointer			_start;
			pointer			_end;

	};
}

# include "vector.tpp"
// # include "vector_iterator.tpp"

#endif