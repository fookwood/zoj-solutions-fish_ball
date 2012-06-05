#include <cstdio>

const int dayInYear[] = { 365, 366 };
const int dayInMonth[2][13] = {
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

inline bool isLeap( int year ) {
    return year % 400 == 0 ||
           year % 4 == 0 &&
           year % 100;
}

const char* WD[] = { "Saturday",
                     "Sunday",
                     "Monday",
                     "Tuesday",
                     "Wednesday",
                     "Thursday",
                     "Friday" };

int main() {
    int days;
    while( scanf( "%d", &days ) && days != -1 ) {
        int year = 2000;
        int month = 1;
        int weekDay = days % 7;
        days += 1;
        while( days > dayInYear[ isLeap( year ) ] ) {
            days -= dayInYear[ isLeap( year++ ) ];
        }
        const int* MD = dayInMonth[ isLeap( year ) ];
        while( days > MD[month] ) {
            days -= MD[month];
            month++;
        }
        printf( "%d-%02d-%02d %s\n",
            year, month, days, WD[weekDay] );
    }
}
