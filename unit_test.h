#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "status.h"
Status test_topokuaf_init_default_returns_nonNULL(char* buffer, int length);
Status test_topokuaf_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_topokuaf_get_capacity_on_init_default(char* buffer, int length);

Status test_topokuaf_get_size_on_push_back_returns_1(char* buffer, int length);
Status test_topokuaf_get_size_on_push_back_realloc_returns_8(char* buffer, int length);
Status test_topokuaf_get_capacity_on_push_back_realloc_returns_14(char* buffer, int length);

Status test_topokuaf_my_string_pop_back_returns_fail_when_empty(char* buffer, int length);
Status test_topokuaf_my_string_pop_back_returns_success_when_non_empty(char* buffer, int length);

Status test_topokuaf_my_string_empty_returns_true_on_init_default(char* buffer, int length);
Status test_topokuaf_my_string_empty_returns_fail_with_one_item(char* buffer, int length);

Status test_topokuaf_my_string_at_returns_correct_first_item(char* buffer, int length);
Status test_topokuaf_my_string_at_returns_correct_last_item(char* buffer, int length);
Status test_topokuaf_my_string_at_returns_correct_arbitrary_item(char* buffer, int length);

Status test_topokuaf_my_string_c_str_returns_short_string_with_null_character(char* buffer, int length);
Status test_topokuaf_my_string_c_str_returns_long_string_with_null_character(char* buffer, int length);

Status test_topokuaf_my_string_concat_returns_result_string_with_correct_size(char* buffer, int length);
Status test_topokuaf_my_string_concat_returns_append_string_unchanged(char* buffer, int length);
Status test_topokuaf_my_string_concat_returns_failure_when_result_string_is_NULL(char* buffer, int length);
Status test_topokuaf_my_string_concat_returns_result_unchanged_when_append_empty(char* buffer, int length);

Status test_topokuaf_my_string_compare_successfully_compares_equal_lexicographic_strings(char* buffer, int length);
Status test_topokuaf_my_string_compare_successfully_compares_different_lexicographic_strings(char* buffer, int length);
Status test_topokuaf_my_string_compare_successfully_compares_empty_and_full_lexicographic_strings(char* buffer, int length);

Status test_topokuaf_my_string_extraction_returns_failure_when_file_is_empty(char* buffer, int length);
Status test_topokuaf_my_string_insertion_returns_failure_when_string_is_NULL(char* buffer, int length);
Status test_topokuaf_my_string_destroy_destroys_string_and_sets_to_NULL(char* buffer, int length);
Status test_create_100_elements(char* buffer, int length);
#endif
