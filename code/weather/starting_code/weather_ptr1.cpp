// Weather: take readings from a weather station.
// This is the starting, minimal version.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const bool DEBUG = true;

class Reading
{
    friend ostream& operator<<(ostream& os, const Reading& r) {
        os << "Weather reading; temp: " << r.temp;
        os << "; temp change: " << r.get_tchange();
        return os;
    }

 public:
    Reading(int tmp, Reading* prv=nullptr)
        : temp(tmp), prev(prv) {}

    double get_tchange() const {
        if (prev == nullptr) return nan("");
        else return temp - prev->temp;
    }

    void set_prev(Reading* prv) { prev = prv; }

 private:
    double temp;
    Reading* prev;
};


void collect_readings(istream& is, vector<Reading>& rvec) {
    // we have some fields we ain't using yet, so:
    int ign1, ign2, ign3;
    double ign4, ign5;
    // and one we care about:
    int temp;
    Reading* prev = nullptr;
    rvec.reserve(100);
    while (is >> ign1 >> ign2 >> ign3 >> temp >> ign4 >> ign5) {
        Reading rd(temp, prev);
        rvec.push_back(rd);
        prev = &(rvec.back());;
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
