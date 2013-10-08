#include <iostream>

class TestClass {
  public:
    TestClass(int a) {
      std::cout<<"Constructor!"<<std::endl;
    }
/*    TestClass() {
      std::cout<<"Default Constructor!"<<std::endl;
      TestClass(0);
    };*/
    

    ~TestClass() {
      std::cout<<"Destructor!"<<std::endl;
    };

    void Go() {
      std::cout<<"Go!"<<std::endl;
    };
};

int main (void) {
  TestClass a[1](0);
  std::cout<<"Initialized"<<std::endl;
  for (int i = 0; i < 2; i++) {
    a[i] = TestClass(i);
  }

  for (int i = 0; i < 2; i++) {
    a[i].Go();
  }
  return 0;
} 
