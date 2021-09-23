#include <stdio.h>
#include <stdlib.h>

//#include "unit_test.h"
#include "status.h"
#include "my_string.h"

struct my_string {
	int size;
	int capacity;
	char* data;
};
typedef struct my_string My_string;

MY_STRING my_string_init_default(void)
{
	//char *input_string;
	int cursize = 0;
	My_string* pMy_string = NULL;
	pMy_string = (My_string*)malloc(sizeof(My_string));
	if (pMy_string != NULL) {
		pMy_string->size = cursize;
		pMy_string->capacity = 7;
		pMy_string->data = malloc(sizeof(char) * pMy_string->capacity);

		//printf("Enter a string under 7 characters:\n");
		//scanf("%s.", pMy_string->data);

		return pMy_string;
	}
	free(pMy_string);
	pMy_string = NULL;
	return NULL;
}

int my_string_get_size(MY_STRING hMy_string) {
	My_string* pMy_string = (My_string*)hMy_string;
	if (pMy_string == NULL)
		return 0;
	int size = pMy_string->size;
	return size;
}


int my_string_get_capacity(MY_STRING hMy_string) {
	My_string* pMy_string = (My_string*)hMy_string;
	int capacity = pMy_string->capacity;
	return capacity;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {
	My_string* pLeft_string = (My_string*)hLeft_string;
	My_string* pRight_string = (My_string*)hRight_string;
	if (pLeft_string->size == 0 && pRight_string->size == 0)
		return 0;
	if (pLeft_string->size == 0)
		return -1;
	if (pRight_string->size == 0)
		return 1;

	int count = 0;
	while (pLeft_string->data[count] == pRight_string->data[count] && pLeft_string->size - 1 != count && pRight_string->size - 1 != count) {
		count++;
	}
	if (pLeft_string->data[count] < pRight_string->data[count])
	{
		return -1;
	}
	if (pLeft_string->data[count] > pRight_string->data[count])
	{
		return 1;
	}
	if (pLeft_string->data[count] == pRight_string->data[count])
	{
		return 0;
	}
	return -31337;
}

void my_string_destroy(Item* pItem) {
	My_string* pMy_string = (My_string*)*pItem;

	free(pMy_string->data);
	free(pMy_string);
	*pItem = NULL;
	return;
}
Status my_string_assignment(Item* pLeft, Item Right) {
	My_string* pRightstring = (My_string*)Right;
	int i;
	// if pLeft is uninitialized
	if (*pLeft == NULL) {
		My_string* pLeftstring = (My_string*)malloc(sizeof(My_string));

		if (pLeftstring == NULL)
			return FAILURE;
		*pLeft = pLeftstring;
		pLeftstring->size = pRightstring->size;
		pLeftstring->capacity = pRightstring->capacity;
		pLeftstring->data = malloc(sizeof(char) * pRightstring->capacity);
		for (i = 0; i < pLeftstring->size; i++) {
			pLeftstring->data[i] = pRightstring->data[i];
		}
		return SUCCESS;
	}
	//if pLeft is already but has wrong capacity so must resize
	My_string* pLeftstring = (My_string*)*pLeft;
	char* temp;
	if (pRightstring->size >= pLeftstring->capacity) {
		temp = (char*)malloc(sizeof(char) * pRightstring->capacity + 1);
		if (temp == NULL) {
			return FAILURE;
		}
		for (i = 0; i < pRightstring->size; i++) {
			temp[i] = pRightstring->data[i];
		}
		free(pLeftstring->data);
		pLeftstring->data = temp;
		pLeftstring->capacity = pRightstring->capacity + 1;
		return SUCCESS;
	}

	//if pLeft is made and has capacity large enough
	*pLeft = pLeftstring;
	pLeftstring->size = pRightstring->size;
	pLeftstring->capacity = pRightstring->capacity;
	for (i = 0; i < pLeftstring->size; i++) {
		pLeftstring->data[i] = pRightstring->data[i];
	}
	return SUCCESS;

}

MY_STRING my_string_init_c_string(const char* c_string) {
	int cursize = 0; int i = 0;
	while (c_string[i] != '\0') {
		cursize++; i++;
	}

	My_string* pMy_string = (My_string*)malloc(sizeof(My_string));

	if (pMy_string != NULL) {
		pMy_string->size = cursize;
		pMy_string->capacity = cursize + 1;
		pMy_string->data = malloc(sizeof(char) * pMy_string->capacity);
		for (i = 0; i < pMy_string->size; i++) {
			pMy_string->data[i] = c_string[i];
		}
	}
	return (MY_STRING)pMy_string;
}

//void g_vector_destroy(G_VECTOR* phG_Vector) {
//	G_Vector* pVector = (G_Vector*)*phG_Vector;
//	int i;
//	for (i = 0; i < pVector->capacity; ++i) {
//		if (pVector->data[i] != NULL)
//			pVector->item_destroy(&pVector->data[i]);
//	}
//	free(pVector->data);
//	free(pVector);
//	*phG_Vector = NULL;
//}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp) {
	int noc = 0; int i = 0; int j; char ch;

	My_string* pMy_string = hMy_string;

	pMy_string->size = 0;
	
	noc = fscanf(fp, " %c", &ch);
	i = 0;
	while (noc != EOF && !(ch == '\t' || ch == '\n' || ch == ' '))
	{
		char* temp;
		if (pMy_string->size >= pMy_string->capacity)
		{
			temp = malloc(sizeof(char) * pMy_string->capacity * 2);
			if (temp == NULL) {
				return FAILURE;
			}
			for (j = 0; j < pMy_string->size; j++) {
				temp[j] = pMy_string->data[j];
			}
			free(pMy_string->data);
			pMy_string->data = temp;
			pMy_string->capacity *= 2;
		}
		pMy_string->data[i] = ch;
		noc = fscanf(fp, "%c", &ch);
		pMy_string->size++;
		i++;

	}
	if (i == 0)
		return FAILURE;
	if (noc != EOF)
	{
		ungetc(ch, fp);
	}
	return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp) {
	int i;
	My_string* pMy_string = hMy_string;
	if (pMy_string == NULL)
		return FAILURE;
	for (i = 0; i < pMy_string->size; i++) {
		fprintf(fp, "%c", pMy_string->data[i]);

	}
	return SUCCESS;
}


