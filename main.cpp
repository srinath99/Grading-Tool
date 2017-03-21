#include <iostream>
#include <string>
#include "Assignment.hpp"
#include "AssignmentMeta.hpp"
#include "Student.hpp"
#include "colors.h"


aMeta * getAssignmentInfo();
Student * gradeOneStudent(std::string);
void printReport(aMeta * meta, Assignment * assignment);


int main() {
    // Store information on the current assignment
    aMeta * meta = getAssignmentInfo();
    Assignment * current = new Assignment(meta);
    current -> printAssignmentInfo();

    // Store students, one at a time
    current -> readStudents(meta);
    printReport(meta, current);

    delete meta;
    delete current;

    return 0;
}

aMeta * getAssignmentInfo() {
    std::string letters;
    std::cout << BLUE << "Enter the class letters (i.e CS/CIS/etc.): " << ENDCOLORS;
    std::cin >> letters;

    std::string number;
    std::cout << BLUE << "Enter the class number(s)/letter(s)\n" << ENDCOLORS;
    std::cout << BLUE << "This must be exactly as it appears in the solution URL: " << ENDCOLORS;
    std::cin >> number;

    std::string aName;
    std::cout << BLUE << "Enter the assignment name/number: " << ENDCOLORS;
    std::cin >> aName;

    int aScore;
    std::cout << BLUE << "Enter the assignment points: " << ENDCOLORS;
    std::cin >> aScore;

    std::string password;
    std::cout << BLUE << "Please enter the password for this solution: " << ENDCOLORS;
    std::cin >> password;

    aMeta * data = new aMeta(aScore, aName, letters, number, password);
    return data;
}

void printReport(aMeta * meta, Assignment * current) {
    std::cout << GREEN << "\n\nFINAL GRADING REPORT FOR ASSIGNMENT ";
    std::cout << meta -> getAName() << ":\n" << ENDCOLORS;
    current -> printStudentInfo();
}
