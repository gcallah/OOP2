// Copyright 2019 Gene Callahan
#include <string>
#include <iostream>
using namespace std;
#include "./image.h"


Image::Image(int width, int height, string flnm)
    : width(width), height(height) {
    image_buf = new unsigned char[image_sz()];
}

Image::Image(const Image& img2) {
    /*
     * This is the Image copy constructor. We have to handle 
     * properly copying the `image_buf` to the target object.
     * */
    copy_fields(img2);
}

Image::~Image() {
    /*
     * Image destructor must free the image buf.
     * */
    if (image_buf != nullptr) delete image_buf;
}

Image& Image::operator=(const Image& img2) {
    /*
     * The Image assignment operator has to delete the image buf is
     * not null, then do the copy like the copy constructor.
     * */
    if (image_buf != nullptr) delete image_buf;
    copy_fields(img2);
    return *this;
}


void Image::display() {
    cout << "displayed\n";
}


int Image::image_sz() { return width * height; }


void Image::copy_fields(const Image& img2) {
    /*
     * We extract the copy into its own method so that it can be shared
     * by the copy constructor and assignment.
     * */
    width = img2.width;
    height = img2.height;
    image_buf = new unsigned char[image_sz()];
    memcpy(image_buf, img2.image_buf, image_sz());
}


/*
 * Correct way to call base class copy constructor:
 * */
Gif::Gif(const Gif& img2) : Image(img2) {
}


/*
 * Incorrect wat to call it:
Gif::Gif(const Gif& img2) {
    Image(img2);
}
 * */


void Gif::display() { 
    /*
     * Specialized over-ridden display method for Gif.
     * In it we call the parent display method with
     * `Image::display()`.
     * */
    cout << "GIF of height " << get_height() << " and width "
        << get_width() << " "; 
    Image::display();
}


void Gif::compress(int i) {
    cout << "compressing at level: " << i << endl;
}


void AnimGif::display() { 
    /*
     * Specialized over-ridden display method for AnimGif.
     * In it we call the parent display method with
     * `Image::display()`.
     * */
    cout << "AnimGif "; 
    Image::display();
}


void Jpeg::display() { 
    /*
     * Specialized over-ridden display method for Jpeg.
     * In it we call the parent display method with
     * `Image::display()`.
     * */
    cout << "JPEG "; 
    Image::display();
}


void Png::display() { 
    /*
     * Specialized over-ridden display method for Png.
     * In it we call the parent display method with
     * `Image::display()`.
     * */
    cout << "PNG "; 
    Image::display();
}