Status my_string_push_back(MY_STRING hMy_string, char item) {
	My_string* pMy_string = (My_string*)hMy_string;
	char* temp;
	int i;
	if (pMy_string->size >= pMy_string->capacity) {
		temp = (char*)malloc(sizeof(char) * pMy_string->capacity * 2);
		if (temp == NULL) {
			return FAILURE;
		}
		for (i = 0; i < pMy_string->size; i++) {
			temp[i] = pMy_string->data[i];
		}
		free(pMy_string->data);
		pMy_string->data = temp;
		pMy_string->capacity *= 2;
	}
	pMy_string->data[pMy_string->size] = item;
	pMy_string->size++;
	return SUCCESS;
	//Precondition: hMy_string is the handle to a valid My_string object.
	//Postcondition: If successful, places the character item at the end of the
	// string and returns SUCCESS. If the string does not have enough room and
	// cannot resize to accomodate the new character then the operation fails
	// and FAILURE is returned. The resize operation will attempt to amortize
	// the cost of a resize by making the string capacity somewhat larger than
	// it was before (up to 2 times bigger).

}
Status my_string_pop_back(MY_STRING hMy_string) {
	My_string* pMy_string = (My_string*)hMy_string;
	if (pMy_string->size <= 0) {
		return FAILURE;
	}
	pMy_string->size--;
	return SUCCESS;
	//Precondition: hMy_string is the handle to a valid My_string object.
	//Postcondition: Removes the last character of a string in constant time.
	// Guaranteed to not cause a resize operation of the internal data. Returns
	// SUCCESS on success and FAILURE if the string is empty.
}
char* my_string_at(MY_STRING hMy_string, int index) {
	My_string* pMy_string = (My_string*)hMy_string;
	if (index < 0 || index >= pMy_string->capacity) {
		return NULL;
	}
	return &pMy_string->data[index];
	//Precondition: hMy_string is the handle to a valid My_string object.
	//Postcondition: Returns the address of the character located at the given
	// index if the index is in bounds but otherwise returns NULL. This address
	// is not usable as a c-string since the data is not NULL terminated and is
	// intended to just provide access to the element at that index.
}
char* my_string_c_str(MY_STRING hMy_string) {
	My_string* pMy_string = (My_string*)hMy_string;
	char* temp;
	int i;
	if (pMy_string->size >= pMy_string->capacity) {
		pMy_string->capacity += 1;
		temp = (char*)malloc(sizeof(char) * pMy_string->capacity);
		if (temp == NULL) {
			return FAILURE;
		}
		for (i = 0; i < pMy_string->size; i++) {
			temp[i] = pMy_string->data[i];
		}
		free(pMy_string->data);
		pMy_string->data = temp;

	}
	pMy_string->data[pMy_string->size] = '\0';
	return &pMy_string->data[0];
	//Precondition: hMy_string is the handle to a valid My_string object.
	//Postcondition: Returns the address of the first element of the string object
	// for use as a c-string. The resulting c-string is guaranteed to be NULL
	// terminated and the memory is still maintained by the string object though
	// the NULL is not actually counted as part of the string (in size).
}
Status my_string_concat(MY_STRING hResult, MY_STRING hAppend) {
	My_string* pResult_string = (My_string*)hResult;
	My_string* pAppend_string = (My_string*)hAppend;
	char* orig_string; char* temp;
	int i; int j;
	if (pResult_string == NULL)
		return FAILURE;
	orig_string = (char*)malloc(sizeof(char) * pResult_string->capacity);
	if (orig_string == NULL) {
		return FAILURE;
	}
	for (i = 0; i < pResult_string->size; i++) {
		orig_string[i] = pResult_string->data[i];
	}
	//saves original string data in case of failure

	for (i = 0; i < pAppend_string->size; i++) {
		if (pResult_string->size >= pResult_string->capacity) {
			temp = (char*)malloc(sizeof(char) * pResult_string->capacity * 2);
			if (temp == NULL) {
				//if resize fails then original string data is restored
				for (j = 0; i < pResult_string->size; j++) {
					pResult_string->data = orig_string;
				}
				return FAILURE;
			}
			for (j = 0; j < pResult_string->size; j++) {
				temp[j] = pResult_string->data[j];
			}
			free(pResult_string->data);
			pResult_string->data = temp;
			pResult_string->capacity *= 2;
		}
		pResult_string->data[pResult_string->size] = pAppend_string->data[i];
		pResult_string->size++;


	}
	free(orig_string);
	return SUCCESS;
	//Precondition: hResult and hAppend are handles to valid My_string objects.
	//Postcondition: hResult is the handle of a string that contains the original
	// hResult object followed by the hAppend object concatenated together. This
	// function should guarantee no change to the hAppend object and return
	// SUCCESS if they operation is successful and FAILURE if the hResult object
	// is unable to accomodate the characters in the hAppend string perhaps
	// because of a failed resize operation. On FAILURE, no change to either
	// string should be made.
}
Boolean my_string_empty(MY_STRING hMy_string) {
	My_string* pMy_string = (My_string*)hMy_string;
	if (pMy_string->size == 0) {
		return TRUE;
	}
	else
		return FALSE;
	//Precondition: hMy_string is the handle to a valid My_string object.
	//Postcondition: Returns an enumerated type with value TRUE if the string
	// is empty and FALSE otherwise.

}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess) {
//Precondition:current_word_family, new_key and word are all handles to valid
// MY_STRING opaque objects. guess is an alphabetical character that can be either
// upper or lower case.
	My_string* pcurrent_word_family = (My_string*)current_word_family;
	if (pcurrent_word_family == NULL)
		return FAILURE;
	My_string* pnew_key = (My_string*)new_key;
	if (pnew_key == NULL)
		return FAILURE;
	int i;
	//new key = currrent word family aka the old key
	my_string_assignment(&pnew_key, pcurrent_word_family);
	char* x; char* y;
	guess = tolower(guess);
	MY_STRING pword = (My_string*)word;

	//MY_STRING guessedChar = my_string_init_c_string(cGuess);
	MY_STRING guessedChar = my_string_init_default();

	my_string_push_back(guessedChar, guess);
	//printf("%c\n", *my_string_at(guessedChar, 0));
	//printf("%c\n", guess);

	
	for (i = 0; i < my_string_get_size(pword); i++) {
		x = my_string_at(guessedChar, 0);
		y = my_string_at(pword, i);
		if (x[0] == y[0]) {
			pnew_key->data[i] = guess;

		}

	}
	return SUCCESS;



//Postcondition: Returns SUCCESS after replacing the string in new_key with the key
// value formed by considering the current word family, the word and the guess.
// Returns failure in the case of a resizing problem with the new_key string.

}