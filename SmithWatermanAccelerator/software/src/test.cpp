#include <iostream>
#include <set>
int main(void) {
	std::set<int> s;
	s.insert(4);
	s.insert(3);
	s.insert(10);
	s.insert(11);
	s.insert(8);
	for (std::set<int>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout<<*it << std::endl;
	}
	std::cout << "Hello" << std::endl;
}
