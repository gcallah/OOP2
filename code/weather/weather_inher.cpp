// Weather: take readings from a weather station.
// This is the starting, minimal version.
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

const bool DEBUG = true;
const int NO_VAL = -100000;

class Reading
{
 public:
 //   Reading()  {}

    Reading(double tmp) : temp(tmp), humidity(.50) {}

    virtual void verify() = 0;
    
    void set_temp(double t) { temp = t; }

    virtual string str() const {
        return " reading: temp = " + to_string(temp)
            + "; humid. = " + to_string(humidity);
    }

 private:
    double temp;
    double humidity;
};


/*
class AustralianReading : public Reading {
 public:
    AustralianReading() : kangaroos(0) {}

 private:
    int kangaroos;
};
*/


class AsianReading : public Reading {
 public:
    AsianReading(double temp, double ws) : Reading(temp),
        windspeed(ws)  {}

    void verify() {
        cout << "Asian reading verified";
    }

    string str() const {
        return "Asian " + Reading::str() + " wind: "
            + to_string(windspeed);
    }
 private:
    double windspeed;
};


class NorthAmericanReading : public Reading {
 public:
    NorthAmericanReading(double temp) : Reading(temp) {}

    void verify() {
        cout << "North American reading verified";
    }

    string str() const override {
        // return "NA reading; temp: " + to_string(temp) + " barom: "
        return "NA " + Reading::str() + " barom: "
            + to_string(barom);
    }

    /*
    void print_na_temp(const NorthAmericanReading& na) {
        cout << na.temp;
    }

    void print_asian_temp(const AsianReading& ar) {
        cout << ar.temp;
    }
    */

 private:
    double barom;
};


class SouthAmericanReading : public Reading {
 public:
    using Reading::Reading;

//    SouthAmericanReading(double temp) : Reading(temp) {}
    void verify() {
        cout << "South American reading verified";
    }


 private:
    double humid;
};


ostream& operator<<(ostream& os, const Reading& rd)
{
    os << rd.str();
    return os;
}


void check_reading(Reading& rd) {
    rd.verify();
    // log any problems! (code to be written)
}


void print_vector(const vector<Reading*>& rvec) {
    for (const Reading* rd : rvec) {
        cout << *rd << " ; ";
    }
    cout << endl;
}


int main()
{
    // A program to collect and output weather station
    // readings.
    vector<Reading*> reading_vec;

    /*
    Reading basic_read(45.3);
    cout << "size of basic == " << sizeof(basic_read) << endl;
    check_reading(basic_read);
    basic_read.set_temp(23.2);
    reading_vec.push_back(&basic_read);
    */
//    AustralianReading austr(45.6);
//    AustralianReading austr();
//    austr.set_temp(45.6);
//    reading_vec.push_back(&austr);

    AsianReading asia(5.9, 18.7);
    cout << "size of asia == " << sizeof(asia) << endl;
    check_reading(asia);
    reading_vec.push_back(&asia);

    NorthAmericanReading na(25.8);
    cout << "size of na == " << sizeof(na) << endl;
    check_reading(na);
    reading_vec.push_back(&na);

    cout << "SA reading:\n";
    SouthAmericanReading sa(25.8);
    sa.verify();

    cout << "size of sa == " << sizeof(sa) << endl;
    check_reading(sa);
    reading_vec.push_back(&sa);
    print_vector(reading_vec);

//    na = basic_read;
}
