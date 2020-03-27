#ifndef CLI_H
#define CLI_H

#include <stdbool.h>

/** Maximum length of a command line. */
#define CLI_LINE_MAX 80

/** Maximum amount of arguments for any given command. */
#define CLI_ARGC_MAX 20

/**
 * A parsed command, analogous to `argv` & `argc`.
 *
 * Example: if the user enters the command `gpio LED1 write 1`, this
 * struct will contain `tokens = {"gpio", "LED1", "write", "1"}`, and
 * `count = 4`.
 */
typedef struct {
    /** Command line buffer. Arguments are separated by null characters. */
    char buf[CLI_LINE_MAX];
    /** Pointers to the first character of each argument (`tokens[0]` would be the command name). */
    char *tokens[CLI_ARGC_MAX];
    /** Amount of arguments (including the command itself). */
    int count;
} cmd_args_t;

bool try_parse(cmd_args_t *args);

#endif

