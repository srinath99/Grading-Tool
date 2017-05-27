#include <iostream>
#include <string>
#include <fstream>
#include "Assignment.hpp"
#include "AssignmentMeta.hpp"
#include "Student.hpp"
#include "colors.h"


aMeta * getAssignmentInfo();
Student * gradeOneStudent(std::string);
void printReport(aMeta * meta, Assignment * assignment);


int main() {

    std::ifstream currentFile;
    currentFile.open("currentClass.txt");
    aMeta * meta = nullptr;
    if (currentFile.is_open()) {
        char result;
        std::cout << BLUE << "There's an existing file being graded. Would you like to load the settings? (y/n) " << ENDCOLORS;
        std::cin >> result;
        if (result == 'y' || result == 'Y') {
            std::string letters, classLetters, assignmentName, password;
            int numPoints;

            currentFile >> letters;
            currentFile >> classLetters;
            currentFile >> assignmentName;
            currentFile >> numPoints;
            currentFile >> password;
            
            meta = new aMeta(numPoints, assignmentName, letters, classLetters, password);

        } else {
            meta = getAssignmentInfo();
        }
    } else {
        meta = getAssignmentInfo();
    }
    // Store information on the current assignment
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

    std::ofstream newFile("currentClass.txt");
    newFile << letters << std::endl << number << std::endl << aName << std::endl << aScore << std::endl << password;
    newFile.close();
    return data;
}

void printReport(aMeta * meta, Assignment * current) {
    std::cout << GREEN << "\n\nFINAL GRADING REPORT FOR ASSIGNMENT ";
    std::cout << meta -> getAName() << ":\n" << ENDCOLORS;
    current -> printStudentInfo();
}
