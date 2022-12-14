#ifndef VECTOR_ITERATOR_TPP
# define VECTOR_ITERATOR_TPP

# include "vector_iterator.hpp"

using namespace ft;

template <class T>
vector_iterator<T>::vector_iterator(pointer ptr) : _ptr(ptr) {
	cout << "Vector_iterator constructor called\n";
}

template <class T>
vector_iterator<T>::vector_iterator(const vector_iterator &vector_iterator_var) {
	cout << "Vector_iterator copy constructor called\n";
	*this = vector_iterator_var;
}

template <class T>
vector_iterator<T>::~vector_iterator() {
	cout << "Vector_iterator destructor called\n";
}

template <class T>
vector_iterator<T>	&vector_iterator<T>::operator = (const vector_iterator &vector_iterator_var) {
	cout << "Vector_iterator copy assignment operator called\n";
	this->_prt = vector_iterator_var._ptr;
	return (*this);
}

template <class T>
vector_iterator<T>	&vector_iterator<T>::operator ++ (void) {
	this->_ptr++;
	return (*this);
}

template <class T>
vector_iterator<T>	&vector_iterator<T>::operator -- (void) {
	this->_ptr--;
	return (*this);
}

template <class T>
vector_iterator<T>	vector_iterator<T>::operator ++ (int) {
	vector_iterator	temp(*this);

	temp->_ptr++;
	return (temp);
}

template <class T>
vector_iterator<T>	vector_iterator<T>::operator -- (int) {
	vector_iterator	temp(*this);

	temp->_ptr--;
	return (temp);
}

template <class T>
vector_iterator<T>	&vector_iterator<T>::operator += (difference_type val) {
	this->_ptr += val;
	return (*this);
}

template <class T>
vector_iterator<T>	&vector_iterator<T>::operator -= (difference_type val) {
	this->_ptr -= val;
	return (*this);
}

template <class T>
bool	vector_iterator<T>::operator < (vector_iterator &vector_iterator_var) {
	return (*this < vector_iterator_var);
}

template <class T>
bool	vector_iterator<T>::operator > (vector_iterator &vector_iterator_var) {
	return (*this > vector_iterator_var);
}

template <class T>
bool	vector_iterator<T>::operator <= (vector_iterator &vector_iterator_var) {
	return (*this <= vector_iterator_var);
}

template <class T>
bool	vector_iterator<T>::operator >= (vector_iterator &vector_iterator_var) {
	return (*this >= vector_iterator_var);
}

template <class T>
typename vector_iterator<T>::reference	vector_iterator<T>::operator * (void) {
	return (*this->_ptr);
}

template <class T>
typename vector_iterator<T>::pointer	vector_iterator<T>::operator -> (void) {
	return (this->_ptr);
}

template <class T>
typename vector_iterator<T>::reference	vector_iterator<T>::operator [] (difference_type index) {
	return (*(this->_ptr + index));
}

template <class T>
vector_iterator<T>	operator + (vector_iterator<T> it, typename vector_iterator<T>::difference_type val) {
	vector_iterator<T>	temp_it(it);

	temp_it += val;
	return (temp_it);
}

template <class T>
vector_iterator<T>	operator - (vector_iterator<T> it, typename vector_iterator<T>::difference_type val) {
	vector_iterator<T>	temp_it(it);

	temp_it -= val;
	return (temp_it);
}

template <class T>
vector_iterator<T>	operator + (typename vector_iterator<T>::difference_type val, vector_iterator<T> it) {
	vector_iterator<T>	temp_it(it);

	temp_it += val;
	return (temp_it);
}

template <class T>
vector_iterator<T>	operator - (typename vector_iterator<T>::difference_type val, vector_iterator<T> it) {
	vector_iterator<T>	temp_it(it);

	temp_it -= val;
	return (temp_it);
}

template <class T>
typename vector_iterator<T>::difference_type	operator - (vector_iterator<T> it1, vector_iterator<T> it2) {
	return (it1 - it2);
}

#endif