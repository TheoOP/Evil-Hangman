#include <stdio.h>
#include <stdlib.h>
#include "status.h"
//#include "unit_test.h"

#include "avl.h"



void clearKeyboardBuffer(void);
int user_wishes_to_continue(void);

int prompt_length(void);
int prompt_num_guesses(void);
char prompt_guess_for_word(MY_STRING myStringGuess);
int prompt_running_total(void);


int main(int argc, char* argv[]) {

	G_VECTOR vectorArray[30]; G_VECTOR masterWordList; G_VECTOR largestWordGroup;
	int i;	int wLength; int numGuess;  int myStringGuessIndex = 0; int runningTotal = 0;
	char currentLetter;
	FILE* fp;
	MY_STRING myStringGuess = my_string_init_default();
	MY_STRING tempString;
	HANG_TREE hTree = my_tree_init_default();
	if (hTree == NULL)
		exit(1);
	tempString = my_string_init_default();

	
	fp = fopen("dictionary.txt", "r");
	if (fp == NULL)
	{
		printf("Dictionary file failed to open correctly");
		exit(1);
	}

	// initializing array elements 
	for (i = 0; i < 30; i++) {
		vectorArray[i] = g_vector_init_default(my_string_assignment, my_string_destroy);
	}

	while (my_string_extraction(tempString, fp)) {

		g_vector_push_back(vectorArray[my_string_get_size(tempString)], tempString);
		my_string_destroy(&tempString);
		tempString = my_string_init_default();
	}

	//for (i = 0; i < 30; i++) {
	//	printf("The number of words with %d characters is %d\n", i, g_vector_get_size(vectorArray[i]));
	//}
	Boolean userHaswon = FALSE;

	//hTree->hVector = g_vector_init_default(my_string_assignment, my_string_destroy);
	MY_STRING currentWordFam = my_string_init_default();
	MY_STRING key = my_string_init_default();
	do {
		//GAME SETUP
		wLength = prompt_length();
		numGuess = prompt_num_guesses();
		masterWordList = g_vector_init_default(my_string_assignment, my_string_destroy);

		//create MASTERWORDLIST
		for (i = 0; i < g_vector_get_size(vectorArray[wLength]); i++) {
			g_vector_push_back(masterWordList, g_vector_at(vectorArray[wLength], i));
		}
		do {
			
			// hTree->hVector = vectorArray[wLength - 1];
			

			
			if (runningTotal == 0) {
				runningTotal = prompt_running_total();
				if (runningTotal == 0)
					runningTotal = -1;
				//running total will be displayed throughout the game
				//printf("The number of words remaining with %d characters is %d\n", wLength, g_vector_get_size(vectorArray[wLength]));
			}
			if (runningTotal == 1)
				printf("The number of words remaining with %d characters is %d\n", wLength, g_vector_get_size(vectorArray[wLength]));;
			printf("You have %d guesses remaining\n", numGuess);

			//create word family
			for (i = 0; i < wLength; i++) {
				my_string_push_back(currentWordFam, '-');
			}
			currentLetter = prompt_guess_for_word(myStringGuess); //ask user their guess

			for (i = 0; i < g_vector_get_size(masterWordList); i++) {
				
				get_word_key_value(currentWordFam, key, (MY_STRING)g_vector_at(masterWordList, i), currentLetter);
				insert_new_node(hTree, key, (MY_STRING)g_vector_at(masterWordList,i));
			}


			masterWordList = get_largest_word_vector(hTree);
			g_vector_destroy(&(vectorArray[wLength]));
			vectorArray[wLength] = g_vector_init_default(my_string_assignment, my_string_destroy);
			for (i = 0; i < g_vector_get_size(masterWordList); i++) {
				g_vector_push_back(vectorArray[wLength], g_vector_at(masterWordList, i));

			}
			
			get_word_key_value(currentWordFam, key, g_vector_at(masterWordList, i), currentLetter);
			if (my_string_compare(key, currentWordFam) == 0) {
				printf("The hidden word does not contain any %c's. Try again!\n\n", currentLetter);
				numGuess--;
			}
			my_string_assignment(&key, currentWordFam);
			my_string_destroy(&currentWordFam);
			g_vector_destroy(&masterWordList);
			currentWordFam = my_string_init_default();
			hTree = my_tree_init_default(my_string_assignment, my_string_destroy);
			myStringGuessIndex++;

		} while (!userHaswon && numGuess > 0);
	
		printf("You have run out of guesses. You lose!\n");
	} while (user_wishes_to_continue());

	for (i = 0; i < 30; i++) {
		g_vector_destroy(&vectorArray[i]);
	}
	fclose(fp);
	return 0;
}

