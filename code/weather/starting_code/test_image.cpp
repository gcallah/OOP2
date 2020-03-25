// Copyright 2019 Gene Callahan
// date_test: test our date class
#include <iostream>
#include <vector>
#include <cassert>

#include "image.h"

using namespace std;

string show(Image& img) {
    cout << "In show(Image&)\n";
    return img.display("");
}


string show(Gif& img) {
    cout << "In show(Gif&)\n";
    return img.display("");
}


int main() {
    /*
     * Run some tests on our Image class.
     * Because Image is abstract, we can't construct an Image:
     * Image img(2000, 2000, "base class");
     * The above line won't compile.
     * */
    AnimGif gif(2000, 2000, "derived class");
    Jpeg jpeg(2000, 2000, "Jpeg class");
    Png png(2000, 2000, "png class");

    Image* img = &gif;

    // this illustrates the interaction of overloading
    // and class heirarachies:
    string ret;

//    ret = show(gif);
//    assert(ret == "AnimGif");
//    ret = show(jpeg);
//    assert(ret == "Jpeg");
//    ret = show(*img);
//    assert(ret == "AnimGif");

    gif.compress();

    cout << "\n_______________\n\nVector:\n";

    vector<Image*> images;
    images.push_back(&gif);
    images.push_back(&jpeg);
    images.push_back(&png);
    /*
     * This is a classic example of when we want 
     * *polymorphism*! We want to have a collection of
     * base-class pointers, but get the right `display()`
     * method for each specific object.
     * */
    ret = "";
    for(Image* img : images) {
        ret += img->display("");
    }
//    assert(ret == "AnimGifJpegPng");
}
