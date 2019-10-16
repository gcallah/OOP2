/*
    testPrincess.cpp
    Cyclic Association
    Sec Base
*/

#include <iostream>
#include <string>
using namespace std;

class FrogPrince;


class Princess {
    friend class FrogPrince;

    friend ostream& operator<<(ostream& os, const Princess& princess);

public:
    Princess(const string& name) : name(name), spouse(nullptr) {}

    const string& get_name() const { return name; }

    void marries(FrogPrince* fp);

private:
    string name;
    FrogPrince* spouse;
};

class FrogPrince {
    friend class Princess;

    friend ostream& operator<<(ostream& os, const FrogPrince& frog);

public:
    FrogPrince(const string& name) : name(name), spouse(nullptr) {}

    const string& get_name() const { return name; }

    void marries(Princess* fp);

private:
    string name;
    Princess* spouse;
};


void Princess::marries(FrogPrince* fp) { 
    spouse = fp;
    fp->spouse = this;
}


void FrogPrince::marries(Princess* pp) { 
    spouse = pp;
    pp->spouse = this;
}


ostream& operator<<(ostream& os, const Princess& princess) {
    string marital_status = (princess.spouse ?
            "married to " + princess.spouse->get_name()
            : "unmarried");
    os << "Princess: " << princess.name << " is " << marital_status << endl;
    return os;
}

ostream& operator<<(ostream& os, const FrogPrince& frog) {
    string marital_status = (frog.spouse ?
            "married to " + frog.spouse->get_name()
            : "unmarried");
    os << "Frog Prince: " << frog.name << " is " << marital_status << endl;
    return os;
}


int main() {
    Princess snowy("Snow White");
    cout << snowy << endl;
    FrogPrince froggy("Froggy");
    cout << froggy << endl;
    snowy.marries(&froggy);
    cout << snowy << endl;

    Princess sleeping("Sleeping Beauty");
    FrogPrince bullfrog("Bull Frog");
    bullfrog.marries(&sleeping);
    cout << sleeping << endl;
    cout << bullfrog << endl;
    //      << froggy << endl;
}


