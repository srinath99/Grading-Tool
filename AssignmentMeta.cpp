#include "AssignmentMeta.hpp"
#include "colors.h"
#include <iostream>
#include <string>
#include <fstream>


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
    std::cout << "URL: " << patternMatchURL() << std::endl;
    std::cout << "Username: " << "a" + assignmentName << std::endl;
    std::cout << "Password: " << solutionPWD << std::endl;
}

std::string aMeta::getAssignmentIdentifier() {
    return classLetters + classNumber + "_assignment" + assignmentName;
}

std::string aMeta::patternMatchURL() {
    std::string pattern;
    std::string result = "";
    std::string key = "";
    std::ifstream infile;
    infile.open ("config.txt");
    std::getline(infile, pattern);
    for (unsigned long i = 0; i < pattern.size(); i++) {
        // If the character isn't a key delimiter add it
        if (pattern[i] != '%') {
            result = result + pattern[i];
        }
        // We are looking at a delimiter (%)
        else {
            i++; // increment past the delimiter
            key = ""; // reset the key - we are about to read it
            while (pattern[i] != '%') { // until the next delimiter, build the key
                key = key + pattern[i];
                i++;
            }
            // The key is done, now we use it to store the value
            if (key == "classNum")
                result = result + classNumber;
            else if (key == "assignment")
                result = result + assignmentName;
            // Now, we are looking at a delimiter, so the loop increments one past it.
        }
    }
    return result;

}
