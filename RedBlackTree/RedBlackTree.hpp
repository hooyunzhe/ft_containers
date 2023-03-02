#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP

# include <iostream>
# include <string>
# include "RedBlackTree_iterator.hpp"
# include "RedBlackTreeNode.hpp"
# include "../utils/reverse_iterator.hpp"
# include "../utils/lexicographical_compare.hpp"
# include "../utils/equal.hpp"

# define BLK	"\e[0;30m"
# define RD		"\e[0;31m"
# define RESET		"\e[0m"

using std::cout;
using std::endl;
using std::string;

namespace	ft
{
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class	RedBlackTree {
		public:
			typedef T																value_type;
			typedef Compare															compare_type;
			typedef Alloc															allocator_type;
			typedef size_t															size_type;
			typedef ft::RedBlackTreeNode<T>*										node_pointer;
			typedef typename Alloc::template rebind<RedBlackTreeNode<T> >::other	node_allocator;
			typedef ft::RedBlackTree_iterator<T>									iterator;
			typedef ft::RedBlackTree_iterator<const T>								const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;

			RedBlackTree(const compare_type &compare, const allocator_type &alloc);
			RedBlackTree(const RedBlackTree &redblacktree_var);
			~RedBlackTree();
			RedBlackTree	&operator = (const RedBlackTree &redblacktree_var);

			compare_type	get_compare(void) const;
			node_pointer	get_root(void) const;
			size_type		get_size(void) const;

			iterator				begin(void);
			const_iterator			begin(void) const;
			iterator				end(void);
			const_iterator			end(void) const;
			reverse_iterator		rbegin(void);
			const_reverse_iterator	rbegin(void) const;
			reverse_iterator		rend(void);
			const_reverse_iterator	rend(void) const;

			void	print_tree(node_pointer node, string prefix = "", bool is_right = false) const;
			void	copy_tree(node_pointer current);
			void	clear_tree(node_pointer current);

			bool	less_than(value_type value1, value_type value2) const;
			bool	more_than(value_type value1, value_type value2) const;
			bool	is_equals(value_type value1, value_type value2) const;

			void	left_rotate(node_pointer node);
			void	right_rotate(node_pointer node);
			void	transplant(node_pointer old_node, node_pointer new_node);

			iterator		find(value_type to_find);
			const_iterator	find(value_type to_find) const;
			node_pointer	find_node(value_type to_find, node_pointer current) const;
			node_pointer	find_minimum(node_pointer current) const;
			node_pointer	find_maximum(node_pointer current) const;
			node_pointer	create_node(value_type value);

			iterator		insert(value_type value);
			node_pointer	insert_node(node_pointer parent, node_pointer new_node);
			int				erase(value_type value);
			void			erase_node(node_pointer to_erase);

			void	insert_fixup(node_pointer current);
			void	erase_fixup(node_pointer current);

			void	swap(RedBlackTree &redblacktree_var);

		private:
			allocator_type	_value_alloc;
			node_allocator	_node_alloc;
			compare_type	_compare;
			node_pointer	_sentinel;
			node_pointer	_root;
			size_type		_size;
	};
}

# include "RedBlackTree.tpp"

#endif
