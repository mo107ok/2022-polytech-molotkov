#include "StudentList.h"

StudentList::StudentList() {
    students = new Student[0];
    size = 0;
}

StudentList::~StudentList() {
    delete[] students;
}

int StudentList::getSize() const {
    return size;
}

Student StudentList::getStudent(int index) const {
    return students[index];
}

void StudentList::addStudent(Student* student) {
    auto* newStudents = new Student[size + 1];
    for (int i = 0; i < size; i++) {
        newStudents[i] = students[i];
    }
    newStudents[size] = *student;
    delete[] students;
    students = newStudents;
    size++;
}

void StudentList::removeStudent(Student* student) {
    auto* newStudents = new Student[size - 1];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (students[i] != *student) {
            newStudents[j] = students[i];
            j++;
        }
    }
    delete[] students;
    students = newStudents;
    size--;
}

void StudentList::giveMark(Student *student, int mark) {
    for (int i = 0; i < size; i++) {
        if (students[i] == *student) {
            students[i].setMark(mark);
        }
    }
}

double StudentList::getAverageMark() {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += students[i].getMark();
    }
    return sum / size;
}

StudentList StudentList::getBestStudents() {
    StudentList bestStudents;
    int maxMark = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].getMark() > maxMark) {
            maxMark = students[i].getMark();
        }
    }
    for (int i = 0; i < size; i++) {
        if (students[i].getMark() == maxMark) {
            bestStudents.addStudent(&students[i]);
        }
    }
    return bestStudents;
}

StudentList StudentList::getWorstStudents() {
    StudentList worstStudents;
    int minMark = 10;
    for (int i = 0; i < size; i++) {
        if (students[i].getMark() < minMark) {
            minMark = students[i].getMark();
        }
    }
    for (int i = 0; i < size; i++) {
        if (students[i].getMark() == minMark) {
            worstStudents.addStudent(&students[i]);
        }
    }
    return worstStudents;
}
