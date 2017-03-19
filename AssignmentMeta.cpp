#include "AssignmentMeta.hpp"
#include <iostream>
#include <string>


aMeta::aMeta() {
    totalScore = 0;
    assignmentName = "";
    classLetters = "CS";
    classNumber = "";
}

aMeta::aMeta(int score, std::string name, std::string letters, std::string number) {
    totalScore = score;
    assignmentName = name;
    classLetters = letters;
    classNumber = number;
}

void aMeta::printClassMeta() {
    std::cout << "-- Assignment metadata --------------------------------------" << std::endl;
    std::cout << "Class name: " << classLetters << classNumber << std::endl;
    std::cout << "Current assignment: " << assignmentName << std::endl;
    std::cout << "Assignment points: " << totalScore << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
}
