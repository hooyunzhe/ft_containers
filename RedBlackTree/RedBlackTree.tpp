#ifndef REDBLACKTREE_TPP
# define  REDBLACKTREE_TPP

namespace	ft
{
	template <class T, class Compare, class Alloc>
	RedBlackTree<T, Compare, Alloc>::RedBlackTree(const compare_type &compare, const allocator_type &alloc) {
		this->_value_alloc = alloc;
		this->_node_alloc = node_allocator();
		this->_compare = compare;
		this->_sentinel = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(this->_sentinel);
		this->_root = this->_sentinel;
		this->_minimum = this->_sentinel;
		this->_size = 0;
	}

	template <class T, class Compare, class Alloc>
	RedBlackTree<T, Compare, Alloc>::RedBlackTree(const RedBlackTree &redblacktree_var) {
		this->_value_alloc = redblacktree_var._value_alloc;
		this->_node_alloc = redblacktree_var._node_alloc;
		this->_compare = redblacktree_var._compare;
		this->_sentinel = redblacktree_var._sentinel;
		this->_root = redblacktree_var._sentinel;
		this->_minimum = redblacktree_var._sentinel;
		this->_size = 0;
		this->copy_tree(redblacktree_var._root);
	}

	template <class T, class Compare, class Alloc>
	RedBlackTree<T, Compare, Alloc>::~RedBlackTree() {
		this->clear_tree(this->_root);
	}

