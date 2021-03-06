/*
 * Let's use the *Standard Template Library*!
 * First, we will include the headers we need:
 * */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

/*
 * Let's make a template for a `print_vec` that can handle
 * vectors of any type:
 * Templates are the C++ feature that enable generic programming.
 * */
template <typename Printable>
void print_vec(string hdr, vector<Printable> vp) {
    cout << hdr << endl;
    for (Printable p : vp) {
        cout << p << " ";
    }
    cout << endl;
}


/*
 * But, we can go even more generic, and make a `print` that can print
 * *containers* of any sequential type:
 * */
template <typename Collection>
void print(string hdr, Collection c) {
    cout << hdr << endl;
    for (auto item : c) {
        cout << item << ' ';
    }
    cout << endl;
}


class Cat {
    friend ostream& operator<<(ostream& os, const Cat& cat) {
        os << "meow ";
        return os;
    }
};

/*
 * We could pass this `is_odd()` function in to a `find_if()`,
 * or pass a *lambda* instead.
 * */
bool is_odd(int n) { return (n % 2) != 0; }

/*
 * Or, we could have a *functor*!
 * */

/*
 * Let's see how find() could be written:
 * */
template <typename T, typename U>
T our_find(T start, T finish, U sought) {
    for (T iter = start; iter != finish; iter++) {
        if (sought == *iter) return iter;
    }
    return finish;
}


/*
 * Our main will exercise some STL capabilities.
 * */
int main() {
    int bjarnelen = 17;
    int dennislen = 14;

    char s[]  = "Bjarne Stroustrup";
    char s2[] = "Dennis Ritchie";

    cout << "C++ creator: " << s << "\n";
    cout << "C creator, 4th letter: " << s2[3] << "\n";

    /*
     * Let's do some things with a `vector`.
     * We will create it with a half-open range, and then sort it.
     * */
    vector<char> cvec(s2, s2 + dennislen);
    print_vec("cvec", cvec);
    /*
     * Illustrate how iterators can select slices:
     * */
    vector<char>::iterator start_at_R = find(cvec.begin(), cvec.end(), 'R');
    vector<char>::iterator end_at_h = find(cvec.begin(), cvec.end(), 'h');
    sort(start_at_R, end_at_h);
    print_vec("sorted cvec", cvec);
    /*
     * Test out our own find function:
     * */
    vector<char>::iterator our_attempt = our_find(cvec.begin(), cvec.end(), 'i');
    cout << "Does our own find work? " << *our_attempt << endl;

    /*
     * Create a `char` list:
     * */
    list<char> clist(s, s + bjarnelen);
    list<char> clist2 = clist;
    list<char> clist3(s2, s2 + dennislen);
    /*
     * The STL provides us with a `reverse()` functions that
     * reverses an iterable structure:
     * */
    reverse(clist.begin(), clist.end());
    print("clist reversed", clist);
    /*
     * But even after `clist` is reversed, `clist` and
     * `clist2` are still permutations of each other:
     * */
    cout << "Is clist a permutation of clist2? "
        << is_permutation(clist.begin(), clist.end(), clist2.begin())
        << endl; ;
    cout << "Is clist a permutation of clist3? "
        << is_permutation(clist.begin(), clist.end(), clist3.begin())
        << endl; ;

    /*
     * Testing a list of Cats:
     * */
    Cat catptr[] = { Cat(), Cat(), Cat() };
    list<Cat> catlist(catptr, catptr + 3);
    print("Cat list", catlist);

    /*
     * Testing an int list:
     * */
    int ilen = 8;
    int iptr[] = { 16, 32, 64, 128, 2, 4, 8, 17 };
    list<int> ilist(iptr, iptr + ilen);
    /*
     * Our print can work for lists as well as vectors:
     * */
    print("ilist", ilist);
    /*
     * `sort()` does not work for lists, since they aren't random access.
     * Thus lists have their own `sort()` method, called below:
     * This *won't* work: `sort(ilist.begin(), ilist.end());`
     * */
    ilist.sort();
    print("ilist sorted", ilist);

    /*
     * Here we are going to pass `is_odd()` to `find_if()`.
     * */
    list<int>::iterator odd_loc = find_if(ilist.begin(), ilist.end(), is_odd);
    cout << "First odd number in ilist is " << *odd_loc << endl;
    cout << "Rest of list:\n";
    for(list<int>::iterator iter = odd_loc; iter != ilist.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    /*
     * Here we are going to pass a *lambda* to `find_if()`.
     * The lambda starts with `[]`. The point here is to show
     * that this form and the one above are identical in effect.
     * */
    list<int>::iterator if_iter3 = find_if(ilist.begin(), ilist.end(), [](auto num) { return num % 2; });
    cout << "First lambda odd number in list is: " << *if_iter3 << endl;

    /*
     * Here we are going to pass functor `IsOdd` to `find_if()`.
     * */
}
