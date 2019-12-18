#ifndef TOOLS_H
#define TOOLS_H

#define MAX_HEIGHT 8
#define MIN_HEIGHT 1

// in uppercase letters
#define MAX_WIDTH 8
#define MIN_WIDTH 1

#include <string>


bool read_string(char *string, int size);
void fix_string(char *string);
bool valid_x(int x);
bool valid_y(int y);
#endif
