#include <string>
#include <iostream>
#include "AssignmentMeta.hpp"
#include "Assignment.hpp"
#include "Student.hpp"
#include "colors.h"

Assignment::Assignment(aMeta * data) {
    assignmentData = data;
}

void Assignment::printAssignmentInfo() {
    assignmentData -> printClassMeta();
}

void Assignment::printStudentInfo() {
    for (std::vector<Student *>::iterator it = students.begin(); it != students.end(); ++it)
        (*it) -> printStudent(assignmentData);
}

bool Assignment::addStudent(Student * myStudent) {
    students.push_back(myStudent);
    return true;
}

bool Assignment::readStudents(aMeta * meta) {
    keyWord * keys = new keyWord();
    keys -> readKeys();

    std::string fname;
    char linit;
    std::cout << BLUE << "Enter the student's first name (quit to end): " << ENDCOLORS;
    std::cin >> fname;

    do {
        std::cin >> linit;
        Student * myStudent = new Student(fname, linit);
        myStudent -> runGrading(keys, meta);
        addStudent(myStudent);
        myStudent -> printStudent(meta);
        // meta -> outPutFinishedMessage();
        std::cout << BLUE << "Enter the student's first name (quit to end): " << ENDCOLORS;
        std::cin >> fname;
    } while (fname != "quit");

    return true;
}
