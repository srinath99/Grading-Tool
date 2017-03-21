#include "keyWord.hpp"
#include "colors.h"
#include <string>
#include <fstream>

int main() {
    keyWord * keys = new keyWord();
    keys -> readKeys();
    keys -> printComments();
    std::cout << "Add a key to make grading faster, easier, and more efficient!" << std::endl;
    std::string enteredWord, comment;
    int value;
    std::cout << BLUE << "Enter the keyWord (something short and memorable - quit to stop): " << ENDCOLORS;
    std::cin >> enteredWord;
    while (enteredWord != "quit") {
        std::cout << BLUE << "Enter the deduction as an integer: " << ENDCOLORS;
        std::cin >> value;
        std::cout << BLUE << "Enter the comment you'd like to display for this keyword (no newlines, please!): " << ENDCOLORS;
        std::cin.ignore();
        std::getline(std::cin, comment);
        keys -> addKey(enteredWord, value, comment);
        std::ofstream outfile;

        outfile.open("keyWords.txt", std::ios_base::app);
        std::string outputStr = enteredWord + " " + std::to_string(value) + " " + comment + "\n";
        std::cout << "The new entry is:\n" << outputStr << std::endl;
        outfile << outputStr;

        std::cout << BLUE << "Enter the keyWord (something short and memorable - quit to stop): " << ENDCOLORS;
        std::cin >> enteredWord;
    }
}
