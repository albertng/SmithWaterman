#include <iostream>
#include <dirent.h>
#include <errno.h>
#include <string>
#include <vector>

int GetDir(std::string dir, std::vector<std::string>* files) {
	DIR *dp;
	struct dirent *dirp;
	if ((dp = opendir(dir.c_str())) == NULL) {
		std::cout << "Error(" << errno << ") opening " << dir << std::endl;
		return errno;
	}

	while ((dirp = readdir(dp)) != NULL) {
		files->push_back(std::string(dirp->d_name));
	}
	closedir(dp);
	return 0;
}

int main(void) {
	std::string dir = std::string(".");
	std::vector<std::string> files = std::vector<std::string>();
	GetDir(dir, &files);
	for (int i = 0; i < files.size(); i++) {
		std::cout << files[i] << std::endl;
	}
	return 0;
}
