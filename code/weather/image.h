// header file for image class
#ifndef WEATHER_IMAGE
#define WEATHER_IMAGE 1

#include <string>
using namespace std;

const int DEF_HEIGHT = 1600;
const int DEF_WIDTH = 2400;


class Image
{
 public:
    Image(int width, int height, string flnm);
    // copy constructor:
    Image(const Image& img2);
    ~Image();
    Image& operator=(const Image& img2);
    int image_sz();

 private:
    int width;
    int height;
    unsigned char* image_buf;
    void copy_fields(const Image& img2);
};


void mess_with_image(Image img);

#endif
