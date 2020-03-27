#ifndef TOOLS_H
#define TOOLS_H

#include <string>

#define RESET     "\033[0m"
#define FG_BLACK  "\033[30m"
#define BG_BLACK  "\033[40m"
#define FG_BLUE   "\033[34m"
#define BG_BLUE   "\033[44m"
#define FG_CYAN   "\033[36m"
#define BG_CYAN   "\033[46m"
#define FG_WHITE  "\033[37m"
#define BG_WHITE  "\033[47m"

void change_colors(const char *setting = "", const char *fg = "", const char *bg = "");

#define PLAY 1
#define QUIT 2


enum Color { black, white, none };

bool read_string(char *string, const char *size);
void fix_string(char *string);
#endif
