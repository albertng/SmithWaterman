#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
	std::ifstream file(argv[1]);
	file.seekg(24);
	std::string line;
	getline(file, line);
	std::cout << line << std::endl;
}
