#include <iostream>
#include <list>

int main(void) {
	std::list<int> l;
	l.push_front(5);
	l.push_front(10);
	l.push_front(3);
	l.push_front(7);
	l.push_front(4);
	l.push_front(1);
	l.push_front(2);
	
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout<<std::endl;

	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		std::cout<<"On "<<*it<<std::endl;
		std::list<int>::iterator it2 = it;
		for (it2++; it2 != l.end(); ++it2) {
			if (*it2 < *it) {
				std::cout << "Removing " << *it2 << std::endl;
				l.erase(it2);
				it2--;
			}
		}
	}
	std::cout<<std::endl;
}
