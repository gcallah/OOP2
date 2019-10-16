#ifndef FROG_H
#define FROG_H

#include <string>
#include <iostream>

class Princess;


class Frog {
    friend class Princess;

    friend std::ostream& operator<<(std::ostream& os, const Frog& frog);

public:
    Frog(const std::string& name) : name(name), spouse(nullptr) {}

    const std::string& get_name() const { return name; }

    void marries(Princess* fp);

private:
    std::string name;
    Princess* spouse;
};

#endif
