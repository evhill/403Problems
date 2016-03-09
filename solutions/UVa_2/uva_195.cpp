/* UVa problem: 195 - Anagram
 * Topic: Combinatorics
 * Brief problem description:
 * 		Given a string, print out all the different permutations.
 * Solution Summary:
 * 	  Anagram problem with constraints that uppercase letters come before their
 * 	  lowercase counterparts, but not before other lower case letters (A before a, but
 * 	  not B before a). The hint from the book really helped with using next_permutation
 * 	  and then it was just a matter of defining how I wanted the ordering. For this problem
 * 	  I switched everything to uppercase and then just found the smallest char and returned
 * 	  that.
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct compareLexo {
	bool operator()(const char& a, const char& b) {
		//Same letter differentiated by case
		if (toupper(a) == toupper(b))
			return a < b;

		//make them all the same case and then return which is smaller
		return toupper(a) < toupper(b);
	}
};

int main() {
	int cases;
	cin >> cases;
	string word;
	while (cases--) {
		cin >> word;

		//need to sort for lexographical order since next_permutation will miss
		//permutations if they are not sorted
		sort(word.begin(), word.end(), compareLexo());

		do { //do{} because next_permutation will miss the first word if not
			cout << word << endl;
		} while (next_permutation(word.begin(), word.end(), compareLexo()));
	}
	return 0;
}
