
/*
 * This file has code illustrating the use of a simple functor
 * that does a sine calculations, as well as a more complex functors that 
 * memo-izes a recursive Fibonacci calculation.
 * */
#include <iostream>
#include <cmath>

using namespace std;


/*
 * `Sin` is a trivial functor for calculating the sine of an angle:
 * */
class Sin {
    public:
        double operator()(double n) {
            return sin(n);
        }
};

/*
 * `Fib` is a more significant functor: it takes a recursive Fibonacci
 * functions, which has exponential run time, and memo-izes it to 
 * achieve linear run time.
 * */
class Fib {
    public:
        /*
         * The constructor sets up the memo-ization by setting all
         * values to `NOT_CALCED`.
         * */
        Fib() {
            for (int i = 0; i < MAX_FIB; i++)
                memo[i] = NOT_CALCED;
        }

        /*
         * The function call itself uses a stored value if present;
         * it only performs the calculation if the `memo` value
         * for the i<sup>th</sup> integer is `NOT_CALCED`.
         * */
        double operator()(int n) {
            // if we calced it before, return that number:
            if (memo[n] != NOT_CALCED) return memo[n];

            long result = 0;
            if (n <= 1) result = 1;
            else result = (operator()(n - 1) + operator()(n - 2));

            memo[n] = result;operator()(
            return result;
        }

        const int MAX_FIB = 100;
        const int NOT_CALCED = -1;

    private:
        int* memo = new int[MAX_FIB];
};


/*
 * `main()` simply contains the code to test the above functors:
 * */
int main() {
    // sine:
//    Sin sine = Sin();
//    double d = sine(1);
//    cout << "sin(1) == " << d << endl;

    // fibonacci number:
    int fib_num = 10;   // some default or other!
    while (fib_num >= 0) {
        cout << "Enter fib number: ";
        cin >> fib_num;
        cout << "\nThanks!\n";
        if (fib_num >= 0) {
            Fib fib = Fib();
            long f = fib(fib_num);
            cout << "fib(" << fib_num << ") == " << f << endl;
        }
    }
}
