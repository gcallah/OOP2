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
    Reading() {}

    ostream& operator<<(ostream& os)
    {
        os << "Weather reading";
        return os;
    }
};


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

    readings.close();
}
