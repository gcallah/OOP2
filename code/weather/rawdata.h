// Copyright 2019 Gene Callahan
// header file for image class
#ifndef WEATHER_RAWDATA
#define WEATHER_RAWDATA 1

#include <string>
using namespace std;


class RawData {
    /*
     * This will be the base class for all types of raw data.
     * */
    friend std::ostream& operator<<(std::ostream& os, const RawData& rd);
 public:
    RawData() : len(0) {}

    // copy constructor:
    RawData(const RawData& img2) { cout << "RawData copy constr\n"; }

    // destructor:
    ~RawData() { cout << "RawData destructor\n"; }

    // assignment operator:
    RawData& operator=(const RawData& img2);

    int size() const { return len; }

 private:
    /*
     * 'len' is just a field to show how copy control works.
     * */
    int len;
};

std::ostream& operator<<(std::ostream& os, const RawData& rd);


class Binary : public RawData {
    /*
     * Here we have a descendant of RawData that overrides certain
     * methods.
     * */
    friend std::ostream& operator<<(std::ostream& os, const Binary& rd);
 public:
    // default constructor:
    Binary() : RawData() {}

    // destructor:
    ~Binary() { cout << "Binary destructor\n"; }
};

std::ostream& operator<<(std::ostream& os, const Binary& rd);


class Csv : public RawData {
    /*
     * Another child of RawData, just here to make the reason for inheritance
     * clearer.
     * */
 public:
    // default constructor:
    Csv() : RawData() {}

    // destructor:
    ~Csv() { cout << "CSV destructor\n"; }
};


class Json : public RawData {
    /*
     * Another child of RawData, just here to make the reason for inheritance
     * clearer.
     * */
 public:
    Json() : RawData() {}
};


#endif
