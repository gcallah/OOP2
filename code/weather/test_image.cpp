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

int main()
{
    Image base(2000, 2000, "Base class");
    show(base);
    Gif derived(2000, 2000, "derived class");
    show(derived);
    Jpeg jpeg(2000, 2000, "Jpeg class");
    show(jpeg);
    Png png(2000, 2000, "png class");
    show(png);

    vector<Image*> images;
    images.push_back(&base);
    images.push_back(&derived);
    images.push_back(&jpeg);
    images.push_back(&png);
    for(Image* img : images)
        img->display();
}
