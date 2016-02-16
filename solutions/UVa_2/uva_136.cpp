/* UVa problem: 135 - Ugly Numbers
 * Topic: Number Theory
 *
 * Brief problem description:
 *   Find the 1500'th ugly number. An ugly number is a number whose prime factors
 *   are only 2, 3, and 5.
 *
 * Solution Summary:
 *   Use a set, as a set is sorted in ascending order and has no duplicates.
 *	 Use an iterator (.begin())to get the smallest number (1 in this case) and 
 *   multiply that number by 2,3, and 5. Then increase the iterator	which will give 
 *   the next smallest number to multiply.. 
 */
#include <iostream>
#include <set>

using namespace std;
set<long> uglySet;

/*
 * Multiplies given number by 2, 3, and 5 for next set of
 * ugly numbers
 */
void uglyInsert(long minUgly){
	uglySet.insert(minUgly * 2);
	uglySet.insert(minUgly * 3);
	uglySet.insert(minUgly * 5);
}

int main() {
	long SIZE = 1500;

	//insert 1 since it is an ugly number by convention
	uglySet.insert(1);

	//Initialize an iterator to the beginning of the set ('1')
	set<long>::iterator it = uglySet.begin();
	long minUgly = 0;

	/*
	 * Until we reach the SIZE of the number we're looking for
	 * find the minimum ugly number and multiply it by 2,3,5
	 */

	for(int i = 0; i < SIZE; it++, i++){
		//This will point to the smallest number of a set based on Set logic
		minUgly = *it;
		uglyInsert(minUgly);
	}

	cout << "The " << SIZE << "'th ugly number is " << minUgly << "." << endl;
	return 0;
}
