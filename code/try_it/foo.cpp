#include <iostream>

using namespace std;


struct Foo {
	int num;
	Foo(int i): num(i) {};
};

class Bar {
	int num;
	Bar(int i): num(i) {};
};

int main(){
	Foo f = Foo(5);		//line A
	Bar b = Bar(7);		//line B
	cout << f.num;		//line C
	cout << b.num;		//line D
}


