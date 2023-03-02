#ifndef REVERSE_ITERATOR_TPP
# define REVERSE_ITERATOR_TPP

using namespace	ft;

template <class Iter>
reverse_iterator<Iter>::reverse_iterator() {}

template <class Iter>
reverse_iterator<Iter>::reverse_iterator(typename reverse_iterator<Iter>::iterator_type it) {
	this->_iterator = it - 1;
}

template <class Iter>
template <class U>
reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<U> &reverse_iterator_var) {
	*this = reverse_iterator_var;
}

template <class Iter>
reverse_iterator<Iter>::~reverse_iterator() {}

template <class Iter>
template <class U>
reverse_iterator<Iter>	&reverse_iterator<Iter>::operator = (const reverse_iterator<U> &reverse_iterator_var) {
	this->_iterator = reverse_iterator_var.base() - 1;
	return (*this);
};

template <class Iter>
reverse_iterator<Iter>	&reverse_iterator<Iter>::operator ++ (void) {
	this->_iterator--;
	return (*this);
}

template <class Iter>
reverse_iterator<Iter>	&reverse_iterator<Iter>::operator -- (void) {
	this->_iterator++;
	return (*this);
}

template <class Iter>
reverse_iterator<Iter>	reverse_iterator<Iter>::operator ++ (int) {
	reverse_iterator	temp(*this);

	this->_iterator--;
	return (temp);
}

template <class Iter>
reverse_iterator<Iter>	reverse_iterator<Iter>::operator -- (int) {
	reverse_iterator	temp(*this);

	this->_iterator++;
	return (temp);
}

template <class Iter>
reverse_iterator<Iter>	&reverse_iterator<Iter>::operator += (typename reverse_iterator<Iter>::difference_type val) {
	this->_iterator -= val;
	return (*this);
}

template <class Iter>
reverse_iterator<Iter>	&reverse_iterator<Iter>::operator -= (typename reverse_iterator<Iter>::difference_type val) {
	this->_iterator += val;
	return (*this);
}

template <class Iter>
typename reverse_iterator<Iter>::reference	reverse_iterator<Iter>::operator * (void) const {
	return (*this->_iterator);
}

template <class Iter>
typename reverse_iterator<Iter>::pointer	reverse_iterator<Iter>::operator -> (void) const {
	return (this->_iterator.operator->());
}

template <class Iter>
typename reverse_iterator<Iter>::reference	reverse_iterator<Iter>::operator [] (typename reverse_iterator<Iter>::difference_type index) {
	return (*(this->_iterator - index));
}

template <class Iter>
typename reverse_iterator<Iter>::iterator_type	reverse_iterator<Iter>::base(void) const {
	return (this->_iterator + 1);
}

template <class Iter>
reverse_iterator<Iter>	operator + (const reverse_iterator<Iter> &it, typename reverse_iterator<Iter>::difference_type val) {
	reverse_iterator<Iter>	temp_it(it);

	temp_it += val;
	return (temp_it);
}

template <class Iter>
reverse_iterator<Iter>	operator - (const reverse_iterator<Iter> &it, typename reverse_iterator<Iter>::difference_type val) {
	reverse_iterator<Iter>	temp_it(it);

	temp_it -= val;
	return (temp_it);
}

template <class Iter>
reverse_iterator<Iter>	operator + (typename reverse_iterator<Iter>::difference_type val, const reverse_iterator<Iter> &it) {
	reverse_iterator<Iter>	temp_it(it);

	temp_it += val;
	return (temp_it);
}

template <class Iter>
reverse_iterator<Iter>	operator - (typename reverse_iterator<Iter>::difference_type val, const reverse_iterator<Iter> &it) {
	reverse_iterator<Iter>	temp_it(it);

	temp_it -= val;
	return (temp_it);
}

template <class Iter, class Iter2>
typename reverse_iterator<Iter>::difference_type	operator - (const reverse_iterator<Iter> &it1, const reverse_iterator<Iter2> &it2) {
	return (it2.base() - it1.base());
}

template <class Iter, class Iter2>
bool	operator < (const reverse_iterator<Iter> &it1, const reverse_iterator<Iter2> &it2) {
	return (it1.base() > it2.base());
}

template <class Iter, class Iter2>
bool	operator <= (const reverse_iterator<Iter> &it1, const reverse_iterator<Iter2> &it2) {
	return (it1.base() >= it2.base());
}

template <class Iter, class Iter2>
bool	operator > (const reverse_iterator<Iter> &it1, const reverse_iterator<Iter2> &it2) {
	return (it1.base() < it2.base());
}

template <class Iter, class Iter2>
bool	operator >= (const reverse_iterator<Iter> &it1, const reverse_iterator<Iter2> &it2) {
	return (it1.base() <= it2.base());
}

template <class Iter, class Iter2>
bool	operator == (const reverse_iterator<Iter> &it1, const reverse_iterator<Iter2> &it2) {
	return (it1.base() == it2.base());
}

template <class Iter, class Iter2>
bool	operator != (const reverse_iterator<Iter> &it1, const reverse_iterator<Iter2> &it2) {
	return (it1.base() != it2.base());
}

#endif
