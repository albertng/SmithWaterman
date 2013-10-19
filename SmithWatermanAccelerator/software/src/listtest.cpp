#include <list>
#include <iostream>

int main(void) {
  std::list<int> l;
  l.push_back(0);
  l.push_back(1);
  l.push_back(2);

  for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
    std::cout<<*it<<" ";
  }
  std::cout<<std::endl;

  std::list<int>::iterator it = l.begin();
  ++it;
  l.insert(it, 10);
  it = l.erase(it);
  --it;
  ++it;
  l.insert(it, 20);
  it = l.erase(it);
  
  for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
    std::cout<<*it<<" ";
  }
  std::cout<<std::endl;

  return 0;
}
