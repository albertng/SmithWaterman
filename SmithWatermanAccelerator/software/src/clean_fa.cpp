#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Usage: ./clean_fa <INPUT FILE> <OUTPUT FILE>" << std::endl;
    return 1;
  }

  std::ifstream in_file(argv[1]);
  std::ofstream out_file(argv[2]);

  bool name_line = true;
  std::string line;
  while (getline(in_file, line)) {
    if (line.size() == 0) {
      continue;
    }
    if (name_line) {
      out_file << line << '\n';
      name_line = false;
    } else {
      while (line.size() != 0) {
        int len = line.size() < 50 ? line.size() : 50;
        out_file << line.substr(0, len) << '\n';
        line = line.substr(len);
      }
      name_line = true;
    }
  }
  in_file.close();
  out_file.close();
}
