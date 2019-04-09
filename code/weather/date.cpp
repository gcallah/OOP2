// Copyright 2019 Gene Callahan
#include <iostream>
#include <string>

#include "./date.h"

using namespace std;


Date::Date(int m, int d, int y) : month(m), day(d), year(y) {
    /*
     * A date constructor that just uses initialization in a straightforward
     * manner.
     * */
}


void Date::add_years(int y) { year += y; }


void Date::add_months(int m) {
    /*
     * This only works now for adding up to the next year.
     * It must be re-written to handle arbitrary numbers of months.
     * */
    month += m;
    if( month > 12) {
        (month %= 12)++;
        year++;
    }
}


std::string Date::to_string() const {
    return(std::to_string(month) + "/" + std::to_string(day)
        + "/" + std::to_string(year));
}


ostream& operator<<(ostream& os, const Date& date) {
    os << date.month << "/" << date.day
        << "/" << date.year;
    return os;
}
