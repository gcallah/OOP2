#include <iostream>
#include <string>

using namespace std;


class FederationStarship  {
public:
    FederationStarship() {}

    void attack(int weapon) { 
        cout << "FederationStarship firing weapon # " << weapon; 
    }   
};

class Constitution : public FederationStarship {
public:
    virtual void transport() { cout << "Beam me up!"; }
    void attack() { 
        cout << "Constitution firing photon torpedos"; 
    }
};

int main() {
   Constitution* NCC_1701 = new Constitution();
   NCC_1701->attack("phasers");
}


