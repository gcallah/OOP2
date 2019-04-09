// Copyright 2019 Gene Callahan
// Weather: take readings from a weather station.
// This is the starting, minimal version.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#include "./date.h"
#include "./image.h"
#include "./reading.h"

using namespace std;

const bool DEBUG = true;
const bool DEBUG2 = false;


void process_image(Image img) {
    cout << "Pretending to process image\n";
    Image img2{DEF_HEIGHT, DEF_WIDTH, "weather.jpg"};
    img2 = img;
}


void read_records(string filenm, vector<Reading*>& readings) {
    /*
     * Read all weather station records from `filenm`.
     * */
    ifstream rfile(filenm);
    if (!rfile)
    {
        cerr << "Could not read input file: " << filenm << endl;
        exit(1);
    }
    int m, d, y;
    double temp, hum, ws;
    Reading* prev = nullptr;
    cout << "A reading is " << sizeof(Reading) << " bytes in size\n";
    cout << "An image is " << sizeof(Image) << " bytes in size\n";
    // const int LOOPS = 100000000;
    const int LOOPS = 2;
    for (int i = 0; i < LOOPS; i++)
    {
        if (readings.size() > 0)
        {
            cout << "Before delete: ";
            cout << *(readings[0]) << endl;
        }
        for (Reading* rd : readings) delete rd;  // free mem we don't need!
        readings.clear();  // Pointers are no good anymore

        while (rfile >> m >> d >> y >> temp >> hum >> ws)
        {
            Date date{m, d, y};
            Reading* rd = new Reading{date, temp, hum, ws, prev};
            readings.push_back(rd);
            prev = rd;
            if (DEBUG) cout << "prev = " << prev << endl;
            process_image(rd->get_image());
        }
        // reset file for next time around loop
        rfile.clear();
        rfile.seekg(0, ios::beg);
    }
    rfile.close();
}


void process_records(vector<Reading*>& readings) {
    cout << "Processing records.\n";
}


void output_records(vector<Reading*>& readings) {
    for (Reading* rd : readings)
    {
        cout << *rd << endl;
    }
}


int main() {
    /*
     * This is the framework program that runs our weather station
     * sample code.
     * */
    string filenm;
    cout << "Input weather reading file name: ";
    cin >> filenm;

    vector<Reading*> readings;
    read_records(filenm, readings);
    process_records(readings);
    output_records(readings);
}
