#include "AssignmentMeta.hpp"
#include "colors.h"
#include <iostream>
#include <string>


aMeta::aMeta() {
    totalScore = 0;
    assignmentName = "";
    classLetters = "CS";
    classNumber = "";
}

aMeta::aMeta(int score, std::string name, std::string letters, std::string number, std::string password) {
    totalScore = score;
    assignmentName = name;
    classLetters = letters;
    classNumber = number;
    solutionPWD = password;
}

void aMeta::printClassMeta() {
    std::cout << GREEN << "\n-- Assignment metadata --------------------------------------" << std::endl;
    std::cout << "Class name: " << classLetters << classNumber << std::endl;
    std::cout << "Current assignment: " << assignmentName << std::endl;
    std::cout << "Assignment points: " << totalScore << std::endl;
    std::cout << "\nCompletion Message:\n";
    outPutFinishedMessage();
    std::cout << "-------------------------------------------------------------\n" << ENDCOLORS << std::endl;
}

int aMeta::getTotalScore() {
    return totalScore;
}

std::string aMeta::getAName() {
    return assignmentName;
}

void aMeta::outPutFinishedMessage() {
    std::cout << initialMessage << std::endl;
    std::cout << "URL: " << baseURL + classNumber + "/s" + assignmentName + "/s" + assignmentName + ".shtml" << std::endl;
    std::cout << "Username: " << "a" + assignmentName << std::endl;
    std::cout << "Password: " << solutionPWD << std::endl;
}

std::string aMeta::getAssignmentIdentifier() {
    return classLetters + classNumber + "_assignment" + assignmentName;
}
