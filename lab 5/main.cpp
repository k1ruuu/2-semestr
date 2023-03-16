#include <iostream>
#include "lab5.hpp"
using namespace std;


int main() {
    BoolVector vec(true);
    vec.push_back(false);
    ifprint(vec);
    vec[1] = true;
    ifprint(vec);
    vec.at(1) = false;
    ifprint(vec);
    vec.insert(1, true);
    ifprint(vec);
    vec.erase(1);
    ifprint(vec);
}

