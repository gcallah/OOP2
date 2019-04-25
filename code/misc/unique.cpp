#include<bits/stdc++.h>
#include <string>
using namespace std;

bool isUnique(string s) {
    string seen = "";    
    for (char c : s) {
        if (s.find(c) != string::npos) return false;
        s += c;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    cout << (isUnique(s) ? "True" : "False") << endl;
    return 0;
}

