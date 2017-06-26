#include <string>
#include <iostream>
#include "Comment.hpp"
#include "colors.h"

Comment::Comment(int theDeduction, std::string theKey) {
    deduction = theDeduction;
    key = theKey;
}

void Comment::printComment() {
    if (deduction > 0)
        std::cout << "-" << deduction << " point(s) - " << key << std::endl << std::endl;
    else
        std::cout << key << std::endl << std::endl;
}
