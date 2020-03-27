#ifndef TERMINAL_H
#define TERMINAL_H

#include <stdlib.h>
#include <stdbool.h>

/** Write a string to the terminal, appending `'\\r\\n'`. */
void terminal_println(const char s[]);

/** Read a single character from the terminal. */
char terminal_getc();

/** Print an error message. */
#define log_error(msg) terminal_println("Error: " msg)

#endif
