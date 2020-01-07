#ifndef TOOLS_H
#define TOOLS_H

#ifndef COLORS_
#define COLORS_

#define P_RST  "\033[0m"
#define P_BLC  "\033[1;30;47m"
#define P_WHT "\033[1;37;40m"
#define P_BLUE "\033[34;44m"

#endif  /* COLORS_ */


#include <string>

enum Color { black, white };

bool read_string(char *string, int size);
void fix_string(char *string);
#endif
