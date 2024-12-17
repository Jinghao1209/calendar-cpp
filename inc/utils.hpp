#if !defined(__UTILS_HPP)
#define __UTILS_HPP

#include <iostream>
#include <string>
using namespace std;

void cout_help(string command_name);
int char_const_array_search(const char *str, const char *array[], int size);
int init_args(int argc, char const *argv[], bool *is_cover, int *start_year, int *end_year, string *filename);

#endif          // __UTILS_HPP
