#include <iostream>
#include <string>

using namespace std;

const int ARR_SIZE = 10;


void header(string msg) {
    cout << "\n*******************\n" << msg << endl;
}


int main() {
    header("Let's examine an int array:");
    int int_array[ARR_SIZE];

    cout << "int_array = " << int_array << endl;

    for (int item : int_array) {
        cout << "item = " << item << ' ';
    }
    cout << endl;

    for (size_t i = 0; i < ARR_SIZE; i++) {
        cout << "Where is item " << i << "? (take address): "
            << &(int_array[i]) << endl;
        cout << "Where is item " << i << "? (use pointer): "
            << int_array + i << endl;
    }

    header("Let's examine a double array:");
    double double_array[ARR_SIZE];

    cout << "double_array = " << double_array << endl;

    for (double item : double_array) {
        cout << "item = " << item << ' ';
    }
    cout << endl;

    for (size_t i = 0; i < ARR_SIZE; i++) {
        cout << "Where is item " << i << "? (take address): "
            << &(double_array[i]) << endl;
        cout << "Where is item " << i << "? (use pointer): "
            << double_array + i << endl;
    }

    header("Now let's try to cause some trouble:");
    for (size_t i = 0; i < ARR_SIZE * 10; i++) {
        int_array[i] = i;
    }
    cout << "At index 50 we find " << int_array[50] << endl;
}


