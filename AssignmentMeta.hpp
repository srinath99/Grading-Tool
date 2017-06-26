#include <string>

#ifndef __AMETA_DEF
#define __AMETA_DEF

class aMeta {
public:
    aMeta();
    aMeta(int, std::string, std::string, std::string, std::string);
    void printClassMeta();
    int getTotalScore();
    std::string getAName();
    void outPutFinishedMessage();
    std::string getAssignmentIdentifier();
    std::string getClassNumber();
private:
    int totalScore;
    std::string assignmentName;
    std::string classNumber;
    std::string classLetters;
    std::string initialMessage = "Here is the information to view the solution. Please do NOT share it with anyone else.";
    std::string solutionPWD;
    std::string patternMatchURL();



};
#endif
