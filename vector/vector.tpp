#ifndef VECTOR_TPP
# define VECTOR_TPP

namespace	ft
{
	template <class T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type &alloc) : _alloc(alloc) {
		this->_size = 0;
		this->_capacity = 0;
		this->_ptr = 0;
	}

	template <class T, class Alloc>
	vector<T, Alloc>::vector(size_type n, const_reference value, const allocator_type &alloc) : _alloc(alloc) {
		this->_size = n;
		this->_capacity = n;
		this->_ptr = this->_alloc.allocate(this->_capacity);
		for (size_type i = 0; i < this->_size; i++) {
			this->_alloc.construct(this->_ptr + i, value);
		}
	}

	template <class T, class Alloc>
	template <class Iter>
	vector<T, Alloc>::vector(Iter first, Iter last, const allocator_type &alloc, typename enable_if<!is_integral<Iter>::value>::type *) : _alloc(alloc) {
		Iter	temp;

		temp = first;
		this->_size = 0;
		while (temp != last) {
			temp++;
			this->_size++;
		}
		this->_capacity = this->_size;
		this->_ptr = this->_alloc.allocate(this->_capacity);
		for (size_type i = 0; i < this->_size; i++) {
			this->_alloc.construct(this->_ptr + i, *first++);
		}
	}

	template <class T, class Alloc>
	vector<T, Alloc>::vector(const vector &vector_var) : _alloc(vector_var._alloc) {
		this->_size = 0;
		this->_capacity = 0;
		*this = vector_var;
	}

	template <class T, class Alloc>
	vector<T, Alloc>::~vector() {
		this->clear();
		this->_alloc.deallocate(this->_ptr, this->_capacity);
	}

	template <class T, class Alloc>
	vector<T, Alloc>	&vector<T, Alloc>::operator = (const vector &vector_var) {
		for (size_type i = 0; i < this->_size; i++) {
			this->_alloc.destroy(this->_ptr + i);
		}
		if (this->_capacity > 0) {
			this->_alloc.deallocate(this->_ptr, this->_capacity);
		}
		this->_size = vector_var._size;
		this->_capacity = vector_var._capacity;
		if (this->_capacity == 0) {
			this->_ptr = 0;
		}
		else {
			this->_ptr = this->_alloc.allocate(this->_capacity);
		}
		for (size_type i = 0; i < this->_size; i++) {
			this->_alloc.construct(this->_ptr + i, vector_var[i]);
		}
		return (*this);
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::assign(size_type count, const_reference value) {
		for (size_type i = 0; i < this->_size; i++) {
			this->_alloc.destroy(this->_ptr + i);
		}
		if (this->_capacity > 0) {
			this->_alloc.deallocate(this->_ptr, this->_capacity);
		}
		this->_size = count;
		this->_capacity = this->_size;
		this->_ptr = this->_alloc.allocate(this->_capacity);
		for (size_type i = 0; i < this->_size; i++) {
			this->_alloc.construct(this->_ptr + i, value);
		}
	}

	template <class T, class Alloc>
	template <class Iter>
	void	vector<T, Alloc>::assign(Iter first, Iter last, typename enable_if<!is_integral<Iter>::value>::type *) {
		Iter	temp;
		
		for (size_type i = 0; i < this->_size; i++) {
			this->_alloc.destroy(this->_ptr + i);
		}
		if (this->_capacity > 0) {
			this->_alloc.deallocate(this->_ptr, this->_capacity);
		}
		temp = first;
		this->_size = 0;
		while (temp != last) {
			this->_size++;
			temp++;
		}
		this->_capacity = this->_size;
		this->_ptr = this->_alloc.allocate(this->_capacity);
		for (size_type i = 0; i < this->_size; i++) {
			this->_alloc.construct(this->_ptr + i, *first++);
		}
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::allocator_type	vector<T, Alloc>::get_allocator(void) const {
		return (this->_alloc);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::at(size_type index) {
		if (index >= this->_size) {
			throw std::out_of_range("Error: index out of range...");
		}
		return (this->_ptr[index]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::at(size_type index) const {
		if (index >= this->_size) {
			throw std::out_of_range("Error: index out of range...");
		}
		return (this->_ptr[index]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::operator [] (size_type index) {
		return (this->_ptr[index]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::operator [] (size_type index) const {
		return (this->_ptr[index]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::front(void) {
		return (this->_ptr[0]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::front(void) const {
		return (this->_ptr[0]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::back(void) {
		return (this->_ptr[this->_size - 1]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::back(void) const {
		return (this->_ptr[this->_size - 1]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::pointer	vector<T, Alloc>::data(void) {
		return (this->_ptr);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_pointer	vector<T, Alloc>::data(void) const {
		return (this->_ptr);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::begin(void) {
		return (iterator(this->_ptr));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::begin(void) const {
		return (const_iterator(this->_ptr));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::end(void) {
		return (iterator(this->_ptr + this->_size));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::end(void) const {
		return (const_iterator(this->_ptr + this->_size));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator	vector<T, Alloc>::rbegin(void) {
		return (reverse_iterator(this->end()));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rbegin(void) const {
		return (const_reverse_iterator(this->end()));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator	vector<T, Alloc>::rend(void) {
		return (reverse_iterator(this->begin()));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rend(void) const {
		return (const_reverse_iterator(this->begin()));
	}

	template <class T, class Alloc>
	bool	vector<T, Alloc>::empty(void) const {
		return (this->_size == 0);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type	vector<T, Alloc>::size(void) const {
		return (this->_size);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type	vector<T, Alloc>::max_size(void) const {
		return (this->_alloc.max_size());
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::reserve(size_type new_capacity) {
		vector	temp;

		if (new_capacity > this->_capacity) {
			temp = *this;
			for (size_type i = 0; i < this->_size; i++) {
				this->_alloc.destroy(this->_ptr + i);
			}
			if (this->_capacity > 0) {
				this->_alloc.deallocate(this->_ptr, this->_capacity);
			}
			this->_capacity = new_capacity;
			this->_ptr = this->_alloc.allocate(this->_capacity);
			for (size_type i = 0; i < temp._size; i++) {
				this->_alloc.construct(this->_ptr + i, temp._ptr[i]);
			}
		}
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity(void) const {
		return (this->_capacity);
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::clear(void) {
		for (size_type i = 0; i < this->_size; i++) {
			this->_alloc.destroy(this->_ptr + i);
		}
		this->_size = 0;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator pos, const_reference value) {
		difference_type	offset;

		offset = pos - this->begin();
		this->insert(pos, 1, value);
		return (iterator(this->_ptr + offset));
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::insert(iterator pos, size_type count, const_reference value) {
		pointer	new_ptr;
		int		current_pos;

		if (this->_size + count > this->_capacity) {
			new_ptr = this->_alloc.allocate(std::max(this->_capacity * 2, this->_capacity + count));
		}
		else {
			new_ptr = this->_ptr;
		}
		current_pos = this->_size + count - 1;
		for (iterator it = this->end() + count - 1; it != this->begin() - 1; it--) {
			if (it >= pos && it < pos + count) {
				this->_alloc.construct(new_ptr + current_pos, value);
			}
			else if (this->_size + count > this->_capacity) {
				this->_alloc.construct(new_ptr + current_pos, this->_ptr[current_pos - count * (it > pos)]);
				this->_alloc.destroy(this->_ptr + current_pos);
			}
			else if (count > 0) {
				this->_ptr[current_pos] = this->_ptr[current_pos - count * (it > pos)];
			}
			current_pos--;
		}
		if (new_ptr != this->_ptr) {
			this->_alloc.deallocate(this->_ptr, this->_capacity);
			this->_ptr = new_ptr;
			this->_capacity = std::max(this->_capacity * 2, this->_capacity + count);
		}
		this->_size += count;
	}

	template <class T, class Alloc>
	template <class Iter>
	void	vector<T, Alloc>::insert(iterator pos, Iter first, Iter last, typename enable_if<!is_integral<Iter>::value>::type *) {
		Iter			temp;
		difference_type	count;
		pointer			new_ptr;
		int				current_pos;

		temp = first;
		count = 0;
		while (temp != last) {
			count++;
			temp++;
		}
		if (this->_size + count > this->_capacity) {
			new_ptr = this->_alloc.allocate(std::max(this->_capacity * 2, this->_capacity + count));
		}
		else {
			new_ptr = this->_ptr;
		}
		current_pos = this->_size + count - 1;
		for (iterator it = this->end() + count - 1; it != this->begin() - 1; it--) {
			if (it >= pos && it < pos + count) {
				this->_alloc.construct(new_ptr + current_pos, *(--last));
			}
			else if (this->_size + count > this->_capacity) {
				this->_alloc.construct(new_ptr + current_pos, this->_ptr[current_pos - count * (it > pos)]);
			}
			else if (count > 0) {
				this->_ptr[current_pos] = this->_ptr[current_pos - count * (it > pos)];
			}
			current_pos--;
		}
		if (new_ptr != this->_ptr) {
			this->_alloc.deallocate(this->_ptr, this->_capacity);
			this->_ptr = new_ptr;
			this->_capacity = std::max(this->_capacity * 2, this->_capacity + count);
		}
		this->_size += count;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator pos) {
		iterator	temp;

		temp = pos;
		this->_alloc.destroy(&(*pos));
		while (temp != this->end()) {
			*temp = *(temp + 1);
			temp++;
		}
		this->_size--;
		return (pos);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator first, iterator last) {
		difference_type	count;

		count = last - first;
		while (first != this->end()) {
			if (first < last) {
				this->_alloc.destroy(&(*first));
			}
			*first = *(first + count);
			first++;
		}
		this->_size -= count;
		return (last - count);
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::push_back(const_reference value) {
		pointer	new_ptr;

		if (this->_size + 1 > this->_capacity) {
			new_ptr = this->_alloc.allocate(std::max(this->_capacity * 2, this->_capacity + 1));
		}
		else {
			new_ptr = this->_ptr;
		}
		this->_size++;
		for (size_type i = 0; i < this->_size; i++) {
			if (i == this->_size - 1) {
				this->_alloc.construct(new_ptr + i, value);
			}
			else if (new_ptr != this->_ptr) {
				this->_alloc.construct(new_ptr + i, this->_ptr[i]);
				this->_alloc.destroy(this->_ptr + i);
			}
			else {
				new_ptr[i] = this->_ptr[i];
			}
		}
		if (new_ptr != this->_ptr) {
			this->_alloc.deallocate(this->_ptr, this->_capacity);
			this->_ptr = new_ptr;
			this->_capacity = std::max(this->_capacity * 2, this->_capacity + 1);
		}
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::pop_back(void) {
		this->_alloc.destroy(this->_ptr + this->_size);
		this->_size--;
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::resize(size_type new_size, value_type value) {
		pointer		new_ptr;
		size_type	i;

		if (new_size > this->_capacity) {
			new_ptr = this->_alloc.allocate(std::max(this->_capacity * 2, new_size));
		}
		else {
			new_ptr = this->_ptr;
		}
		for (i = 0; i < this->_size; i++) {
			if (i >= new_size) {
				this->_alloc.destroy(this->_ptr + i);
			}
			else if (new_ptr != this->_ptr) {
				this->_alloc.construct(new_ptr + i, this->_ptr[i]);
				this->_alloc.destroy(this->_ptr + i);
			}
		}
		for (size_type j = i; j < new_size; j++) {
			this->_alloc.construct(new_ptr + j, value);
		}
		this->_size = new_size;
		if (new_ptr != this->_ptr) {
			this->_alloc.deallocate(this->_ptr, this->_capacity);
			this->_ptr = new_ptr;
			this->_capacity = std::max(this->_capacity * 2, new_size);
		}
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::swap(vector &vector_var) {
		std::swap(this->_alloc, vector_var._alloc);
		std::swap(this->_ptr, vector_var._ptr);
		std::swap(this->_size, vector_var._size);
		std::swap(this->_capacity, vector_var._capacity);
	}

	template <class T, class Alloc>
	bool	operator == (const vector<T, Alloc> &vector_left, const vector<T, Alloc> &vector_right) {
		return ((vector_left.size() == vector_right.size()) && equal(vector_left.begin(), vector_left.end(), vector_right.begin()));
	}

	template <class T, class Alloc>
	bool	operator != (const vector<T, Alloc> &vector_left, const vector<T, Alloc> &vector_right) {
		return (!(vector_left == vector_right));
	}

	template <class T, class Alloc>
	bool	operator < (const vector<T, Alloc> &vector_left, const vector<T, Alloc> &vector_right) {
		return (lexicographical_compare(vector_left.begin(), vector_left.end(), vector_right.begin(), vector_right.end()));
	}

	template <class T, class Alloc>
	bool	operator <= (const vector<T, Alloc> &vector_left, const vector<T, Alloc> &vector_right) {
		return (!lexicographical_compare(vector_right.begin(), vector_right.end(), vector_left.begin(), vector_left.end()));
	}

	template <class T, class Alloc>
	bool	operator > (const vector<T, Alloc> &vector_left, const vector<T, Alloc> &vector_right) {
		return (lexicographical_compare(vector_right.begin(), vector_right.end(), vector_left.begin(), vector_left.end()));
	}

	template <class T, class Alloc>
	bool	operator >= (const vector<T, Alloc> &vector_left, const vector<T, Alloc> &vector_right) {
		return (!lexicographical_compare(vector_left.begin(), vector_left.end(), vector_right.begin(), vector_right.end()));
	}

	template <class T, class Alloc>
	void	swap(vector<T, Alloc> &vector_left, vector<T, Alloc> &vector_right) {
		vector_left.swap(vector_right);
	}
}

#endif
