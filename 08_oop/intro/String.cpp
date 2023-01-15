#include <iostream>
#include <cstring>
#include "String.h"

String::String() {
  length = 0;
  data = new char[1];
  data[0] = '\0';
}

String::String(const char *init) {
  std::cout << "ctor" << std::endl;
  length = std::strlen(init);
  data = new char[length+1];
  std::strcpy(data, init);
}

String::~String() {
  delete[] data;
}

unsigned int String::get_length() const {
  return length;
}

const char *String::c_str() const {
  return data;
}

char String::operator[](unsigned int pos) {
  return data[pos];
}

String String::operator+(const String &other) {
  String result;
  result.length = length + other.length;
  delete[] result.data;
  result.data = new char[result.length + 1];
  std::strcpy(result.data, data);
  std::strcat(result.data, other.data);
  return result;
}