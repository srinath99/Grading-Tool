#include <string>
#include <iostream>
#include "Comment.hpp"

Comment::Comment(int theDeduction, std::string theKey) {
    deduction = theDeduction;
    key = theKey;
}

void Comment::printComment() {
    if (deduction > 0)
        std::cout << "-" << deduction << " point(s) - " << key << std::endl;
    else
        std::cout << key << std::endl;
}
