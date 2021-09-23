//#include <stdio.h>
//#include <stdlib.h>
//#include "unit_test.h"
//#include "my_string.h"
//int main(int argc, char* argv[])
//{
//	Status(*tests[])(char*, int) =
//	{
//	test_topokuaf_init_default_returns_nonNULL, //test 1
//	test_topokuaf_get_size_on_init_default_returns_0, //test 2
//	test_topokuaf_get_capacity_on_init_default, //test 3
//
//	test_topokuaf_get_size_on_push_back_returns_1, //test 4
//	test_topokuaf_get_size_on_push_back_realloc_returns_8, //test 5
//	test_topokuaf_get_capacity_on_push_back_realloc_returns_14, //test 6
//
//	test_topokuaf_my_string_pop_back_returns_fail_when_empty, //test 7
//	test_topokuaf_my_string_pop_back_returns_success_when_non_empty, //test 8
//
//	test_topokuaf_my_string_empty_returns_true_on_init_default, //test 9
//	test_topokuaf_my_string_empty_returns_fail_with_one_item,//test 10
//
//	test_topokuaf_my_string_at_returns_correct_first_item, //test 11
//	test_topokuaf_my_string_at_returns_correct_last_item, //test 12
//	test_topokuaf_my_string_at_returns_correct_arbitrary_item, //test 13
//
//	test_topokuaf_my_string_c_str_returns_short_string_with_null_character, //test 14
//	test_topokuaf_my_string_c_str_returns_long_string_with_null_character, //test 15
//
//	test_topokuaf_my_string_concat_returns_result_string_with_correct_size, //test 16
//	test_topokuaf_my_string_concat_returns_append_string_unchanged, //test 17
//	test_topokuaf_my_string_concat_returns_failure_when_result_string_is_NULL, //test 18
//	test_topokuaf_my_string_concat_returns_result_unchanged_when_append_empty, //test 19
//
//	test_topokuaf_my_string_compare_successfully_compares_equal_lexicographic_strings, //test 20
//	test_topokuaf_my_string_compare_successfully_compares_different_lexicographic_strings, //test 21
//	test_topokuaf_my_string_compare_successfully_compares_empty_and_full_lexicographic_strings, //test 22
//
//	test_topokuaf_my_string_extraction_returns_failure_when_file_is_empty, //test 23
//	test_topokuaf_my_string_insertion_returns_failure_when_string_is_NULL, //test 24
//	test_topokuaf_my_string_destroy_destroys_string_and_sets_to_NULL, //test 25
//	test_create_100_elements //test 26
//	};
//	int number_of_functions = sizeof(tests) / sizeof(tests[0]);
//	int i;
//	char buffer[500];
//	int success_count = 0;
//	int failure_count = 0;
//	for (i = 0; i < number_of_functions; i++)
//	{
//		if (tests[i](buffer, 500) == FAILURE)
//		{
//			printf("FAILED: Test %d failed miserably\n", i + 1);
//			printf("\t%s\n", buffer);
//			failure_count++;
//		}
//		else
//		{
//			// printf("PASS: Test %d passed\n", i);
//			// printf("\t%s\n", buffer);
//			success_count++;
//		}
//	}
//	printf("Total number of tests: %d\n", number_of_functions);
//	printf("%d/%d Pass, %d/%d Failure\n", success_count,
//		number_of_functions, failure_count, number_of_functions);
//	return 0;
//}