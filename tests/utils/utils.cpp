#include "utils.hpp"

void	display_divider(int len) {
	cout << endl << string(len, '-') << endl;
}

void	display_header(string desc, int len) {
	if (len == 0) {
		len = desc.length();
	}
	cout << YELLOW;
	display_divider(len);
	cout << desc;
	display_divider(len);
	cout << RESET;
}
