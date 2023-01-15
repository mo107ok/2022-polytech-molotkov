#pragma once
#include <string>
#include <iostream>

// student class with name and mark
class Student {
public:
    Student();
    Student(const std::string &name, int mark);
    ~Student();

    std::string getName() const;
    int getMark() const;
    void setMark(int mark);
    bool operator==(const Student &other) const;
    bool operator!=(const Student &other) const;
private:
    std::string name;
    int mark;
};

inline std::ostream& operator<<(std::ostream &out, const Student &student) {
    out << student.getName() << " " << student.getMark();
    return out;
}
