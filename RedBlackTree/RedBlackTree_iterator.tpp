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
	bool	RedBlackTree_iterator<T>::is_sentinel(node_pointer node) const {
		return (node->parent == nullptr);
	}

	template <class T>
	typename RedBlackTree_iterator<T>::node_pointer	RedBlackTree_iterator<T>::find_minimum(node_pointer current) const {
		if (this->is_sentinel(current) || this->is_sentinel(current->left)) {
			cout << "STOP\n";
			return (current);
		}
		return (this->find_minimum(current->left));
	}

	template <class T>
	typename RedBlackTree_iterator<T>::node_pointer	RedBlackTree_iterator<T>::find_maximum(node_pointer current) const {
		if (this->is_sentinel(current) || this->is_sentinel(current->right)) {
			return (current);
		}
		return (this->find_maximum(current->right));
	}

	template <class T>
	void	RedBlackTree_iterator<T>::increment_node(void) {
		node_pointer	parent;

		if (this->is_sentinel(this->node_ptr)) {
			this->node_ptr = this->node_ptr->left;
		}
		else if (this->is_sentinel(this->node_ptr->right)) {
			parent = this->node_ptr->parent;
			while (parent->right == this->node_ptr) {
				this->node_ptr = parent;
				parent = this->node_ptr->parent;
			}
			this->node_ptr = parent;
		}
		else {
			this->node_ptr = this->find_minimum(this->node_ptr->right);
		}
	}

	template <class T>
	void	RedBlackTree_iterator<T>::decrement_node(void) {
		node_pointer	parent;

		if (this->is_sentinel(this->node_ptr)) {
			this->node_ptr = this->node_ptr->right;
		}
		else if (this->is_sentinel(this->node_ptr->left)) {
			parent = this->node_ptr->parent;
			while (parent->left == this->node_ptr) {
				this->node_ptr = parent;
				parent = this->node_ptr->parent;
			}
			this->node_ptr = parent;
		}
		else {
			this->node_ptr = this->find_maximum(this->node_ptr->left);
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