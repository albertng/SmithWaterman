#include <iostream>
#include <sstream>
#include <string>

int main (void) {
	std::string s = "1 2 3";
	std::istringstream iss(s);
	//iss.exceptions(std::ios::failbit | std::ios::eofbit);
	iss.exceptions(std::ios::failbit);
	try {
		int a, b, c, d;
		iss >> a;
		iss >> b;
		iss >> c;
		//iss >> d;
		d = 1/0;	
		std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<std::endl;
	//} catch(std::ios_base::failure &e) {
	} catch(const std::exception& e) {
		std::cerr << "Exception caught"<<e.what() << std::endl;
	}
}
