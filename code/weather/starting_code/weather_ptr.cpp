// Weather: take readings from a weather station.
// This is the starting, minimal version.
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

const bool DEBUG = true;

class Reading
{
 public:
    Reading() {}

    ostream& operator<<(ostream& os)
    {
        os << "Weather reading; temp: " << temp;
        return os;
    }

 private:
    double temp;
};


void collect_readings(istream& is, Vector<Reading>& rvec) {
}


void print_readings(ostream& os, Vector<Reading>& rvec) {
}


int main()
{
    // A program to collect and output weather station
    // readings.
    string filenm;
    cout << "Input weather reading file name:\n";
    cin >> filenm;
    if(DEBUG)
    {
        cout << "input file name is: " << filenm << endl;
    }
    ifstream readings(filenm);
    if(!readings)
    {
        cerr << "Could not read input file.\n";
        exit(1);
    }

    vector<Reading> rvec;
    collect_readings(readings, rvec);
    readings.close();

    print_readings(cout, rvec);
}
