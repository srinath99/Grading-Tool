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
    std::cout << "Enter the keyWord (something short and memorable - quit to stop): ";
    std::cin >> enteredWord;
    while (enteredWord != "quit") {
        std::cout << "Enter the deduction as an integer: ";
        std::cin >> value;
        std::cout << "Enter the comment you'd like to display for this keyword (no newlines, please!): ";
        std::cin.ignore();
        std::getline(std::cin, comment);
        keys -> addKey(enteredWord, value, comment);

        std::ofstream outfile;

        outfile.open("keyWords.txt", std::ios_base::app | std::ios_base::out);
        std::string outputStr = enteredWord + " " + std::to_string(value) + " " + comment + "\n";
        outfile << outputStr;

        std::cout << "Enter the keyWord (something short and memorable - quit to stop): ";
        std::cin >> enteredWord;
    }
}
