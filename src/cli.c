#include <string.h>
#include "terminal.h"
#include "cli.h"

/** Parse the command line tokens, replacing spaces with null characters in the buffer. */
static void parse_arguments(cmd_args_t *args) {
    args->count = 0;
    for (
        char *token = strtok(args->buf, " \t");
        token && args->count < CLI_ARGC_MAX;
        token = strtok(NULL, " \t")
    ) {
        args->tokens[args->count++] = token;
    }
}

static bool str_endswith(char s[], char c) {
    for (size_t i = 0; s[i]; i++) {
        if (s[i] == c && s[i + 1] == '\0') {
            return true;
        }
    }
    return false;
}

/** Remove `\r\n`. \return false if no newline characters were found. */
void str_rstrip(char s[]) {
    for (size_t i = 0; s[i]; i++) {
        if (s[i] == '\n' || s[i] == '\r') {
            s[i] = '\0';
            break;
        }
    }
}

void terminal_consume_until(char c) {
    while (terminal_getc() != c)
        ;
}

bool try_parse(cmd_args_t *args) {
    if (!str_endswith(args->buf, '\n')) {
        log_error("Line is too long.");
        terminal_consume_until('\n');
        return false;
    }
    str_rstrip(args->buf);

    parse_arguments(args);

    if (args->count == 0) {
        return false;
    }

    if (args->count >= CLI_ARGC_MAX) {
        log_error("Too many arguments.");
        return false;
    }

    return true;
}

