// Copyright 2019 Gene Callahan
#ifndef WEATHER_DATE
#define WEATHER_DATE

#include <iostream>
#include <string>

class Date {
    /*
     * This is a class to hold dates. It should be extended to 
     * support multiple I/O formats.
     * */
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
 public:
    Date(int m, int d, int y);
    void add_months(int);
    void add_years(int);
    std::string to_string() const;

 private:
    int month;
    int day;
    int year;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif
