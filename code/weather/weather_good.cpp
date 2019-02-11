// Weather: take readings from a weather station.
// This is the starting, minimal version.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const bool DEBUG = true;
constexpr double C_TO_F_RATIO = 5.0 / 9.0;

class Date
{
public:
    Date(int m, int d, int y) : month(m), day(d), year(y)
    {
    }

private:
    int month;
    int day;
    int year;
};


class Reading
{
public:
    Reading(double temp, double hum, double ws)
        : temperature(temp), humidity(hum), windspeed(ws)
    {
    }
    double get_tempF() const { return temperature; }
    double get_tempC() const
    {
        return (temperature - 32) * C_TO_F_RATIO;
    }
    double get_hum() const { return humidity; }
    double get_ws() const { return windspeed; }

private:
    double temperature;
    double humidity;
    double windspeed;
};

ostream& operator<<(ostream& os, const Reading& r)
{
    os << "Weather reading: " << r.get_tempF() << "F; "
        << r.get_tempC() << "C"
        << " Hum: " << r.get_hum()
        << " Wind: " << r.get_ws();
    return os;
}

ostream& operator<<(ostream& os, const Date& date)
{
    os << " Date: " << date.month << "/" << date.day
        << "/" << date.year;
    return os;
}


int main()
{
    // A program to collect and output weather station
    // readings.
    string filenm;
    cout << "Input weather reading file name: ";
    cin >> filenm;
    if(DEBUG)
    {
        cout << "input file name is: " << filenm << endl;
        cout << "C_TO_F_RATIO is: " << C_TO_F_RATIO << endl;
    }
    ifstream readings(filenm);
    if(!readings)
    {
        cerr << "Could not read input file: " << filenm << endl;
        exit(1);
    }
    int m, d, y;
    double temp, hum, ws;
    while(readings >> m >> d >> y >> temp >> hum >> ws)
    {
        Date date{m, d, y};
        Reading r{temp, hum, ws};
        if(DEBUG) cout << r << endl;
    }

    readings.close();
}
