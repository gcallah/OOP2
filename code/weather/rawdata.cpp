// Copyright 2019 Gene Callahan
#include <string>
#include <iostream>
using namespace std;
#include "./rawdata.h"


ostream& operator<<(ostream& os, const RawData& rd) {
    /*
     * We manage to "override" the output operator -- which we can't literally
     * do, since it is not in a class -- by having it call the virtual
     * `to_string()` method implemented in our RawData class heirarchy.
     * */
    os << rd.to_string() << endl;
    return os;
}
