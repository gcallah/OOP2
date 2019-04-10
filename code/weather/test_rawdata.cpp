// Copyright 2019 Gene Callahan
// date_test: test our date class
#include <iostream>
#include <vector>

#include "./rawdata.h"

using namespace std;


int main() {
    /*
     * Run some tests on our RawData class.
     * The purpose here is to see how copy control interacts with 
     * a class heirarchy.
     * */
    RawData rd;
    Binary binary;
    Csv csv;
    Json json;

    Binary* bptr = new Binary();

    cout << "\n_______________\n\nVector:\n";

    vector<RawData*> rds;
    rds.push_back(&binary);
    rds.push_back(&csv);
    rds.push_back(&json);
    rds.push_back(bptr);
    /*
     * This is a classic example of when we want 
     * *polymorphism*! We want to have a collection of
     * base-class pointers, but get the right output
     * method for each specific object.
     * */
    for(RawData* rd : rds) {
        cout << *rd << endl;
    }
}
