#include "frog.h"
#include "princess.h"

using namespace std;


void Frog::marries(Princess* pp) { 
    spouse = pp;
    pp->spouse = this;
}

ostream& operator<<(ostream& os, const Frog& frog) {
    string marital_status = (frog.spouse ?
            "married to " + frog.spouse->get_name()
            : "unmarried");
    os << "Frog Prince: " << frog.name << " is " << marital_status << endl;
    return os;
}

