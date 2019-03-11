// header file for image class
#include <string>
using namespace std;


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

