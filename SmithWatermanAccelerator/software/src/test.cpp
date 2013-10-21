#include <iostream>

int main (void) {
  std::cout<<isdigit('1')<<" " <<isdigit('a')<<std::endl;
  if (isdigit('1')) {
    std::cout<<'1'<<std::endl;
  }
  if (isalpha('a')) {
    std::cout<<" a1"<<std::endl;
  }
  return 0;
}
