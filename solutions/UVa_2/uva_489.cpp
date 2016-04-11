/* UVa problem: 489 - Hangman Judge
 * Topic: Strings
 * Brief problem description:
 *    Given a word WORD and a series of characters, see if you win a
 *    game of hangman. A game is won if your guess characters
 *    successfully find all of the letters in X before you reach
 *    7 strokes.
 * Solution Summary:
 *   Pretty simple find and delete character problem. For every character
 *   in the guess, search through the WORD and delete any characters that
 *   match. If WORD becomes empty before your guesses are over, and you've
 *   made less than 7 guesses, you win. Keep track of duplicate guesses, as
 *   they don't count towards your stroke total.
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <iterator>
#include <string>
#include <sstream>

using namespace std;


int main() {
	int cases, Glength, tries;
	map<char, int> hanged;
	bool isEmpty;

	while (cin >> cases && cases != -1) {
		string word, guess;
		tries = 0;
		isEmpty = false;
		cin >> word >> guess;
		Glength = guess.length();

		//Sets the visited status of each letter of the guess to false until we use it
		//keeps duplicate guesses from being counted as tries
		for(int i = 0; i < Glength; i++)
			hanged[guess[i]] = false;

		for (int i = 0; i < Glength && !(word.empty()); i++) {
			//find and delete the letter
			if (find(word.begin(), word.end(), guess[i]) != word.end() && hanged[guess[i]] == false){
				word.erase(remove(word.begin(), word.end(), guess[i]), word.end());
				hanged[guess[i]] = true;

			}
			else if(hanged[guess[i]] == false)
				tries++;

			hanged[guess[i]] = true;
		}

		if (word.length() == 0)
			isEmpty = true;

		cout << "Round " << cases << endl;
		if (tries >= 7)
			cout << "You lose." << endl;
		else if (isEmpty == true)
			cout << "You win." << endl;
		else
			cout << "You chickened out." << endl;

	}

	return 0;
}
