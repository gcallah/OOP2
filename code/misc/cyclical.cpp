/*
    cyclical.cpp
    Cyclic Association
*/

#include <iostream>
#include <string>
using namespace std;

class Princess {
    public:
        Princess(string nm) : name(nm) {}

    private:
        string name;
};


class Frog {
    public:
        Frog(string nm) : name(nm) {}

    private:
        string name;
};


int main() {
    Princess snowy("Snow White");
//    cout << snowy << endl;
    Frog froggy("Froggy");
//    cout << froggy << endl;
//    snowy.marries(&froggy);
//    cout << snowy << endl;
//
//    Princess sleeping("Sleeping Beauty");
//    Frog bullfrog("Bull Frog");
//    bullfrog.marries(&sleeping);
//    cout << sleeping << endl;
//    cout << bullfrog << endl;
    exit(0);
}


