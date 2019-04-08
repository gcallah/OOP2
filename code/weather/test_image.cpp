// Copyright 2019 Gene Callahan
// date_test: test our date class
#include <iostream>
#include <vector>

#include "image.h"

using namespace std;

void show(Image& img)
{
    img.display();
}

int main() {
    /*
     * Run some tests on our Image class.
     * Because Image is abstract, we can't construct an Image:
     * Image img(2000, 2000, "base class");
     * The above line won't compile.
     * */
    Gif gif(2000, 2000, "derived class");
    show(gif);
    Jpeg jpeg(2000, 2000, "Jpeg class");
    show(jpeg);
    Png png(2000, 2000, "png class");
    show(png);

    cout << "\n_______________\n\nVector:\n";

    vector<Image*> images;
    images.push_back(&gif);
    images.push_back(&jpeg);
    images.push_back(&png);
    for(Image* img : images) {
        img->display();
    }
}
