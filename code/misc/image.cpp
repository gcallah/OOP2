
/*
 * `image.cpp` is designed to illustrate basic memory management.
 * */
#include <iostream>
#include <vector>
using namespace std;

/*
 * We define a simple structure with a constructor and a single field.
 * */
class Image {
public:
    Image(int q, string d, int sz) : quality(q), descr(d),
        size(sz) {
        buffer = new int [sz];
    }

    Image(const Image& source) {
        quality = source.quality;
        descr = source.descr;
        size = source.size;
        buffer = new int [size];
        for (int i = 0; i < size; i++) {
            buffer[i] = source.buffer[i];
        }
    }

    ~Image() { delete buffer; }

    Image& operator=(const Image& rhs) {
        if (this != &rhs) {
            delete buffer;
            quality = source.quality;
            descr = source.descr;
            size = source.size;
            buffer = new int [size];
            for (int i = 0; i < size; i++) {
                buffer[i] = source.buffer[i];
            }
        }
        return *this;
    }

private:
    int quality;
    string descr;
    int  size;
    int* buffer;
//    Image(int i) : val(i) {}
};

/*
 * In `main()` we are going to
 * allocate an array of 100 `Image` pointers,
 * fill it with `Image`s, change their values,
 * and then delete them:
 * */
int main() {
    // allocate array:
//    Image** data = new Image*[100];
//    const int x = 7;
//    int* iptr = &x;
//    x = 17;
//
//    // Fill array with Images:
//    for (int i = 0; i < 100; i++) {
//        data[i] = new Image{i + 1};
//    }
//
//    // Change their values:
//    for (int i = 0; i < 100; i++) {
//        data[i]->val += i;
//        cout << "data[" << i << "] == " << data[i]->val << endl;
//    }
    Image image(3, "Photo of the moonrise.", 100);
}
