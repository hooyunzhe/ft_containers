#ifndef REDBLACKTREE_TPP
# define  REDBLACKTREE_TPP

namespace	ft
{
	template <class T, class Compare, class Alloc>
	RedBlackTree<T, Compare, Alloc>::RedBlackTree(const compare_type &compare, const allocator_type &alloc) : _compare(compare) {
		this->_value_alloc = alloc;
		this->_node_alloc = node_allocator();
		this->_sentinel = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(this->_sentinel);
		this->_sentinel->left = this->_sentinel;
		this->_sentinel->right = this->_sentinel;
		this->_sentinel->is_sentinel = true;
		this->_root = this->_sentinel;
		this->_size = 0;
	}

	template <class T, class Compare, class Alloc>
	RedBlackTree<T, Compare, Alloc>::RedBlackTree(const RedBlackTree &redblacktree_var) : _compare(redblacktree_var._compare) {
		this->_value_alloc = redblacktree_var._value_alloc;
		this->_node_alloc = redblacktree_var._node_alloc;
		this->_sentinel = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(this->_sentinel);
		this->_sentinel->left = this->_sentinel;
		this->_sentinel->right = this->_sentinel;
		this->_sentinel->is_sentinel = true;
		this->_root = this->_sentinel;
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
		this->_sentinel = this->_node_alloc.allocate(1);
		this->_node_alloc.construct(this->_sentinel);
		this->_sentinel->left = this->_sentinel;
		this->_sentinel->right = this->_sentinel;
		this->_sentinel->is_sentinel = true;
		this->_root = this->_sentinel;
		this->copy_tree(redblacktree_var._root);
		return (*this);
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
		return (iterator(this->_sentinel->left));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::const_iterator	RedBlackTree<T, Compare, Alloc>::begin(void) const {
		return (const_iterator(this->_sentinel->left));
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
		if (!node->is_sentinel) {
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
		if (current->parent != nullptr) {
			this->insert(*(current->value));
			this->copy_tree(current->left);
			this->copy_tree(current->right);
		}
	}

	template <class T, class Compare, class Alloc>
	void	RedBlackTree<T, Compare, Alloc>::clear_tree(node_pointer current) {
		if (current == this->_root) {
			this->_root = this->_sentinel;
			this->_sentinel->left = this->_sentinel;
			this->_sentinel->right = this->_sentinel;
		}
		if (!current->is_sentinel) {
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
		if (!node->right->is_sentinel) {
			node->right->parent = node;
		}
		node_right->parent = node->parent;
		if (node->parent->is_sentinel) {
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
		if (!node->left->is_sentinel) {
			node->left->parent = node;
		}
		node_left->parent = node->parent;
		if (node->parent->is_sentinel) {
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
		if (old_node->parent->is_sentinel) {
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
	typename RedBlackTree<T, Compare, Alloc>::iterator	RedBlackTree<T, Compare, Alloc>::find(value_type to_find) {
		node_pointer	found;

		found = this->find_node(to_find, this->_root);
		if (found->is_sentinel || !this->is_equals(*(found->value), to_find)) {
			return (this->end());
		}
		return (iterator(found));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::const_iterator	RedBlackTree<T, Compare, Alloc>::find(value_type to_find) const {
		node_pointer	found;

		found = this->find_node(to_find, this->_root);
		if (found->is_sentinel || !this->is_equals(*(found->value), to_find)) {
			return (this->end());
		}
		return (const_iterator(found));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::node_pointer	RedBlackTree<T, Compare, Alloc>::find_node(value_type to_find, node_pointer current) const {
		if (current->is_sentinel) {
			return (current);
		}
		if (this->less_than(to_find, *(current->value))) {
			if (current->left->is_sentinel) {
				return (current);
			}
			return (this->find_node(to_find, current->left));
		}
		else if (this->more_than(to_find, *(current->value))) {
			if (current->right->is_sentinel) {
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
		if (this->_root->is_sentinel) {
			return (this->_sentinel);
		}
		if (current->left->is_sentinel) {
			return (current);
		}
		return (this->find_minimum(current->left));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::node_pointer	RedBlackTree<T, Compare, Alloc>::find_maximum(node_pointer current) const {
		if (this->_root->is_sentinel) {
			return (this->_sentinel);
		}
		if (current->right->is_sentinel) {
			return (current);
		}
		return (this->find_maximum(current->right));
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
		node_pointer	new_node;

		to_insert = this->find_node(value, this->_root);
		if (to_insert->is_sentinel || !this->is_equals(value, *(to_insert->value))) {
			new_node = this->create_node(value);
			if (this->_sentinel->left->is_sentinel || this->less_than(value, *(this->_sentinel->left->value))) {
				this->_sentinel->left = new_node;
			}
			if (this->_sentinel->right->is_sentinel || this->more_than(value, *(this->_sentinel->right->value))) {
				this->_sentinel->right = new_node;
			}
			this->_size++;
			this->insert_node(to_insert, new_node);
			to_insert = new_node;
		}
		return (iterator(to_insert));
	}

	template <class T, class Compare, class Alloc>
	typename RedBlackTree<T, Compare, Alloc>::node_pointer	RedBlackTree<T, Compare, Alloc>::insert_node(node_pointer parent, node_pointer new_node) {
		new_node->parent = parent;
		if (parent->is_sentinel) {
			this->_root = new_node;
		}
		else if (this->less_than(*(new_node->value), *(parent->value))) {
			parent->left = new_node;
		}
		else {
			parent->right = new_node;
		}
		if (!new_node->parent->is_sentinel && !new_node->parent->parent->is_sentinel) {
			this->insert_fixup(new_node);
		}
		return (new_node);
	}

	template <class T, class Compare, class Alloc>
	int	RedBlackTree<T, Compare, Alloc>::erase(value_type value) {
		node_pointer	to_erase;

		to_erase = this->find_node(value, this->_root);
		if (!this->is_equals(value, *(to_erase->value))) {
			return (0);
		}
		this->erase_node(to_erase);
		if (to_erase == this->_sentinel->left) {
			this->_sentinel->left = this->find_minimum(this->_root);
		}
		if (to_erase == this->_sentinel->right) {
			this->_sentinel->right = this->find_maximum(this->_root);
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
		if (to_erase->left->is_sentinel) {
			last_moved = to_erase->right;
			this->transplant(to_erase, to_erase->right);
		}
		else if (to_erase->right->is_sentinel) {
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
			this->erase_fixup(last_moved);
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
	void	RedBlackTree<T, Compare, Alloc>::erase_fixup(node_pointer current) {
		node_pointer	sibling;

		while (!current->is_sentinel && current->color == BLACK) {
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
		std::swap(this->_size, redblacktree_var._size);
	}

	template <class T, class Compare, class Alloc>
	bool	operator == (const RedBlackTree<T, Compare, Alloc> &rbt_left, const RedBlackTree<T, Compare, Alloc> &rbt_right) {
		return ((rbt_left.get_size() == rbt_right.get_size()) && equal(rbt_left.begin(), rbt_left.end(), rbt_right.begin()));
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
	bool	operator >= (const RedBlackTree<T, Compare, Alloc> &rbt_left, const RedBlackTree<T, Compare, Alloc> &rbt_right) {
		return (!lexicographical_compare(rbt_left.begin(), rbt_left.end(), rbt_right.begin(), rbt_right.end()));
	}
}

#endif
