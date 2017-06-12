#include "keyWord.hpp"
#include "colors.h"
#include <string>
#include <fstream>

int main() {
    keyWord * keys = new keyWord();
    keys -> readKeys();
    keys -> printComments();

    delete keys;
    return 0;
}
