#include <string>
#include <vector>
#include "Comment.hpp"
#include "keyWord.hpp"
#include "AssignmentMeta.hpp"

#ifndef __Student_DEF
#define __Student_DEF

class Student {
public:
    Student(std::string fname, char lInit, std::string classNumber);
    void printStudent(aMeta * meta);
    bool runGrading(keyWord * keys, aMeta * meta);
    void writeStudentToFile(aMeta * meta);

private:
    std::string first_name;
    std::string class_number;
    char last_init;
    int totalScore;
    double percentage;
    std::vector<Comment *> allComments;
    bool addComment(int value, std::string comment);
    bool addKeyWord(keyWord * keys, std::string enteredWord);
    void printComments();
    std::string getQualifier(int percentage);



};


#endif
