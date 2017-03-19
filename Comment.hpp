#include <string>
#include <vector>

#ifndef __Comment_DEF
#define __Comment_DEF

class Comment {
public:
    Comment(int deduction, std::string key);
    void printComment();
private:
    int deduction;
    std::string key;
};


#endif
