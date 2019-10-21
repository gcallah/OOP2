#include "princess.h"
#include "frog.h"

using namespace std;


void Princess::marries(amphib::Frog* fp) { 
    spouse = fp;
    fp->spouse = this;
}


ostream& operator<<(ostream& os, const Princess& princess) {
    string marital_status = (princess.spouse ?
            "married to " + princess.spouse->get_name()
            : "unmarried");
    os << "Princess: " << princess.name << " is " << marital_status << endl;
    return os;
}
