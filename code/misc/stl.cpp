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
    string s2 = "Dennis Ritchie";

    cout << "C++ creator: " << s << "\n";
    cout << "C creator, 4th letter: " << s2[3] << "\n";

    int clen = 17;

    // char lists:
    list<char> clist(s, s + clen);
    list<char> clist2 = clist;
    reverse(clist.begin(), clist.end());
    cout << "Is clist a permutation of clist2? "
        << is_permutation(clist.begin(), clist.end(), clist2.begin())
        << endl; ;
    print_list(clist);

    // int lists:
    int ilen = 8;
    int iptr[] = { 16, 32, 64, 128, 2, 4, 8, 17 };
    list<int> ilist(iptr, iptr + ilen);
    print_list(ilist);
    ilist.sort();
    cout << "After sort, ilist is: \n";
    print_list(ilist);

    // iterators:
    list<int>::iterator iiter = find(ilist.begin(), ilist.end(), 8);
    cout << "After find(), iter is at: " << *iiter << endl;
    ++iiter;
    if (iiter != ilist.end()) {
        cout << "After increment, iter is at: " << *(iiter) << endl;
    }

    /*
     * Here we are going to pass a lambda to `find_if()`.
     * The lambda starts with [].
     * */
    list<int>::iterator if_iter = find_if(ilist.begin(),
            ilist.end(), [] (int n) { return (n % 2) != 0; });
    cout << "First odd number in list is: " << *if_iter << endl;
}








