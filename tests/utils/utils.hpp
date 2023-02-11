#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include "Colours.h"

using std::cout;
using std::endl;
using std::string;

void	display_divider(int len);

void	display_header(string desc, int len = 0);

template <class T>
void	display_output(string desc, const T &stl_output, const T &ft_output) {
	cout << BLUE << desc << endl;
	cout << GREEN << "STL: " << stl_output << endl;
	if (stl_output != ft_output) {
		cout << RED;
	}
	cout << "FT: " << ft_output << RESET;
	display_divider(20);
};

#endif
