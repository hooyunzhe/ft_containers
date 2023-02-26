#include "test.hpp"

void	constructor(void) {
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
		std::vector<int>	iv_std = {1, 2, 3};
		ft::vector<int>		iv_ft;

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
		string			diff_std;
		string			diff_ft;

		iv_std.push_back(4);
		iv_std.push_back(2);
		iv_ft.push_back(4);
		iv_ft.push_back(2);

		std::vector<int>	iv2_std(iv_std);
		ft::vector<int>		iv2_ft(iv_ft);

		diff_std = iv2_std.data() == iv_std.data() ? "True" : "False";
		diff_ft = iv2_ft.data() == iv_ft.data() ? "True" : "False";

		display_output("vector.data() == prev_vector.data()", diff_std, diff_ft, diff_std.length());
		display_elements(iv2_std, iv2_ft);
	}
}

std::pair<std::vector<int>*, ft::vector<int>* > destructor_helper(void) {
	std::vector<std::vector<int> >	vv_std(1, std::vector<int>(2, 42));
	ft::vector<ft::vector<int> >	vv_ft(1, ft::vector<int>(2, 42));
	std::vector<int>	*iiv_ptr_std;
	ft::vector<int>		*iiv_ptr_ft;

	iiv_ptr_std = &(vv_std[0]);
	iiv_ptr_ft = &(vv_ft[0]);
	display_elements(vv_std[0], vv_ft[0], "inner_vector ");
	return (std::make_pair(iiv_ptr_std, iiv_ptr_ft));
}

void	destructor(void) {
	display_header("Destructor", "vector<vector<int>>(1, vector<int>(2, 42))", "vector<vector<int>>");
	std::pair<std::vector<int>*, ft::vector<int>* >	iv_ptrs;
	string	diff_std;
	string	diff_ft;

	iv_ptrs = destructor_helper();

	diff_std = (*(iv_ptrs.first))[0] == 42 ? "True" : "False";
	diff_ft = (*(iv_ptrs.second))[0] == 42 ? "True" : "False";
	display_output("post destructor of outer_vector", "", "", 0);
	display_output("(*(ptr to inner_vector))[0] == 42", diff_std, diff_ft, diff_std.length());
}

void	assignment_operator(void) {
	display_header("Assignment operator = (vector<vector<int>>(1, vector<int>(2, 42)))", "vector<vector<int>>(1, vector<int>{4, 2})", "vector<vector<int>>");
	std::vector<std::vector<int> >	vv_std(1, std::vector<int>(2, 42));
	ft::vector<ft::vector<int> >	vv_ft(1, ft::vector<int>(2, 42));
	std::vector<std::vector<int> >	vv_std2;
	ft::vector<ft::vector<int> >	vv_ft2;
	std::vector<int>	iv_std;
	ft::vector<int>		iv_ft;
	std::vector<int>	*iiv_ptr_std;
	ft::vector<int>		*iiv_ptr_ft;
	string	diff_std;
	string	diff_ft;

	iiv_ptr_std = &(vv_std[0]);
	iiv_ptr_ft = &(vv_ft[0]);
	display_elements(vv_std[0], vv_ft[0], "inner_vector ");

	iv_std.push_back(4);
	iv_std.push_back(2);
	iv_ft.push_back(4);
	iv_ft.push_back(2);
	vv_std2.push_back(iv_std);
	vv_ft2.push_back(iv_ft);

	vv_std = vv_std2;
	vv_ft = vv_ft2;

	diff_std = (*(iiv_ptr_std))[0] == 42 ? "True" : "False";
	diff_ft = (*(iiv_ptr_ft))[0] == 42 ? "True" : "False";
	display_output("post assignment of outer_vector", "", "", 0);
	display_output("(*(ptr to inner_vector))[0] == 42", diff_std, diff_ft, diff_std.length());

	diff_std = vv_std.data() == vv_std2.data() ? "True" : "False";
	diff_ft = vv_ft.data() == vv_ft2.data() ? "True" : "False";
	display_output("vector.data() == prev_vector.data()", diff_std, diff_ft, diff_std.length());

	diff_std = vv_std[0].data() == vv_std2[0].data() ? "True" : "False";
	diff_ft = vv_ft[0].data() == vv_ft2[0].data() ? "True" : "False";
	display_output("(inner_vector of vector).data() == (inner_vector of prev_vector).data()", diff_std, diff_ft, diff_std.length());

	display_elements(vv_std[0], vv_ft[0], "inner_vector ");
}

void	assign(void) {
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
		std::vector<int>	iv_std = {1, 2, 3};
		ft::vector<int>		iv_ft;
		std::vector<int>	iv2_std;
		ft::vector<int>		iv2_ft;

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

	diff_std = (typeid(iv_std.get_allocator()).name() == typeid(alloc).name()) ? "True" : "False";
	diff_ft = (typeid(iv_ft.get_allocator()).name() == typeid(alloc).name()) ? "True" : "False";
	display_output("type == std::allocator<int>", diff_std, diff_ft, diff_std.length());
}

void	vector_test(void) {
	// constructor();
	// destructor();
	// assignment_operator();
	// assign();
	// get_allocator();
}
