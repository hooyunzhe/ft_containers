#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <vector>
# include "../../vector/vector.hpp"
# include "Colours.h"

using std::cout;
using std::endl;
using std::string;

void	display_divider(void);
void	display_padding(int length);
void	display_padding(string desc, int output_length);
void	display_header(string desc, string type);
void	display_header(string desc, string desc2, string type);

template <class T>
int		get_num_length(T value) {
	return (std::to_string(value).length());
}

template <class T>
void	display_output(string desc, const T &stl_output, const T &ft_output, int output_len) {
	cout << BLUE << desc;
	display_padding(desc, 13);
	cout << GREEN << "|";
	display_padding(5 - output_len);
	cout << stl_output << "|";
	if (stl_output != ft_output) {
		cout << RED;
	}
	display_padding(5 - output_len);
	cout << ft_output << "|\n" << RESET;
	display_divider();
};

template <class std_container, class ft_container>
void	display_container(string method, std_container v1, ft_container v2) {
	if (method == ".data()") {
		display_output("data()", v1.data(), v2.data(), get_num_length(reinterpret_cast<intptr_t>(v1.data())));
	}
	else if (method == ".size()") {
		display_output("size()", v1.size(), v2.size(), get_num_length(v1.size()));
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
void	display_elements(std_container v1, ft_container v2, string prefix = "") {
	string	elements_std;
	string	elements_ft;
	typename std_container::iterator	it_std;
	typename ft_container::iterator		it_ft;

	it_std = v1.begin();
	it_ft = v2.begin();
	while (it_std != v1.end() - 1) {
		elements_std += std::to_string(*it_std) + ",";
		elements_ft += std::to_string(*it_ft) + ",";
		it_std++;
		it_ft++;
	}
	elements_std += std::to_string(*it_std);
	elements_ft += std::to_string(*it_ft);
	display_output(prefix + "elements", elements_std, elements_ft, elements_std.size());
}

#endif
