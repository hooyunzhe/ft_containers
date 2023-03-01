#include "test.hpp"

void	vector_constructors(void) {
	{
		display_header("Default constructor", "vector<int>");
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;

		display_vector(".data()", iv_std, iv_ft);
		display_vector(".size()", iv_std, iv_ft);
	}
	{
		display_header("Fill constructor (3)", "vector<int>");
		std::vector<int>	iv_std(3);
		ft::vector<int>		iv_ft(3);

		display_elements(iv_std, iv_ft);

		display_header("Fill constructor (2, 42)", "vector<int>");
		std::vector<int>	iv2_std(2, 42);
		ft::vector<int>		iv2_ft(2, 42);

		display_elements(iv2_std, iv2_ft);
	}
	{
		display_header("Range constructor (begin(), end())", "vector<int>{1, 2, 3}", "vector<int>");
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;

		iv_std.push_back(1);
		iv_std.push_back(2);
		iv_std.push_back(3);
		iv_ft.push_back(1);
		iv_ft.push_back(2);
		iv_ft.push_back(3);

		std::vector<int>	iv2_std(iv_std.begin(), iv_std.end());
		ft::vector<int>		iv2_ft(iv_ft.begin(), iv_ft.end());

		display_elements(iv2_std, iv2_ft);
	}
	{
		display_header("Copy constructor (vector<int>{4, 2})", "vector<int>");
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;

		iv_std.push_back(4);
		iv_std.push_back(2);
		iv_ft.push_back(4);
		iv_ft.push_back(2);

		std::vector<int>	iv2_std(iv_std);
		ft::vector<int>		iv2_ft(iv_ft);

		display_equality("vector.data() == prev_vector.data()", iv2_std.data() == iv_std.data(), iv2_ft.data() == iv_ft.data());
		display_elements(iv2_std, iv2_ft);
	}
}

void	vector_assignment(void) {
	{
		display_header("Assignment operator= (vector<int>{4, 2})", "vector<int>(2, 42)", "vector<int>");
		std::vector<int>	iv_std(2, 42);
		ft::vector<int>		iv_ft(2, 42);
		std::vector<int>	iv2_std;
		ft::vector<int>		iv2_ft;

		iv2_std.push_back(4);
		iv2_std.push_back(2);
		iv2_ft.push_back(4);
		iv2_ft.push_back(2);

		display_elements(iv_std, iv_ft, "before assignment");
		iv_std = iv2_std;
		iv_ft = iv2_ft;
		display_elements(iv_std, iv_ft, "after assignment");
		display_equality("vector.data() == prev_vector.data()", iv_std.data() == iv2_std.data(), iv_ft.data() == iv2_ft.data());
	}
	{
		display_header("assign (2, 42)", "vector<int>");
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;

		iv_std.assign(2, 42);
		iv_ft.assign(2, 42);
		display_elements(iv_std, iv_ft);
	}
	{
		display_header("assign (begin(), end())", "vector<int>{1, 2, 3}", "vector<int>");
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;
		std::vector<int>	iv2_std;
		ft::vector<int>		iv2_ft;

		iv_std.push_back(1);
		iv_std.push_back(2);
		iv_std.push_back(3);
		iv_ft.push_back(1);
		iv_ft.push_back(2);
		iv_ft.push_back(3);

		iv2_std.assign(iv_std.begin(), iv_std.end());
		iv2_ft.assign(iv_ft.begin(), iv_ft.end());
		display_elements(iv2_std, iv2_ft);
	}
}

void	vector_get_allocator(void) {
	display_header("get_allocator", "vector<int>(std::allocator<int>())", "vector<int>");
	std::allocator<int>	alloc;
	std::vector<int>	iv_std(alloc);
	ft::vector<int>		iv_ft(alloc);

	display_equality("type == std::allocator<int>", typeid(iv_std.get_allocator()).name() == typeid(alloc).name(), typeid(iv_ft.get_allocator()).name() == typeid(alloc).name());
}

