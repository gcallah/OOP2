#include <iostream>
#include <string>

using namespace std;

const int ARR_SIZE = 12;


void header(string msg) {
    cout << "\n*******************\n" << msg << endl;
}


int main() {
    header("Let's examine an int array:");
    int int_array[ARR_SIZE];
    int int_array2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    cout << "int_array = " << int_array << endl;

    for (int item : int_array) {
        cout << "item = " << item << ' ';
    }
    cout << endl;

    /*
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
    */

    header("Now let's try to cause some trouble:");
    for (size_t i = 0; i < ARR_SIZE + 8; i++) {
        int_array[i] = i;
    }

    for (size_t i = 0; i < ARR_SIZE; i++) {
        cout << "int_array2[" << i << "] = " << int_array2[i] << endl;
    }
    /*
    */
}


