//
// Created by kmou424 on 2021/10/31.
//

#include "tools.hpp"

/**
 *  @brief date2Stamp(const std::string& date)
 *  @order Convert formatted date to UNIX timestamp
 *  @param  _date  Formatted date (%Y%m%d%H%M%S)
 *  @return   The UNIX timestamp of date
*/

time_t date2Stamp(const std::string& _date)
{
    struct tm stm;
    int year, month, day, hour, minute, second;

    memset(&stm,0,sizeof(stm));
    year = atoi(_date.substr(0, 4).c_str());
    month = atoi(_date.substr(4, 2).c_str());
    day = atoi(_date.substr(6, 2).c_str());
    hour = atoi(_date.substr(8, 2).c_str());
    minute = atoi(_date.substr(10, 2).c_str());
    second = atoi(_date.substr(12, 2).c_str());

    stm.tm_year = year - 1900;
    stm.tm_mon = month - 1;
    stm.tm_mday = day;
    stm.tm_hour = hour;
    stm.tm_min = minute;
    stm.tm_sec = second;

    return (time_t)mktime(&stm);
}

/**
 *  @brief stamp2Date(time_t t)
 *  @order Convert UNIX timestamp to formatted date
 *  @param  _t  A UNIX timestamp
 *  @return   The formatted date string (%Y%m%d%H%M%S)
*/

std::string stamp2Date(time_t _t) {
    char time_s[256] = {0};
    struct tm * tm_t = localtime(&_t);
    strftime(time_s, sizeof(time_s), "%Y%m%d%H%M%S", tm_t);
    return std::string(time_s);
}