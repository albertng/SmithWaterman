#include <iostream>
#include <stdint.h>

int main (void) {
  uint32_t** asdf;
  asdf = new uint32_t* [2];
  for (int i = 0; i < 2; i++) {
    asdf[i] = new uint32_t [2];
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      asdf[i][j] = j;
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout<<asdf[i][j]<<" ";
    }
  }
  std::cout<<std::endl;
  return 0;
}
