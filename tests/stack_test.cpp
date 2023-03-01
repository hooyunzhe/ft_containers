#include "test.hpp"

void	stack_constructors(void) {
	{
		display_header("Default constructor", "stack<int>", 24);

		std::stack<int>	is_std;
		ft::stack<int>	is_ft;
		std::stack<int, std::list<int> >	is2_std;
		ft::stack<int, std::list<int> >		is2_ft;

		display_output("stack<int>", "", "", 0);
		display_equality("empty()", is_std.empty(), is_ft.empty());
		display_output("size()", is_std.size(), is_ft.size(), 1);
		display_output("stack<int, list<int>>", "", "", 0);
		display_equality("empty()", is2_std.empty(), is2_ft.empty());
		display_output("size()", is2_std.size(), is2_ft.size(), 1);
	}
	{
		std::vector<int>	iv_std(2, 42);
		ft::vector<int>		iv_ft(2, 42);

		std::stack<int, std::vector<int> >	is_std(iv_std);
		ft::stack<int, ft::vector<int> >	is_ft(iv_ft);

		display_output("stack<int, vector<int>>", "", "", 0);
		display_output("top()", is_std.top(), is_ft.top(), 2);
		display_equality("empty()", is_std.empty(), is_ft.empty());
		display_output("size()", is_std.size(), is_ft.size(), 1);
	}
	{
		std::list<int>		il_std(2, 42);
		std::stack<int, std::list<int> >	is_std(il_std);
		ft::stack<int, std::list<int> >		is_ft(il_std);
		
		display_output("stack<int, list<int>>", "", "", 0);
		display_output("top()", is_std.top(), is_ft.top(), 2);
		display_equality("empty()", is_std.empty(), is_ft.empty());
		display_output("size()", is_std.size(), is_ft.size(), 1);
	}
}

void	stack_assignment(void) {
	{
		display_header("Assignment operator=", "stack<int>", 24);
		std::stack<int, std::vector<int> >	is_std(std::vector<int>(2, 24));
		ft::stack<int, ft::vector<int> >	is_ft(ft::vector<int>(2, 24));
		std::stack<int, std::vector<int> >	is2_std(std::vector<int>(2, 42));
		ft::stack<int, ft::vector<int> >	is2_ft(ft::vector<int>(2, 42));

		display_output("stack<int, vector<int>>", "", "", 0);
		display_output("before assignment", is_std.top(), is_ft.top(), 2);
		is_std = is2_std;
		is_ft = is2_ft;
		display_output("after assignment", is_std.top(), is_ft.top(), 2);
	}
	{
		std::stack<int, std::list<int> >	is_std(std::list<int>(2, 24));
		ft::stack<int, std::list<int> >		is_ft(std::list<int>(2, 24));
		std::stack<int, std::list<int> >	is2_std(std::list<int>(2, 42));
		ft::stack<int, std::list<int> >		is2_ft(std::list<int>(2, 42));

		display_output("stack<int, list<int>>", "", "", 0);
		display_output("before assignment", is_std.top(), is_ft.top(), 2);
		is_std = is2_std;
		is_ft = is2_ft;
		display_output("after assignment", is_std.top(), is_ft.top(), 2);
	}
}

