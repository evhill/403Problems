/* UVa problem: 11584 - Partitioning by Palindromes
 * Topic: Dynamic Programming
 * Brief problem description:
 *    Given a string, partition it in such a way that each substring
 *    is a palindrome.
 *
 * Solution Summary:
 *	  Precompute the substrings that are palindromes with a bool table.
 *	  Start with a length of 2, and then check if any two adjacent
 *	  characters are equal (ie these will be palindromes). Continue this
 *	  method for every length of substring until you reach the max length
 *	  of the string. This will give you a lookup table for any given string.
 *	  It will look something like this. 
 *
 *
 *	  		c  a  a  a  t
 *	  		0  1  2  3  4
 *	  	  0 T  F' F* F  F 			Length 2 check from 0-1, 1-2, 2-3....
 *	  	  1	   T  T! T^ F			' 0-1 = C and A meaning they are not pal
 *	  	  2       T	 T	F:			! 1-2 = A and A
 *	  	  3          T  F			....
 *	  	  4	            T			* 0-1-2 is C A A which is false
 *	  	  							^ 1-2-3 is A A A which is true
 *	  	  							: 2-3-4 is A A T which is false
 *
 *	 Once we have a lookup table, we need to find the partitions. Take
 *	 the minimum between palindrome comparisons + 1. For example, in row 0, 
 *	 we have one T and 4 F, 0 is the minimum, but we need to add one for the
 *	 cut so 1 and etc
 */
#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;
string word;
int length;

int main() {
	int cases;
	cin >> cases;

	while (cases--) {
		int i, j;

		cin >> word;
		length = word.length();

		bool ispalin[length][length];
		int numPartitions[length];

		for (i = 0; i < length; i++) {
			for (j = 0; j < length; j++) {
				ispalin[i][j] = true;
				numPartitions[i] = 10001;

			}
		}
		numPartitions[0] = 1;


		for (int a = 2; a <= length; a++) { //start with length of 2
			for (i = 0; i < length - a + 1; i++) { //only go up to a
				j = i + a - 1; //end index
				if (word[i] == word[j])
					ispalin[i][j] = ispalin[i + 1][j - 1];
				else
					ispalin[i][j] = false;
			}
		}

		for (i = 1; i < length; i++) {
			if (ispalin[0][i] == true)
				numPartitions[i] = 1;
			else
				for (j = 1; j <= i; j++) {
					if (ispalin[j][i] == true)
						numPartitions[i] = min(numPartitions[i], numPartitions[j - 1] + 1);
				}
		}
		cout << numPartitions[length - 1] << endl;
	}
	return 0;

}
