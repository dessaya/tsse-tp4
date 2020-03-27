#include "unity.h"
#include "cli.h"
#include "mock_terminal.h"

void test_Empty() {
    char s[] = "";
    str_rstrip(s);
    TEST_ASSERT_EQUAL_STRING("", s);
}

void test_JustEndl() {
    char s[] = "\n";
    str_rstrip(s);
    TEST_ASSERT_EQUAL_STRING("", s);
}

void test_JustCarriageEndl() {
    char s[] = "\r\n";
    str_rstrip(s);
    TEST_ASSERT_EQUAL_STRING("", s);
}

void test_NonEmpty() {
    char s[] = "hello world";
    str_rstrip(s);
    TEST_ASSERT_EQUAL_STRING("hello world", s);
}

void test_NonEmptyEndl() {
    char s[] = "hello world\n";
    str_rstrip(s);
    TEST_ASSERT_EQUAL_STRING("hello world", s);
}

void test_NonEmptyCarriageEndl() {
    char s[] = "hello world\r\n";
    str_rstrip(s);
    TEST_ASSERT_EQUAL_STRING("hello world", s);
}
