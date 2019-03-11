// Copyright 2019 Gene Callahan
// Weather: take readings from a weather station.
// This is the starting, minimal version.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "image.h"

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


const int DEF_HEIGHT = 1600;
const int DEF_WIDTH = 2400;

class Reading
{
    friend ostream& operator<<(ostream& os, const Reading& r);
 public:
    Reading(Date dt, double temp, double hum,
            double ws, Reading* p)
        : date{dt}, temperature{temp}, humidity{hum},
          windspeed{ws}, prev{p},
        // just making up file name!
          image{DEF_HEIGHT, DEF_WIDTH, "weather.jpg"}
    {
    }
    void set_tempF(double t) { temperature = t; }
    double get_tempF() const { return temperature; }
    double get_tempC() const
    {
        return (temperature - 32) * C_TO_F_RATIO;
    }
    double get_temp_changeF() const
    {
        if (prev == nullptr) return 0.0;
        else
            return get_tempF() - prev->get_tempF();
    }
    double get_hum() const { return humidity; }
    double get_ws() const { return windspeed; }
    Image get_image() { return image; }

 private:
    Date date;
    double temperature;
    double humidity;
    double windspeed;
    Reading* prev;
    Image image;   // perhaps we have photos from the weather station
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


void process_image(Image img)
{
    cout << "Pretending to process image\n";
    Image img2{DEF_HEIGHT, DEF_WIDTH, "weather.jpg"};
    mess_with_image(img);
    img2 = img;
}


void read_records(string filenm, vector<Reading*>& readings)
{
    ifstream rfile(filenm);
    if (!rfile)
    {
        cerr << "Could not read input file: " << filenm << endl;
        exit(1);
    }
    int m, d, y;
    double temp, hum, ws;
    Reading* prev = nullptr;
    cout << "A reading is " << sizeof(Reading) << " bytes in size\n";
    cout << "An image is " << sizeof(Image) << " bytes in size\n";
    // const int LOOPS = 100000000;
    const int LOOPS = 2;
    for (int i = 0; i < LOOPS; i++)
    {
        if (readings.size() > 0)
        {
            cout << "Before delete: ";
            cout << *(readings[0]) << endl;
        }
        for (Reading* rd : readings) delete rd;  // free mem we don't need!
        readings.clear();  // Pointers are no good anymore

        while (rfile >> m >> d >> y >> temp >> hum >> ws)
        {
            Date date{m, d, y};
            Reading* rd = new Reading{date, temp, hum, ws, prev};
            readings.push_back(rd);
            prev = rd;
            if (DEBUG) cout << "prev = " << prev << endl;
            process_image(rd->get_image());
        }
        // reset file for next time around loop
        rfile.clear();
        rfile.seekg(0, ios::beg);
    }
    rfile.close();
}


void process_records(vector<Reading*>& readings)
{
    cout << "Processing records.\n";
}


void output_records(vector<Reading*>& readings)
{
    for (Reading* rd : readings)
    {
        cout << *rd << endl;
    }
}


int main()
{
    // A program to collect and output weather station
    // readings.
    string filenm;
    cout << "Input weather reading file name: ";
    cin >> filenm;

    vector<Reading*> readings;
    read_records(filenm, readings);
    process_records(readings);
    output_records(readings);
}
