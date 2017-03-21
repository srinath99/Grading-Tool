#include "Student.hpp"
#include "keyWord.hpp"
#include "AssignmentMeta.hpp"
#include "colors.h"
#include <iostream>
#include <fstream>

Student::Student(std::string fname, char lInit) {
    first_name = fname;
    last_init = lInit;
    totalScore = 0;
    percentage = 0;
}

void Student::printStudent(aMeta * meta) {
    std::cout << std::endl;
    std::cout << PINK << first_name << " " << last_init << ". ----" << ENDCOLORS << std::endl;
    std::cout << totalScore << " points for " << percentage << "%\n" << std::endl;
    printComments();
    if (percentage < 50.0) {
        std::cout << RED << "\nThis score received less than 50%. Please don't include\nthe solution in your comment.\n" << ENDCOLORS;
    } else {
        std::cout << "\n";
        meta -> outPutFinishedMessage();
        std::cout << "\n";
    }
    std::cout << "\n";
}

bool Student::runGrading(keyWord * keys, aMeta * meta) {
    std::string word;

    std::cout << BLUE << "Please enter the keyword for the comment you'd like to enter (done to finish): " << ENDCOLORS;
    std::cin >> word;

    while (word != "done") {
        if (keys -> isProperKeyWord(word)) {
            std::string theComment = keys -> getComment(word);
            int theValue = keys -> getValue(word);
            addComment(theValue, theComment);
        }
        else if (word == "custom") {
            std::string tempComment;
            int tempValue;
            std::cout << BLUE << "Please enter the comment you'd like to enter: " << ENDCOLORS;
            std::cin.ignore();
            std::getline(std::cin, tempComment);
            std::cout << BLUE << "Please enter the point deduction (integer): " << ENDCOLORS;
            std::cin >> tempValue;
            addComment(tempValue, tempComment);
        }
        else if (word == "fail"){
            addComment(meta -> getTotalScore(), "Unfortunately, this solution does not work well enough or follow the instructions properly to receive credit");
            break;
        } else {
            if (word != "done") {
                bool added = addKeyWord(keys, word);
                if (added) {
                    if (keys -> isProperKeyWord(word)) {
                        std::string theComment = keys -> getComment(word);
                        int theValue = keys -> getValue(word);
                        addComment(theValue, theComment);
                    }
                }
            }
        }

        std::cout << BLUE << "Please enter the keyword for the comment you'd like to enter (done to finish): " << ENDCOLORS;
        std::cin >> word;
    }
    int numWrong = totalScore;
    totalScore = meta -> getTotalScore() + numWrong;
    percentage = (double)totalScore / meta -> getTotalScore() * 100;

    return true;
}

bool Student::addComment(int value, std::string comment) {
    totalScore -= value;
    Comment * myComment = new Comment(value, comment);
    allComments.push_back(myComment);
    return true;
}

bool Student::addKeyWord(keyWord * keys, std::string enteredWord) {
    char result;
    std::cout << BLUE << "Would you like to enter a new keyWord for " << enteredWord << " ? (y/n)" << ENDCOLORS;
    std::cin >> result;

    if (result == 'y' || result == 'Y') {
        int value;
        std::string comment;

        std::cout << BLUE <<  "Enter the point reduction for the keyWord (integer): " << ENDCOLORS;
        std::cin >> value;
        std::cout << BLUE << "Enter the full text for the comment: " << ENDCOLORS;
        std::cin.ignore();
        std::getline(std::cin, comment);
        keys -> addKey(enteredWord, value, comment);

        std::ofstream outfile;

        outfile.open("keyWords.txt", std::ios_base::app | std::ios_base::out);
        std::string outputStr = enteredWord + " " + std::to_string(value) + " " + comment + "\n";
        outfile << outputStr;

        return true;
    }
    return false;
}

void Student::printComments() {
    std::cout << "Comments: " << std::endl;
    for (std::vector<Comment *>::iterator it = allComments.begin(); it != allComments.end(); ++it)
        (*it) -> printComment();
}
