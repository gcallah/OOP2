// Copyright 2019 Gene Callahan
#include <iostream>

#include "code/weather/date.h"

using namespace std;


Date::Date(int m, int d, int y) : month(m), day(d), year(y)
{
}

void Date::add_years(int y) { year += y; }

ostream& operator<<(ostream& os, const Date& date)
{
    os << date.month << "/" << date.day
        << "/" << date.year;
    return os;
}
