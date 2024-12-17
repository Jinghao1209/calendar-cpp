#include "utils.hpp"

void cout_help(string command_name) {
    cout << "Usage: " << command_name << " [options]" << endl
         << endl
         << "Options:" << endl
         << "  -s, --start <start_year>    Start year" << endl
         << "  -e, --end <end_year>        End year" << endl
         << "  -f, --filename <filename>   Output filename" << endl
         << "  -c, --cover                 Cover the output file if it exists" << endl
         << "  -h, --help                  Show this help message and exit" << endl
         << endl
         << "Example:" << endl
         << "  " << command_name << " -s 2024 -e 2025 -f output.txt" << endl;
}

int char_const_array_search(const char *str, const char *array[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(str, array[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int init_args(int argc, char const *argv[], bool *is_cover, int *start_year, int *end_year, string *filename) {
    if (argc < 2) {
        cout << "Error: Missing year argument" << endl
             << endl;
        cout_help(argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--start") == 0) {
            if (i + 1 < argc) {
                *start_year = atoi(argv[i + 1]);
                i++;
            } else {
                cout << "Error: Missing year after -s or --start" << endl
                     << endl;
                cout_help(argv[0]);
                return 1;
            }
        } else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--end") == 0) {
            if (i + 1 < argc) {
                *end_year = atoi(argv[i + 1]);
                i++;
            } else {
                cout << "Error: Missing year after -e or --end" << endl
                     << endl;
                cout_help(argv[0]);
                return 1;
            }
        } else if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--filename") == 0) {
            if (i + 1 < argc) {
                *filename = argv[i + 1];
                i++;
            } else {
                cout << "Error: Missing filename after -f or --filename" << endl
                     << endl;
                cout_help(argv[0]);
            }
        }
    }

    if (char_const_array_search("-c", argv, argc) != -1 || char_const_array_search("--cover", argv, argc) != -1) {
        if ((*filename).empty()) {
            cout << "Error: Missing filename argument" << endl
                 << endl;
            cout_help(argv[0]);
            return 1;
        }
        *is_cover = true;
    }

    if (*start_year == -1) {
        cout << "Error: Missing year argument" << endl
             << endl;
        cout_help(argv[0]);
        return 1;
    }

    if (*end_year != -1 && *start_year > *end_year) {
        cout << "Error: Start year must be less than end year" << endl
             << endl;
        cout_help(argv[0]);
        return 1;
    } else if (*end_year == -1) {
        *end_year = *start_year;
    }

    return 0;
}
