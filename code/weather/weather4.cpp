// Weather: take readings from a weather station.
// This is the starting, minimal version.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const bool DEBUG = true;
const bool DEBUG2 = false;

constexpr double C_TO_F_RATIO = 5.0 / 9.0;

class Date
{
    friend ostream& operator<<(ostream& os, const Date& date);
public:
    Date(int m, int d, int y) : month(m), day(d), year(y)
    {
    }

private:
    int month;
    int day;
    int year;
};

ostream& operator<<(ostream& os, const Date& date)
{
    os << date.month << "/" << date.day
        << "/" << date.year;
    return os;
}


class Reading
{
    friend ostream& operator<<(ostream& os, const Reading& r);
public:
    Reading(Date dt, double temp, double hum,
            double ws, Reading* p)
        : date{dt}, temperature{temp}, humidity{hum},
          windspeed{ws}, prev{p}
    {
    }
    double get_tempF() const { return temperature; }
    double get_tempC() const
    {
        return (temperature - 32) * C_TO_F_RATIO;
    }
    double get_temp_changeF() const
    {
        if(prev == NULL) return 0.0;
        else return get_tempF() - prev->get_tempF();
    }
    double get_hum() const { return humidity; }
    double get_ws() const { return windspeed; }

private:
    Date date;
    double temperature;
    double humidity;
    double windspeed;
    Reading* prev;
};

ostream& operator<<(ostream& os, const Reading& r)
{
    os << fixed << setprecision(2)
        << "Weather reading: "
        << r.date
        << "; Temp: " << r.get_tempF() << "F "
        << " (change = " << r.get_temp_changeF() << "); "
        << r.get_tempC() << "C"
        << " Hum: " << r.get_hum()
        << " Wind: " << r.get_ws();
    return os;
}


int main()
{
    // A program to collect and output weather station
    // readings.
    string filenm;
    cout << "Input weather reading file name: ";
    cin >> filenm;
    if(DEBUG2)
    {
        cout << "input file name is: " << filenm << endl;
        cout << "C_TO_F_RATIO is: " << C_TO_F_RATIO << endl;
    }
    ifstream rfile(filenm);
    if(!rfile)
    {
        cerr << "Could not read input file: " << filenm << endl;
        exit(1);
    }
    int m, d, y;
    double temp, hum, ws;
    vector<Reading> readings;
    Reading* prev = NULL;
    cout << "A reading is " << sizeof(Reading) << " bytes in size\n";
    while(rfile >> m >> d >> y >> temp >> hum >> ws)
    {
        Date date{m, d, y};
        Reading* rd = new Reading{date, temp, hum, ws, prev};
        readings.push_back(*rd);
        if(DEBUG2) cout << *rd << endl;
        prev = rd;
        if(DEBUG) cout << prev << endl;
    }

    if(DEBUG)
    {
        for(Reading rd : readings)
        {
            cout << rd << endl;
        }
    }

    rfile.close();
}
