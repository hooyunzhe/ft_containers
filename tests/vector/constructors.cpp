#include "test.hpp"

void	constructor(void) {
	vector<int>	v1;

	cout << "First element of a newly initialized vector<int>: " << v1[0] << endl;
	v1.push_back(42);
	cout << "Last element of vector after push back: " << v1.back() << endl;
}
