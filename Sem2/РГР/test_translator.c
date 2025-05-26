#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "translator_utils.h"

// === find_translation ===

static void test_find_translation_known(void **state) {
    DictionaryEntry dict[] = {
        {"привет", "你好"},
        {"мир", "世界"}
    };
    const char* result = find_translation("привет", dict, 2);
    assert_string_equal(result, "你好");
}

static void test_find_translation_unknown(void **state) {
    DictionaryEntry dict[] = {
        {"кот", "猫"},
        {"собака", "狗"}
    };
    const char* result = find_translation("город", dict, 2);
    assert_true(result == NULL);
}

static void test_utf8_char_len_ascii(void **state) {
    assert_int_equal(utf8_char_len('A'), 1);
}

static void test_utf8_char_len_two_byte(void **state) {
    unsigned char c = 0xD0;  // Начало русской буквы
    assert_int_equal(utf8_char_len(c), 2);
}

static void test_utf8_char_len_three_byte(void **state) {
    unsigned char c = 0xE2;  // начало 3-байтного символа, например, € (E2 82 AC)
    assert_int_equal(utf8_char_len(c), 3);
}


static void test_is_utf8_letter_start_ascii(void **state) {
    assert_true(is_utf8_letter_start('A'));
    assert_true(is_utf8_letter_start('z'));
    assert_false(is_utf8_letter_start(' '));
}

static void test_is_utf8_letter_start_utf8(void **state) {
    assert_true(is_utf8_letter_start(0xD0)); // кириллица
}


static void test_process_line_simple(void **state) {
    DictionaryEntry dict[] = {
        {"привет", "你好"},
        {"мир", "世界"}
    };
    char input[] = "привет мир!\n";
    char output[256] = {0};

    FILE* out = fmemopen(output, sizeof(output), "w");
    process_line(input, out, dict, 2);
    fclose(out);

    assert_string_equal(output, "你好 世界!\n");
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_find_translation_known),
        cmocka_unit_test(test_find_translation_unknown),
        cmocka_unit_test(test_utf8_char_len_ascii),
        cmocka_unit_test(test_utf8_char_len_two_byte),
        cmocka_unit_test(test_utf8_char_len_three_byte),
        cmocka_unit_test(test_is_utf8_letter_start_ascii),
        cmocka_unit_test(test_is_utf8_letter_start_utf8),
        cmocka_unit_test(test_process_line_simple),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
