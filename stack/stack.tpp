#ifndef STACK_TPP
# define STACK_TPP

namespace	ft
{
	template <class T, class Container>
	stack<T, Container>::stack(const container_type &container) {
		this->_container = container;
	}

	template <class T, class Container>
	stack<T, Container>::~stack() {}

	template <class T, class Container>
	stack<T, Container>	&stack<T, Container>::operator = (const stack &stack_var) {
		this->_container = stack_var._container;
		return (*this);
	}

	template <class T, class Container>
	typename stack<T, Container>::reference	stack<T, Container>::top(void) {
		return (this->_container.back());
	}

	template <class T, class Container>
	typename stack<T, Container>::const_reference	stack<T, Container>::top(void) const {
		return (this->_container.back());
	}

	template <class T, class Container>
	typename stack<T, Container>::container_type	stack<T, Container>::data(void) {
		return (this->_container);
	}

	template <class T, class Container>
	const typename stack<T, Container>::container_type	stack<T, Container>::data(void) const {
		return (this->_container);
	}

	template <class T, class Container>
	bool	stack<T, Container>::empty(void) const {
		return (this->_container.empty());
	}

	template <class T, class Container>
	typename stack<T, Container>::size_type	stack<T, Container>::size(void) const {
		return (this->_container.size());
	}

	template <class T, class Container>
	void	stack<T, Container>::push(const_reference value) {
		this->_container.push_back(value);
	}

	template <class T, class Container>
	void	stack<T, Container>::pop(void) {
		this->_container.pop_back();
	}

	template <class T, class Container>
	void	stack<T, Container>::swap(stack &stack_var) {
		this->_container.swap(stack_var._container);
	}

	template <class T, class Container>
	bool	operator == (const stack<T, Container> &stack_left, const stack<T, Container> &stack_right) {
		return (stack_left.data() == stack_right.data());
	}

	template <class T, class Container>
	bool	operator != (const stack<T, Container> &stack_left, const stack<T, Container> &stack_right) {
		return (stack_left.data() != stack_right.data());
	}

	template <class T, class Container>
	bool	operator < (const stack<T, Container> &stack_left, const stack<T, Container> &stack_right) {
		return (stack_left.data() < stack_right.data());
	}

	template <class T, class Container>
	bool	operator <= (const stack<T, Container> &stack_left, const stack<T, Container> &stack_right) {
		return (stack_left.data() <= stack_right.data());
	}

	template <class T, class Container>
	bool	operator > (const stack<T, Container> &stack_left, const stack<T, Container> &stack_right) {
		return (stack_left.data() > stack_right.data());
	}

	template <class T, class Container>
	bool	operator >= (const stack<T, Container> &stack_left, const stack<T, Container> &stack_right) {
		return (stack_left.data() >= stack_right.data());
	}

	template <class T, class Container>
	void	swap(stack<T, Container> &stack_left, stack<T, Container> &stack_right) {
		stack_left.swap(stack_right);
	}
}

#endif
