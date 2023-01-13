// #include "vector.hpp"
#include <iostream>
#include <iterator>
#include <vector>

// using namespace	ft;

int	main(void) {
	std::vector<int>	iv(5, 100);
	std::vector<int>	sv(5, 69);
	std::vector<std::vector<int> >	vv(5, iv);

	std::vector<std::vector<int> >::iterator	it = vv.begin();
	
	std::cout << &it << std::endl;
	vv.insert(vv.begin() + 3, 0, sv);
	std::cout << &it << std::endl;
}
