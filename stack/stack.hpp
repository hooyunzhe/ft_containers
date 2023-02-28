#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"

namespace	ft
{
	template <class T, class Container = ft::vector<T> >
	class	stack {
		public:
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

			explicit stack(const container_type &container = container_type());
			~stack();
			stack	&operator = (const stack &stack_var);

			reference	top(void);
			const_reference	top(void) const;
			container_type	data(void);
			const container_type	data(void) const;

			bool	empty(void) const;
			size_type	size(void) const;

			void	push(const_reference value);
			void	pop(void);
			void	swap(stack &stack_var);

		private:
			container_type	_container;
	};
}

# include "stack.tpp"

#endif
