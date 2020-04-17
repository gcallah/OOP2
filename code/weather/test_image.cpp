// Copyright 2019 Gene Callahan
// date_test: test our date class
#include <iostream>
#include <vector>
#include <cassert>

#include "image.h"

using namespace std;

void show(Image& img) {
    cout << "In show(Image&)\n";
    img.display();
}

void show(Gif& img) {
    cout << "In show(Gif&)\n";
    img.display();
}


int main() {
    /*
     * Run some tests on our Image class.
     * Because Image is abstract, we can't construct an Image:
     * Image image(1000, 800, "Base class");
     * The above line won't compile.
     * */
    AnimGif anim_gif(2000, 2000, "derived class");
    anim_gif.play();
    Jpeg jpeg(2000, 2000, "Jpeg class");
    Png png(2000, 2000, "png class");

//    cout << "Going to copy construct a animgif\n";
//    AnimGif agif2 = gif;
//    cout << "Going to copy construct a png\n";
//    Png png2 = png;
    Image* img = &anim_gif;
    // cout << "img display() = ";
    // img->display("Which?");
    // anim_gif.display("Which?");
    // cout << "\n";

    // this illustrates the interaction of overloading
    // and class heirarachies:
//    cout << "show(anim_gif) = " << show(anim_gif) << endl;
//    show(jpeg);
//    cout << "show(img) = " << show(*img) << endl;

    anim_gif.compress();
    anim_gif.compress(3);

    cout << "\n_______________\n\nVector:\n";

    vector<Image*> images;
//    images.push_back(&image);
    images.push_back(&anim_gif);
    images.push_back(&jpeg);
    images.push_back(&png);
    /*
     * This is a classic example of when we want 
     * *polymorphism*! We want to have a collection of
     * base-class pointers, but get the right `display()`
     * method for each specific object.
     * */
    for(Image* img : images) {
        img->display("");
    }
}
