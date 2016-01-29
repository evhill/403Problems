/* UVa problem: 135 - Ugly Numbers
 * Topic: Number Theory
 * Brief problem description:
 *   Find the 1500'th ugly number. An ugly number is a number whose prime factors
 *   are only 2, 3, and 5.
 */
#include <iostream>
#include <set>

using namespace std;
set<long> uglySet;

void uglyInsert(long minUgly){
	uglySet.insert(minUgly * 2);
	uglySet.insert(minUgly * 3);
	uglySet.insert(minUgly * 5);
}

int main() {
	long SIZE = 1500;

	//insert 1 since it is an ugly number by convention
	uglySet.insert(1);
	set<long>::iterator it = uglySet.begin();

	int i = 0;
	long minUgly = 0;

	while(it!=uglySet.end()){
		minUgly = *it;
		uglyInsert(minUgly);
		it++; i++;

		if(i == SIZE){
			cout << "The " << SIZE << "'th ugly number is " << minUgly << "." << endl;
			break;
		}
	}

	return 0;
}