void	vector_element_access(void) {
	display_header("Element Access", "vector<int>{1, 2, 3}", "vector<int>");
	std::vector<int>	iv_std;
	ft::vector<int>		iv_ft;

	iv_std.push_back(1);
	iv_std.push_back(2);
	iv_std.push_back(3);
	iv_ft.push_back(1);
	iv_ft.push_back(2);
	iv_ft.push_back(3);
	display_output("at(1)", iv_std.at(1), iv_ft.at(1), 1);
	iv_std.at(1) = 42;
	iv_ft.at(1) = 42;
	display_output("at(1) = 42", "", "", 0);
	display_output("operator[] (1)", iv_std[1], iv_ft[1], 2);
	iv_std[0] = 24;
	iv_ft[0] = 24;
	display_output("vector[0] = 24", "", "", 0);
	display_output("front()", iv_std.front(), iv_ft.front(), 2);
	iv_std.front() = 4242;
	iv_ft.front() = 4242;
	display_output("vector.front() = 4242", iv_std.front(), iv_ft.front(), 4);
	display_output("back()", iv_std.back(), iv_ft.back(), 1);
	iv_std.back() = 2424;
	iv_ft.back() = 2424;
	display_output("vector.back() = 2424", iv_std.back(), iv_ft.back(), 4);
}

void	vector_iterators(void) {
	{
		display_header("Iterators", "vector<int>{1, 2, 3}", "vector<int>", 31);
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;
		string	elements_std;
		string	elements_ft;

		iv_std.push_back(1);
		iv_std.push_back(2);
		iv_std.push_back(3);
		iv_ft.push_back(1);
		iv_ft.push_back(2);
		iv_ft.push_back(3);
		for (std::vector<int>::iterator it = iv_std.begin(); it != iv_std.end(); it++) {
			elements_std += std::to_string(*it) + ",";
		}
		for (ft::vector<int>::iterator it = iv_ft.begin(); it != iv_ft.end(); it++) {
			elements_ft += std::to_string(*it) + ",";
		}
		elements_std.pop_back();
		elements_ft.pop_back();
		display_output("*(begin())", *(iv_std.begin()), *(iv_ft.begin()), 1);
		display_output("*(end() - 1)", *(iv_std.end() - 1), *(iv_ft.end() - 1), 1);
		display_output("elements", elements_std, elements_ft, 5);

		std::vector<int>::iterator	it_std(iv_std.begin());
		ft::vector<int>::iterator	it_ft(iv_ft.begin());

		display_output("copy constructor (begin())", "", "", 0);
		display_output("pre increment ++", *(++it_std), *(++it_ft), 1);
		display_output("pre decrement --", *(--it_std), *(--it_ft), 1);
		display_output("post increment ++", *(it_std++), *(it_ft++), 1);
		display_output("post decrement --", *(it_std--), *(it_ft--), 1);
		display_output("operator+ (it, 2)", *(it_std + 2), *(it_ft + 2), 1);
		it_std += 2;
		it_ft += 2;
		display_output("operator+=", *it_std, *it_ft, 1);
		display_output("operator- (it, 2)", *(it_std - 2), *(it_ft - 2), 1);
		it_std -= 2;
		it_ft -= 2;
		display_output("operator-=", *it_std, *it_ft, 1);
	}
	{
		std::vector<string>	iv_std(1, "42");
		ft::vector<string>	iv_ft(1, "42");
		std::vector<string>	iv2_std(1, "42KL");
		ft::vector<string>	iv2_ft(1, "42KL");
		std::vector<string>::iterator	it_std;
		ft::vector<string>::iterator	it_ft;
		std::vector<string>::iterator	it2_std;
		ft::vector<string>::iterator	it2_ft;

		it_std = iv_std.begin();
		it_ft = iv_ft.begin();
		it2_std = iv2_std.begin();
		it2_ft = iv2_ft.begin();
		display_output("before assignment", *it_std, *it_ft, 2);
		it_std = it2_std;
		it_ft = it2_ft;
		display_output("assignment operator= (begin())", *it_std, *it_ft, 4);
		display_output("operator*", *it_std, *it_ft, 4);
		display_output("operator-> (length())", it_std->length(), it_ft->length(), 1);
		display_output("operator[] (0)", it_std[0], it_ft[0], 4);
	}
	{
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;
		string	diff_std;
		string	diff_ft;

		iv_std.push_back(1);
		iv_std.push_back(2);
		iv_std.push_back(3);
		iv_ft.push_back(1);
		iv_ft.push_back(2);
		iv_ft.push_back(3);

		std::vector<int>::iterator	it_std(iv_std.begin());
		ft::vector<int>::iterator	it_ft(iv_ft.begin());
		std::vector<int>::iterator	it2_std(iv_std.begin() + 2);
		ft::vector<int>::iterator	it2_ft(iv_ft.begin() + 2);

		display_output("operator- (it, it + 2)", it2_std - it_std, it2_ft - it_ft, 1);
		display_equality("operator< (it, it + 2)", it_std < it2_std, it_ft < it2_ft);
		display_equality("operator<= (it, it)", it_std <= it_std, it_ft <= it_ft);
		display_equality("operator> (it, it + 2)", it_std > it2_std, it_ft > it2_ft);
		display_equality("operator>= (it, it)", it_std >= it_std, it_ft >= it_ft);
		display_equality("operator== (it, it + 2)", it_std == it_std, it2_ft == it2_ft);
		display_equality("operator== (it, it + 2)", it_std == it_std, it2_ft == it2_ft);
	}
}

