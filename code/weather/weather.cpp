// Weather: take readings from a weather station.
// This is the starting, minimal version.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const bool DEBUG = true;
const double ZERO_F = 32.0;
constexpr double C_TO_F_RATIO = 5.0 / 9.0;

class Date
{
    public:
        Date(int m, int d, int y) : month(m), day(d), year(y) {}

    private:
        int month, day, year;
};


class Reading
{
public:
    Reading(double temp, double hum, double ws)
        : tempF(temp), humidity(hum), windspeed(ws) {}
    double get_tempF() const { return tempF; }
    double get_tempC() const
    {
        return (tempF - ZERO_F) * C_TO_F_RATIO;
    }
    double get_wspeed() const { return windspeed; }
    double get_hum() const { return humidity; }

private:
    double tempF;
    double humidity;
    double windspeed;
};

ostream& operator<<(ostream& os, const Reading& r)
{
    os << fixed << setprecision(2)
        << "Weather reading: " << r.get_tempF() << "F; "
        << r.get_tempC() << "C; "
        << "Humidity: " << r.get_hum()
        << "; Wind speed: " << r.get_wspeed();
    return os;
}


ostream& operator<<(ostream& os, const Date& dt)
{
    os << "Date: " << dt.month << "/" << dt.day << "/"
        << dt.year;
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
        Reading rd{temp, hum, ws};
        if(DEBUG) cout << rd <<  endl;
    }

    readings.close();
}
