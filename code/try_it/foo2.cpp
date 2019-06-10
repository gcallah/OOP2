#include <iostream>

using namespace std;


class Foo {
public:
	Foo(int i): num(i) {};  // line A
	int get_num() const {
		return num++;  // line B
	}
	void set_num (int i) {
		num = i;  // line C
	}
private:
	int num;

int main() {
	Foo bar = Foo(5);
	bar.set_num(7);
	cout << bar.get_num();
};