void	vector_reverse_iterators(void) {
	{
		display_header("Reverse iterators", "vector<int>{1, 2, 3}", "vector<int>", 31);
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;
		string	elements_std;
		string	elements_ft;

		iv_std.push_back(1);
		iv_std.push_back(2);
		iv_std.push_back(3);
		iv_ft.push_back(1);
		iv_ft.push_back(2);
		iv_ft.push_back(3);
		for (std::vector<int>::reverse_iterator it = iv_std.rbegin(); it != iv_std.rend(); it++) {
			elements_std += std::to_string(*it) + ",";
		}
		for (ft::vector<int>::reverse_iterator it = iv_ft.rbegin(); it != iv_ft.rend(); it++) {
			elements_ft += std::to_string(*it) + ",";
		}
		elements_std.pop_back();
		elements_ft.pop_back();
		display_output("*(rbegin())", *(iv_std.rbegin()), *(iv_ft.rbegin()), 1);
		display_output("*(rend() - 1)", *(iv_std.rend() - 1), *(iv_ft.rend() - 1), 1);
		display_output("elements", elements_std, elements_ft, 5);

		std::vector<int>::reverse_iterator	it_std(iv_std.rbegin());
		ft::vector<int>::reverse_iterator	it_ft(iv_ft.rbegin());

		display_output("copy constructor (rbegin())", "", "", 0);
		display_output("pre increment ++", *(++it_std), *(++it_ft), 1);
		display_output("pre decrement --", *(--it_std), *(--it_ft), 1);
		display_output("post increment ++", *(it_std++), *(it_ft++), 1);
		display_output("post decrement --", *(it_std--), *(it_ft--), 1);
		display_output("operator+ (rit, 2)", *(it_std + 2), *(it_ft + 2), 1);
		it_std += 2;
		it_ft += 2;
		display_output("operator+=", *it_std, *it_ft, 1);
		display_output("operator- (rit, 2)", *(it_std - 2), *(it_ft - 2), 1);
		it_std -= 2;
		it_ft -= 2;
		display_output("operator-=", *it_std, *it_ft, 1);
	}
	{
		std::vector<string>	iv_std(1, "42");
		ft::vector<string>	iv_ft(1, "42");
		std::vector<string>	iv2_std(1, "42KL");
		ft::vector<string>	iv2_ft(1, "42KL");
		std::vector<string>::reverse_iterator	it_std;
		ft::vector<string>::reverse_iterator	it_ft;
		std::vector<string>::reverse_iterator	it2_std;
		ft::vector<string>::reverse_iterator	it2_ft;

		it_std = iv_std.rbegin();
		it_ft = iv_ft.rbegin();
		it2_std = iv2_std.rbegin();
		it2_ft = iv2_ft.rbegin();
		display_output("before assignment", *it_std, *it_ft, 2);
		it_std = it2_std;
		it_ft = it2_ft;
		display_output("assignment operator= (rbegin())", *it_std, *it_ft, 4);
		display_output("operator*", *it_std, *it_ft, 4);
		display_output("operator-> (length())", it_std->length(), it_ft->length(), 1);
		display_output("operator[] (0)", it_std[0], it_ft[0], 4);
	}
	{
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;
		string	diff_std;
		string	diff_ft;

		iv_std.push_back(1);
		iv_std.push_back(2);
		iv_std.push_back(3);
		iv_ft.push_back(1);
		iv_ft.push_back(2);
		iv_ft.push_back(3);

		std::vector<int>::reverse_iterator	it_std(iv_std.rbegin());
		ft::vector<int>::reverse_iterator	it_ft(iv_ft.rbegin());
		std::vector<int>::reverse_iterator	it2_std(iv_std.rbegin() + 2);
		ft::vector<int>::reverse_iterator	it2_ft(iv_ft.rbegin() + 2);

		display_output("operator- (rit, rit + 2)", it2_std - it_std, it2_ft - it_ft, 1);
		display_equality("operator< (rit, rit + 2)", it_std < it2_std, it_ft < it2_ft);
		display_equality("operator<= (rit, rit)", it_std <= it_std, it_ft <= it_ft);
		display_equality("operator> (rit, rit + 2)", it_std > it2_std, it_ft > it2_ft);
		display_equality("operator>= (rit, rit)", it_std >= it_std, it_ft >= it_ft);
		display_equality("operator== (rit, rit + 2)", it_std == it_std, it2_ft == it2_ft);
		display_equality("operator== (rit, rit + 2)", it_std == it_std, it2_ft == it2_ft);
	}
}

