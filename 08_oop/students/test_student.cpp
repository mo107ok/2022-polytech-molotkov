#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Student.h"
#include "StudentList.h";

TEST_CASE("tests for Student") {
    CHECK_EQ(Student("John", 9).getName(), "John");
    CHECK_EQ(Student("John", 9).getMark(), 9);
    Student a = Student("John", 9);
    a.setMark(10);
    CHECK_EQ(a.getMark(), 10);
    CHECK_EQ(Student("John", 9), Student("John", 9));
    CHECK_EQ(Student("John", 9) != Student("John", 10), true);
}

TEST_CASE("tests for StudentList") {
    StudentList list;
    CHECK_EQ(list.getSize(), 0);
    list.addStudent(new Student("John", 9));
    CHECK_EQ(list.getSize(), 1);
    CHECK_EQ(list.getStudent(0), Student("John", 9));
    list.addStudent(new Student("Jane", 10));
    CHECK_EQ(list.getSize(), 2);
    CHECK_EQ(list.getStudent(1), Student("Jane", 10));
    list.removeStudent(new Student("John", 9));
    CHECK_EQ(list.getSize(), 1);
    CHECK_EQ(list.getStudent(0), Student("Jane", 10));
    list.giveMark(new Student("Jane", 10), 9);
    CHECK_EQ(list.getStudent(0), Student("Jane", 9));
    CHECK_EQ(list.getAverageMark(), 9);
    list.addStudent(new Student("John", 9));
    list.addStudent(new Student("Jack", 9));
    list.addStudent(new Student("Jill", 7));
    list.addStudent(new Student("Jenny", 6));
    list.addStudent(new Student("Jenny", 5));
    list.addStudent(new Student("Jenny", 4));
    list.addStudent(new Student("Jenny", 3));
    list.addStudent(new Student("Jenny", 2));
    list.addStudent(new Student("Jenny", 1));
    list.addStudent(new Student("Jenny", 1));
    CHECK_EQ(list.getBestStudents().getSize(), 3);
    CHECK_EQ(list.getWorstStudents().getSize(), 2);
    list.addStudent(new Student("Jenny", 10));
    CHECK_EQ(list.getAverageMark(), 5.5);
}