	template <class T, class Compare, class Alloc>
	RedBlackTree<T, Compare, Alloc>	&RedBlackTree<T, Compare, Alloc>::operator = (const RedBlackTree &redblacktree_var) {
		this->clear_tree(this->_root);
		this->_value_alloc = redblacktree_var._value_alloc;
		this->_node_alloc = redblacktree_var._node_alloc;
		this->_compare = redblacktree_var._compare;
		this->_sentinel = redblacktree_var._sentinel;
		this->_root = redblacktree_var._sentinel;
		this->_minimum = redblacktree_var._sentinel;
		this->copy_tree(redblacktree_var._root);
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::compare_type	RedBlackTree<T, Compare, Alloc>::get_compare(void) const {
		return (this->_compare);
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::node_pointer	RedBlackTree<T, Compare, Alloc>::get_root(void) const {
		return (this->_root);
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::size_type	RedBlackTree<T, Compare, Alloc>::get_size(void) const {
		return (this->_size);
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::iterator	RedBlackTree<T, Compare, Alloc>::begin(void) {
		return (iterator(this->_minimum));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::const_iterator	RedBlackTree<T, Compare, Alloc>::begin(void) const {
		return (const_iterator(this->_minimum));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::iterator	RedBlackTree<T, Compare, Alloc>::end(void) {
		return (iterator(this->_sentinel));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::const_iterator	RedBlackTree<T, Compare, Alloc>::end(void) const {
		return (const_iterator(this->_sentinel));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::reverse_iterator	RedBlackTree<T, Compare, Alloc>::rbegin(void) {
		return (reverse_iterator(this->end()));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::const_reverse_iterator	RedBlackTree<T, Compare, Alloc>::rbegin(void) const {
		return (const_reverse_iterator(this->end()));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::reverse_iterator	RedBlackTree<T, Compare, Alloc>::rend(void) {
		return (reverse_iterator(this->begin()));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::const_reverse_iterator	RedBlackTree<T, Compare, Alloc>::rend(void) const {
		return (const_reverse_iterator(this->begin()));
	}

	template<class T, class Compare, class Alloc>
	void	RedBlackTree<T, Compare, Alloc>::print_tree(node_pointer node, string prefix, bool is_right) const {
		if (node != this->_sentinel) {
			cout << prefix;
			if (is_right) {
				cout << "├──";
				prefix += "│   ";
			}
			else {
				cout << "└──";
				prefix += "    ";
			}
			if (node->color == RED) {
				cout << RD;
			}
			cout << *node->value << RESET << endl;
			this->print_tree(node->right, prefix, true);
			this->print_tree(node->left, prefix, false);
		}
	}

	template <class T, class Compare, class Alloc>
	void	RedBlackTree<T, Compare, Alloc>::copy_tree(node_pointer current) {
		if (current != this->_sentinel) {
			this->insert(*(current->value));
			this->copy_tree(current->left);
			this->copy_tree(current->right);
		}
	}

	template <class T, class Compare, class Alloc>
	void	RedBlackTree<T, Compare, Alloc>::clear_tree(node_pointer current) {
		if (current != this->_sentinel) {
			this->clear_tree(current->left);
			this->clear_tree(current->right);
			this->erase_node(current);
			this->_size--;
			this->_value_alloc.destroy(current->value);
			this->_value_alloc.deallocate(current->value, 1);
			this->_node_alloc.destroy(current);
			this->_node_alloc.deallocate(current, 1);
		}
	}

	template <class T, class Compare, class Alloc>
	bool	RedBlackTree<T, Compare, Alloc>::less_than(value_type value1, value_type value2) const {
		return (this->_compare(value1, value2));
	}

	template <class T, class Compare, class Alloc>
	bool	RedBlackTree<T, Compare, Alloc>::more_than(value_type value1, value_type value2) const {
		return (this->_compare(value2, value1));
	}

	template <class T, class Compare, class Alloc>
	bool	RedBlackTree<T, Compare, Alloc>::is_equals(value_type value1, value_type value2) const {
		return (!this->less_than(value1, value2) && !this->more_than(value1, value2));
	}

	template <class T, class Compare, class Alloc>
	void	RedBlackTree<T, Compare, Alloc>::left_rotate(node_pointer node) {
		node_pointer	node_right;

		node_right = node->right;
		node->right = node_right->left;
		if (node->right != this->_sentinel) {
			node->right->parent = node;
		}
		node_right->parent = node->parent;
		if (node->parent == this->_sentinel) {
			this->_root = node_right;
		}
		else if (node == node->parent->left) {
			node->parent->left = node_right;
		}
		else {
			node->parent->right = node_right;
		}
		node_right->left = node;
		node->parent = node_right;
	}

	template <class T, class Compare, class Alloc>
	void	RedBlackTree<T, Compare, Alloc>::right_rotate(node_pointer node) {
		node_pointer	node_left;

		node_left = node->left;
		node->left = node->left->right;
		if (node->left != this->_sentinel) {
			node->left->parent = node;
		}
		node_left->parent = node->parent;
		if (node->parent == this->_sentinel) {
			this->_root = node_left;
		}
		else if (node == node->parent->left) {
			node->parent->left = node_left;
		}
		else {
			node->parent->right = node_left;
		}
		node_left->right = node;
		node->parent = node_left;
	}

	template <class T, class Compare, class Alloc>
	void	RedBlackTree<T, Compare, Alloc>::transplant(node_pointer old_node, node_pointer new_node) {
		if (old_node->parent == this->_sentinel) {
			this->_root = new_node;
		}
		else if (old_node == old_node->parent->left) {
			old_node->parent->left = new_node;
		}
		else {
			old_node->parent->right = new_node;
		}
		new_node->parent = old_node->parent;
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::node_pointer	RedBlackTree<T, Compare, Alloc>::find_node(value_type to_find, node_pointer current) const {
		if (current == this->_sentinel) {
			return (current);
		}
		if (this->less_than(to_find, *(current->value))) {
			if (current->left == this->_sentinel) {
				return (current);
			}
			return (this->find_node(to_find, current->left));
		}
		else if (this->more_than(to_find, *(current->value))) {
			if (current->right == this->_sentinel) {
				return (current);
			}
			return (this->find_node(to_find, current->right));
		}
		else {
			return (current);
		}
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::node_pointer	RedBlackTree<T, Compare, Alloc>::find_minimum(node_pointer current) const {
		if (current->left == this->_sentinel) {
			return (current);
		}
		return (this->find_minimum(current->left));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::node_pointer	RedBlackTree<T, Compare, Alloc>::create_node(value_type value) {
		node_pointer	new_node;

		new_node = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(new_node);
		new_node->value = this->_value_alloc.allocate(1);
		this->_value_alloc.construct(new_node->value, value);
		new_node->color = RED;
		new_node->parent = this->_sentinel;
		new_node->left = this->_sentinel;
		new_node->right = this->_sentinel;
		return (new_node);
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::iterator	RedBlackTree<T, Compare, Alloc>::insert(value_type value) {
		node_pointer	to_insert;

		to_insert = this->find_node(value, this->_root);
		if (to_insert != this->_sentinel && this->is_equals(value, *(to_insert->value))) {
			return (iterator(to_insert));
		}
		if (this->_minimum == this->_sentinel || this->less_than(value, *(this->_minimum->value))) {
			this->_minimum = to_insert;
		}
		this->_size++;
		return (iterator(this->insert_node(to_insert, this->create_node(value))));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::node_pointer	RedBlackTree<T, Compare, Alloc>::insert_node(node_pointer parent, node_pointer new_node) {
		new_node->parent = parent;
		if (parent == this->_sentinel) {
			this->_root = new_node;
		}
		else if (this->less_than(*(new_node->value), *(parent->value))) {
			parent->left = new_node;
		}
		else {
			parent->right = new_node;
		}
		this->insert_fixup(new_node);
		return (new_node);
	}

	template <class T, class Compare, class Alloc>
	int	RedBlackTree<T, Compare, Alloc>::erase(value_type value) {
		node_pointer	to_erase;
		
		to_erase = this->find_node(value, this->_root);
		if (!this->is_equals(value, *(to_erase->value))) {
			return (0);
		}
		this->_erase_node(to_erase);
		if (to_erase == this->_minimum) {
			this->_minimum = this->find_minimum(this->_root);
		}
		this->_size--;
		this->_value_alloc.destroy(to_erase->value);
		this->_value_alloc.deallocate(to_erase->value, 1);
		this->_node_alloc.destroy(to_erase);
		this->_node_alloc.deallocate(to_erase, 1);
		return (1);
	}

	template <class T, class Compare, class Alloc>
	void	RedBlackTree<T, Compare, Alloc>::erase_node(node_pointer to_erase) {
		node_pointer	successor;
		node_pointer	last_moved;
		Color			original_color;

		successor = to_erase;
		original_color = successor->color;
		if (to_erase->left == this->_sentinel) {
			last_moved = to_erase->right;
			this->transplant(to_erase, to_erase->right);
		}
		else if (to_erase->right == this->_sentinel) {
			last_moved = to_erase->left;
			this->transplant(to_erase, to_erase->left);
		}
		else {
			successor = this->find_minimum(to_erase->right);
			original_color = successor->color;
			last_moved = successor->right;
			if (successor->parent != to_erase) {
				this->transplant(successor, successor->right);
				successor->right = to_erase->right;
				successor->right->parent = successor;
			}
			this->transplant(to_erase, successor);
			successor->left = to_erase->left;
			successor->left->parent = successor;
			successor->color = to_erase->color;
		}
		if (original_color == BLACK) {
			this->delete_fixup(last_moved);
		}
	}

	template <class T, class Compare, class Alloc>
	void	RedBlackTree<T, Compare, Alloc>::insert_fixup(node_pointer current) {
		node_pointer	parent_sibling;

		while (current->parent->color == RED) {
			if (current->parent == current->parent->parent->left) {
				parent_sibling = current->parent->parent->right;
				if (parent_sibling->color == RED) {
					current->parent->color = BLACK;
					parent_sibling->color = BLACK;
					current->parent->parent->color = RED;
					current = current->parent->parent;
				}
				else {
					if (current == current->parent->right) {
						current = current->parent;
						this->left_rotate(current);
					}
					current->parent->color = BLACK;
					current->parent->parent->color = RED;
					this->right_rotate(current->parent->parent);
				}
			}
			else {
				parent_sibling = current->parent->parent->left;
				if (parent_sibling->color == RED) {
					current->parent->color = BLACK;
					parent_sibling->color = BLACK;
					current->parent->parent->color = RED;
					current = current->parent->parent;
				}
				else {
					if (current == current->parent->left) {
						current = current->parent;
						this->right_rotate(current);
					}
					current->parent->color = BLACK;
					current->parent->parent->color = RED;
					this->left_rotate(current->parent->parent);
				}
			}
		}
		this->_root->color = BLACK;
	}

	template <class T, class Compare, class Alloc>
	void	RedBlackTree<T, Compare, Alloc>::delete_fixup(node_pointer current) {
		node_pointer	sibling;

		while (current != this->_sentinel && current->color == BLACK) {
			if (current == current->parent->left) {
				sibling = current->parent->right;
				if (sibling->color == RED) {
					sibling->color = BLACK;
					current->parent->color = RED;
					this->left_rotate(current->parent);
					sibling = current->parent->right;
				}
				if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
					sibling->color = RED;
					current = current->parent;
				}
				else {
					if (sibling->right->color == BLACK) {
						sibling->left->color = BLACK;
						sibling->color = RED;
						this->right_rotate(sibling);
						sibling = current->parent->right;
					}
					sibling->color = current->parent->color;
					current->parent->color = BLACK;
					sibling->right->color = BLACK;
					this->left_rotate(current->parent);
					current = this->_root;
				}
			}
			else {
				sibling = current->parent->left;
				if (sibling->color == RED) {
					sibling->color = BLACK;
					current->parent->color = RED;
					this->right_rotate(current->parent);
					sibling = current->parent->left;
				}
				if (sibling->right->color == BLACK && sibling->left->color == BLACK) {
					sibling->color = RED;
					current = current->parent;
				}
				else {
					if (sibling->left->color == BLACK) {
						sibling->right->color = BLACK;
						sibling->color = RED;
						this->left_rotate(sibling);
						sibling = current->parent->left;
					}
					sibling->color = current->parent->color;
					current->parent->color = BLACK;
					sibling->left->color = BLACK;
					this->right_rotate(current->parent);
					current = this->_root;
				}
			}
		}
		current->color = BLACK;
	}

	template <class T, class Compare, class Alloc>
	void	RedBlackTree<T, Compare, Alloc>::swap(RedBlackTree &redblacktree_var) {
		std::swap(this->_value_alloc, redblacktree_var._value_alloc);
		std::swap(this->_node_alloc, redblacktree_var._node_alloc);
		std::swap(this->_compare, redblacktree_var._compare);
		std::swap(this->_sentinel, redblacktree_var._sentinel);
		std::swap(this->_root, redblacktree_var._root);
		std::swap(this->_minimum, redblacktree_var._minimum);
		std::swap(this->_size, redblacktree_var._size);
	}

	template <class T, class Compare, class Alloc>
	bool	operator == (const RedBlackTree<T, Compare, Alloc> &rbt_left, const RedBlackTree<T, Compare, Alloc> &rbt_right) {
		typename RedBlackTree<T, Compare, Alloc>::iterator	current_left;
		typename RedBlackTree<T, Compare, Alloc>::iterator	current_right;
		
		if (rbt_left.get_size() != rbt_right.get_size()) {
			return (false);
		}
		current_left = rbt_left.begin();
		current_right = rbt_right.begin();
		while (current_left != rbt_left.end()) {
			if (*current_left != *current_right) {
				return (false);
			}
			current_left++;
			current_right++;
		}
		return (true);
	}

	template <class T, class Compare, class Alloc>
	bool	operator != (const RedBlackTree<T, Compare, Alloc> &rbt_left, const RedBlackTree<T, Compare, Alloc> &rbt_right) {
		return (!(rbt_left == rbt_right));
	}

	template <class T, class Compare, class Alloc>
	bool	operator < (const RedBlackTree<T, Compare, Alloc> &rbt_left, const RedBlackTree<T, Compare, Alloc> &rbt_right) {
		return (lexicographical_compare(rbt_left.begin(), rbt_left.end(), rbt_right.begin(), rbt_right.end()));
	}

	template <class T, class Compare, class Alloc>
	bool	operator <= (const RedBlackTree<T, Compare, Alloc> &rbt_left, const RedBlackTree<T, Compare, Alloc> &rbt_right) {
		return (!lexicographical_compare(rbt_right.begin(), rbt_right.end(), rbt_left.begin(), rbt_left.end()));
	}

	template <class T, class Compare, class Alloc>
	bool	operator > (const RedBlackTree<T, Compare, Alloc> &rbt_left, const RedBlackTree<T, Compare, Alloc> &rbt_right) {
		return (lexicographical_compare(rbt_right.begin(), rbt_right.end(), rbt_left.begin(), rbt_left.end()));
	}

	template <class T, class Compare, class Alloc>
	bool	operator <= (const RedBlackTree<T, Compare, Alloc> &rbt_left, const RedBlackTree<T, Compare, Alloc> &rbt_right) {
		return (!lexicographical_compare(rbt_left.begin(), rbt_left.end(), rbt_right.begin(), rbt_right.end()));
	}
}

#endif