void	vector_capacity(void) {
	display_header("Capacity", "vector<int>(42, 42)", "vector<int>", 0, 19);
	std::vector<int>	empty_iv_std;
	ft::vector<int>		empty_iv_ft;
	std::vector<int>	iv_std(42, 42);
	ft::vector<int>		iv_ft(42, 42);

	display_vector(".empty()", iv_std, iv_ft, 19, "empty()");
	display_vector(".empty()", empty_iv_std, empty_iv_ft, 19, "empty(vector<int>())");
	display_vector(".size()", iv_std, iv_ft, 19);
	display_vector(".max_size()", iv_std, iv_ft, 19);
	display_output("capacity()", iv_std.capacity(), iv_ft.capacity(), 2, 19);
	iv_std.reserve(4242);
	iv_ft.reserve(4242);
	display_output("reserve(4242)", iv_std.capacity(), iv_ft.capacity(), 4, 19);
}

void	vector_modifiers(void) {
	display_header("Modifiers", "vector<int>", 37, 19);

	std::vector<int>	iv_std(2, 42);
	ft::vector<int>		iv_ft(2, 42);
	std::vector<int>	iv2_std;
	ft::vector<int>		iv2_ft;

	display_elements(iv_std, iv_ft, "", 19);
	display_vector(".size()", iv_std, iv_ft, 19);
	display_output("capacity()", iv_std.capacity(), iv_ft.capacity(), 1, 19);

	iv_std.clear();
	iv_ft.clear();
	display_output("clear()", iv_std.size(), iv_ft.size(), 1, 19);

	iv_std.push_back(1);
	iv_std.push_back(3);
	iv_ft.push_back(1);
	iv_ft.push_back(3);
	display_elements(iv_std, iv_ft, "before insertion", 19);
	display_output("insert(begin() + 1, 2)", *(iv_std.insert(iv_std.begin() + 1, 2)), *(iv_ft.insert(iv_ft.begin() + 1, 2)), 1, 19);
	display_elements(iv_std, iv_ft, "after insertion", 19);
	display_output("capacity()", iv_std.capacity(), iv_ft.capacity(), 1, 19);

	iv_std.insert(iv_std.end(), 0, 42);
	iv_ft.insert(iv_ft.end(), 0, 42);
	display_elements(iv_std, iv_ft, "insert(begin(), 0, 42)", 19);
	iv_std.insert(iv_std.begin(), 2, 42);
	iv_ft.insert(iv_ft.begin(), 2, 42);
	display_elements(iv_std, iv_ft, "insert(begin(), 2, 42)", 19);
	display_output("capacity() after insertion", iv_std.capacity(), iv_ft.capacity(), 1, 19);

	iv2_std.push_back(4);
	iv2_std.push_back(5);
	iv2_std.push_back(6);
	iv2_std.push_back(7);
	iv2_ft.push_back(4);
	iv2_ft.push_back(5);
	iv2_ft.push_back(6);
	iv2_ft.push_back(7);
	display_elements(iv2_std, iv2_ft, "vector", 19);
	iv_std.insert(iv_std.begin(), iv2_std.begin(), iv2_std.begin());
	iv_ft.insert(iv_ft.begin(), iv2_ft.begin(), iv2_ft.begin());
	display_elements(iv_std, iv_ft, "insert(begin(), v.begin(), v.begin())", 19);
	iv_std.insert(iv_std.begin(), iv2_std.end(), iv2_std.end());
	iv_ft.insert(iv_ft.begin(), iv2_ft.end(), iv2_ft.end());
	display_elements(iv_std, iv_ft, "insert(begin(), v.end(), v.end())", 19);
	iv_std.insert(iv_std.end(), iv2_std.begin(), iv2_std.end());
	iv_ft.insert(iv_ft.end(), iv2_ft.begin(), iv2_ft.end());
	display_elements(iv_std, iv_ft, "insert(end(), v.begin(), v.end())", 19);
	display_output("capacity() after insertion", iv_std.capacity(), iv_ft.capacity(), 2, 19);

	display_output("erase(begin() + 2)", *(iv_std.erase(iv_std.begin() + 2)), *(iv_ft.erase(iv_ft.begin() + 2)), 1, 19);
	display_elements(iv_std, iv_ft, "after erasure", 19);
	display_output("erase(begin() + 2, end() - 1)", *(iv_std.erase(iv_std.begin() + 2, iv_std.end() - 1)), *(iv_ft.erase(iv_ft.begin() + 2, iv_ft.end() - 1)), 1, 19);
	display_elements(iv_std, iv_ft, "after erasure", 19);
	display_output("erase(end() - 1, end() - 1)", *(iv_std.erase(iv_std.end() - 1, iv_std.end() - 1)), *(iv_ft.erase(iv_ft.end() - 1, iv_ft.end() - 1)), 1, 19);
	display_elements(iv_std, iv_ft, "after erasure", 19);

	display_elements(iv2_std, iv2_ft, "vector", 19);
	display_output("capacity() before push_back()", iv2_std.capacity(), iv2_ft.capacity(), 1, 19);
	iv2_std.push_back(42);
	iv2_ft.push_back(42);
	display_elements(iv2_std, iv2_ft, "push_back(42)", 19);
	display_output("capacity() after push_back()", iv2_std.capacity(), iv2_ft.capacity(), 1, 19);

	iv2_std.pop_back();
	iv2_ft.pop_back();
	display_elements(iv2_std, iv2_ft, "pop_back()", 19);

	iv2_std.resize(2, 42);
	iv2_ft.resize(2, 42);
	display_elements(iv2_std, iv2_ft, "resize(2, 42)", 19);
	iv2_std.resize(4);
	iv2_ft.resize(4);
	display_elements(iv2_std, iv2_ft, "resize(4)", 19);
	iv2_std.resize(10, 1);
	iv2_ft.resize(10, 1);
	display_elements(iv2_std, iv2_ft, "resize(10, 1)", 19);
	display_output("capacity() after resize()", iv2_std.capacity(), iv2_ft.capacity(), 2, 19);

	display_elements(iv_std, iv_ft, "vector1 elements", 19);
	display_vector(".size()", iv_std, iv_ft, 19);
	display_output("capacity()", iv_std.capacity(), iv_ft.capacity(), 2, 19);
	display_elements(iv2_std, iv2_ft, "vector2 elements", 19);
	display_vector(".size()", iv2_std, iv2_ft, 19);
	display_output("capacity()", iv2_std.capacity(), iv2_ft.capacity(), 2, 19);
	iv_std.swap(iv2_std);
	iv_ft.swap(iv2_ft);
	display_elements(iv_std, iv_ft, "after swap()", 19);
	display_vector(".size()", iv_std, iv_ft, 19);
	display_output("capacity()", iv_std.capacity(), iv_ft.capacity(), 2, 19);
	display_elements(iv2_std, iv2_ft, "after swap()", 19);
	display_vector(".size()", iv2_std, iv2_ft, 19);
	display_output("capacity()", iv2_std.capacity(), iv2_ft.capacity(), 2, 19);

	std::swap(iv_std, iv2_std);
	ft::swap(iv_ft, iv2_ft);
	display_elements(iv_std, iv_ft, "after std::swap(v1, v2)", 19);
	display_vector(".size()", iv_std, iv_ft, 19);
	display_output("capacity()", iv_std.capacity(), iv_ft.capacity(), 2, 19);
	display_elements(iv2_std, iv2_ft, "after ft::swap(v1, v2)", 19);
	display_vector(".size()", iv2_std, iv2_ft, 19);
	display_output("capacity()", iv2_std.capacity(), iv2_ft.capacity(), 2, 19);
}

