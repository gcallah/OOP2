#include <cassert>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    /*
     * This code demonstrates basic `vector` handling in C++.
     * */
    cout << "Enter recent temperatures and we will calulate their average:\n";
    
    vector<double> temps;
    /*
     * can't run the following on Travis:
    for(double temp; cin >> temp; )
        temps.push_back(temp);
     */
    /*
     * For Travis:
    */
    temps.push_back(50);
    temps.push_back(100);
    double total = 0.0;
    for(double temp : temps)
        total += temp;
    double mean = total / temps.size();
    cout << "The 40th temp is: " << temps[39] << endl;
    cout << "Your mean temperature for the last " << temps.size()
         << " days was " << mean << '\n';
    assert(mean == 75);
    return 0;
}
