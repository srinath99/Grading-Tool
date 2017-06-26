#include "keyWord.hpp"
#include "Comment.hpp"
#include "colors.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

keyWord::keyWord() {
}

bool keyWord::addKey(std::string key, int value, std::string comment){
    keyWordPoint[key] = value;
    keyWordComment[key] = comment;

    return true;
}

void keyWord::readKeys(std::string classNumber) {
    // Read the keyWords from the file
    std::string key;
    int value;
    std::string comment;
    std::string fileName = "keyWords_" + classNumber + ".txt";

    std::ifstream infile;
    infile.open (fileName);
    while (infile >> key >> value) {
        std::getline(infile, comment);
        addKey(key, value, comment);
    }

}

bool keyWord::isProperKeyWord(std::string key) {
    return !(keyWordPoint.find(key) == keyWordPoint.end() && keyWordComment.find(key) == keyWordComment.end());
}

std::string keyWord::getComment(std::string key) {
    return keyWordComment[key];
}

int keyWord::getValue(std::string key) {
    int defaultValue = keyWordPoint[key];
    char newValue[3] = "SN";

    std::cout << CYAN << "The default point deduction is " << defaultValue << ". Enter deduction for student if different: " << ENDCOLORS;
    std::cin.ignore();
    std::cin.getline(newValue, 3);

    if (isdigit(newValue[0])) {
        return atoi(newValue);
    }

    return defaultValue;
}

void keyWord::printComments() {
    std::cout << GREEN << "\nExisting deductions, keywords, and values ----------------------------------------------------------\n" << ENDCOLORS << std::endl;
    for( auto iter = keyWordComment.begin(); iter != keyWordComment.end(); ++iter )
        std::cout << GREEN << iter -> first << ENDCOLORS << " -" << BLUE << getValue(iter -> first) << ENDCOLORS << " point(s) - " <<  iter -> second << "\n\n";
    std::cout << GREEN << "----------------------------------------------------------------------------------------------------\n" << ENDCOLORS << std::endl;
}
