#include <iostream>
#include "tools.h"
#include <string.h>


#define P_BLUE "\033[34;44m"
void change_colors(const char *setting, const char *fg, const char *bg) {
    std::cout << setting << fg << bg;
}
