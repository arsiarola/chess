#ifndef TOOLS_H
#define TOOLS_H

#define P_RST  "\033[0m"
#define P_BLC  "\033[1;30;47m"
#define P_WHT "\033[1;37;40m"
#define P_BLUE "\033[34;44m"


#define PLAY 1
#define LOAD 2
#define QUIT 3

#include <string>

enum Color { black, white, none };



bool read_string(char *string, int size);
void fix_string(char *string);
#endif
