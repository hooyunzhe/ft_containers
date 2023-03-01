#include "test.hpp"

void	map_constructors() {
	display_header("Default constructor", "map<string, int>");
	std::map<string, int>	sim_std;
	ft::map<string, int>	sim_ft;

	display_output("size()", sim_std.size(), sim_ft.size(), 1);

	display_header("Range constructor (begin(), end())", "map<string, int>{(A,1), (B,2)}", "map<string, int>", 0, 10);
	sim_std.insert(std::make_pair("A", 1));
	sim_std.insert(std::make_pair("B", 2));
	sim_ft.insert(ft::make_pair("A", 1));
	sim_ft.insert(ft::make_pair("B", 2));
	std::map<string, int>	sim2_std(sim_std.begin(), sim_std.end());
	ft::map<string, int>	sim2_ft(sim_ft.begin(), sim_ft.end());

	display_output("size()", sim_std.size(), sim_ft.size(), 1, 10);
	display_map_elements(sim2_std, sim2_ft, "elements", 10);

	display_header("Copy constructor (map<string, int>{(A,1), (B,2)})", "map<string, int>");
	std::map<string, int>	sim3_std(sim2_std);
	ft::map<string, int>	sim3_ft(sim2_ft);

	display_output("size()", sim_std.size(), sim_ft.size(), 1, 10);
	display_map_elements(sim2_std, sim2_ft, "elements", 10);
}

void	map_assignment(void) {
	display_header("Assignment operator= (map<string, int>{(A,42), (B,42)})", "map<string, int>", 17, 12);
	std::map<string, int>	sim_std;
	ft::map<string, int>	sim_ft;
	std::map<string, int>	sim2_std;
	ft::map<string, int>	sim2_ft;

	sim_std.insert(std::make_pair("A", 1));
	sim_std.insert(std::make_pair("B", 2));
	sim_ft.insert(ft::make_pair("A", 1));
	sim_ft.insert(ft::make_pair("B", 2));
	sim2_std.insert(std::make_pair("A", 42));
	sim2_std.insert(std::make_pair("B", 42));
	sim2_ft.insert(ft::make_pair("A", 42));
	sim2_ft.insert(ft::make_pair("B", 42));
	
	display_map_elements(sim_std, sim_ft, "before assignment", 12);
	sim_std = sim2_std;
	sim_ft = sim2_ft;
	display_map_elements(sim_std, sim_ft, "after assignment", 12);
}

void	map_get_allocator(void) {
	display_header("get_allocator", "map<string, int>(std::allocator<int>())", "map<int>");
	std::allocator<std::pair<const string, int> >	alloc_std;
	std::allocator<ft::pair<const string, int> >	alloc_ft;
	std::map<string, int>	sim_std(alloc_std);
	ft::map<string, int>	sim_ft(std::less<string>(), alloc_ft);

	display_equality("type == std::allocator<int>", typeid(sim_std.get_allocator()).name() == typeid(alloc_std).name(), typeid(sim_ft.get_allocator()).name() == typeid(alloc_ft).name());
}

void	map_element_access(void) {
	display_header("Element Access", "map<string, int>{(C,3), (D,4)}", "map<string, int>");
	std::map<string, int>	sim_std;
	ft::map<string, int>	sim_ft;

	sim_std.insert(std::make_pair("C", 3));
	sim_std.insert(std::make_pair("D", 4));
	sim_ft.insert(ft::make_pair("C", 3));
	sim_ft.insert(ft::make_pair("D", 4));

	display_output("at(\"C\")", sim_std.at("C"), sim_ft.at("C"), 1);
	sim_std.at("C") = 42;
	sim_ft.at("C") = 42;
	display_output("map.at(\"C\") = 42", sim_std.at("C"), sim_ft.at("C"), 2);
	display_output("operator[] (\"D\")", sim_std["D"], sim_ft["D"], 1);
	sim_std["D"] = 42;
	sim_ft["D"] = 42;
	display_output("map[\"D\"] = 42", sim_std["D"], sim_ft["D"], 2);
	display_output("before insertion size()", sim_std.size(), sim_ft.size(), 1);
	sim_std["E"] = 5;
	sim_ft["E"] = 5;
	display_output("map[\"E\"] = 5", sim_std["E"], sim_ft["E"], 1);
	display_output("after insertion size()", sim_std.size(), sim_ft.size(), 1);
}

void	map_test(void) {
	// map_constructors();
	// map_assignment();
	// map_get_allocator();
	map_element_access();
}