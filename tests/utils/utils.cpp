#include "utils.hpp"

static int	max_len;

void	display_divider(void) {
	cout << string(max_len, '-') << endl;
}

void	display_padding(int length) {
	cout << string(length, ' ');
}

void	display_padding(string desc, int output_length) {
	cout << string(max_len - desc.length() - output_length, ' ');
}

void	display_header(string desc, string type) {
	max_len = desc.length() + type.length() + 3;

	cout << YELLOW;
	display_divider();
	cout << desc;
	display_padding(desc, type.length());
	cout << type << "\n";
	display_divider();
	cout << MAGENTA << "Description";
	display_padding("Description", 13);
	cout << "|  STD|   FT|\n" << RESET;
	display_divider();
}

void	display_header(string desc, string desc2, string type) {
	max_len = std::max(desc.length(), desc2.length()) + type.length() + 3;

	cout << YELLOW;
	display_divider();
	cout << desc;
	display_padding(desc, type.length());
	cout << type << "\n";
	cout << desc2;
	display_padding(desc2, 0);
	cout << "\n";
	display_divider();
	cout << MAGENTA << "Description";
	display_padding("Description", 13);
	cout << "|  STD|   FT|\n" << RESET;
	display_divider();
}
