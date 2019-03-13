#ifndef WEATHER_DATE
#define WEATHER_DATE

#include <iostream>

class Date
{
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
 public:
    Date(int m, int d, int y);
    void add_years(int);

 private:
    int month;
    int day;
    int year;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif
