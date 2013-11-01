#include <set>
#include <iostream>

struct classcomp {
	bool operator() (const int& lhs, const int& rhs) const {
		return lhs > rhs;
	}
};

int main(void) {
	std::set<int, classcomp> s;
	s.insert(10);
	s.insert(5);
	s.insert(15);
	for (std::set<int, classcomp>::iterator it = s.begin(); it != s.end(); ++it) {
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
}
