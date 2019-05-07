#ifndef BASE_CONV_H
#define BASE_CONV_H 1

/*
 * Code for converting between bases.
 * Right now we only go up to 16.
 * */
#include <string>

const int OCT = 8;
const int DEC = 10;
const int HEX = 16;


std::string base_conv(int n, int to_base=HEX);

#endif
