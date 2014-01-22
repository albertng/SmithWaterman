#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
	std::ifstream file(argv[1]);
	std::string line;
	long long int cur_pos;
	while (getline(file, line)) {
		std::cout << file.tellg() << std::endl;
		std::cout << line << std::endl;;
	}
}
