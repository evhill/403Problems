/* UVa problem: 10930 - A Sequence
 * Topic: Dynamic Programming
 * Brief problem description:
 *  Given a sequence of numbers, determine if it is an A-sequence. An A-sequence
 *  is true if there are no duplicate numbers, all are in ascending order, and 
 *  no two or more numbers sum to equal another number. 
 *
 * Solution Summary:

 * The bool table is created by going through each element of a set and 
 * determining if it is capable of summing to a given number with the 
 * previous elements of the set. You do this by taking the truth value of
 * an above cell in the table. If it is false, and your number is less than
 * or equal to the sum you're trying to find, then you subtract the 
 * set element from the sum and check the truth value of that new cell. 
 * If it is true, you have a subset sum. 
 *
 * EX) If sum = 6, and set = {2,3,6,7} then this is an A sequence since we 
 * only have a T in the 6 sum column when we are looking at the 6th element. 
 * Same with 7. But if we have a set of {2,3,6,7,10} then:
 *
 *				bool array[set][sum] or [i][j]
 *  	 ________________sum____________________________
 *		 |_|_0_|_1_|_2_|_3_|_4_|_5_|_6_|_7_|_8_|_9_|_10_|
 *		 |0| T   F   F   F   F   F   F   F   F   F   F
 *	set	 |2| T   F   T   F   F   F   F   F   F   F   F
 *element|3| T   F   T   T   F   T   F   F   F   F   F
 * 		 |6| T   F   T   T*  F   T   T   F   F   F   F*
 * 		 |7| T   F   T   T   F   T   T   T   F   T   T <-! ^^ check value above. 
 * 		 |10|T   F   T   T   F   T   T   T   F   T   T        10-7 = 3
 *															  Cell for 3 is True
 *
 * 	For 10, when we are looking at the 7th element and trying to find
 * 	if there is a sum of 10, we subtract 7 from 10 and see the truth value
 * 	in that cell. In this case it is 3 which has a truth value of T and
 * 	therefore we can make a sum of a subset.
 */
#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

bool check(int set[], int sum, int size) {
	bool sequence[size + 1][sum + 1];

	for (int i = 0; i <= size; i++) {
		sequence[i][0] = true;
	}
	// sum not 0 but empty set. Going across first row
	for (int i = 1; i <= sum; i++) {
		sequence[0][i] = false;
	}

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= sum; j++) {
			//look at the above row for the bool value
			sequence[i][j] = sequence[i - 1][j];
			if (sequence[i][j] == false && j >= set[i - 1]) {
				//Takes the value of a cell we subtract from or remains the same as the above
				sequence[i][j] = sequence[i - 1][j - set[i - 1]] || sequence[i][j];

			}
		}

	}

	//false == no sum == a sequence
	return sequence[size][sum];

}

int main() {
	int x = 1, cases = 0, num = 0, last = 0;
	while (cin >> cases) {
		bool badSequence = false;
		int chain[cases], k = 0;
		last = 0;
		cout << "Case #" << x << ":";
		for (int i = 0; i < cases; i++) {
			cin >> num;
			cout << " " << num;
			chain[k] = num;
			if (num <= last)
				badSequence = true;
			if (num == 0)
				badSequence = true;
			last = num;
			k++;
		}
		cout << endl;

		if (badSequence == false) {
			for (int i = 0; i < cases; i++) {
				badSequence |= check(chain, chain[i], i);
			}
		}

		if (badSequence == false)
			cout << "This is an A-sequence." << endl;
		else
			cout << "This is not an A-sequence." << endl;
		x++;
	}
	return 0;
}
