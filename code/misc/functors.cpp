
#include <iostream>
#include <cmath>

using namespace std;


class Sin {
    public:
        double operator()(double n) {
            return sin(n);
        }
};

class Fib {
    public:
        Fib() {
            for (int i = 0; i < MAX_FIB; i++)
                memo[i] = NOT_CALCED;
        }

        double operator()(int n) {
            if (memo[n] != NOT_CALCED) return memo[n];

            int result = 0;
            if (n <= 1) result = 1;
            else result = (operator()(n - 1) + operator()(n - 2));

            memo[n] = result;
            return result;
        }

        const int MAX_FIB = 100;
        const int NOT_CALCED = -1;
    private:
        int* memo = new int[MAX_FIB];
};

int main() {
    Sin sine = Sin();
    double d = sine(1);
    cout << "sin(1) == " << d << endl;
    Fib fib = Fib();
    int f = fib(40);
    cout << "fib(40) == " << f << endl;
}
