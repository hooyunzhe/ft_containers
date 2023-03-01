#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include "../../vector/vector.hpp"
# include "../../map/map.hpp"
# include "Colours.h"

using std::cout;
using std::endl;
using std::string;

void	display_divider(void);
void	display_padding(int length);
void	display_padding(string desc, int output_length);
void	display_header(string desc, string type, size_t len = 0, int output_max_len = 5);
void	display_header(string desc, string desc2, string type, size_t len = 0, int output_max_len = 5);
void	display_equality(string message, bool std_equals, bool ft_equals, int output_max_len = 5);

template <class T>
int		get_num_length(T value) {
	return (std::to_string(value).length());
}

template <class T>
void	display_output(string desc, const T &std_output, const T &ft_output, int output_len, int output_max_len = 5) {
	cout << BLUE << desc;
	display_padding(desc, output_max_len * 2 + 3);
	cout << GREEN << "|";
	display_padding(output_max_len - output_len);
	cout << std_output << "|";
	if (std_output != ft_output) {
		cout << RED;
	}
	display_padding(output_max_len - output_len);
	cout << ft_output << "|\n" << RESET;
	display_divider();
};

template <class T>
void	display_vector(string method, std::vector<T> c1, ft::vector<T> c2, int output_max_len = 5, string message = string()) {
	if (method == ".data()") {
		display_output("data()", c1.data(), c2.data(), get_num_length(reinterpret_cast<intptr_t>(c1.data())), output_max_len);
	}
	else if (method == ".empty()") {
		display_equality(message, c1.empty(), c2.empty(), output_max_len);
	}
	else if (method == ".size()") {
		display_output("size()", c1.size(), c2.size(), get_num_length(c1.size()), output_max_len);
	}
	else if (method == ".max_size()") {
		display_output("max_size()", c1.max_size(), c2.max_size(), get_num_length(c1.max_size()), output_max_len);
	}
}

// template <class T>
// void	display_vector_element_at(int index, string message, std::vector<T> v1, ft::vector<T> v2) {
// 	display_output(message, v1[index], v2[index], get_num_length(v1[index]));
// }

// template <class T>
// void	display_vector_element_at(int index, int index2, string message, std::vector<T> v1, ft::vector<T> v2) {
// 	display_output(message, v1[index][index2], v2[index][index2], get_num_length(v1[index][index2]));
// }

// template <class T>
// void	display_vector_element_at(int index, string method, string message, std::vector<T> v1, ft::vector<T> v2) {
// 	if (method == ".size()") {
// 		display_output(message, v1[index].size(), v2[index].size(), get_num_length(v1[index].size()));
// 	}
// }

template <class std_container, class ft_container>
void	display_elements(std_container v1, ft_container v2, string message = "", int output_max_len = 5) {
	string	elements_std;
	string	elements_ft;
	typename std_container::iterator	it_std;
	typename ft_container::iterator	it_ft;

	it_std = v1.begin();
	it_ft = v2.begin();
	while (it_std != (--v1.end())) {
		elements_std += std::to_string(*it_std) + ",";
		elements_ft += std::to_string(*it_ft) + ",";
		it_std++;
		it_ft++;
	}
	elements_std += std::to_string(*it_std);
	elements_ft += std::to_string(*it_ft);
	if (message == "") {
		message = "elements";
	}
	display_output(message, elements_std, elements_ft, elements_std.size(), output_max_len);
}

template <class Key, class T>
void	display_map_elements(std::map<Key, T> m1, ft::map<Key, T> m2, string message = "", int output_max_len = 5) {
	string	elements_std;
	string	elements_ft;
	typename std::map<Key, T>::iterator	it_std;
	typename ft::map<Key, T>::iterator	it_ft;

	it_std = m1.begin();
	it_ft = m2.begin();
	while (it_std != m1.end()) {
		elements_std += "(" + it_std->first + ",";
		elements_ft += "(" + it_ft->first + ",";
		elements_std += std::to_string(it_std->second) + ")";
		elements_ft += std::to_string(it_ft->second) + ")";
		it_std++;
		it_ft++;
	}
	if (message == "") {
		message = "elements";
	}
	display_output(message, elements_std, elements_ft, elements_std.size(), output_max_len);
}

#endif
