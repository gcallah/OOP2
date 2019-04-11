// Copyright 2019 Gene Callahan
// header file for image class
#ifndef WEATHER_IMAGE
#define WEATHER_IMAGE 1

#include <string>
using namespace std;

const int DEF_HEIGHT = 1600;
const int DEF_WIDTH = 2400;


class Image {
    /*
     * This will be the base class for all types of images.
     * It is an abstract class, due to the `display()` method.
     * */
 public:
    Image(int width, int height, string flnm);
    // copy constructor:
    Image(const Image& img2);
    ~Image();
    Image& operator=(const Image& img2);
    int image_sz();
    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
    virtual void display() = 0;
    /*
     * If we don't want virtual method lookup, we
     * could just declare:
     * void display();
     * */
    virtual void compress() { cout << "Compressing!\n"; }
    int get_height() { return height; }
    int get_width() { return width; }

 private:
    int width;
    int height;
    unsigned char* image_buf;
    void copy_fields(const Image& img2);
};


class Gif : public Image {
    /*
     * Here we have a descendant of Image that overrides certain
     * methods.
     * We don't need copy control here because our parent has it.
     * */
 public:
    Gif(int width, int height, string flnm) : Image(width, height, flnm) {}
    /*
     * display() overrides the parent class display().
     * Notice the key word `override`: it is a safety mechanism to catch 
     * typos!
     * */
    void display() override;

    /*
     * The following line of code *hides* `compress()` from
     * our base class:
     * */
    void compress(int level);

    /*
     * The line below makes `compress()` available in Gif.
     * We could also have written:
     * void compress() { Image::compress(); }
     * */
    using Image::compress;
};


class AnimGif : public Gif {
    /*
     * This will be a "grandchild" class.
     * */
 public:
    AnimGif(int width, int height, string flnm) : Gif(width, height, flnm) {}
    void display() override;
};


class Jpeg : public Image {
    /*
     * Another child of Image, just here to make the reason for inheritance
     * clearer.
     * */
 public:
    Jpeg(int width, int height, string flnm) : Image(width, height, flnm) {}
    void display() override;
};


class Png : public Image {
    /*
     * Another child of Image, just here to make the reason for inheritance
     * clearer.
     * */
 public:
    Png(int width, int height, string flnm) : Image(width, height, flnm) {}
    void display() override;
};


/*
 * Just some funcs to explore overloading and overriding:
 * */
void mess_with_image(Image& img);
void f(Image& img);
void f(Gif& img);

/*
 * Below doesn't work: can't overload on const vs. non-const
 * param.
void f(const Gif& img) { cout << "Const gif f()\n"; }
 * */


#endif
