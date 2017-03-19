#include <string>

#ifndef __AMETA_DEF
#define __AMETA_DEF

class aMeta {
public:
    aMeta();
    aMeta(int, std::string, std::string, std::string);
    void printClassMeta();
private:
    int totalScore;
    std::string assignmentName;
    std::string classNumber;
    std::string classLetters;
};
#endif
