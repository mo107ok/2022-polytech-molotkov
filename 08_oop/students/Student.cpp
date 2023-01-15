#include "Student.h"

Student::Student() {
    name = "";
    mark = 0;
}

Student::Student(const std::string &name, int mark) {
    this->name = name;
    this->mark = mark;
}

Student::~Student() {}

std::string Student::getName() const {
    return name;
}

int Student::getMark() const {
    return mark;
}

void Student::setMark(int mark) {
    this->mark = mark;
}

bool Student::operator==(const Student &other) const {
    return name == other.name && mark == other.mark;
}

bool Student::operator!=(const Student &other) const {
    return !(name == other.name && mark == other.mark);
}
