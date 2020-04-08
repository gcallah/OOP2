// Copyright 2019 Gene Callahan

/*
 * This is the implementation of our image class.
 * It is designed to teach class hierarchy and buffer
 * allocation.
 * */
#include <string>
#include <iostream>
using namespace std;
#include "./image.h"


/*
 * "Ordinary" constructor initializing each field:
 * */
Image::Image(int width, int height, const string& flnm)
    : width(width), height(height) {
    image_buf = new unsigned char[image_sz()];
}


/*
 * This is the `Image` *copy constructor*. We have to handle 
 * properly copying the `image_buf` to the target object.
 * We use `copy_fields()` so we can share copy code with the
 * assignment operator.
 * */
Image::Image(const Image& img2) {
    cout << "In image copy constructor\n";
    copy_fields(img2);
}


/*
 * `Image` *destructor* must *free* the image buf so
 * that the memory can be used for other purposes.
 * */
Image::~Image() {
    if (image_buf != nullptr) delete image_buf;
}


/*
 * The `Image` assignment operator has to delete the image buf is
 * not null, then do the copy like the *copy constructor*.
 * */
Image& Image::operator=(const Image& img2) {
    if (image_buf != nullptr) delete image_buf;
    copy_fields(img2);
    return *this;
}


/*
 * This is the base class `display()` operator, to illustrate
 * *polymorphism*.
 * */
const string& Image::display(const string& s) const {
    cout << s << endl;
    return s;
}


int Image::image_sz() { return width * height; }


/*
 * We extract the copy into its own method so that it can be shared
 * by the copy constructor and assignment.
 * */
void Image::copy_fields(const Image& img2) {
    width = img2.width;
    height = img2.height;
    image_buf = new unsigned char[image_sz()];
    for (int i = 0; i < image_sz(); i++)
        image_buf[i] = img2.image_buf[i];
}


/*
 * Correct way to call base class copy constructor:
Gif::Gif(const Gif& img2) : Image(img2) {
}
 * */


/*
 * Incorrect way to call it:
Gif::Gif(const Gif& img2) {
    Image(img2);
}
 * */


/*
 * Specialized over-riding display method for Gif.
 * In it we call the parent display method with
 * `Image::display()`.
 * */
const string& Gif::display(const string& s) const { 
    return Image::display("Gif");
}


/*
 * Gif has its own `compress()` with an int parameter.
 * It will hide the base class `compress()` unless we
 * explicitly prevent it from doing so.
 * */
void Gif::compress(int i) {
    cout << "compressing at level: " << i << endl;
}



AnimGif::AnimGif(int width, int height, const string& flnm)
    : Gif(width, height, flnm) {
    image_buf2 = new unsigned char[image_sz()];
}

AnimGif::AnimGif(const AnimGif& img2) : Gif(img2) {
    cout << "In AnimGif copy constructor\n";
    image_buf2 = new unsigned char[image_sz()];
    for (int i = 0; i < image_sz(); i++)
        image_buf2[i] = img2.image_buf2[i];
}

AnimGif& AnimGif::operator=(const AnimGif& img2) {
    Gif::operator=(img2);
    if (image_buf2 != nullptr) delete image_buf2;
    for (int i = 0; i < image_sz(); i++)
        image_buf2[i] = img2.image_buf2[i];
    return *this;
}

AnimGif::~AnimGif() {
    if (image_buf2 != nullptr) delete image_buf2;
}

/*
 * Specialized over-riding display method for AnimGif.
 * In it we call the parent display method with
 * `Image::display()`.
const string& AnimGif::display(const string& s) const {
    return Image::display("AnimGif");
}
 * */



/*
 * Specialized over-riding display method for Jpeg.
 * In it we call the parent display method with
 * `Image::display()`.
 * */
const string& Jpeg::display(const string& s) const {
    return Image::display("Jpeg");
}


/*
 * Specialized over-riding display method for Png.
 * In it we call the parent display method with
 * `Image::display()`.
 * */
const string& Png::display(const string& s) const {
    return Image::display("Png");
}
