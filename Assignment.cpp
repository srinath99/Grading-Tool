#include <string>
#include <iostream>
#include "AssignmentMeta.hpp"
#include "Assignment.hpp"
#include "Student.hpp"

Assignment::Assignment(aMeta * data) {
    assignmentData = data;
}

void Assignment::printAssignmentInfo() {
    assignmentData -> printClassMeta();
}

void Assignment::printStudentInfo() {
    for (std::vector<Student *>::iterator it = students.begin(); it != students.end(); ++it)
        (*it) -> printStudent();
}

bool Assignment::addStudent(Student * myStudent) {
    students.push_back(myStudent);
    return true;
}

bool Assignment::readStudents() {
    keyWord * keys = new keyWord();
    keys -> readKeys();

    std::string fname;
    char linit;
    std::cout << "Enter the student's first name (quit to end): ";
    std::cin >> fname;

    do {
        std::cin >> linit;
        Student * myStudent = new Student(fname, linit);
        myStudent -> runGrading(keys);
        addStudent(myStudent);
        std::cout << "Enter the student's first name (quit to end): ";
        std::cin >> fname;
    } while (fname != "quit");

    return true;
}
