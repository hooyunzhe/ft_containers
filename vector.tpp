#ifndef VECTOR_TPP
# define VECTOR_TPP

template <class T, class Alloc>
vector<T, Alloc>::vector(allocator_type &alloc = allocator_type()){
	cout << "Vector default constructor called\n";
	this->_alloc = alloc;
	this->_size = 0;
	this->_start = this->_alloc.allocate(0);
	this->_end = this->_start;
}

template <class T, class Alloc>
vector<T, Alloc>::vector(size_type n, const reference value = value_type(), allocator_type &alloc = allocator_type()) {
	cout << "Vector fill constructor called\n";
	this->_alloc = alloc;
	this->_size = n;
	this->_start = this->_alloc.allocate(n);
	this->_end = this->_start + (n - 1);
	this->_alloc.construct(this->_start, value);
}

template <class T, class Alloc>
vector<T, Alloc>::vector(iterator first, iterator last, allocator_type &alloc = allocator_type()) {
	cout << "Vector range constructor called\n";
	this->_alloc = alloc;
	if (is_integral<iterator>) {
		this->_size = static_cast<size_type>(first);
		this->_start = this->_alloc.allocate(this->_size);
		this->_end = this->_start + (n - 1);
		this->_alloc.construct(this->_start, static_cast<value_type>(last));
	}
	else {
		this->_size = (last - first) + 1;
		this->_start = this->_alloc.allocate(this->_size);
		this->_end = this->_start + (this->_size - 1);
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
}

template <class T, class Alloc>
vector<T, Alloc>	&vector<T, Alloc>::operator = (const vector &vector_var) {
	cout << "Vector copy assignment operator called\n";
	if (this->_size > 0) {
		this->_alloc.destroy(this->_start);
		this->_alloc.deallocate(this->_start, this->_size);
	}
	this->_size = vector_var._size;
	this->_start = this->_alloc.allocate(this->_size);
	this->_end = this->_start + (this->_size - 1);
	for (int i = 0; i < this->_size; i++) {
		this->_alloc[i] = vector_var._alloc[i];
	}
	return (*this);
}

#endif