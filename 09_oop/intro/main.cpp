#include <iostream>

class Person {
public:
    Person() {
        std::cout << "Person::ctor" << std::endl;
    }
    virtual ~Person() {
        std::cout << "Person::dtor" << std::endl;
    }

    virtual void pay() {
        std::cout << "paid" << std::endl;
    }
};

class Student: public Person {
public:
    Student() {
        std::cout << "Student::ctor" << std::endl;
    }
    ~Student() override {
        std::cout << "Student::dtor" << std::endl;
    }
    void pay() override {
        std::cout << "paid scolarship" << std::endl;
    }
    int score{};
};

class Teacher: public Person {
public:
    Teacher() {
        std::cout << "Teacher::ctor" << std::endl;
    }
    ~Teacher() override {
        std::cout << "Teacher::dtor" << std::endl;
    }
    void pay() override {
        std::cout << "paid salary" << std::endl;
    }
};

class TA: public Teacher, public Student {
public:
    TA() {
        std::cout << "TA::ctor" << std::endl;
    }
    ~TA() override {
        std::cout << "TA::dtor" << std::endl;
    }
};


int main() {
    {
        std::cout << "Example 1" << std::endl;
        Student student;
        Teacher teacher;
        student.pay();
        teacher.pay();
    }

    {
        std::cout << std::endl;
        std::cout << "Example 2" << std::endl;
        Student student;
        Teacher teacher;
        Person *ptr_student = &student;
        Person *ptr_teacher = &teacher;
        ptr_student->pay();
        ptr_teacher->pay();
    }

    {
        std::cout << std::endl;
        std::cout << "Example 3" << std::endl;
        TA ta;
        ta.Student::pay();
        ta.Teacher::pay();
    }

    return 0;
}