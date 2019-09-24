#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


struct Warrior {
    string name;
    int strength;
};


void status(const vector<Warrior>& warriors) {
    cout << "In status\n";
    for (Warrior w : warriors) {
        cout << "Warrior " << w.name << " has strength " << w.strength << endl;
    }
}


void battle(istream& is, const vector<Warrior>& warriors) {
    string w1, w2;
    is >> w1 >> w2;
    cout << "In battle\n";
    
    for (Warrior w : warriors) {
        if (w1 == w.name) {
            cout << w1 << " is ready to battle!\n";
        }
        if (w2 == w.name) {
            cout << w2 << " is ready to battle!\n";
        }
    }
}


void create_warrior(istream& is, vector<Warrior>& warriors) {
    Warrior new_w;
    is >> new_w.name >> new_w.strength;
    cout << "In create_warrior\n";
    warriors.push_back(new_w);
}


int main() {
    ifstream input("input.txt");
    string command;
    vector<Warrior> warriors;
 
    while (input >> command) {
        cout << "Command is " << command << endl;
        if (command == "Status")
            status(warriors);
        else if (command == "Warrior")
            create_warrior(input, warriors);
        else if (command == "Battle")
            battle(input, warriors);
    }
}
