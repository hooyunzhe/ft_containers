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

void	display_header(string desc, string type, size_t len) {
	max_len = std::max((desc.length() + type.length()), len) + 3;

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

void	display_header(string desc, string desc2, string type, size_t len, int output_len) {
	max_len = std::max(std::max(desc.length(), desc2.length()), len) + type.length() + 3;
	max_len = std::max(max_len, max_len + (output_len - 5) * 2);

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
	display_padding("Description", (output_len * 2) + 3);
	cout << "|" << string(output_len - 3, ' ') << "STD|";
	cout << string(output_len - 2, ' ') << "FT|\n" << RESET;
	display_divider();
}

void	display_equality(string message, bool std_equals, bool ft_equals, int output_max_len) {
	string	boolstring_std;
	string	boolstring_ft;

	boolstring_std = std_equals ? "True" : "False";
	boolstring_ft = ft_equals ? "True" : "False";
	display_output(message, boolstring_std, boolstring_ft, boolstring_std.length(), output_max_len);
}
