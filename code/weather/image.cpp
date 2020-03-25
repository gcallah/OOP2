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
Image::Image(int width, int height, string flnm)
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
 * This is a dummy `display()` operator, to illustrate
 * *polymorphism*.
 * */
string Image::display(string s="Base") {
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
 * */
Gif::Gif(const Gif& img2) : Image(img2) {
}


/*
 * Incorrect way to call it:
Gif::Gif(const Gif& img2) {
    Image(img2);
}
 * */


/*
 * Specialized over-ridden display method for Gif.
 * In it we call the parent display method with
 * `Image::display()`.
 * */
//string Gif::display(string s) { 
//    return Image::display("Gif");
//}


/*
 * Gif has its own `compress()` with an int parameter.
 * It will hide the base class `compress()` unless we
 * explicitly prevent it from doing so.
 * */
void Gif::compress(int i) {
    cout << "compressing at level: " << i << endl;
}


/*
 * Specialized over-ridden display method for AnimGif.
 * In it we call the parent display method with
 * `Image::display()`.
 * */
string AnimGif::display(string s) { 
    return Image::display("AnimGif");
}


/*
 * Specialized over-ridden display method for Jpeg.
 * In it we call the parent display method with
 * `Image::display()`.
 * */
string Jpeg::display(string s) { 
    return Image::display("Jpeg");
}


/*
 * Specialized over-ridden display method for Png.
 * In it we call the parent display method with
 * `Image::display()`.
 * */
string Png::display(string s) { 
    return Image::display("Png");
}
