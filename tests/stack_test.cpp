#include "test.hpp"

void	stack_constructors(void) {
	{
		display_header("Default constructor", "stack<int>");

		std::stack<int>	is_std;
		ft::stack<int>	is_ft;

		display_output(".size()", is_std.size(), is_ft.size(), 1);
	}
}

void	stack_test(void) {
	stack_constructors();
}