void	vector_relational() {
	display_header("Relational operators", "vector<int>", 19, 6);
	std::vector<int>	iv_std;
	ft::vector<int>		iv_ft;
	std::vector<int>	iv2_std;
	ft::vector<int>		iv2_ft;
	std::vector<int>	iv3_std;
	ft::vector<int>		iv3_ft;

	iv_std.push_back(1);
	iv_std.push_back(2);
	iv_std.push_back(3);
	iv_ft.push_back(1);
	iv_ft.push_back(2);
	iv_ft.push_back(3);
	iv2_std.push_back(1);
	iv2_std.push_back(2);
	iv2_std.push_back(3);
	iv2_ft.push_back(1);
	iv2_ft.push_back(2);
	iv2_ft.push_back(3);
	iv3_std.push_back(1);
	iv3_std.push_back(2);
	iv3_std.push_back(42);
	iv3_ft.push_back(1);
	iv3_ft.push_back(2);
	iv3_ft.push_back(42);

	display_elements(iv_std, iv_ft, "vector1 elements", 6);
	display_elements(iv2_std, iv2_ft, "vector2 elements", 6);
	display_elements(iv3_std, iv3_ft, "vector3 elements", 6);
	display_equality("operator== (v, v2)", iv_std == iv2_std, iv_ft == iv2_ft, 6);
	display_equality("operator== (v1, v42)", iv_std == iv3_std, iv_ft == iv3_ft, 6);
	display_equality("operator!= (v1, v42)", iv_std != iv3_std, iv_ft != iv3_ft, 6);
	display_equality("operator!= (v1, v2)", iv_std != iv2_std, iv_ft != iv2_ft, 6);
	display_equality("operator< (v1, v42)", iv_std < iv3_std, iv_ft < iv3_ft, 6);
	display_equality("operator< (v1, v2)", iv_std < iv2_std, iv_ft < iv2_ft, 6);
	display_equality("operator<= (v1, v2)", iv_std <= iv2_std, iv_ft <= iv2_ft, 6);
	display_equality("operator<= (v42, v1)", iv3_std <= iv_std, iv3_ft <= iv_ft, 6);
	display_equality("operator> (v42, v1)", iv3_std > iv_std, iv3_ft > iv_ft, 6);
	display_equality("operator> (v1, v2)", iv_std > iv2_std, iv_ft > iv2_ft, 6);
	display_equality("operator>= (v1, v2)", iv_std >= iv2_std, iv_ft >= iv2_ft, 6);
	display_equality("operator>= (v1, v42)", iv_std >= iv3_std, iv_ft >= iv3_ft, 6);
}

void	vector_test(void) {
	vector_constructors();
	vector_assignment();
	vector_get_allocator();
	vector_element_access();
	vector_iterators();
	vector_reverse_iterators();
	vector_capacity();
	vector_modifiers();
	vector_relational();
}
