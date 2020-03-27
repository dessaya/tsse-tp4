#include <stdio.h>
#include "terminal.h"

void terminal_println(const char s[]) {
    puts(s);
}

char terminal_getc() {
    return getc(stdin);
}
