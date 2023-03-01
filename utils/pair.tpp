#ifndef PAIR_TPP
# define PAIR_TPP

template <class T1, class T2>
pair<T1, T2>::pair() : first(first_type()), second(second_type()) {}

template <class T1, class T2>
pair<T1, T2>::pair(const first_type &first_val, const second_type &second_val) : first(first_val), second(second_val) {}

template <class T1, class T2>
template <class U, class V>
pair<T1, T2>::pair(const pair<U, V> &pair_var) : first(pair_var.first), second(pair_var.second) {}

template <class T1, class T2>
pair<T1, T2>	&pair<T1, T2>::operator = (const pair &pair_var) {
	this->first = pair_var.first;
	this->second = pair_var.second;
	return (*this);
}

template <class T1, class T2>
void	pair<T1, T2>::swap(pair &pair_var) {
	std::swap(this->first, pair_var.first);
	std::swap(this->second, pair_var.second);
}

template <class T1, class T2>
bool	operator == (const pair<T1, T2> &pair_left, const pair<T1, T2> &pair_right) {
	return (pair_left.first == pair_right.first && pair_left.second == pair_right.second);
}

template <class T1, class T2>
bool	operator != (const pair<T1, T2> &pair_left, const pair<T1, T2> &pair_right) {
	return (!(pair_left == pair_right));
}

template <class T1, class T2>
bool	operator < (const pair<T1, T2> &pair_left, const pair<T1, T2> &pair_right) {
	return (pair_left.first < pair_right.first || (!(pair_right.first < pair_left.first) && pair_left.second < pair_right.second));
}

template <class T1, class T2>
bool	operator <= (const pair<T1, T2> &pair_left, const pair<T1, T2> &pair_right) {
	return (!(pair_right < pair_left));
}

template <class T1, class T2>
bool	operator > (const pair<T1, T2> &pair_left, const pair<T1, T2> &pair_right) {
	return (pair_right < pair_left);
}

template <class T1, class T2>
bool	operator >= (const pair<T1, T2> &pair_left, const pair<T1, T2> &pair_right) {
	return (!(pair_left < pair_right));
}

template <class T1, class T2>
void	swap(const pair<T1, T2> &pair_left, const pair<T1, T2> &pair_right) {
	pair_left.swap(pair_right);
}

template <class T1, class T2>
pair<T1, T2>	make_pair(T1 first_val, T2 second_val) {
	return (pair<T1, T2>(first_val, second_val));
}

template <class T1, class T2>
ostream	&operator << (ostream &out, const pair<T1, T2> &pair) {
	out << "(" << pair.first << ", " << pair.second << ")";
	return (out);
}

#endif