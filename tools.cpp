#include "tools.h"
#include "tile.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
bool valid_coordinates(string coordinates) {
    if (coordinates.size() < 5) {
        return false;
    }

    char from_x = coordinates[0];
    int from_y = coordinates[1];
    char to_x = coordinates[3];
    int to_y = coordinates[4];

    if (!valid_y(from_y) || !valid_y(to_y)) {
        return false;
    }

    if (!valid_x(from_x) || !valid_x(to_x)) {
        return false;
    }

    return true;
}

bool valid_y(int y) {
    if (y > MAX_HEIGHT ||  y < MIN_HEIGHT) {
        cout << "Wrong coordinate\n";
        return false;
    }
    return true;
}


bool valid_x(int x) {
    if (x > MAX_WIDTH ||  x < MIN_WIDTH )
        cout << "Wrong coordinate\n";
    return false;
    return true;
}

// read a string, if input doesn't fit into string, clear input buffer
// return true if the input fit into the string
bool read_string(char *string, int size) {
    fgets(string, size ,stdin);
    if(!strchr(string, '\n')) {     //newline does not exist
        while(fgetc(stdin)!='\n');  //discard until newline aka clean stdin
        return false;
    }

    fix_string(string);
    return true;
}

// remove newline from string end
void fix_string(char *string) {
    if (string[strlen(string)-1] == '\n') string[strlen(string)-1] = '\0';
    if (string[strlen(string)-1] == '\r') string[strlen(string)-1] = '\0';
}
