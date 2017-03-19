#include <string>
#include <vector>

#include "AssignmentMeta.hpp"
#include "Student.hpp"
#include "keyWord.hpp"


#ifndef __A_DEF
#define __A_DEF

class Assignment {
public:
    Assignment(aMeta * data);
    void printAssignmentInfo();
    void printStudentInfo();
    bool addStudent(Student * studentInfo);
    bool readStudents();

private:
    aMeta * assignmentData;
    std::vector<Student *> students;


};
#endif
