#include "unity.h"
#include "cli.h"
#include "mock_terminal.h"

void test_Empty() {
    cmd_args_t args = {.buf = "\n"};

    bool r = try_parse(&args);

    TEST_ASSERT_EQUAL_INT(false, r);
}

void test_OneToken() {
    cmd_args_t args = {.buf = "token\n"};

    bool r = try_parse(&args);

    TEST_ASSERT_EQUAL_INT(true, r);
    TEST_ASSERT_EQUAL_INT(1, args.count);
    TEST_ASSERT_EQUAL_STRING("token", args.tokens[0]);
}

void test_TwoTokens() {
    cmd_args_t args = {.buf = "token1 token2\n"};

    bool r = try_parse(&args);

    TEST_ASSERT_EQUAL_INT(true, r);
    TEST_ASSERT_EQUAL_INT(2, args.count);
    TEST_ASSERT_EQUAL_STRING("token1", args.tokens[0]);
    TEST_ASSERT_EQUAL_STRING("token2", args.tokens[1]);
}

void test_LineTooLong() {
    cmd_args_t args;
    for (int i = 0; i < CLI_LINE_MAX; i++)
        args.buf[i] = 'a';

    terminal_println_Expect("Error: Line is too long.");
    terminal_getc_IgnoreAndReturn('\n');

    bool r = try_parse(&args);

    TEST_ASSERT_EQUAL_INT(false, r);
}

void test_TooManyArgs() {
    cmd_args_t args = {.buf = ""};
    for (int i = 0; i < CLI_ARGC_MAX; i++) {
        args.buf[2 * i] = 'a';
        args.buf[2 * i + 1] = ' ';
    }
    args.buf[2 * CLI_ARGC_MAX] = '\n';

    terminal_println_Expect("Error: Too many arguments.");

    bool r = try_parse(&args);

    TEST_ASSERT_EQUAL_INT(false, r);
}
