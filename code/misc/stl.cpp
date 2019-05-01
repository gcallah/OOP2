/*
 * Let's use the Standard Template Library!
 * */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <typename T>
void print_list(list<T> l) {
    cout << "_______" << endl;
    for (T item : l) cout << item << endl;
    cout << "_______" << endl;
}


bool is_odd(int n) { return (n % 2) != 0; }

int main() {
    /*
     * Tests for STL code usage.
     * */
    char s[] = "Bjarne Stroustrup";

    cout << s << "\n";

    int clen = 17;
    sort(s, s + clen);

    cout << s << "\n";

    // char lists:
    list<char> clist(s, s + clen);
    print_list(clist);

    // int lists:
    int ilen = 8;
    int iptr[] = { 16, 32, 64, 128, 2, 4, 8, 17 };
    list<int> ilist(iptr, iptr + ilen);
    print_list(ilist);

    // iterators:
    list<int>::iterator iiter = find(ilist.begin(), ilist.end(), 8);
    cout << "Iter is at: " << *iiter << endl;
    ++iiter;
    if (iiter != ilist.end()) {
        cout << "Iter is at: " << *(iiter) << endl;
    }

    list<int>::iterator if_iter = find_if(ilist.begin(),
            ilist.end(), [] (int n) { return (n % 2) != 0; });
    cout << "If iter is at: " << *if_iter << endl;
}








