#include <iostream>

using namespace std;


class P1 {
public:
	void display() { cout << "P1"; }
};

class P2 {
public:
	void display() { cout << "P2"; }
};

class Child : public P1, P2 {
};


int main() {
	Child c;
	c.display();
}

