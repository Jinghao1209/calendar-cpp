#if !defined(__CALENDAR_HPP)
#define __CALENDAR_HPP

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

#define INIT_YEAR 1900
#define MIN_YEAR INIT_YEAR
#define MAX_YEAR 9999
#define COMMON_WIDTH 3
typedef int WDAY;
typedef struct
{
    int year;          // 1900 ~ 9999
    vector<vector<pair<int, WDAY>>> calendar;
} calendar_t;

calendar_t new_calendar(int year);
void print_calendar(calendar_t calendar, int width, std::ostream &cout);
void write_calendar(calendar_t calendar, int width, string filename, bool cover_file_content);
/**
 * year = 2024
 * month = 1
 * day = 21
 * 21/01/2024
 */
int calculate_weekday(int year, int month, int day);

#endif          // __CALENDAR_HPP
