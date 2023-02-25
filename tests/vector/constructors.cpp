#include "test.hpp"

void	constructor(void) {
	{
		display_header("Default constructor", "vector<int>", 34);
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;

		display_vector(".data()", iv_std, iv_ft);
		display_vector(".size()", iv_std, iv_ft);
		iv_std.push_back(42);
		iv_ft.push_back(42);
		display_vector_element_at(0, "vector.push_back(42)", iv_std, iv_ft);
		display_vector(".size()", iv_std, iv_ft);

		display_header("Default constructor", "vector<vector<int>>", 45);
		std::vector<ft::vector<int> >	vv_std;
		ft::vector<ft::vector<int> >	vv_ft;

		display_vector(".data()", vv_std, vv_ft);
		display_vector(".size()", vv_std, vv_ft);
		vv_std.push_back(iv_ft);
		vv_ft.push_back(iv_ft);
		display_vector_element_at(0, 0, "vector.push_back(vector<int>{42})", vv_std, vv_ft);
		display_vector(".size()", vv_std, vv_ft);
		display_vector_element_at(0, ".size()", "vector[0].size()", vv_std, vv_ft);
		vv_std[0].push_back(4242);
		vv_ft[0].push_back(4242);
		display_vector_element_at(0, 1, "vector[0].push_back(4242)", vv_std, vv_ft);
		display_vector_element_at(0, ".size()", "vector[0].size()" , vv_std, vv_ft);
	}
	// {
	// 	display_header("Fill constructor (5) | vector<int>");
	// 	std::vector<int>	iv_std(5);
	// 	ft::vector<int>		iv_ft(5);

	// 	display_output("vector.size(): ", iv_std.size(), iv_ft.size());
	// 	display_output("vector[0]: ", iv_std[0], iv_ft[0]);

	// 	display_header("Fill constructor (5, 42) | vector<int>");
	// 	std::vector<int>	iv2_std(5, 42);
	// 	ft::vector<int>		iv2_ft(5, 42);

	// 	display_output("vector.size(): ", iv2_std.size(), iv2_ft.size());
	// 	display_output("vector[4]: ", iv2_std[4], iv2_ft[4]);

	// 	display_header("Fill constructor (5) | vector<vector<int>>");
	// 	std::vector<ft::vector<int>>	vv_std(5);
	// 	ft::vector<ft::vector<int>>		vv_ft(5);

	// 	display_output("vector.size(): ", vv_std.size(), vv_ft.size());
	// 	display_output("vector[0].size(): ", vv_std[0].size(), vv_ft[0].size());
	// 	display_output("vector[0].data(): ", vv_std[0].data(), vv_ft[0].data());

	// 	display_header("Fill constructor (5, vector<int>(5, 42)) | vector<vector<int>>");
	// 	std::vector<ft::vector<int>>	vv2_std(5, vector<int>(5, 42));
	// 	ft::vector<ft::vector<int>>		vv2_ft(5, vector<int>(5, 42));

	// 	display_output("vector.size(): ", vv2_std.size(), vv2_ft.size());
	// 	display_output("vector[4].size(): ", vv2_std[4].size(), vv2_ft[4].size());
	// 	display_output("vector[0][4]: ", vv2_std[0][4], vv2_ft[0][4]);
	// }
	// {
	// 	display_header("Range constructor (begin(), end()) | vector<int>\nVector of begin/end: vector<int>{1, 2, 3, 4, 5}", 48);
	// 	std::vector<int>	iv_std = {1, 2, 3, 4, 5};
	// 	ft::vector<int>		iv_ft;

	// 	iv_ft.push_back(1);
	// 	iv_ft.push_back(2);
	// 	iv_ft.push_back(3);
	// 	iv_ft.push_back(4);
	// 	iv_ft.push_back(5);

	// 	std::vector<int>::iterator	begin_std = iv_std.begin();
	// 	std::vector<int>::iterator	end_std = iv_std.end();
	// 	ft::vector<int>::iterator	begin_ft = iv_ft.begin();
	// 	ft::vector<int>::iterator	end_ft = iv_ft.end();

	// 	std::vector<int>	iv2_std(begin_std, end_std);
	// 	ft::vector<int>		iv2_ft(begin_ft, end_ft);

	// 	display_output("vector.size(): ", iv2_std.size(), iv2_ft.size());
	// 	display_output("vector[2]: ", iv2_std[2], iv2_ft[2]);

	// 	display_header("Range constructor (begin(), end()) | vector<vector<int>>\nVector of begin/end: vector<vector<int>>{{1~5}, {6~10}, {11~15}})", 65);
	// 	std::vector<std::vector<int>>	vv_std = {
	// 		std::vector<int>{1, 2, 3, 4, 5},
	// 		std::vector<int>{6, 7, 8, 9, 10},
	// 		std::vector<int>{11, 12, 13, 14, 15}
	// 	};
	// 	ft::vector<std::vector<int>>	vv_ft;

	// 	vv_ft.push_back(std::vector<int>{1, 2, 3, 4, 5});
	// 	vv_ft.push_back(std::vector<int>{6, 7, 8, 9, 10});
	// 	vv_ft.push_back(std::vector<int>{11, 12, 13, 14, 15});

	// 	std::vector<std::vector<int>>::iterator	begin2_std = vv_std.begin();
	// 	std::vector<std::vector<int>>::iterator	end2_std = vv_std.end();
	// 	ft::vector<std::vector<int>>::iterator	begin2_ft = vv_ft.begin();
	// 	ft::vector<std::vector<int>>::iterator	end2_ft = vv_ft.end();

	// 	std::vector<std::vector<int>>	vv2_std(begin2_std, end2_std);
	// 	ft::vector<std::vector<int>>	vv2_ft(begin2_ft, end2_ft);

	// 	display_output("vector.size(): ", vv2_std.size(), vv2_ft.size());
	// 	display_output("vector[0].size(): ", vv2_std[0].size(), vv2_ft[0].size());
	// 	display_output("vector[0][0]: ", vv2_std[0][0], vv2_std[0][0]);
	// 	display_output("vector[0][4]: ", vv2_std[0][4], vv2_std[0][4]);
	// 	display_output("vector[1][0]: ", vv2_std[1][0], vv2_std[1][0]);
	// 	display_output("vector[1][4]: ", vv2_std[1][4], vv2_std[1][4]);
	// 	display_output("vector[2][0]: ", vv2_std[2][0], vv2_std[2][0]);
	// 	display_output("vector[2][4]: ", vv2_std[2][4], vv2_std[2][4]);
	// }
	// {
	// 	display_header("Copy constructor (vector<int>(5, 42)) | vector<int>");
	// 	std::vector<int>	iv_std(5, 42);
	// 	std::vector<int>	iv2_std(iv_std);
	// 	ft::vector<int>	iv_ft(5, 42);
	// 	ft::vector<int>	iv2_ft(iv_ft);
	// 	string			diff_std;
	// 	string			diff_ft;

	// 	diff_std = iv2_std.data() != iv_std.data() ? "True" : "False";
	// 	diff_ft = iv2_ft.data() != iv_ft.data() ? "True" : "False";
	// 	display_output("vector.data() != prev_vector.data(): ", diff_std, diff_ft);
	// 	display_output("vector.size(): ", iv2_std.size(), iv2_ft.size());
	// 	display_output("vector[0]: ", iv2_std[0], iv2_ft[0]);

	// 	display_header("Copy constructor (vector_of_vectors) | vector<vector<int>>\nVector: vector<vector<int>>{vector<int>(5, 42), vector<int>(5, 4242)}", 69);
	// 	std::vector<std::vector<int>>	vv_std = {
	// 		std::vector<int>(5, 42),
	// 		std::vector<int>(5, 4242)
	// 	};
	// 	ft::vector<std::vector<int>>	vv_ft;

	// 	vv_ft.push_back(std::vector<int>(5, 42));
	// 	vv_ft.push_back(std::vector<int>(5, 4242));

	// 	std::vector<std::vector<int>>	vv2_std(vv_std);
	// 	ft::vector<std::vector<int>>	vv2_ft(vv_ft);
	// 	string	diff2_std;
	// 	string	diff2_ft;
	// 	string	diff3_std;
	// 	string	diff3_ft;

	// 	diff2_std = vv2_std.data() != vv_std.data() ? "True" : "False";
	// 	diff2_ft = vv2_ft.data() != vv_ft.data() ? "True" : "False";
	// 	diff3_std = vv2_std[0].data() != vv_std[0].data() ? "True" : "False";
	// 	diff3_ft = vv2_ft[0].data() != vv_ft[0].data() ? "True" : "False";
	// 	display_output("vector.data() != prev_vector.data(): ", diff2_std, diff2_ft);
	// 	display_output("vector[0].data() != prev_vector[0].data(): ", diff3_std, diff3_ft);
	// 	display_output("vector.size(): ", vv2_std.size(), vv2_ft.size());
	// 	display_output("vector[0].size(): ", vv2_std[0].size(), vv2_ft[0].size());
	// 	display_output("vector[0][0]: ", vv2_std[0][0], vv2_std[0][0]);
	// 	display_output("vector[1][0]: ", vv2_std[1][0], vv2_std[1][0]);
	// }
}
