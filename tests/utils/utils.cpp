#include "utils.hpp"

static int	max_len;

void	display_divider(void) {
	cout << endl << string(max_len, '-') << endl;
}

void	display_padding(int length) {
	cout << string(length, ' ');
}

void	display_padding(string desc, int output_length) {
	cout << string(max_len - desc.length() - output_length, ' ');
}

void	display_header(string desc, string type, int len) {
	max_len = len;

	cout << YELLOW;
	display_divider();
	cout << desc;
	display_padding(desc, type.length());
	cout << type;
	display_divider();
	cout << MAGENTA << "Method";
	display_padding("Method", 11);
	cout << "| STL|  FT|" << RESET;
	display_divider();
}
