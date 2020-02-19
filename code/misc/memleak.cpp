/*
 * This code leaks memory like a madman:
 * just showing the effect of not cleaning up!
 * */

#include <iostream>
struct Thing {
    int* iarr;
    Thing(int n) {
        iarr = new int[n];
    }
};

const int OUTER = 1000000;
const int INNER = 10000;

int main() {
    /*
     * In these loops we allocate more and more heap memory
     * without ever cleaning it up:
     * */
    for (int i = 0; i < OUTER; i++) {
        Thing** things = new Thing*[INNER];
        for (int j = 0; j < INNER; j++) {
            things[j] = new Thing(INNER);
        }
    }
}