void	stack_modifiers(void) {
	{
		display_header("Modifiers", "stack<int>", 24);
		std::stack<int, std::vector<int> >	is_std(std::vector<int>(2, 42));
		ft::stack<int, ft::vector<int> >	is_ft(ft::vector<int>(2, 42));
		std::stack<int, std::vector<int> >	is2_std(std::vector<int>(3, 24));
		ft::stack<int, ft::vector<int> >	is2_ft(ft::vector<int>(3, 24));

		display_output("stack<int, vector<int>>", "", "", 0);
		display_output("size()", is_std.size(), is_ft.size(), 1);
		display_output("before push(4242)", is_std.top(), is_ft.top(), 2);
		is_std.push(4242);
		is_ft.push(4242);
		display_output("after push(4242)", is_std.top(), is_ft.top(), 4);
		display_output("size()", is_std.size(), is_ft.size(), 1);
		is_std.pop();
		is_ft.pop();
		display_output("after pop()", is_std.top(), is_ft.top(), 2);
		display_output("size()", is_std.size(), is_ft.size(), 1);
		display_output("stack2 top()", is2_std.top(), is2_ft.top(), 2);
		display_output("stack2 size()", is2_std.size(), is2_ft.size(), 1);
		is_std.swap(is2_std);
		is_ft.swap(is2_ft);
		display_output("after swap()", "", "", 0);
		display_output("stack top()", is_std.top(), is_ft.top(), 2);
		display_output("stack size()", is_std.size(), is_ft.size(), 1);
		display_output("stack2 top()", is2_std.top(), is2_ft.top(), 2);
		display_output("stack2 size()", is2_std.size(), is2_ft.size(), 1);
		std::swap(is_std, is2_std);
		ft::swap(is_ft, is2_ft);
		display_output("after std/ft::swap()", "", "", 0);
		display_output("stack top()", is_std.top(), is_ft.top(), 2);
		display_output("stack size()", is_std.size(), is_ft.size(), 1);
		display_output("stack2 top()", is2_std.top(), is2_ft.top(), 2);
		display_output("stack2 size()", is2_std.size(), is2_ft.size(), 1);
	}
	{
		std::stack<int, std::list<int> >	is_std(std::list<int>(2, 42));
		ft::stack<int, std::list<int> >	is_ft(std::list<int>(2, 42));
		std::stack<int, std::list<int> >	is2_std(std::list<int>(3, 24));
		ft::stack<int, std::list<int> >	is2_ft(std::list<int>(3, 24));

		display_output("stack<int, list<int>>", "", "", 0);
		display_output("size()", is_std.size(), is_ft.size(), 1);
		display_output("before push(4242)", is_std.top(), is_ft.top(), 2);
		is_std.push(4242);
		is_ft.push(4242);
		display_output("after push(4242)", is_std.top(), is_ft.top(), 4);
		display_output("size()", is_std.size(), is_ft.size(), 1);
		is_std.pop();
		is_ft.pop();
		display_output("after pop()", is_std.top(), is_ft.top(), 2);
		display_output("size()", is_std.size(), is_ft.size(), 1);
		display_output("stack2 top()", is2_std.top(), is2_ft.top(), 2);
		display_output("stack2 size()", is2_std.size(), is2_ft.size(), 1);
		is_std.swap(is2_std);
		is_ft.swap(is2_ft);
		display_output("after swap()", "", "", 0);
		display_output("stack top()", is_std.top(), is_ft.top(), 2);
		display_output("stack size()", is_std.size(), is_ft.size(), 1);
		display_output("stack2 top()", is2_std.top(), is2_ft.top(), 2);
		display_output("stack2 size()", is2_std.size(), is2_ft.size(), 1);
		std::swap(is_std, is2_std);
		ft::swap(is_ft, is2_ft);
		display_output("after std/ft::swap()", "", "", 0);
		display_output("stack top()", is_std.top(), is_ft.top(), 2);
		display_output("stack size()", is_std.size(), is_ft.size(), 1);
		display_output("stack2 top()", is2_std.top(), is2_ft.top(), 2);
		display_output("stack2 size()", is2_std.size(), is2_ft.size(), 1);
	}
}

