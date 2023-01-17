#ifndef VECTOR_TPP
# define VECTOR_TPP

template <class T, class Alloc>
vector<T, Alloc>::vector(allocator_type &alloc = allocator_type()){
	cout << "Vector default constructor called\n";
	this->_alloc = alloc;
	this->_size = 0;
	this->_capacity = 0;
	this->_alloc.allocate(0);
}

template <class T, class Alloc>
vector<T, Alloc>::vector(size_type n, const_reference value = value_type(), allocator_type &alloc = allocator_type()) {
	cout << "Vector fill constructor called\n";
	this->_alloc = alloc;
	this->_size = n;
	this->_capacity = n;
	this->_alloc.allocate(this->_capacity);
	for (int i = 0; i < this->_size; i++) {
		this->_alloc.construct(this->_alloc + i, value);
	}
}

template <class T, class Alloc>
vector<T, Alloc>::vector(iterator first, iterator last, allocator_type &alloc = allocator_type()) {
	cout << "Vector range constructor called\n";
	this->_alloc = alloc;
	// TO BE FIXED WITH ENABLE_IF
	if (is_integral<iterator>) {
		this->_size = static_cast<size_type>(first);
		this->_capacity = this->_size;
		this->_alloc.allocate(this->_capacity);
		for (int i = 0; i < this->_size; i++) {
			this->_alloc.construct(this->_alloc + i, static_cast<value_type>(last));
		}
	}
	else {
		this->_size = last - first;
		this->_capacity = this->_size;
		this->_alloc.allocate(this->_capacity);
		for (int i = 0; i < this->_size; i++) {
			this->_alloc[i] = first[i];
		}
	}
}

template <class T, class Alloc>
vector<T, Alloc>::vector(const vector &vector_var) {
	cout << "Vector copy constructor called\n";
	*this = vector_var;
}

template <class T, class Alloc>
vector<T, Alloc>::~vector() {
	cout << "Vector destructor called\n";
	this->clear();
	this->_alloc.deallocate(this->_alloc, this->_capacity);
}

template <class T, class Alloc>
vector<T, Alloc>	&vector<T, Alloc>::operator = (const vector &vector_var) {
	cout << "Vector copy assignment operator called\n";
	for (int i = 0; i < this->_size; i++) {
		this->_alloc.destroy(this->_alloc + i);
	}
	if (this->_capacity > 0) {
		this->_alloc.deallocate(this->_alloc, this->_capacity);
	}
	this->_size = vector_var._size;
	this->_capacity = vector_var._capacity;
	this->_alloc.allocate(this->_capacity);
	for (int i = 0; i < this->_size; i++) {
		this->_alloc[i] = vector_var._alloc[i];
	}
	return (*this);
}

template <class T, class Alloc>
void	vector<T, Alloc>::assign(size_type count, const_reference value) {
	for (int i = 0; i < this->_size; i++) {
		this->_alloc.destroy(this->_alloc + i);
	}
	if (this->_capacity > 0) {
		this->_alloc.deallocate(this->_alloc, this->_capacity);
	}
	this->_size = count;
	this->_capacity = this->_size;
	this->_alloc.allocate(this->_capacity);
	for (int i = 0; i < this->_size; i++) {
		this->_alloc.construct(this->_alloc + i, value);
	}
}

