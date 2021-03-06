// Copyright 2019 Gene Callahan
// header file for image class
#ifndef WEATHER_IMAGE
#define WEATHER_IMAGE 1

#include <string>

const int DEF_HEIGHT = 1600;
const int DEF_WIDTH = 2400;


/*
 * A trivial class just to demonstrate multiple inheritance.
 * */
class Movie {
 public:
     void play() const { std::cout << "Playing a movie\n"; }
     virtual void display(const std::string& s) const
        { std::cout << "Displaying a movie\n"; }
};


/*
 * This will be the base class for all types of images.
 * It is an abstract class, due to the `display()` method.
 * */
class Image {
 public:
    Image(int width, int height, const std::string& flnm);
    // copy constructor:
    Image(const Image& img2);
    ~Image();
    Image& operator=(const Image& img2);
    int image_sz();

    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
    // const std::string& display(const std::string& s="Base") const;
    virtual const std::string& display(const std::string& s="Base") const;

    void compress() { std::cout << "Compressing!\n"; }
    int get_height() const { return height; }
    int get_width() const { return width; }

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
     using Image::Image;
//    Gif(int width, int height, const std::string& flnm)
//        : Image(width, height, flnm) {
//    }
//    // copy constructor:
//    Gif(const Gif& img2);
    /*
     * display() will override the parent class display().
     * Notice the key word `override`: it is a safety mechanism to catch 
     * typos!
     * */
    const std::string& display(const std::string& s="") const;  // override;

    /*
     * The following line of code *hides* `compress()` from
     * our base class:
     * */
    void compress(int level);

    /*
     * The line below makes `compress()` available in Gif.
        using Image::compress;
     * We could also have written:
     * void compress() override { Image::compress(); }
     * */
};


class AnimGif : public Movie, public Gif {
    /*
     * This will be a "grandchild" class.
     * */
 public:
    AnimGif(int width, int height, const std::string& flnm);
    // copy constructor:
    AnimGif(const AnimGif& img2);
    AnimGif& operator=(const AnimGif& img2);
    // const std::string& display(const std::string&) const;
    ~AnimGif();

 private:
    unsigned char* image_buf2;
};


class Jpeg : public Image {
    /*
     * Another child of Image, just here to make the reason for inheritance
     * clearer.
     * */
 public:
    Jpeg(int width, int height, const std::string& flnm)
        : Image(width, height, flnm) {
    }
    const std::string& display(const std::string&) const;
};


class Png : public Image {
    /*
     * Another child of Image, just here to make the reason for inheritance
     * clearer.
     * */
 public:
    Png(int width, int height, std::string flnm) : Image(width, height, flnm) {
    }
    const std::string& display(const std::string&) const;
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
void f(const Gif& img) { std::cout << "Const gif f()\n"; }
 * */


#endif
