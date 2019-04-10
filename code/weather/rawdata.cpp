// Copyright 2019 Gene Callahan
#include <string>
#include <iostream>
using namespace std;
#include "./rawdata.h"


ostream& operator<<(ostream& os, const RawData& rd) {
    os << "RawData; len = " << rd.size() << endl;
    return os;
}


ostream& operator<<(ostream& os, const Binary& rd) {
    os << "Binary; len = " << rd.size() << endl;
    return os;
}