int user_wishes_to_continue(void)
{
	char answer;
	printf("Do you wish to continue (y/n):");
	scanf(" %c", &answer);
	clearKeyboardBuffer();
	while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
	{
		printf("I'm sorry you must enter a 'y' or 'n'\n");
		printf("Do you wish to continue (y/n):");
		scanf("%c", &answer);
		clearKeyboardBuffer();
	}

	if (answer == 'y' || answer == 'Y')
	{
		return 1;
	}
	return 0;
}



void clearKeyboardBuffer(void)
{
	char ch;
	scanf("%c", &ch);
	while (ch != '\n' && ch != '\0') {
		scanf("%c", &ch);
	}
}




int prompt_length(void) {
	int wordLength;
	printf("Please enter the length of the word you would like to play with:\n");
	scanf("%d", &wordLength);
	clearKeyboardBuffer();
	while ((wordLength <= 2 || wordLength >= 30))
	{
		printf("I'm sorry, that length is too large or not positive.\n");
		printf("Please enter a length from 1 - 29\n");
		scanf("%d", &wordLength);
		clearKeyboardBuffer();
	}
	return wordLength;
}

int prompt_num_guesses(void) {
	int guesses;
	printf("Please enter the number of guesses of the word you would like to play with:\n");
	scanf("%d", &guesses);
	clearKeyboardBuffer();
	while (guesses <= 1)
	{
		printf("I'm sorry, that number of guesses is not positive.\n");
		printf("Please enter a length from 1- 29\n");
		scanf("%d", &guesses);
		clearKeyboardBuffer();
	}
	return guesses;
}

char prompt_guess_for_word(MY_STRING myStringGuess) {
	int j = 0; int x = 0; char temp; int valid = 1;
	printf("What do you think the hidden word is? Please enter a guess:\n");
	scanf("%c", &temp);
	clearKeyboardBuffer();
	while (!isalpha(temp))
	{
		printf("I'm sorry, that character is not a valid letter of the alphabet or you have already guessed that letter.\n");
		printf("Please enter a valid letter:\n");
		scanf("%c", &temp);
		clearKeyboardBuffer();
	}
	do {
			for (j; j < my_string_get_size(myStringGuess); j++) {
				if (temp == my_string_at(myStringGuess, j)) {
					valid = 0;
					printf("I'm sorry, that character is not a valid letter of the alphabet or you have already guessed that letter.\nPlease enter a valid letter: \n");
					scanf("%c", &temp);
					clearKeyboardBuffer(); 
					break;
				}
			}

	} while (valid == 0);
	my_string_push_back(myStringGuess, temp);
	return temp;
}

int prompt_running_total(void) {
	char runnningTotal;
	printf("Would you like a running total of the number of words remaining in the word list? Enter (Y/N).\n");
	scanf("%c", &runnningTotal);
	clearKeyboardBuffer();
	while (runnningTotal != 'y' && runnningTotal != 'Y' && runnningTotal != 'n' && runnningTotal != 'N')
	{

		printf("I'm sorry, that is not a (Y/N) character please enter a (Y/N)\n");
		scanf("%c", &runnningTotal);
		clearKeyboardBuffer();
	}

	if (runnningTotal == 'Y' || runnningTotal == 'y')
		return 1;
	if (runnningTotal == 'N' || runnningTotal == 'n')
		return 0;

	return 0;
}

