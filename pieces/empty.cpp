#include <string>
#include "empty.h"

using namespace std;

Empty::Empty(string name_, int color_) {
    name = name_;
    color = color_;
}

bool Empty::move() {
    return false;
}
