#ifndef VECTOR_ITERATOR_TPP
# define VECTOR_ITERATOR_TPP

namespace	ft
{
	template <class T>
	vector_iterator<T>::vector_iterator() {}

	template <class T>
	vector_iterator<T>::vector_iterator(typename remove_const<T>::type *ptr) : _ptr(ptr) {}

	template <class T>
	vector_iterator<T>::vector_iterator(const vector_iterator<typename remove_const<T>::type> &vector_iterator_var) {
		*this = vector_iterator_var;
	}

	template <class T>
	vector_iterator<T>::~vector_iterator() {}

	template <class T>
	vector_iterator<T>	&vector_iterator<T>::operator = (const vector_iterator<typename remove_const<T>::type> &vector_iterator_var) {
		this->_ptr = vector_iterator_var._ptr;
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

		this->_ptr++;
		return (temp);
	}

	template <class T>
	vector_iterator<T>	vector_iterator<T>::operator -- (int) {
		vector_iterator	temp(*this);

		this->_ptr--;
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
	typename vector_iterator<T>::reference	vector_iterator<T>::operator * (void) const {
		return (*this->_ptr);
	}

	template <class T>
	typename vector_iterator<T>::pointer	vector_iterator<T>::operator -> (void) const {
		return (this->_ptr);
	}

	template <class T>
	typename vector_iterator<T>::reference	vector_iterator<T>::operator [] (difference_type index) {
		return (*(this->_ptr + index));
	}

	template <class T>
	vector_iterator<T>	operator + (const vector_iterator<T> &it, typename vector_iterator<T>::difference_type val) {
		vector_iterator<T>	temp_it(it);

		temp_it += val;
		return (temp_it);
	}

	template <class T>
	vector_iterator<T>	operator - (const vector_iterator<T> &it, typename vector_iterator<T>::difference_type val) {
		vector_iterator<T>	temp_it(it);

		temp_it -= val;
		return (temp_it);
	}

	template <class T>
	vector_iterator<T>	operator + (typename vector_iterator<T>::difference_type val, const vector_iterator<T> &it) {
		vector_iterator<T>	temp_it(it);

		temp_it += val;
		return (temp_it);
	}

	template <class T>
	vector_iterator<T>	operator - (typename vector_iterator<T>::difference_type val, const vector_iterator<T> &it) {
		vector_iterator<T>	temp_it(it);

		temp_it -= val;
		return (temp_it);
	}

	template <class T, class U>
	typename vector_iterator<T>::difference_type	operator - (const vector_iterator<T> &it1, const vector_iterator<U> &it2) {
		return (it1._ptr - it2._ptr);
	}

	template <class T, class U>
	bool	operator == (const vector_iterator<T> &it1, const vector_iterator<U> &it2) {
		return (it1._ptr == it2._ptr);
	}

	template <class T, class U>
	bool	operator != (const vector_iterator<T> &it1, const vector_iterator<U> &it2) {
		return (it1._ptr != it2._ptr);
	}

	template <class T, class U>
	bool	operator < (const vector_iterator<T> &it1, const vector_iterator<U> &it2) {
		return (it1._ptr < it2._ptr);
	}

	template <class T, class U>
	bool	operator <= (const vector_iterator<T> &it1, const vector_iterator<U> &it2) {
		return (it1._ptr <= it2._ptr);
	}

	template <class T, class U>
	bool	operator > (const vector_iterator<T> &it1, const vector_iterator<U> &it2) {
		return (it1._ptr > it2._ptr);
	}

	template <class T, class U>
	bool	operator >= (const vector_iterator<T> &it1, const vector_iterator<U> &it2) {
		return (it1._ptr >= it2._ptr);
	}
}

#endif
