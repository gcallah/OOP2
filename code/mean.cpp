#include <iostream>
#include <vector>
using namespace std;

int main() {
    /*
     * This code demonstrates basic `vector` handling in C++.
     * */
    cout << "Enter recent temperatures and we will calulate their average:\n";
    
    vector<double> temps;
    for(double temp; cin >> temp; )
        temps.push_back(temp);
    double total = 0.0;
    for(double temp : temps)
        total += temp;
    double mean = total / temps.size();
    cout << "Your mean temperature for the last " << temps.size()
         << " days was " << mean << '\n';
    cout << temps[10000];
    return 0;
}
