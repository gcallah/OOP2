/*
    testPrincess.cpp
    Cyclic Association
    Sec Base
*/

#include <iostream>
#include <string>

#include "frog.h"
#include "princess.h"

using namespace std;


int main() {
    Princess snowy("Snow White");
    cout << snowy << endl;
    amphib::Frog froggy("Froggy");
    cout << froggy << endl;
    snowy.marries(&froggy);
    cout << snowy << endl;

    Princess sleeping("Sleeping Beauty");
    amphib::Frog bullfrog("Bull Frog");
    bullfrog.marries(&sleeping);
    cout << sleeping << endl;
    cout << bullfrog << endl;
    //      << froggy << endl;
}


