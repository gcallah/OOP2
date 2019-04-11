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
    RawData() : len(0) { cout << "Raw default cons\n"; }

    // copy constructor:
    RawData(const RawData& rd2) { len = rd2.len; cout << "RawData copy constr\n"; }

    // destructor:
    virtual ~RawData() { cout << "RawData destructor\n__________\n"; }

    // assignment operator:
    RawData& operator=(const RawData& rd2)  { len = rd2.len; return *this; }

    void set_len(int l)  { len = l; }
    int size() const { return len; }
    virtual string to_string() const { return "Raw data"; }

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
 public:
    // default constructor:
    Binary() : RawData() { cout << "Binary default cons\n"; }

    // copy constructor:
    Binary(const Binary& rd2) { cout << "Binary copy constr\n"; }

    // destructor:
    ~Binary() { cout << "Binary destructor\n"; }

    string to_string() const { return "Binary"; }
};


class BinEncr : public Binary {
    /*
     * Here we have a descendant of RawData that overrides certain
     * methods.
     * */
    friend std::ostream& operator<<(std::ostream& os, const BinEncr& rd);
 public:
    // default constructor:
    BinEncr() : Binary() { cout << "BinEncr default cons\n"; }

    // copy constructor:
    BinEncr(const BinEncr& rd2) { cout << "BinEncr copy constr\n"; }

    // destructor:
    ~BinEncr() { cout << "BinEncr destructor\n"; }

    string to_string() const { return "Binary encrypted"; }
};


class Csv : public RawData {
    /*
     * Another child of RawData, just here to make the reason for inheritance
     * clearer.
     * */
 public:
    // default constructor:
    Csv() : RawData() { cout << "Csv default cons\n"; }

    // destructor:
    ~Csv() { cout << "CSV destructor\n"; }

    string to_string() const { return "Csv"; }
};


class Json : public RawData {
    /*
     * Another child of RawData, just here to make the reason for inheritance
     * clearer.
     * */
 public:
    Json() : RawData() { cout << "Json default cons\n"; }

    // copy constructor:
    Json(const Json& rd2) { cout << "BinEncr copy constr\n"; }

    // destructor:
    ~Json() { cout << "Json destructor\n"; }

    string to_string() const { return "Json"; }
};


#endif
