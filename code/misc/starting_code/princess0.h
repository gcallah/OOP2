#ifndef PRINCESS_H
#define PRINCESS_H

#include <string>
#include <iostream>

class Frog;


class Princess {
    friend class amphib::Frog;

    friend std::ostream& operator<<(std::ostream& os, const Princess& princess);

public:
    Princess(const std::string& name) : name(name), spouse(nullptr) {}

    const std::string& get_name() const { return name; }

    void marries(amphib::Frog* fp);

private:
    std::string name;
    amphib::Frog* spouse;
};

#endif
