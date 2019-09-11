/*
 * */
#include <iostream>
#include <string>
using namespace std;

int get_rot(ifstream& input);
void fill_line_vec(input, lines);
/*
    decrpypt(lines);
    output(lines);
 * */
int main() {
    int rotation;
    vector<string> lines;

    ifstream input("encrypted.txt");
    rotation = get_rot(input);
    fill_line_vec(input, lines);
    decrpypt(lines);
    output(lines);
}


int get_rot(ifstream& input) {
    return 1;
}


void fill_line_vec(ifstream& input, vector<string>& lines) {
    lines.push_back("Janeil");
}
