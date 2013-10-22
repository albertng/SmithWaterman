#include <iostream>
#include <string>
#include <sstream>
#include <list>

#define TEST "TEST"
int main(void) {
	int x = -1;
	std::string s;
	std::stringstream ss;
	ss << x;
	s = ss.str();
	std::cout << s << std::endl;

	ss << 2;
	s = ss.str();
	std::cout << s << std::endl;

	s = "here  is a    sentence";
	std::istringstream iss(s);
	while (iss) {
		std::string sub;
		iss >> sub;
		std::cout << sub;
	}
	std::cout<<"done"<<std::endl;

	s = "1 2 -2 -1 3 -1 -2";
	std::istringstream iss2(s);
	x = 0;
	while(iss2) {
		int y;
		iss2 >> y;
		std::cout << y << " ";
		x += y;
	}
	std::cout<<std::endl<<x<<std::endl;

	std::cout<<sizeof(int)<<std::endl;


	std::list<int> l;
	std::cout<<sizeof(l)<<std::endl;
	l.push_back(1);
	std::cout<<sizeof(l)<<std::endl;
	l.push_back(2);
	std::cout<<sizeof(l)<<std::endl;
	std::cout<<TEST<<std::endl;




	s = "asdf 1 24";
	int x1, x2;
	std::string s2;
	std::istringstream iss3(s);
	iss3 >> s2;
	iss3 >> x1;
	iss3 >> x2;
	std::cout<<s2<<" "<<x1+x2<<std::endl;

}
