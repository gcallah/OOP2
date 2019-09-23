// Weather: take readings from a weather station.
// This is the starting, minimal version.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const bool DEBUG = true;

class Reading
{
    friend ostream& operator<<(ostream& os, const Reading& r) {
        os << "Weather reading; temp: " << r.temp;
        return os;
    }

 public:
    Reading(int tmp) : temp(tmp) {}

 private:
    double temp;
};


void collect_readings(istream& is, vector<Reading>& rvec) {
    // we have some fields we ain't using yet, so:
    int ignore1, ignore2, ignore3;
    double ignore4, ignore5;
    // and one we care about:
    int temp;
    while (is >> ignore1 >> ignore2 >> ignore3 >> temp >> ignore4 >> ignore5) {
        Reading rd(temp);
        rvec.push_back(rd);
    }
}


void print_readings(ostream& os, const vector<Reading>& rvec) {
    for (const Reading& reading : rvec) {
        os << reading << endl;
    }
}


int main()
{
    // A program to collect and output weather station readings.
    string filenm;
    cout << "Input weather reading file name:\n";
    cin >> filenm;
    if(DEBUG)
    {
        cout << "input file name is: " << filenm << endl;
    }
    ifstream rfile(filenm);
    if(!rfile)
    {
        cerr << "Could not read input file.\n";
        exit(1);
    }

    vector<Reading> rvec;
    collect_readings(rfile, rvec);
    rfile.close();

    print_readings(cout, rvec);
}
