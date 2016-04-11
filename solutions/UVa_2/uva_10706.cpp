/* UVa problem: 10706 - Number Sequence
 * Topic: Binary Search
 * Brief problem description:
 *   Given a sequence of numbers in the form (112123123412345....), find
 *   the digit in the ith position.  
 * Solution Summary:
 * 	 Precalculate a string to hold all the numbers from 1-32000. (1234567...). 
 * 	 
 * 	 For each sequence we see that the total number of digits in the sequence 
 * 	 is the number of digits of the previous sequence plus the amount of digits 
 * 	 in the number we want to add to the sequence. 
 *    
 *    EX: sequence 10: sequence 9 total digits is 45, digits per sequence is 9.
 *    9 + 2 (10 has 2 digits) = 11. 45 + 11 = 56;  
 * 
 * 									total digits | digits per sequence
 *     1						--> 	1				1
 *     1 2						-->		3				2
 *     1 2 3					-->		6				3
 *     1 2 3 4 					-->		10				4
 *     1 2 3 4 5				-->		15				5
 *     1 2 3 4 5 6				-->		21				6
 *     1 2 3 4 5 6 7			-->		28				7
 *     1 2 3 4 5 6 7 8			-->		36				8
 *     1 2 3 4 5 6 7 8 9		-->		45				9
 *     1 2 3 4 5 6 7 8 9 10		-->		56 * 			11
 *     1 2 3 4 5 6 7 8 9 10 11	-->   	69				13
 *     
 *     Precalculate all the digits-per-sequence and the total digits over all sequences.
 *     Keep track of which sequence has which total. Then find the sequence where X
 *     is lower than the total digits of one sequence but higher than the previous sequence.
 *     
 *     EX: 60 is higher than 56 so it's not in the 10th sequence but it's lower
 *     than 69 so it must be in the 11th sequence. 69-60 = 9 indexes lower than 
 *     the total of 11. 11th index has a 13 digits in the sequence, so 13 - 9 = 4. 
 *     Your answer will be 4 indexes from the start of the massive string of numbers. 
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

string allNumbers;

//MinGW has a problem with to_string so I used this to compile
namespace fix {
	std::string to_string(int n) {
		std::ostringstream strm;
		strm << n;
		return strm.str();
	}
}

//sums[i][0] = the number of digits in one sequence
//sums[i][1] = the total sum of the sequence from 1 to i
long long sums[32000][2];
void makeSequence() {
	string number;
	long long indexCountOneSequence = 0, indexAllSequences = 0;
	for (long i = 1; i < 32000; i++) {
		number = fix::to_string(i);
		allNumbers.append(number);
		indexCountOneSequence += number.length();
		indexAllSequences += indexCountOneSequence;
		sums[i][0] = indexCountOneSequence;
		sums[i][1] = indexAllSequences;

	}

}

int main() {
	long long cases, indexAll, sequenceIndex, sequenceTotal, numWanted;
	cin >> cases;

	makeSequence();

	while (cases--) {
		indexAll = 0;
		sequenceIndex = 0, sequenceTotal = 0;
		cin >> indexAll;
		for (int i = 1; i < 32000; i++) {
			if (indexAll <= sums[i][1] && indexAll > sums[i - 1][1]) {
				sequenceTotal = sums[i][1];
				sequenceIndex = sums[i][0];
			}
		}
		numWanted = sequenceIndex - (sequenceTotal - indexAll);
		cout << allNumbers[numWanted - 1] << endl;

	}

	return 0;
}
