// Copyright 2019 Gene Callahan
#include <string>
#include <iostream>
using namespace std;
#include "./rawdata.h"


ostream& operator<<(ostream& os, const RawData& rd) {
    os << rd.to_string() << endl;
    return os;
}
