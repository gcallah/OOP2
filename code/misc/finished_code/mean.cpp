/*
* This code demonstrates basic `vector` handling in C++.
* */
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    cout << "Enter recent temperatures and we will calulate their average:\n";
    
    vector<double> temps;
    // can't run the following on Travis:
    for(double temp; cin >> temp; )
        temps.push_back(temp);
    double total = 0.0;
    // loop and total all temps
    for(double temp : temps)
        total += temp;
    double mean = total / temps.size();
    cout << "Your mean temperature for the last " << temps.size()
         << " days was " << mean << '\n';
    return 0;
}
