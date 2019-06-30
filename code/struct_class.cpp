// Creating a new type using struct:
#include <iostream>
using namespace std;

const bool DEBUG = true;

struct CandyStruct
{
    CandyStruct() { cout << "sweet\n"; }
};


class CandyClass
{
    CandyClass() { cout << "sweet\n"; }
};


int main()
{
    CandyStruct c1;
    CandyClass c2;
}
