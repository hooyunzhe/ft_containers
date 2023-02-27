#include "test.hpp"

void	constructors(void) {
	{
		display_header("Default constructor", "vector<int>");
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;

		display_container(".data()", iv_std, iv_ft);
		display_container(".size()", iv_std, iv_ft);
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

void	assignment(void) {
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

		iv_std = iv2_std;
		iv_ft = iv2_ft;
		display_elements(iv2_std, iv2_ft);
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

void	get_allocator(void) {
	display_header("get_allocator", "vector<int>(std::allocator<int>())", "vector<int>");
	std::allocator<int>	alloc;
	std::vector<int>	iv_std(alloc);
	ft::vector<int>		iv_ft(alloc);
	string	diff_std;
	string	diff_ft;

	display_equality("type == std::allocator<int>", typeid(iv_std.get_allocator()).name() == typeid(alloc).name(), typeid(iv_ft.get_allocator()).name() == typeid(alloc).name());
}

void	element_access(void) {
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
	display_output("operator[] (1)", iv_std[1], iv_ft[1], 1);
	display_output("front()", iv_std.front(), iv_ft.front(), 1);
	display_output("back()", iv_std.back(), iv_ft.back(), 1);
}

void	iterators(void) {
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
		display_output("before assigning", *it_std, *it_ft, 2);
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

void	reverse_iterators(void) {
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
		display_output("before assigning", *it_std, *it_ft, 2);
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

void	capacity(void) {
	display_header("Capacity", "vector<int>(42, 42)", "vector<int>", 0, 19);
	std::vector<int>	empty_iv_std;
	ft::vector<int>		empty_iv_ft;
	std::vector<int>	iv_std(42, 42);
	ft::vector<int>		iv_ft(42, 42);

	display_container(".empty()", iv_std, iv_ft, 19, "empty()");
	display_container(".empty()", empty_iv_std, empty_iv_ft, 19, "empty(vector<int>())");
	display_container(".size()", iv_std, iv_ft, 19);
	display_container(".max_size()", iv_std, iv_ft, 19);
	display_container(".capacity()", iv_std, iv_ft, 19);
	iv_std.reserve(4242);
	iv_ft.reserve(4242);
	display_output("reserve(4242)", iv_std.capacity(), iv_ft.capacity(), 4, 19);
}

void	modifiers(void) {
	display_header("Modifiers", "vector<int>", 23);

	std::vector<int>	iv_std(2, 42);
	ft::vector<int>		iv_ft(2, 42);

	display_elements(iv_std, iv_ft);
	display_container(".size()", iv_std, iv_ft);
	iv_std.clear();
	iv_ft.clear();
	display_output("clear()", iv_std.size(), iv_ft.size(), 1);
	iv_std.push_back(1);
	iv_std.push_back(3);
	iv_ft.push_back(1);
	iv_ft.push_back(3);
	display_elements(iv_std, iv_ft);
	iv_std.insert(iv_std.begin() + 1, 2);
	iv_ft.insert(iv_ft.begin() + 1, 2);
	display_elements(iv_std, iv_ft, "insert(begin() + 1, 2)");
}

void	vector_test(void) {
	// constructors();
	// assignment();
	// get_allocator();
	// element_access();
	// iterators();
	// reverse_iterators();
	// capacity();
	modifiers();
}
