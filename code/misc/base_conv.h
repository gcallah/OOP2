#ifndef BASE_CONV_H
#define BASE_CONV_H 1

/*
 * Code for converting between bases.
 * We will start out hard-coding base to 16,
 * then make it generic.
 * */
#include <string>

int OCT = 8;
int DEC = 10;
int HEX = 16;


std::string base_conv(int n, int to_base=HEX);

#endif
