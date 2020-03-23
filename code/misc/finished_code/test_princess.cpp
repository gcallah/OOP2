/*
    testPrincess.cpp
    Cyclic Association
    Sec Base
    Tests the princess and frog_prince classes.
*/

#include <iostream>
#include <string>
using namespace std;

#include "princess.h"
#include "frog.h"


int main() {
    Princess snowy("Snow White");
    cout << snowy << endl;
    FrogPrince froggy("Froggy");
    cout << froggy << endl;
    snowy.marries(&froggy);
    cout << snowy << endl;

    Princess sleeping("Sleeping Beauty");
    FrogPrince bullfrog("Bull Frog");
    bullfrog.marries(&sleeping);
    cout << sleeping << endl;
    cout << bullfrog << endl;
    exit(0);
}


