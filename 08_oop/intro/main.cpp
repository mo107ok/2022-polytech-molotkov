#include <iostream>
#include "String.h"

int main() {
  String s1("Hello");
  String s2("World");
  String s3 = s1 + s2;
  std::cout << s3 << std::endl;
  std::cout << s3.c_str() << std::endl;
  for (unsigned int i = 0; i < s3.get_length(); i++) std::cout << s3[i];
  std::cout << std::endl;
  return 0;
}