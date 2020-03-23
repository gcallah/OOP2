#ifndef FROG_PRINCE_H
#define FROG_PRINCE_H

#include <string>

using namespace std;

class Princess;


class FrogPrince {
    friend class Princess;

    friend ostream& operator<<(ostream& os, const FrogPrince& frog);

public:
    FrogPrince(const string& name) : name(name), spouse(nullptr) {}

    const string& get_name() const;

    void marries(Princess* fp);

private:
    string name;
    Princess* spouse;
};

#endif
