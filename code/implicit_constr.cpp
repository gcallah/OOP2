#include <string>
#include <iostream>

using namespace std;


class Foo {
 public:
    Foo(string s, int n = 0) { str = s; num = n; }
    void display() { cout << str << ':' << num << endl; }
 private:
    string str;
    int num;
};

int main() {
    Foo thingOne("abc", 17);
    string s = "def";
    thingOne = s;
    thingOne.display();
}
