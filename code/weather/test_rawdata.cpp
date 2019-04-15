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
    cout << "___________\n";
    Binary binary;
    cout << "___________\n";
    BinEncr bencr;
    cout << "___________\n";
    Csv csv;
    cout << "___________\n";
    Json json;
    cout << "___________\n";

    /*
     * This following works because base class destructor is virtual!
     * If it were not, we'd only get ~RawData().
     * */
    RawData* bptr = new BinEncr();
    cout << "\nDeleting binary encrypted pointer\n";
    delete bptr;

    cout << "\n_______________\n\nCopy Constructor:\n";
    json.set_len(17);
    Json json2 = json;
    cout << "Json2: " << json2 << endl;

    cout << "\n_______________\n\nVector:\n";

    vector<RawData*> rds;
    rds.push_back(&rd);
    rds.push_back(&binary);
    rds.push_back(&bencr);
    rds.push_back(&csv);
    rds.push_back(&json);
    /*
     * This is a classic example of when we want 
     * *polymorphism*! We want to have a collection of
     * base-class pointers, but get the right output
     * method for each specific object.
     * */
    for(RawData* rd : rds) {
        cout << *rd << endl;
    }

    cout << "\nReaching end of main; expect some destructors:\n";
}
