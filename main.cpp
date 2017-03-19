#include <iostream>
#include <string>
#include "Assignment.hpp"
#include "AssignmentMeta.hpp"
#include "Student.hpp"

aMeta * getAssignmentInfo();
Student * gradeOneStudent(std::string);


int main() {
    // Store information on the current assignment
    aMeta * meta = getAssignmentInfo();
    Assignment * current = new Assignment(meta);
    current -> printAssignmentInfo();

    // Store students, one at a time
    current -> readStudents();
    current -> printStudentInfo();
}

aMeta * getAssignmentInfo() {
    std::string letters;
    std::cout << "Enter the class letters: ";
    std::cin >> letters;

    std::string number;
    std::cout << "Enter the class number(s)/letter(s): ";
    std::cin >> number;

    std::string aName;
    std::cout << "Enter the assignment name/number: ";
    std::cin >> aName;

    int aScore;
    std::cout << "Enter the assignment points: ";
    std::cin >> aScore;

    aMeta * data = new aMeta(aScore, aName, letters, number);
    return data;
}