template <class T, class Alloc>
void	vector<T, Alloc>::assign(iterator first, iterator last) {
	for (int i = 0; i < this->_size; i++) {
		this->_alloc.destroy(this->_alloc + i);
	}
	if (this->_capacity > 0) {
		this->_alloc.deallocate(this->_alloc, this->_capacity);
	}
	// TO BE FIXED WITH ENABLE_IF
	if (is_integral<iterator>) {
		this->_size = static_cast<size_type>(first);
		this->_capacity = this->_size;
		this->_alloc.allocate(this->_capacity)
		for (int i = 0; i < this->_size; i++) {
			this->_alloc.construct(this->_alloc + i, static_cast<value_type>(last));
		}
	}
	else {
		this->_size = last - start;
		this->_capacity = this->_size;
		this->_alloc.allocate(this->_capacity);
		for (int i = 0; i < this->_size; i++) {
			this->_alloc[i] = first[i];
		}
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
	return (this->_alloc[index]);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reference	vector<T, Alloc>::at(size_type index) const {
	if (index >= this->_size) {
		throw std::out_of_range("Error: index out of range...");
	}
	return (this->_alloc[index]);
}

template <class T, class Alloc>
typename vector<T, Alloc>::reference	vector<T, Alloc>::operator [] (size_type index) {
	return (this->_alloc[index]);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reference	vector<T, Alloc>::operator [] (size_type index) const {
	return (this->_alloc[index]);
}

template <class T, class Alloc>
typename vector<T, Alloc>::reference	vector<T, Alloc>::front(void) {
	return (this->_alloc[0]);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reference	vector<T, Alloc>::front(void) const {
	return (this->_alloc[0]);
}

template <class T, class Alloc>
typename vector<T, Alloc>::reference	vector<T, Alloc>::back(void) {
	return (this->_alloc[this->_size - 1]);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_reference	vector<T, Alloc>::back(void) const {
	return (this->_alloc[this->_size - 1]);
}

template <class T, class Alloc>
typename vector<T, Alloc>::pointer	vector<T, Alloc>::data(void) {
	return (this->_alloc);
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_pointer	vector<T, Alloc>::data(void) const {
	return (this->_alloc);
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::begin(void) {
	return (iterator(this->_alloc));
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::begin(void) const {
	return (iterator(this->_alloc));
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::end(void) {
	return (iterator(this->_alloc + this->_size));
}

template <class T, class Alloc>
typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::end(void) const {
	return (iterator(this->_alloc + this->_size));
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
		for (int i = 0; i < this->_size; i++) {
			this->_alloc.destroy(this->_alloc + i);
		}
		if (this->_capacity > 0) {
			this->_alloc.deallocate(this->_alloc, this->_capacity);
		}
		this->_capacity = new_capacity;
		this->_alloc.allocate(this->_capacity);
		for (int i = 0; i < temp->_size; i++) {
			this->_alloc[i] = temp._alloc[i];
		}
	}
}

template <class T, class Alloc>
typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity(void) const {
	return (this->_capacity);
}

template <class T, class Alloc>
void	clear(void) {
	for (int i = 0; i < this->_size; i++) {
		this->_alloc.destroy(this->_alloc + i);
	}
	this->_size = 0;
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator pos, const_reference value) {
	Alloc	new_alloc;
	int		index;

	if (this->_size + 1 > this->_capacity) {
		new_alloc.allocate(this->_capacity * 2);
	}
	else {
		new_alloc = this->_alloc;
	}
	for (int i = this->_size; i >= 0; i--) {
		index = i - (this->_alloc + i > pos);
		if (this->_alloc + i == pos) {
			new_alloc[i].construct(new_alloc[i], value);
		}
		else if (new_alloc != this->_alloc) {
			new_alloc[i].construct(new_alloc[i], this->_alloc[index]);
			this->_alloc.destroy(this->_alloc + index);
		}
		else if (index < i) {
			new_alloc[i] = new_alloc[index];
		}
	}
	if (new_alloc != this->_alloc) [
		this->_alloc.deallocate(this->_alloc, this->_capacity);
		this->_alloc = new_alloc;
		this->_capacity *= 2;
	]
	this->_size += 1;
}

template <class T, class Alloc>
void	vector<T, Alloc>::insert(iterator pos, size_type count, const_reference value) {
	Alloc	new_alloc;
	int		index;

	if (this->_size + count > this->_capacity) {
		new_alloc.allocate(std::max(this->_capacity * 2, this->_capacity + count));
	}
	else {
		new_alloc = this->_alloc;
	}
	for (int i = this->_size + count - 1; i >= 0; i--) {
		index = i - count * (this->_alloc + i >= pos + count);
		if (this->_alloc + i >= pos && this->_alloc + i < pos + count) {
			new_alloc[i].construct(new_alloc[i], value);
		}
		else if (new_alloc != this->_alloc) {
			new_alloc[i].construct(new_alloc[i], this->_alloc[index]);
			this->_alloc.destroy(this->_alloc + index);
		}
		else if (index < i) {
			new_alloc[i] = new_alloc[index];
		}
	}
	if (new_alloc != this->_alloc) {
		this->_alloc.deallocate(this->_alloc, this->_capacity);
		this->_alloc = new_alloc;
		this->_capacity = std::max(this->_capacity * 2, this->_capacity + count);
	}
	this->_size += count;
}

template <class T, class Alloc>
template <class Iter>
void	vector<T, Alloc>::insert(iterator pos, Iter first, Iter last) {
	difference_type	count;
	Alloc			new_alloc;
	int				index;

	count = last - first;
	if (this->_size + count > this->_capacity) {
		new_alloc.allocate(std::max(this->_capacity * 2, this->_capacity + count));
	}
	else {
		new_alloc = this->_alloc;
	}
	for (int i = this->_size + count - 1; i >= 0; i--) {
		index = i - count * (this->_alloc + i >= pos + count);
		if (this->_alloc + i >= pos && this->_alloc + i < pos + count) {
			new_alloc[i].construct(new_alloc[i], *(last - ((this->_alloc + i) - (pos + count))));
		}
		else if (new_alloc != this->_alloc) {
			new_alloc[i].construct(new_alloc[i], this->_alloc[index]);
			this->_alloc.destroy(this->_alloc + index);
		}
		else if (index < i) {
			new_alloc[i] = new_alloc[index];
		}
	}
	if (new_alloc != this->_alloc) {
		this->_alloc.deallocate(this->_alloc, this->_capacity);
		this->_alloc = new_alloc;
		this->_capacity = std::max(this->_capacity * 2, this->_capacity + count);
	}
	if (count > 0)
		this->_size += count;
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator pos) {
	// Needs testing
	
	// Version 1
	this->_alloc.destroy(pos);
	while (pos != this->end()) {
		*pos = *(pos + 1);
		pos++;
	}
	this->_size -= 1;

	// Version 2
	iterator	temp;

	// needs testing:
	// temp = pos;
	temp = this->begin() + (pos - this->begin());
	this->_alloc.destroy(pos);
	while (temp != this->end()) {
		*temp = *(temp + 1);
		temp++;
	}
	this->_size -= 1;
}

template <class T, class Alloc>
typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator first, iterator last) {
	difference_type	count;

	count = last - first;
	while (first != this->end()) {
		if (first < last) {
			this->_alloc.destroy(first);
		}
		*first = *(first + count);
		first++;
	}
}

template <class T, class Alloc>
void	vector<T, Alloc>::push_back(const_reference value) {
	Alloc	new_alloc;
	
	if (this->_size + 1 > this->_capacity) {
		new_alloc.allocate(this->_capacity + 1);
	}
	else {
		new_alloc = this->_alloc;
	}
	this->_size += 1;
	for (int i = 0; i < this->_size; i++) {
		if (i == this->_size - 1) {
			new_alloc.construct(new_alloc[i], value);
		}
		else if (new_alloc != this->_alloc) {
			new_alloc.construct(new_alloc[i], this->_alloc[i]);
			this->_alloc.destroy(this->_alloc + i);
		}
		else {
			new_alloc[i] = this->_alloc[i];
		}
	}
	if (new_alloc != this->_alloc) {
		this->_alloc.deallocate(this->_alloc, this->_capacity);
		this->_alloc = new_alloc;
		this->_capacity += 1;
	}
}

template <class T, class Alloc>
void	vector<T, Alloc>::pop_back(void) {
	this->_alloc.destroy(this->end());
	this->_size -= 1;
}

template <class T, class Alloc>
void	vector<T, Alloc>::resize(size_type new_size, value_type value = value_type()) {
	Alloc	new_alloc;

	if (new_size > this->_capacity) {
		new_alloc.allocate(new_size);
	}
	else {
		new_alloc = this->_alloc;
	}
	for (int i = 0; i < this->_size; i++) {
		if (i >= new_size) {
			this->_alloc.destroy(this->_alloc + i);
		}
		else if (new_alloc != this->_alloc) {
			new_alloc.construct(new_alloc[i], this->_alloc[i]);
			this->_alloc.destroy(this->_alloc + i);
		}
	}
	for (int j = i; j < new_size; j++) {
		new_alloc.construct(new_alloc[j], value);
	}
	this->_size = new_size;
	if (new_alloc != this->_alloc) {
		this->_alloc.deallocate(this->_alloc, this->_capacity);
		this->_alloc = new_alloc;
		this->_capacity = new_size;
	}
}

template <class T, class Alloc>
void	vector<T, Alloc>::swap(vector &vector_var) {
	Alloc	temp;

	temp = this->_alloc;
	this->_alloc = vector_var._alloc;
	vector_var._alloc = temp;
}

template <class T, class Alloc>
bool	operator == (const vector<T, Alloc> &vector_left, const vector<T, Alloc> &vector_right) {
	if (vector_left.size() != vector_right.size()) {
		return (false);
	}
	for (int i = 0; i < vector_left.size(); i++) {
		if (vector_left[i] != vector_right[i]) {
			
		}
	}
}

#endif
