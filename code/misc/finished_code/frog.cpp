#include <iostream>
#include <string>

#include "princess.h"
#include "frog_prince.h"

using namespace std;


const string& GrogPrince::get_name() const { return name; }

void FrogPrince::marries(Princess* pp) { 
    spouse = pp;
    pp->spouse = this;
}

ostream& operator<<(ostream& os, const FrogPrince& frog) {
    string marital_status = (frog.spouse ?
            "married to " + frog.spouse->get_name()
            : "unmarried");
    os << "Frog Prince: " << frog.name << " is " << marital_status << endl;
    return os;
}

