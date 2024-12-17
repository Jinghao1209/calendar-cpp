#include "calendar.hpp"
#include "utils.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
    if (char_const_array_search("-h", argv, argc) != -1 || char_const_array_search("--help", argv, argc) != -1) {
        cout_help(argv[0]);
        return 0;
    }

    bool is_cover = false;
    int start_year = -1;
    int end_year = -1;
    string filename = "";

    int s = init_args(argc, argv, &is_cover, &start_year, &end_year, &filename);
    if (s == 1) return 1;

    for (int i = start_year; i <= end_year; i++) {
        calendar_t calendar = new_calendar(i);
        print_calendar(calendar, COMMON_WIDTH, cout);
        if (!filename.empty()) {
            write_calendar(calendar, COMMON_WIDTH, filename, is_cover);
            is_cover = false;
        }
    }

    return 0;
}
