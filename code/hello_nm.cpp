#include <iostream>
#include <string>
using namespace std;

int main()
{
    // say hello to the user, not the world
    cout << "What is your name?\n";
    string name;
    cin >> name;
    cout << "Hello " << name << "!\n";
}
