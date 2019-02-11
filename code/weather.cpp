// Creating a new type using struct:
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
//    if(!fin)
//    {
//        cerr << "Bad input file\n";
//        exit(1);
//    }
}