void	stack_relational(void) {
	{
		display_header("Relational Operators", "stack<int>", 24, 6);
		display_output("stack<int, vector<int>>", "", "", 0);
		std::vector<int>	iv_std;
		ft::vector<int>		iv_ft;
		std::vector<int>	iv2_std;
		ft::vector<int>		iv2_ft;
		std::vector<int>	iv3_std;
		ft::vector<int>		iv3_ft;
		
		iv_std.push_back(1);
		iv_std.push_back(2);
		iv_std.push_back(3);
		iv_ft.push_back(1);
		iv_ft.push_back(2);
		iv_ft.push_back(3);
		iv2_std.push_back(1);
		iv2_std.push_back(2);
		iv2_std.push_back(3);
		iv2_ft.push_back(1);
		iv2_ft.push_back(2);
		iv2_ft.push_back(3);
		iv3_std.push_back(1);
		iv3_std.push_back(2);
		iv3_std.push_back(42);
		iv3_ft.push_back(1);
		iv3_ft.push_back(2);
		iv3_ft.push_back(42);
		display_elements(iv_std, iv_ft, "vector1 elements", 6);
		display_elements(iv2_std, iv2_ft, "vector2 elements", 6);
		display_elements(iv3_std, iv3_ft, "vector3 elements", 6);

		std::stack<int, std::vector<int> >	is_std(iv_std);
		ft::stack<int, ft::vector<int> >	is_ft(iv_ft);
		std::stack<int, std::vector<int> >	is2_std(iv2_std);
		ft::stack<int, ft::vector<int> >	is2_ft(iv2_ft);
		std::stack<int, std::vector<int> >	is3_std(iv3_std);
		ft::stack<int, ft::vector<int> >	is3_ft(iv3_ft);

		display_equality("operator== (v, v2)", is_std == is2_std, is_ft == is2_ft, 6);
		display_equality("operator== (v1, v42)", is_std == is3_std, is_ft == is3_ft, 6);
		display_equality("operator!= (v1, v42)", is_std != is3_std, is_ft != is3_ft, 6);
		display_equality("operator!= (v1, v2)", is_std != is2_std, is_ft != is2_ft, 6);
		display_equality("operator< (v1, v42)", is_std < is3_std, is_ft < is3_ft, 6);
		display_equality("operator< (v1, v2)", is_std < is2_std, is_ft < is2_ft, 6);
		display_equality("operator<= (v1, v2)", is_std <= is2_std, is_ft <= is2_ft, 6);
		display_equality("operator<= (v42, v1)", is3_std <= is_std, is3_ft <= is_ft, 6);
		display_equality("operator> (v42, v1)", is3_std > is_std, is3_ft > is_ft, 6);
		display_equality("operator> (v1, v2)", is_std > is2_std, is_ft > is2_ft, 6);
		display_equality("operator>= (v1, v2)", is_std >= is2_std, is_ft >= is2_ft, 6);
		display_equality("operator>= (v1, v42)", is_std >= is3_std, is_ft >= is3_ft, 6);
	}
	{
		display_output("stack<int, list<int>>", "", "", 0);
		std::list<int>	iv_std;
		std::list<int>	iv_ft;
		std::list<int>	iv2_std;
		std::list<int>	iv2_ft;
		std::list<int>	iv3_std;
		std::list<int>	iv3_ft;
		
		iv_std.push_back(1);
		iv_std.push_back(2);
		iv_std.push_back(3);
		iv_ft.push_back(1);
		iv_ft.push_back(2);
		iv_ft.push_back(3);
		iv2_std.push_back(1);
		iv2_std.push_back(2);
		iv2_std.push_back(3);
		iv2_ft.push_back(1);
		iv2_ft.push_back(2);
		iv2_ft.push_back(3);
		iv3_std.push_back(1);
		iv3_std.push_back(2);
		iv3_std.push_back(42);
		iv3_ft.push_back(1);
		iv3_ft.push_back(2);
		iv3_ft.push_back(42);
		display_elements(iv_std, iv_ft, "vector1 elements", 6);
		display_elements(iv2_std, iv2_ft, "vector2 elements", 6);
		display_elements(iv3_std, iv3_ft, "vector3 elements", 6);

		std::stack<int, std::list<int> >	is_std(iv_std);
		ft::stack<int, std::list<int> >		is_ft(iv_ft);
		std::stack<int, std::list<int> >	is2_std(iv2_std);
		ft::stack<int, std::list<int> >		is2_ft(iv2_ft);
		std::stack<int, std::list<int> >	is3_std(iv3_std);
		ft::stack<int, std::list<int> >		is3_ft(iv3_ft);

		display_equality("operator== (v, v2)", is_std == is2_std, is_ft == is2_ft, 6);
		display_equality("operator== (v1, v42)", is_std == is3_std, is_ft == is3_ft, 6);
		display_equality("operator!= (v1, v42)", is_std != is3_std, is_ft != is3_ft, 6);
		display_equality("operator!= (v1, v2)", is_std != is2_std, is_ft != is2_ft, 6);
		display_equality("operator< (v1, v42)", is_std < is3_std, is_ft < is3_ft, 6);
		display_equality("operator< (v1, v2)", is_std < is2_std, is_ft < is2_ft, 6);
		display_equality("operator<= (v1, v2)", is_std <= is2_std, is_ft <= is2_ft, 6);
		display_equality("operator<= (v42, v1)", is3_std <= is_std, is3_ft <= is_ft, 6);
		display_equality("operator> (v42, v1)", is3_std > is_std, is3_ft > is_ft, 6);
		display_equality("operator> (v1, v2)", is_std > is2_std, is_ft > is2_ft, 6);
		display_equality("operator>= (v1, v2)", is_std >= is2_std, is_ft >= is2_ft, 6);
		display_equality("operator>= (v1, v42)", is_std >= is3_std, is_ft >= is3_ft, 6);
	}
}

void	stack_test(void) {
	stack_constructors();
	stack_assignment();
	stack_modifiers();
	stack_relational();
}
