#include<iostream>
#include<map>

#ifndef __keyWord
#define __keyWord


class keyWord {
public:
    keyWord();
    // keyWord(std::string key, std::string value) {keyWordComment[key] = value;}
    // keyWord(std::string key, int value) {keyWordPoint[key] = value;}
    bool addKey(std::string key, int value, std::string comment);
    void printComments();
    void readKeys(std::string classNumber);
    bool isProperKeyWord(std::string key);
    std::string getComment(std::string key);
    int getValue(std::string key);



private:
    std::map<std::string, int> keyWordPoint;
    std::map<std::string, std::string> keyWordComment;
};

#endif
