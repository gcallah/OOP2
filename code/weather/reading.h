// Copyright 2019 Gene Callahan
#ifndef WEATHER_READING
#define WEATHER_READING 1

#include <iostream>

#include "image.h"
#include "date.h"

constexpr double C_TO_F_RATIO = 5.0 / 9.0;


class Reading {
    /*
     * This is the class that holds readings from our weather stations,
     * and contains display and conversions methods for
     * those readings.
     * */
    friend std::ostream& operator<<(std::ostream& os,
            const Reading& r);
 public:
    Reading(Date dt, double temp, double hum,
            double ws, Reading* p);
    void set_tempF(double t);
    double get_tempF() const;
    double get_tempC() const;
    double get_temp_changeF() const;
    double get_hum() const;
    double get_ws() const;
    Image get_image();

 private:
    Date date;
    double temperature;
    double humidity;
    double windspeed;
    Reading* prev;
    Image image;   // perhaps we have photos from the weather station
};

std::ostream& operator<<(std::ostream& os, const Reading& r);

#endif
