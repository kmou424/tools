//
// Created by kmou424 on 2021/11/1.
//

#ifndef TOOLS_H
#define TOOLS_H

#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <map>
#include <vector>

typedef std::vector<int> LargeNumber;

// math.cpp
LargeNumber largeNumberPlus(LargeNumber _addend1, LargeNumber _addend2);

// time.cpp
time_t date2Stamp(const std::string& _date);
std::string stamp2Date(time_t _t);

// string.cpp
void split(std::vector<std::string>& result, std::string str, const std::string& pattern);
LargeNumber string2LargeNumber(const std::string& _num);

// DictNodePoint #Start
typedef struct {
    int cnt;
    char character;
} charNode;

struct DictNodePoint {
    charNode chars[26];
    DictNodePoint * nextDictNode = NULL;
};

int getWordShowTimesBeginWith(DictNodePoint * dictNode, std::string word);
void insertWord(DictNodePoint * dictNode, std::string word);
// DictNodePoint #End

// set.cpp
// MergeSearchSet
class MergeSearchSet {
private:
    std::vector<int> _set, _cnt;
public:
    MergeSearchSet(int n);
    std::vector<int> count();
    int find(int x);
    void merge(int parent, int child);
};
#endif //TOOLS_H
