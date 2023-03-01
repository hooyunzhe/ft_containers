#ifndef REDBLACKTREE_ITERATOR_TPP
# define REDBLACKTREE_ITERATOR_TPP

namespace	ft
{
	template <class T>
	RedBlackTree_iterator<T>::RedBlackTree_iterator() {}

	template <class T>
	RedBlackTree_iterator<T>::RedBlackTree_iterator(node_pointer node_ptr_var) {
		this->node_ptr = node_ptr_var;
	}

	template <class T>
	RedBlackTree_iterator<T>::RedBlackTree_iterator(const RedBlackTree_iterator<typename remove_const<T>::type> &redblacktree_iterator_var) {
		*this = redblacktree_iterator_var;
	}

	template <class T>
	RedBlackTree_iterator<T>::~RedBlackTree_iterator() {}

	template <class T>
	RedBlackTree_iterator<T>	&RedBlackTree_iterator<T>::operator = (const RedBlackTree_iterator<typename remove_const<T>::type> &redblacktree_iterator_var) {
		this->node_ptr = redblacktree_iterator_var.node_ptr;
		return (*this);
	}

	template <class T>
	typename RedBlackTree_iterator<T>::node_pointer	RedBlackTree_iterator<T>::find_minimum(node_pointer current) const {
		if (current->left->is_sentinel) {
			return (current);
		}
		return (this->find_minimum(current->left));
	}

	template <class T>
	typename RedBlackTree_iterator<T>::node_pointer	RedBlackTree_iterator<T>::find_maximum(node_pointer current) const {
		if (current->right->is_sentinel) {
			return (current);
		}
		return (this->find_maximum(current->right));
	}


	template <class T>
	void	RedBlackTree_iterator<T>::increment_node(void) {
		node_pointer	parent;

		if (this->node_ptr->is_sentinel) {
			this->node_ptr = this->node_ptr->left;
		}
		else if (!this->node_ptr->right->is_sentinel) {
			this->node_ptr = this->find_minimum(this->node_ptr->right);
		}
		else {
			parent = this->node_ptr->parent;
			while (parent->right == this->node_ptr) {
				this->node_ptr = parent;
				parent = this->node_ptr->parent;
			}
			this->node_ptr = parent;
		}
	}

	template <class T>
	void	RedBlackTree_iterator<T>::decrement_node(void) {
		node_pointer	parent;

		if (this->node_ptr->is_sentinel) {
			this->node_ptr = this->_node_ptr->right;
		}
		else if (!this->node_ptr->left->is_sentinel) {
			this->node_ptr = this->find_maximum(this->node_ptr->left);
		}
		else {
			parent = this->node_ptr->parent;
			while (parent->left == this->node_ptr) {
				this->node_ptr = parent;
				parent = this->node_ptr->parent;
			}
			this->node_ptr = parent;
		}
	}

	template <class T>
	RedBlackTree_iterator<T>	&RedBlackTree_iterator<T>::operator ++ (void) {
		this->increment_node();
		return (*this);
	}

	template <class T>
	RedBlackTree_iterator<T>	&RedBlackTree_iterator<T>::operator -- (void) {
		this->decrement_node();
		return (*this);
	}

	template <class T>
	RedBlackTree_iterator<T>	RedBlackTree_iterator<T>::operator ++ (int) {
		RedBlackTree_iterator	temp(*this);

		this->increment_node();
		return (temp);
	}

	template <class T>
	RedBlackTree_iterator<T>	RedBlackTree_iterator<T>::operator -- (int) {
		RedBlackTree_iterator	temp(*this);

		this->decrement_node();
		return (temp);
	}

	template <class T>
	typename RedBlackTree_iterator<T>::reference	RedBlackTree_iterator<T>::operator * (void) const {
		return (*(this->node_ptr->value));
	}

	template <class T>
	typename RedBlackTree_iterator<T>::pointer	RedBlackTree_iterator<T>::operator -> (void) const {
		return (this->node_ptr->value);
	}

	template <class T, class U>
	bool	operator == (const RedBlackTree_iterator<T> &it1, const RedBlackTree_iterator<U> &it2) {
		return (it1.node_ptr == it2.node_ptr);
	}

	template <class T, class U>
	bool	operator != (const RedBlackTree_iterator<T> &it1, const RedBlackTree_iterator<U> &it2) {
		return (it1.node_ptr != it2.node_ptr);
	}
}

#endif
