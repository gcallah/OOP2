#include <iostream>

using namespace std;


int main(){
    int y = 2;
    for (int x = 3; x > 0; --x) {
    	int counter = x + y;
    	while(counter > 0) { 
    		cout << "1";
    		--counter;
        }
        cout << endl;
    }
}

