#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unit_test.h"
#include "my_string.h"

Status test_topokuaf_init_default_returns_nonNULL(char* buffer, int length)
{
	MY_STRING hString = NULL;
	hString = my_string_init_default();
	if (hString == NULL)
	{
		my_string_destroy(&hString);
		strncpy(buffer, "test_topokuaf_init_default_returns_nonNULL\n"
			"my_string_init_default returns NULL", length);
		return FAILURE;
	}
	else
	{
		my_string_destroy(&hString);
		strncpy(buffer, "\ttest_topokuaf_init_default_returns_nonNULL\n", length);
		return SUCCESS;
	}
}
Status test_topokuaf_get_size_on_init_default_returns_0(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
	if (my_string_get_size(hString) != 0)
	{
		status = FAILURE;
		printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_topokuaf_get_size_on_init_default_returns_0\n"
			"Did not receive 0 from get_size after init_default\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_get_size_on_init_default_returns_0\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_get_capacity_on_init_default(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
	if (my_string_get_capacity(hString) != 7)
	{
		status = FAILURE;
		printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_topokuaf_get_capacity_on_init_default_returns_7\n"
			"Did not receive 7 from get_capacity after init_default\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_get_capacity_on_init_default_returns_0\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_get_size_on_push_back_returns_1(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();
	my_string_push_back(hString, 'a');
	if (my_string_get_size(hString) != 1)
	{
		status = FAILURE;
		printf("Expected a size of 1 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_topokuaf_get_size_on_push_back_returns_1\n"
			"Did not receive correct 1 from get_size after push_back\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_get_size_on_push_back_returns_1\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_get_size_on_push_back_realloc_returns_8(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	int i;
	hString = my_string_init_default();
	for (i = 0; i < 8; i++)
		my_string_push_back(hString, 'h');


	if (my_string_get_size(hString) != 8)
	{
		status = FAILURE;
		printf("Expected a size of 8 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_topokuaf_get_size_on_push_back_realloc_returns_8\n"
			"Did not receive correct 8 from get_size after push_back\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_get_size_on_push_back_realloc_returns_8\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_get_capacity_on_push_back_realloc_returns_14(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	int i;
	hString = my_string_init_default();
	for (i = 0; i < 14; i++)
		my_string_push_back(hString, 'h');


	if (my_string_get_capacity(hString) != 14)
	{
		status = FAILURE;
		printf("Expected a capacity of 14 but got %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_topokuaf_get_capacity_on_push_back_realloc_returns_14\n"
			"Did not receive correct 14 from get_capacity after push_back\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_get_capacity_on_push_back_realloc_returns_14\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_my_string_pop_back_returns_fail_when_empty(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	//int i;
	hString = my_string_init_default();
	//string currently empty
	if (my_string_pop_back(hString) != FAILURE)
	{
		status = FAILURE;
		printf("Expected pop_back to fail(0) but got success(%d)\n", my_string_pop_back(hString));
		strncpy(buffer, "test_topokuaf_my_string_pop_back_returns_fail_when_empty\n"
			"Did not receive fail(0) from pop_back after checking empty struct\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_pop_back_returns_fail_when_empty\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}
Status test_topokuaf_my_string_pop_back_returns_success_when_non_empty(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	my_string_push_back(hString, 'h');
	my_string_push_back(hString, 'e');
	my_string_push_back(hString, 'l');
	my_string_push_back(hString, 'l');
	my_string_push_back(hString, 'o');
	if (my_string_pop_back(hString) == FAILURE)
	{
		status = FAILURE;
		printf("Expected pop_back to return success but got failure:(%d)\n", my_string_pop_back(hString));
		strncpy(buffer, "test_topokuaf_my_string_pop_back_returns_success_when_non_empty\n"
			"Did not receive success from pop_back after checking a non empty struct\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_pop_back_returns_success_when_non_empty\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}


Status test_topokuaf_my_string_empty_returns_true_on_init_default(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();
	//string currently empty
	if (!my_string_empty(hString))
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_empty_returns_true_on_init_default to return boolean True but got false(%d)\n", my_string_empty(hString));
		strncpy(buffer, "test_topokuaf_my_string_empty_returns_true_on_init_default\n"
			"Did not receive boolean true(1) from string_empty on init_default\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_empty_returns_true_on_init_default\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_my_string_at_returns_NULL_on_init_default(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();
	//string currently empty
	if (!my_string_empty(hString))
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_at_returns_NULL_on_init_default to return boolean True but got false(%d)\n", my_string_empty(hString));
		strncpy(buffer, "test_topokuaf_my_string_at_returns_NULL_on_init_default\n"
			"Did not receive boolean true(1) from string_empty on init_default\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_empty_returns_true_on_init_default\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}


Status test_topokuaf_my_string_empty_returns_fail_with_one_item(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();
	//string currently empty
	my_string_push_back(hString, 'h');
	if (my_string_empty(hString))
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_empty_returns_fail_with_one_item to return boolean false but got true(%d)\n", my_string_empty(hString));
		strncpy(buffer, "test_topokuaf_my_string_empty_returns_fail_with_one_item\n"
			"Did not receive boolean false(0) from string_empty on init_default\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_empty_returns_fail_with_one_item\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_my_string_at_returns_correct_first_item(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char* p;
	hString = my_string_init_default();

	my_string_push_back(hString, 'x');
	my_string_push_back(hString, 'y');
	my_string_push_back(hString, 'z');

	p = my_string_at(hString, 0);
	if (*p != 'x')
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_at_returns_correct_first_item to return address to first item 'x' but returned something else(%c)\n", *p);
		strncpy(buffer, "test_topokuaf_my_string_at_returns_correct_first_item\n"
			"Did not receive boolean correct address from my_string_at \n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_at_returns_correct_first_item\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_my_string_at_returns_correct_last_item(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char* p;
	hString = my_string_init_default();

	my_string_push_back(hString, 'x');
	my_string_push_back(hString, 'y');
	my_string_push_back(hString, 'z');

	p = my_string_at(hString, 2);
	if (*p != 'z')
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_at_returns_correct_last_item to return address to last item 'z' but returned something else(%c)\n", *p);
		strncpy(buffer, "test_topokuaf_my_string_at_returns_correct_last_item\n"
			"Did not receive boolean correct address from my_string_at \n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_at_returns_correct_last_item\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_my_string_at_returns_correct_arbitrary_item(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char* p;
	hString = my_string_init_default();

	my_string_push_back(hString, 'a');
	my_string_push_back(hString, 'b');
	my_string_push_back(hString, 'c');
	my_string_push_back(hString, 'c');
	my_string_push_back(hString, 'c');
	my_string_push_back(hString, 'c');
	my_string_push_back(hString, 'c');
	my_string_push_back(hString, 'd');
	my_string_push_back(hString, 'e');
	my_string_push_back(hString, 'f');
	my_string_push_back(hString, 'g');
	my_string_push_back(hString, 'h');



	p = my_string_at(hString, 8);
	if (*p != 'e')
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_at_returns_correct_arbitrary_item to return address to arbitrary item 'e' but returned something else(%c)\n", *p);
		strncpy(buffer, "test_topokuaf_my_string_at_returns_correct_arbitrary_item\n"
			"Did not receive boolean correct address from my_string_at \n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_at_returns_correct_arbitrary_item\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_my_string_c_str_returns_short_string_with_null_character(char* buffer, int length)
{

	MY_STRING hString = NULL;
	Status status;
	char* p;
	hString = my_string_init_default();

	my_string_push_back(hString, 'h');
	my_string_push_back(hString, 'i');

	p = my_string_c_str(hString);
	if (p[2] != '\0')
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_c_str_returns_short_string_with_null_character to return string hi with a null character at the end(%c)\n", *p);
		strncpy(buffer, "test_topokuaf_my_string_c_str_returns_short_string_with_null_character\n"
			"Did not return null character after string\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_c_str_returns_short_string_with_null_character\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_my_string_c_str_returns_long_string_with_null_character(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char* p;
	hString = my_string_init_default();

	my_string_push_back(hString, 'h');
	my_string_push_back(hString, 'i');
	my_string_push_back(hString, 'm');
	my_string_push_back(hString, 'y');
	my_string_push_back(hString, 'n');
	my_string_push_back(hString, 'a');
	my_string_push_back(hString, 'm');
	my_string_push_back(hString, 'e');
	my_string_push_back(hString, 'i');
	my_string_push_back(hString, 's');
	my_string_push_back(hString, 'v');
	my_string_push_back(hString, 'e');
	my_string_push_back(hString, 'r');
	my_string_push_back(hString, 'y');
	my_string_push_back(hString, 'l');
	my_string_push_back(hString, 'o');
	my_string_push_back(hString, 'n');
	my_string_push_back(hString, 'g');

	p = my_string_c_str(hString);
	if (p[18] != '\0')
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_c_str_returns_long_string_with_null_character to return string 'himynameisverylong' with a null character at the end(%c)\n", *p);
		strncpy(buffer, "test_topokuaf_my_string_c_str_returns_long_string_with_null_character\n"
			"Did not return null character after string\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_c_str_returns_long_string_with_null_character\n"
			, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_topokuaf_my_string_concat_returns_result_string_with_correct_size(char* buffer, int length)
{
	MY_STRING hString = NULL;
	MY_STRING hString2 = NULL;
	Status status;

	hString = my_string_init_default();
	hString2 = my_string_init_default();
	my_string_push_back(hString, 'h');
	my_string_push_back(hString, 'e');
	my_string_push_back(hString, 'l');
	my_string_push_back(hString, 'l');
	my_string_push_back(hString, 'o');

	my_string_push_back(hString2, ' ');
	my_string_push_back(hString2, 'w');
	my_string_push_back(hString2, 'o');
	my_string_push_back(hString2, 'r');
	my_string_push_back(hString2, 'l');
	my_string_push_back(hString2, 'd');

	my_string_concat(hString, hString2);

	my_string_get_size(hString);
	if (my_string_get_size(hString) != 11)
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_concat_returns_result_string_with_correct_size to return string 'hello world' which has size %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_topokuaf_my_string_concat_returns_result_string_with_correct_size\n"
			"Did not return resulting string with the correct size\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_concat_returns_result_string_with_correct_size\n"
			, length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	return status;
}

Status test_topokuaf_my_string_concat_returns_append_string_unchanged(char* buffer, int length)
{
	MY_STRING hString = NULL;
	MY_STRING hString2 = NULL;
	MY_STRING hStringtemp = NULL;
	Status status;

	hString = my_string_init_default();
	hString2 = my_string_init_default();
	hStringtemp = my_string_init_default();

	my_string_push_back(hString, 'h');
	my_string_push_back(hString, 'e');
	my_string_push_back(hString, 'l');
	my_string_push_back(hString, 'l');
	my_string_push_back(hString, 'o');

	my_string_push_back(hString2, ' ');
	my_string_push_back(hString2, 'w');
	my_string_push_back(hString2, 'o');
	my_string_push_back(hString2, 'r');
	my_string_push_back(hString2, 'l');
	my_string_push_back(hString2, 'd');

	my_string_push_back(hStringtemp, ' ');
	my_string_push_back(hStringtemp, 'w');
	my_string_push_back(hStringtemp, 'o');
	my_string_push_back(hStringtemp, 'r');
	my_string_push_back(hStringtemp, 'l');
	my_string_push_back(hStringtemp, 'd');

	my_string_concat(hString, hString2);

	//check to see if strings are the same
	if (strcmp(hString2, hStringtemp))
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_concat_returns_append_string_unchanged to return '0' showing that append string ' world' was unchanged but returned %d \n", my_string_get_size(hString));
		strncpy(buffer, "test_topokuaf_my_string_concat_returns_append_string_unchanged\n"
			"Did not return true(0) therefore string was changed\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_concat_returns_append_string_unchanged\n"
			, length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	my_string_destroy(&hStringtemp);
	return status;
}

Status test_topokuaf_my_string_concat_returns_failure_when_result_string_is_NULL(char* buffer, int length)
{
	MY_STRING hString = NULL;
	MY_STRING hString2 = NULL;

	Status status;

	hString2 = my_string_init_default();

	my_string_push_back(hString2, 'h');
	my_string_push_back(hString2, 'e');
	my_string_push_back(hString2, 'l');
	my_string_push_back(hString2, 'l');
	my_string_push_back(hString2, 'o');

	if (my_string_concat(hString, hString2))
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_concat_returns_failure_when_result_string_is_NULL to return failure since result string was NULL\n");
		strncpy(buffer, "test_topokuaf_my_string_concat_returns_failure_when_result_string_is_NULL\n"
			"Did not return failure for null result string\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_concat_returns_failure_when_result_string_is_NULL\n"
			, length);
	}
	my_string_destroy(&hString2);
	return status;
}

Status test_topokuaf_my_string_concat_returns_result_unchanged_when_append_empty(char* buffer, int length)
{
	MY_STRING hString = NULL;
	MY_STRING hString2 = NULL;
	MY_STRING hStringtemp = NULL;

	Status status;

	hString = my_string_init_default();
	hString2 = my_string_init_default();
	hStringtemp = my_string_init_default();

	my_string_push_back(hString, 'h');
	my_string_push_back(hString, 'e');
	my_string_push_back(hString, 'l');
	my_string_push_back(hString, 'l');
	my_string_push_back(hString, 'o');
	my_string_concat(hString, hString2);


	if (strcmp(hString2, hStringtemp))
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_concat_returns_result_unchanged_when_append_empty to return unchanged result string since append string was empty\n");
		strncpy(buffer, "test_topokuaf_my_string_concat_returns_result_unchanged_when_append_empty\n"
			"Did not return unchanged string for result string\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_concat_returns_result_unchanged_when_append_empty\n"
			, length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	my_string_destroy(&hStringtemp);
	return status;
}

Status test_topokuaf_my_string_compare_successfully_compares_equal_lexicographic_strings(char* buffer, int length)
{
	MY_STRING hString = NULL;
	MY_STRING hString2 = NULL;
	Status status;

	hString = my_string_init_default();
	hString2 = my_string_init_default();

	my_string_push_back(hString, 'h');
	my_string_push_back(hString, 'i');

	my_string_push_back(hString2, 'h');
	my_string_push_back(hString2, 'i');

	if (my_string_compare(hString, hString2))
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_compare_successfully_compares_equal_lexicographic_strings to return string 0 since hi and hi are equal lexicographically \n");
		strncpy(buffer, "test_topokuaf_my_string_compare_successfully_compares_equal_lexicographic_strings\n"
			"Did not return correct number after string comparison\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_compare_successfully_compares_equal_lexicographic_strings\n"
			, length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	return status;
}

Status test_topokuaf_my_string_compare_successfully_compares_different_lexicographic_strings(char* buffer, int length)
{
	MY_STRING hString = NULL;
	MY_STRING hString2 = NULL;
	Status status;

	hString = my_string_init_default();
	hString2 = my_string_init_default();

	my_string_push_back(hString, 'w');
	my_string_push_back(hString, 'h');
	my_string_push_back(hString, 'o');

	my_string_push_back(hString2, 'w');
	my_string_push_back(hString2, 'h');
	my_string_push_back(hString2, 'a');
	my_string_push_back(hString2, 't');

	if (my_string_compare(hString, hString2) != 1)
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_compare_successfully_compares_different_lexicographic_strings to return string 1 since 'who' is greater than 'what' lexicographically\n");
		strncpy(buffer, "test_topokuaf_my_string_compare_successfully_compares_different_lexicographic_strings\n"
			"Did not return correct number after string comparison\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_compare_successfully_compares_different_lexicographic_strings\n"
			, length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	return status;
}

Status test_topokuaf_my_string_compare_successfully_compares_empty_and_full_lexicographic_strings(char* buffer, int length)
{
	MY_STRING hString = NULL;
	MY_STRING hString2 = NULL;
	Status status;

	hString = my_string_init_default();
	hString2 = my_string_init_default();

	my_string_push_back(hString2, 'w');
	my_string_push_back(hString2, 'h');
	my_string_push_back(hString2, 'a');
	my_string_push_back(hString2, 't');
	my_string_push_back(hString2, 'u');
	my_string_push_back(hString2, 'p');
	my_string_push_back(hString2, 'p');

	if (my_string_compare(hString, hString2) != -1)
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_compare_successfully_compares_empty_and_full_lexicographic_strings to return string -1 since no characters is less than any character lexicographically\n");
		strncpy(buffer, "test_topokuaf_my_string_compare_successfully_compares_empty_and_full_lexicographic_strings\n"
			"Did not return correct number after string comparison\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_compare_successfully_compares_empty_and_full_lexicographic_strings\n"
			, length);
	}
	my_string_destroy(&hString);
	my_string_destroy(&hString2);
	return status;
}



Status test_topokuaf_my_string_extraction_returns_failure_when_file_is_empty(char* buffer, int length)
{
	MY_STRING hString = NULL;

	Status status;
	hString = my_string_init_default();

	FILE* tmp;
	tmp = tmpfile();

	my_string_push_back(hString, 'h');

	if (my_string_extraction(hString, tmp) != FAILURE)
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_extraction_returns_failure_when_file_is_empty to return failure since file was empty\n");
		strncpy(buffer, "test_topokuaf_my_string_extraction_returns_failure_when_file_is_empty\n"
			"Did not return failure number when string was empty\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_extraction_returns_failure_when_file_is_empty\n"
			, length);
	}
	my_string_destroy(&hString);
	fclose(tmp);
	free(tmp);
	tmp = NULL;
	return status;
}

Status test_topokuaf_my_string_insertion_returns_failure_when_string_is_NULL(char* buffer, int length)
{
	MY_STRING hString = NULL;

	Status status;



	if (my_string_insertion(hString, stdout) != FAILURE)
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_insertion_returns_failure_when_string_is_NULL to return failure since string was NULL\n");
		strncpy(buffer, "test_topokuaf_my_string_insertion_returns_failure_when_string_is_NULL\n"
			"Did not return failure number when string was NULL\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_insertion_returns_failure_when_string_is_NULL\n"
			, length);
	}
	//my_string_destroy(&hString);

	return status;
}

Status test_topokuaf_my_string_destroy_destroys_string_and_sets_to_NULL(char* buffer, int length)
{
	MY_STRING hString = NULL;
	hString = my_string_init_default();
	Status status;

	my_string_destroy(&hString);

	if (hString != NULL)
	{
		status = FAILURE;
		printf("Expected test_topokuaf_my_string_destroy_destroys_string_and_sets_to_NULL to return string to NULL\n");
		strncpy(buffer, "test_topokuaf_my_string_destroy_destroys_string_and_sets_to_NULL\n"
			"Did not return string to NULL\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_topokuaf_my_string_destroy_destroys_string_and_sets_to_NULL\n"
			, length);
	}

	return status;
}



Status test_create_100_elements(char* buffer, int length)
{
	int i;
	MY_STRING hMy_string = NULL;
	MY_STRING aMy_string[100];
	// initializing array elements 
	for (i = 1; i < 100; i++) {
		aMy_string[i] = NULL;
	}
	aMy_string[0] = my_string_init_default();
	printf("Size is %d\tCapacity is %d\t1st char in string is %c\t\n", my_string_get_size(aMy_string[0]), my_string_get_capacity(aMy_string[0]), *my_string_at(aMy_string[0], 0));
	my_string_pop_back(aMy_string[0]);

	my_string_destroy(&aMy_string);

	return SUCCESS;
}