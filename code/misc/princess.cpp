#include <iostream>
#include <string>

#include "princess.h"
#include "frog_prince.h"

using namespace std;


const string& Princess::get_name() const { return name; }

void Princess::marries(FrogPrince* fp) { 
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

