//
// Created by kmou424 on 2021/11/7.
//

#include <tools.hpp>

/**
 *  @order Split string into vector array with pattern
 *  @param  _result  The vector array to save split string
 *  @param  _string  The original string will be used for splitting
 *  @param  _pattern The pattern used to split the string
 *  @return No return value
*/

void split(std::vector<std::string>& _result, std::string _string, const std::string& _pattern)
{
    std::string::size_type pos;
    _string += _pattern;
    unsigned int size = _string.size();

    for (unsigned int i = 0; i < size; i++) {
        pos = _string.find(_pattern, i);
        if (pos < size) {
            std::string s = _string.substr(i, pos -i );
            _result.push_back(s);
            i = pos + _pattern.size() - 1;
        }
    }
}

/*
    Below are some functions prepared for large number computations
*/

/**
 *  @order Convert string to large number array (for large number computation)
 *  @param  _num  The string need to convert
 *  @return Converted array (each element stores a number less than 10 in the corresponding position)
*/

LargeNumber string2LargeNumber(const std::string& _num) {
    LargeNumber _res;
    for (char _c : _num)
        _res.push_back(_c - '0');
    if (_res.empty())
        _res.push_back(0);
    return _res;
}