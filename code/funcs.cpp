#include <iostream>
using namespace std;

void pass_by_value(int n)
{
    n++;
}


void pass_by_ref(int& n)
{
    n++;
}


int call_with_ret(int n)
{
    return(n * n);
}


// uncomment the following function, and you will find it will
// not compile: if `n` is const, we can't modify it!
// void pass_by_constref(const int& n)
// {
//    n++;
// }


int main()
{
    int n = 7;
    pass_by_value(n);
    cout << "after pass_by_value, n = " << n << endl;
    pass_by_ref(n);
    cout << "after pass_by_ref, n = " << n << endl;
    int n2 = call_with_ret(n);
    cout << "after call_with_ret, n2 = " << n2 << endl;
}
