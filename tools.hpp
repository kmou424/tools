//
// Created by kmou424 on 2021/11/1.
//

#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <cstring>
#include <ctime>
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

#endif //TOOLS_H
