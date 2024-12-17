#include "calendar.hpp"

vector<string> MONTHS_SHORTFORM = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
string space = " ";

string pad_start(string s, int width) {
    stringstream ss;
    ss << setw(width) << s;
    return ss.str();
}

string pad_end(string s, int width) {
    stringstream ss;
    ss << s << setw(width);
    return ss.str();
}

int get_days(int year) {
    return 365 + ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void get_month_and_day(int year, int day_of_year, int *month, int *day) {
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (get_days(year) == 366) {
        days_in_month[1] = 29;
    }

    *month = 1;
    while (day_of_year > days_in_month[*month - 1]) {
        day_of_year -= days_in_month[*month - 1];
        (*month)++;
    }
    *day = day_of_year;
}

// Zeller's congruence
int calculate_weekday(int year, int month, int day) {
    if (month == 1 || month == 2) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int weekday = (day + (int)floor(13.0f * (month + 1.0f) / 5.0f) + k + (int)floor(k / 4.0f) + (int)floor(j / 4.0f) + 5 * j) % 7;
    return (weekday + 6) % 7;
}

calendar_t new_calendar(int year) {
    time_t t = time(0);
    struct tm *now = localtime(&t);
    calendar_t calendar;
    if (year < now->tm_year + INIT_YEAR) {
        cout << "Error: Year is in the past" << std::endl;
    } else if (year >= now->tm_year + INIT_YEAR) {
        calendar.year = year;
        int month = 1;
        int day = 1;
        for (int days = 0; days < get_days(year); days++) {
            get_month_and_day(year, days + 1, &month, &day);
            if (day == 1) {
                calendar.calendar.push_back(vector<pair<int, int>>());
            }
            calendar.calendar[month - 1].push_back(pair<int, int>(day, static_cast<int>(calculate_weekday(year, month, day))));
        }
    }
    return calendar;
}

void print_calendar(calendar_t calendar, int width, std::ostream &cout) {
    if (calendar.calendar.size() != MONTHS_SHORTFORM.size()) {
        cout << "Error: months error, calendar size: " << calendar.calendar.size() << std::endl;
        return;
    }
    cout << ">> " << calendar.year << " <<" << endl;
    for (unsigned long i = 0; i < calendar.calendar.size(); i++) {
        cout << MONTHS_SHORTFORM[i] << endl;
        cout << "SUN MON TUE WED THU FRI SAT" << endl;
        bool fp = true;
        for (unsigned long j = 0; j < calendar.calendar[i].size(); j++) {
            if (fp) {
                for (unsigned long k = 0; k < (unsigned long)calendar.calendar[i][j].second; k++) {
                    cout << pad_start(space, width) << " ";
                }
                fp = false;
            }
            cout << pad_start(to_string(calendar.calendar[i][j].first), width) << " ";
            if (calendar.calendar[i][j].second == 6 || j == calendar.calendar[i].size() - 1)
                cout << endl;
        }
        cout << endl;
    }
}

void write_calendar(calendar_t calendar, int width, string filename, bool cover_file_content) {
    ofstream file(filename, cover_file_content ? ios::trunc : ios::app);

    if (file.is_open()) {
        print_calendar(calendar, width, file);
        file.close();
    } else {
        cout << "Error: Unable to open file" << std::endl;
    }
}
