#ifndef REDBLACKTREE_ITERATOR_HPP
# define REDBLACKTREE_ITERATOR_HPP

# include "../utils/Node.hpp"
# include "../utils/remove_const.hpp"

using std::cout;

namespace	ft
{
	struct	bidirectional_iterator_tag {};

	template <class T>
	struct	RedBlackTree_iterator {
		typedef bidirectional_iterator_tag					iterator_category;
		typedef T											value_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef ft::Node<typename remove_const<T>::type>*	node_pointer;

		RedBlackTree_iterator();
		RedBlackTree_iterator(node_pointer ptr_var);
		RedBlackTree_iterator(const RedBlackTree_iterator<typename remove_const<T>::type> &redblacktree_iterator_var);
		~RedBlackTree_iterator();
		RedBlackTree_iterator	&operator = (const RedBlackTree_iterator<typename remove_const<T>::type> &redblacktree_iterator_var);

		bool	is_sentinel(node_pointer node) const;
		
		node_pointer	find_minimum(node_pointer current) const;
		node_pointer	find_maximum(node_pointer current) const;

		void	increment_node(void);
		void	decrement_node(void);

		RedBlackTree_iterator	&operator ++ (void);
		RedBlackTree_iterator	&operator -- (void);
		RedBlackTree_iterator	operator ++ (int);
		RedBlackTree_iterator	operator -- (int);
		reference				operator * (void) const;
		pointer					operator -> (void) const;

		node_pointer	node_ptr;
	};
}

# include "RedBlackTree_iterator.tpp"

#endif