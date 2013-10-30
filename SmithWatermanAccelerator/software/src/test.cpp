#include <iostream>

int main(void) {
	int (*asdf)[5];
	int ghjk[5];
	ghjk[0] = 1;
	asdf = &ghjk;
	std::cout<<(*asdf)[0]<<std::endl;
}
