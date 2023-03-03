#ifndef MAP_TPP
# define MAP_TPP

namespace	ft
{
	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const key_compare &comp, const allocator_type &alloc) : _tree(value_compare(comp), alloc) {
		this->_compare = comp;
		this->_alloc = alloc;
	}

	template <class Key, class T, class Compare, class Alloc>
	template <class Iter>
	map<Key, T, Compare, Alloc>::map(Iter first, Iter last, const key_compare &comp, const allocator_type &alloc) : _tree(value_compare(comp), alloc) {
		this->_compare = comp;
		this->_alloc = alloc;
		while (first != last) {
			this->insert(*first++);
		}
	}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::map(const map &map_var) : _tree(map_var._tree) {
		this->_compare = map_var._compare;
		this->_alloc = map_var._alloc;
	}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>::~map() {}

	template <class Key, class T, class Compare, class Alloc>
	map<Key, T, Compare, Alloc>	&map<Key, T, Compare, Alloc>::operator = (const map &map_var) {
		this->_compare = map_var._compare;
		this->_alloc = map_var._alloc;
		this->_tree = map_var._tree;
		return (*this);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::allocator_type	map<Key, T, Compare, Alloc>::get_allocator(void) const {
		return (this->_alloc);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::tree_type	map<Key, T, Compare, Alloc>::get_tree(void) const {
		return (this->_tree);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::mapped_type	&map<Key, T, Compare, Alloc>::at(const key_type &key) {
		pointer		found;
		
		found = this->_tree.find_node(ft::make_pair(key, mapped_type()), this->_tree.get_root())->value;
		if (found == nullptr || found->first != key) {
			string	message;

			message = "Error: key \"";
			message += key;
			message += "\" doesn't exist...";
			throw std::out_of_range(message);
		}
		return (found->second);
	}

	template <class Key, class T, class Compare, class Alloc>
	const typename map<Key, T, Compare, Alloc>::mapped_type	&map<Key, T, Compare, Alloc>::at(const key_type &key) const {
		pointer		found;
		
		found = this->_tree.find_node(ft::make_pair(key, mapped_type()), this->_tree.get_root())->value;
		if (found == nullptr || found->first != key) {
			string	message;

			message = "Error: key \"";
			message += key;
			message += "\" doesn't exist...";
			throw std::out_of_range(message);
		}
		return (found->second);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::mapped_type	&map<Key, T, Compare, Alloc>::operator [] (const key_type &key) {
		pointer		found;

		found = this->_tree.find_node(ft::make_pair(key, mapped_type()), this->_tree.get_root())->value;
		if (found == nullptr || found->first != key) {
			return (this->insert(ft::make_pair(key, mapped_type())).first->second);
		}
		return (found->second);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::begin(void) {
		return (this->_tree.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator	map<Key, T, Compare, Alloc>::begin(void) const {
		return (this->_tree.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::end(void) {
		return (this->_tree.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator	map<Key, T, Compare, Alloc>::end(void) const {
		return (this->_tree.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::reverse_iterator	map<Key, T, Compare, Alloc>::rbegin(void) {
		return (this->_tree.rbegin());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_reverse_iterator	map<Key, T, Compare, Alloc>::rbegin(void) const {
		return (this->_tree.rbegin());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::reverse_iterator	map<Key, T, Compare, Alloc>::rend(void) {
		return (this->_tree.rend());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_reverse_iterator	map<Key, T, Compare, Alloc>::rend(void) const {
		return (this->_tree.rend());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	map<Key, T, Compare, Alloc>::empty(void) const {
		return (this->_tree.get_size() == 0);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::size(void) const {
		return (this->_tree.get_size());
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::max_size(void) const {
		return (std::numeric_limits<difference_type>::max());
	}

	template <class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>::clear(void) {
		this->_tree.clear_tree(this->_tree.get_root());
	}

	template <class Key, class T, class Compare, class Alloc>
	ft::pair<typename map<Key, T, Compare, Alloc>::iterator, bool>	map<Key, T, Compare, Alloc>::insert(const_reference value) {
		pointer	found;
		bool	inserted;

		found = this->_tree.find_node(value, this->_tree.get_root())->value;
		inserted = (found == nullptr || found->first != value.first);
		return (ft::make_pair(this->_tree.insert(value), inserted));
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::insert(iterator pos, const_reference value) {
		(void)pos;
		
		return (this->_tree.insert(value));
	}

	template <class Key, class T, class Compare, class Alloc>
	template <class Iter>
	void	map<Key, T, Compare, Alloc>::insert(Iter first, Iter last) {
		while (first != last) {
			this->_tree.insert(*first++);
		}
	}

	template <class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>::erase(iterator pos) {
		this->_tree.erase(*pos);
	}

	template <class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>::erase(iterator first, iterator last) {
		while (first != last) {
			this->_tree.erase(*first++);
		}
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::erase(const key_type &key) {
		return (this->_tree.erase(ft::make_pair(key, mapped_type())));
	}

	template <class Key, class T, class Compare, class Alloc>
	void	map<Key, T, Compare, Alloc>::swap(map &map_var) {
		std::swap(this->_compare, map_var._compare);
		std::swap(this->_alloc, map_var._alloc);
		this->_tree.swap(map_var._tree);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::size_type	map<Key, T, Compare, Alloc>::count(const key_type &key) const {
		pointer		found;
		
		found = this->_tree.find_node(ft::make_pair(key, mapped_type()), this->_tree.get_root())->value;
		return (found != nullptr && found->first == key);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::find(const key_type &key) {
		return (this->_tree.find(ft::make_pair(key, mapped_type())));
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator	map<Key, T, Compare, Alloc>::find(const key_type &key) const {
		return (this->_tree.find(ft::make_pair(key, mapped_type())));
	}

	template <class Key, class T, class Compare, class Alloc>
	ft::pair<typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T, Compare, Alloc>::iterator>	map<Key, T, Compare, Alloc>::equal_range(const key_type &key) {
		return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
	}

	template <class Key, class T, class Compare, class Alloc>
	ft::pair<typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key, T, Compare, Alloc>::const_iterator>	map<Key, T, Compare, Alloc>::equal_range(const key_type &key) const {
		return (ft::make_pair(this->lower_bound(key), this->upper_bound(key)));
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::lower_bound(const key_type &key) {
		iterator	current;

		current = this->begin();
		while (current != this->end()) {
			if (current->first >= key) {
				return (current);
			}
			current++;
		}
		return (current);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator	map<Key, T, Compare, Alloc>::lower_bound(const key_type &key) const {
		const_iterator	current;

		current = this->begin();
		while (current != this->end()) {
			if (current->first >= key) {
				return (current);
			}
			current++;
		}
		return (current);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::iterator	map<Key, T, Compare, Alloc>::upper_bound(const key_type &key) {
		iterator	current;

		current = this->begin();
		while (current != this->end()) {
			if (current->first > key) {
				return (current);
			}
			current++;
		}
		return (current);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::const_iterator	map<Key, T, Compare, Alloc>::upper_bound(const key_type &key) const {
		const_iterator	current;

		current = this->begin();
		while (current != this->end()) {
			if (current->first > key) {
				return (current);
			}
			current++;
		}
		return (current);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::key_compare	map<Key, T, Compare, Alloc>::key_comp(void) const {
		return (this->_compare);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::value_compare	map<Key, T, Compare, Alloc>::value_comp(void) const {
		return (this->_tree.get_compare());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator == (const map<Key, T, Compare, Alloc> &map_left, const map<Key, T, Compare, Alloc> &map_right) {
		return (map_left.get_tree() == map_right.get_tree());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator != (const map<Key, T, Compare, Alloc> &map_left, const map<Key, T, Compare, Alloc> &map_right) {
		return (map_left.get_tree() != map_right.get_tree());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator < (const map<Key, T, Compare, Alloc> &map_left, const map<Key, T, Compare, Alloc> &map_right) {
		return (map_left.get_tree() < map_right.get_tree());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator <= (const map<Key, T, Compare, Alloc> &map_left, const map<Key, T, Compare, Alloc> &map_right) {
		return (map_left.get_tree() <= map_right.get_tree());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator > (const map<Key, T, Compare, Alloc> &map_left, const map<Key, T, Compare, Alloc> &map_right) {
		return (map_left.get_tree() > map_right.get_tree());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator >= (const map<Key, T, Compare, Alloc> &map_left, const map<Key, T, Compare, Alloc> &map_right) {
		return (map_left.get_tree() >= map_right.get_tree());
	}

	template <class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc> &map_left, map<Key, T, Compare, Alloc> &map_right) {
		map_left.swap(map_right);
	}
}

#endif