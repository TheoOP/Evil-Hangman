#
HANGMAN RULES
One player thinks of a word or phrase; the others try to guess what it is one letter at a time. The player draws a number of dashes equivalent to the number of letters in the word. If a guessing player suggests a letter that occurs in the word, the other player fills in the blanks with that letter in the right places. If the word does not contain the suggested letter, the other player draws one element of a hangman’s gallows. As the game progresses, a segment of the gallows and of a victim is added for every suggested letter not in the word. The number of incorrect guesses before the game ends is up to the players, but completing a character in a noose provides a minimum of six wrong answers until the game ends. The first player to guess the correct answer thinks of the word for the next game.

This game breaks the original mold by making it so the computer is virtually unbeatable. 
The program does the following:

Reads the file dictionary.txt, which contains the full contents of the Official Scrabble Player’s Dictionary, Second Edition. This word list has over 120,000 words, which should be more than enough for our purposes.

Prompt the user for a word length, reprompting as necessary until she enters a number such that there’s at least one word that’s exactly that long. That is, if the user wants to play with words of length -42 or 137, since no English words are that long, you should reprompt her.

Prompt the user for a number of guesses, which must be an integer greater than zero. Don’t worry about unusually large numbers of guesses – after all, having more than 26 guesses is clearly not going to help your opponent!

Prompt the user for whether she wants to have a running total of the number of words remaining in the word list. This completely ruins the illusion of a fair game that you’ll be cultivating, but it’s quite useful for testing (and grading!)

Play a game of Hangman using the Evil Hangman algorithm, as described below:

Construct a list of all words in the English language whose length matches the input length.

Print out how many guesses the user has remaining, along with any letters the player has guessed and the current blanked-out version of the word. If the user chose earlier to see the number of words remaining, print that out too.

Prompt the user for a single letter guess, reprompting until the user enters a letter that she hasn’t guessed yet. Make sure that the input is exactly one character long and that it’s a letter of the alphabet.

Partition the words in the dictionary into groups by word family.

Find the most common “word family” in the remaining words, remove all words from the word list that aren’t in that family, and report the position of the letters (if any) to the user. If the word family doesn’t contain any copies of the letter, subtract a remaining guess from the user.

If the player has run out of guesses, pick a word from the word list and display it as the word that the computer initially “chose.”

If the player correctly guesses the word, congratulate her.

Ask if the user wants to play again and loop accordingly.
