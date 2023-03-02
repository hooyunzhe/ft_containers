#ifndef SET_TPP
# define SET_TPP

namespace	ft
{
	template <class T, class Compare, class Alloc>
	set<T, Compare, Alloc>::set(const key_compare &comp, const allocator_type &alloc) : _tree(key_compare(comp), alloc) {
		this->_compare = comp;
		this->_alloc = alloc;
	}

	template <class T, class Compare, class Alloc>
	template <class Iter>
	set<T, Compare, Alloc>::set(Iter first, Iter last, const key_compare &comp, const allocator_type &alloc) : _tree(key_compare(comp), alloc) {
		this->_compare = comp;
		this->_alloc = alloc;
		while (first != last) {
			this->insert(*first++);
		}
	}

	template <class T, class Compare, class Alloc>
	set<T, Compare, Alloc>::set(const set &set_var) : _tree(set_var._tree) {
		this->_compare = set_var._compare;
		this->_alloc = set_var._alloc;
	}

	template <class T, class Compare, class Alloc>
	set<T, Compare, Alloc>::~set() {}

	template <class T, class Compare, class Alloc>
	set<T, Compare, Alloc>	&set<T, Compare, Alloc>::operator = (const set &set_var) {
		this->_compare = set_var._compare;
		this->_alloc = set_var._alloc;
		this->_tree = set_var._tree;
		return (*this);
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::allocator_type	set<T, Compare, Alloc>::get_allocator(void) const {
		return (this->_alloc);
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::tree_type	set<T, Compare, Alloc>::get_tree(void) const {
		return (this->_tree);
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::iterator	set<T, Compare, Alloc>::begin(void) {
		return (this->_tree.begin());
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::const_iterator	set<T, Compare, Alloc>::begin(void) const {
		return (this->_tree.begin());
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::iterator	set<T, Compare, Alloc>::end(void) {
		return (this->_tree.end());
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::const_iterator	set<T, Compare, Alloc>::end(void) const {
		return (this->_tree.end());
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::reverse_iterator	set<T, Compare, Alloc>::rbegin(void) {
		return (this->_tree.rbegin());
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::const_reverse_iterator	set<T, Compare, Alloc>::rbegin(void) const {
		return (this->_tree.rbegin());
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::reverse_iterator	set<T, Compare, Alloc>::rend(void) {
		return (this->_tree.rend());
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::const_reverse_iterator	set<T, Compare, Alloc>::rend(void) const {
		return (this->_tree.rend());
	}

	template <class T, class Compare, class Alloc>
	bool	set<T, Compare, Alloc>::empty(void) const {
		return (this->_tree.get_size() == 0);
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::size_type	set<T, Compare, Alloc>::size(void) const {
		return (this->_tree.get_size());
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::size_type	set<T, Compare, Alloc>::max_size(void) const {
		return (std::numeric_limits<difference_type>::max());
	}

	template <class T, class Compare, class Alloc>
	void	set<T, Compare, Alloc>::clear(void) {
		this->_tree.clear_tree(this->_tree.get_root());
	}

	template <class T, class Compare, class Alloc>
	ft::pair<typename set<T, Compare, Alloc>::iterator, bool>	set<T, Compare, Alloc>::insert(const_reference value) {
		pointer	found;
		bool	inserted;

		found = this->_tree.find_node(value, this->_tree.get_root())->value;
		inserted = (found == nullptr || *found != value);
		return (ft::make_pair(this->_tree.insert(value), inserted));
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::iterator	set<T, Compare, Alloc>::insert(iterator pos, const_reference value) {
		(void)pos;
		
		return (this->_tree.insert(value));
	}

	template <class T, class Compare, class Alloc>
	template <class Iter>
	void	set<T, Compare, Alloc>::insert(Iter first, Iter last) {
		while (first != last) {
			this->_tree.insert(*first++);
		}
	}

	template <class T, class Compare, class Alloc>
	void	set<T, Compare, Alloc>::erase(iterator pos) {
		this->_tree.erase(*pos);
	}

	template <class T, class Compare, class Alloc>
	void	set<T, Compare, Alloc>::erase(iterator first, iterator last) {
		while (first != last) {
			this->_tree.erase(*first++);
		}
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::size_type	set<T, Compare, Alloc>::erase(const key_type &key) {
		return (this->_tree.erase(key));
	}

	template <class T, class Compare, class Alloc>
	void	set<T, Compare, Alloc>::swap(set &set_var) {
		std::swap(this->_compare, set_var._compare);
		std::swap(this->_alloc, set_var._alloc);
		this->_tree.swap(set_var._tree);
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::size_type	set<T, Compare, Alloc>::count(const key_type &key) const {
		pointer		found;
		
		found = this->_tree.find_node(key, this->_tree.get_root())->value;
		return (found != nullptr && *found == key);
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::iterator	set<T, Compare, Alloc>::find(const key_type &key) {
		return (this->_tree.find(key));
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::const_iterator	set<T, Compare, Alloc>::find(const key_type &key) const {
		return (this->_tree.find(key));
	}

	template <class T, class Compare, class Alloc>
	ft::pair<typename set<T, Compare, Alloc>::iterator, typename set<T, Compare, Alloc>::iterator>	set<T, Compare, Alloc>::equal_range(const key_type &key) {
		return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
	}

	template <class T, class Compare, class Alloc>
	ft::pair<typename set<T, Compare, Alloc>::const_iterator, typename set<T, Compare, Alloc>::const_iterator>	set<T, Compare, Alloc>::equal_range(const key_type &key) const {
		return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::iterator	set<T, Compare, Alloc>::lower_bound(const key_type &key) {
		iterator	current;

		current = this->begin();
		while (current != this->end()) {
			if (*current >= key) {
				return (current);
			}
			current++;
		}
		return (current);
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::const_iterator	set<T, Compare, Alloc>::lower_bound(const key_type &key) const {
		const_iterator	current;

		current = this->begin();
		while (current != this->end()) {
			if (*current >= key) {
				return (current);
			}
			current++;
		}
		return (current);
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::iterator	set<T, Compare, Alloc>::upper_bound(const key_type &key) {
		iterator	current;

		current = this->begin();
		while (current != this->end()) {
			if (*current > key) {
				return (current);
			}
			current++;
		}
		return (current);
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::const_iterator	set<T, Compare, Alloc>::upper_bound(const key_type &key) const {
		const_iterator	current;

		current = this->begin();
		while (current != this->end()) {
			if (*current > key) {
				return (current);
			}
			current++;
		}
		return (current);
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::key_compare	set<T, Compare, Alloc>::key_comp(void) const {
		return (this->_compare);
	}

	template <class T, class Compare, class Alloc>
	typename set<T, Compare, Alloc>::value_compare	set<T, Compare, Alloc>::value_comp(void) const {
		return (this->_tree.get_compare());
	}

	template <class T, class Compare, class Alloc>
	bool	operator == (const set<T, Compare, Alloc> &set_left, const set<T, Compare, Alloc> &set_right) {
		return (set_left.get_tree() == set_right.get_tree());
	}

	template <class T, class Compare, class Alloc>
	bool	operator != (const set<T, Compare, Alloc> &set_left, const set<T, Compare, Alloc> &set_right) {
		return (set_left.get_tree() != set_right.get_tree());
	}

	template <class T, class Compare, class Alloc>
	bool	operator < (const set<T, Compare, Alloc> &set_left, const set<T, Compare, Alloc> &set_right) {
		return (set_left.get_tree() < set_right.get_tree());
	}

	template <class T, class Compare, class Alloc>
	bool	operator <= (const set<T, Compare, Alloc> &set_left, const set<T, Compare, Alloc> &set_right) {
		return (set_left.get_tree() <= set_right.get_tree());
	}

	template <class T, class Compare, class Alloc>
	bool	operator > (const set<T, Compare, Alloc> &set_left, const set<T, Compare, Alloc> &set_right) {
		return (set_left.get_tree() > set_right.get_tree());
	}

	template <class T, class Compare, class Alloc>
	bool	operator >= (const set<T, Compare, Alloc> &set_left, const set<T, Compare, Alloc> &set_right) {
		return (set_left.get_tree() >= set_right.get_tree());
	}

	template <class T, class Compare, class Alloc>
	void	swap(set<T, Compare, Alloc> &set_left, set<T, Compare, Alloc> &set_right) {
		set_left.swap(set_right);
	}
}

#endif