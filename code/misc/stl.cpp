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


void print_cvec(string hdr, vector<char> cv) {
    cout << hdr << endl;
    for (char c : cv) {
        cout << c << " ";
    }
}

void print_ivec(string hdr, vector<int> iv) {
    cout << hdr << endl;
    for (int n : iv) {
        cout << n << " ";
    }
}

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
template <typename IterableOfPrintables>
void print(string hdr, IterableOfPrintables c) {
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
 * We could pass this `is_odd()` function in to `find_if()`,
 * or pass a *lambda* instead.
 * */
bool is_odd(int n) { return (n % 2) != 0; }

bool is_greater_than_20(int n) { return n > 20; }
bool is_div_by_128(int n) { return n % 128 == 0; }

/*
 * Or, we could have a *functor*!
 * */

/*
 * Our own find():
 * */
template <typename T, typename U>
T our_find(T start, T finish, U sought) {
    for (; start != finish; start++) {
        if (sought == *start) return start;
    }
    return finish;
}

/*
 * Our own find_if():
 * */
template <typename Iterable, typename Predicate>
Iterable our_find_if(Iterable start, Iterable finish, Predicate pred) {
    for (; start != finish; start++) {
        if (pred(*start)) return start;
    }
    return finish;
}

/*
 * Our main will exercise some STL capabilities.
 * */
int main() {
    int bjarnelen = 17;
    int dennislen = 14;

    string bjarne("Bjarne");
    cout << bjarne.length() << endl;
    char s[]  = "bjarne stroustrup";
    char s2[] = "dennis ritchie";

    cout << "C++ creator: " << s << "\n";
    cout << "C creator, 4th letter: " << s2[3] << "\n";

    /*
     * Let's do some things with a `vector`.
     * We will create it with a half-open range, and then sort it.
     * */
    vector<char> cvec(s2, s2 + dennislen);
    vector<char>::iterator our_attempt = our_find(cvec.begin(), cvec.end(), 'i');
    cout << "Did our own find() work? " << *our_attempt << endl;

    print_vec("cvec", cvec);
    vector<char>::iterator start_at_R = find(cvec.begin(), cvec.end(), 'r');
    vector<char>::iterator end_at_h = find(cvec.begin(), cvec.end(), 'h');
//    sort(cvec.begin(), cvec.end());
//    print_vec("sorted cvec", cvec);
    sort(start_at_R, end_at_h);
    print_cvec("sorted Ritchie", cvec);

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
    cout << "Is clist a permutation of clist2? "
        << is_permutation(clist.begin(), clist.end(), clist2.begin())
        << endl; ;
    cout << "Is clist a permutation of clist3? "
        << is_permutation(clist.begin(), clist.end(), clist3.begin())
        << endl; ;

     * */
    /*
     * Testing a list of Cats:
    Cat catptr[] = { Cat(), Cat(), Cat() };
    list<Cat> catlist(catptr, catptr + 3);
    print("Cat list", catlist);
     * */

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
     * This *won't* work:
     * `sort(ilist.begin(), ilist.end());`
     * */
    ilist.sort();
    print("ilist sorted", ilist);

    /*
     * Here we are going to pass `is_odd()` to `find_if()`.
     * */
//    list<int>::iterator odd_loc = our_find_if(ilist.begin(), ilist.end(), is_odd);
//    cout << "First odd number in list is: " << *odd_loc << endl;
//    list<int>::iterator gt = our_find_if(ilist.begin(), ilist.end(), is_greater_than_20);
//    cout << "First number > 20 in list is: " << *gt << endl;
//    list<int>::iterator div_by_128 = our_find_if(ilist.begin(), ilist.end(), is_div_by_128);
//    cout << "First number divisible by 128 in list is: " << *div_by_128 << endl;

    /*
     * Here we are going to pass functor `IsOdd` to `find_if()`.
     * */

    /*
     * Here we are going to pass a *lambda* to `find_if()`.
     * The lambda starts with `[]`. The point here is to show
     * that this form and the one above are identical in effect.
     * */
    list<int>::iterator lambda_iter = find_if(
            ilist.begin(),
            ilist.end(),
            [](auto n) { return n - 24 == 8; });
    cout << "First (lambda) number in list is: " << *lambda_iter << endl;
}
