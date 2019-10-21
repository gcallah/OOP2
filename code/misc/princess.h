#ifndef PRINCESS_H
#define PRINCESS_H
#include <string>

using namespace std;

class FrogPrince;

class Princess {
    friend class FrogPrince;

    friend ostream& operator<<(ostream& os, const Princess& princess);

public:
    Princess(const string& name) : name(name), spouse(nullptr) {}

    const string& get_name() const;

    void marries(FrogPrince* fp);

private:
    string name;
    FrogPrince* spouse;
};

#endif
