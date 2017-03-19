#include "Student.hpp"
#include "keyWord.hpp"
#include <iostream>
#include <fstream>

Student::Student(std::string fname, char lInit) {
    first_name = fname;
    last_init = lInit;
    totalScore = 0;
    percentage = 0;
}

void Student::printStudent() {
    std::cout << first_name << " " << last_init << ". ----" << std::endl;
    std::cout << totalScore << " points for " << percentage << "%" << std::endl;
    printComments();
}

bool Student::runGrading(keyWord * keys) {
    std::string word;

    std::cout << "Please enter the keyword for the comment you'd like to enter (done to finish): " << std::endl;
    std::cin >> word;

    while (word != "done") {
        if (keys -> isProperKeyWord(word)) {
            std::string theComment = keys -> getComment(word);
            int theValue = keys -> getValue(word);
            addComment(theValue, theComment);
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

        std::cout << "Please enter the keyword for the comment you'd like to enter (done to finish): " << std::endl;
        std::cin >> word;
    }

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
    std::cout << "Would you like to enter a new keyWord for " << enteredWord << " ? (y/n)";
    std::cin >> result;

    if (result == 'y' || result == 'Y') {
        int value;
        std::string comment;

        std::cout << "Enter the point reduction for the keyWord (integer): ";
        std::cin >> value;
        std::cout << "Enter the full text for the comment: ";
        std::cin.ignore();
        std::getline(std::cin, comment);
        keys -> addKey(enteredWord, value, comment);

        std::ofstream outfile;

        outfile.open("keyWords.txt", std::ios_base::app);
        std::string outputStr = enteredWord + " " + std::to_string(value) + " " + comment;
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
