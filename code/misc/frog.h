#ifndef FROG_H
#define FROG_H

#include <string>
#include <iostream>

class Princess;

namespace amphib {

    class Frog {
        friend class Princess;
    
        friend std::ostream& operator<<(std::ostream& os, const amphib::Frog& frog);
    
    public:
        Frog(const std::string& name) : name(name), spouse(nullptr) {}
    
        const std::string& get_name() const { return name; }
    
        void marries(Princess* fp);
    
    private:
        std::string name;
        Princess* spouse;
    };

}

#endif
