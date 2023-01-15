#pragma once

class String {
public:
  String();
  String(const char* init);
  ~String();

  unsigned int get_length() const;
  const char* c_str() const;

  char operator[](unsigned int pos);
  String operator+(const String& other);
private:
  unsigned int length;
  char* data;
};

inline std::ostream & operator << (std::ostream& out, const String& other) {
  out << other.c_str();
  return out;
}