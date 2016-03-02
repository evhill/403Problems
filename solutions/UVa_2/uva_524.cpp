/* UVa problem: 524 - Prime Ring
 * Topic: Backtracking
 * Brief problem description:
 * 	Given a number N, produce all chains of numbers in 1-N in a configuration
 * 	where each number plus the previous is equal to a prime.
 *
 * Solution Summary:
 *  Check if a number is available, then check if that number plus
 *  the previous number in the chain is a prime, and then recursively call N+1
 *  until you reach the 'end' of the chain. If you encounter a situation where
 *  the previous chain number and the current chain number do not equal prime,
 *  then backtrack and try another solution.
 */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

string s;

//Max ring size is 16 so no sum of the ring nodes will be bigger than 31 and be prime
int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
int taken[17];
int chain[17];
int ringSize;

bool checkPrime(int x) {

	for (int i = 0; i < 11; i++) {
		if (x == primes[i])
			return true;
	}
	return false;
}

void backTracking(int c) {
	// C in this case is the 'index' not the value of the chain itself.

	if (c == ringSize) {
		// We're at the end need to check if this number plus 1 is prime
		if (checkPrime(chain[c-1] + 1)) {
			cout << chain[0];
			for (int i = 1; i < ringSize; i++)
				cout << " " << chain[i];
			cout << endl;
		}
		return;
	}

	for (int x = 2; x <= ringSize; x++) {
		if (!taken[x]) {
			if (checkPrime(x + chain[c-1])) {
				taken[x] = 1;
				chain[c] = x;
				backTracking(c + 1);
				taken[x] = 0;
			}
		}
	}

}

int main() {
	int i = 1;
	while (cin >> ringSize) {
		if(i > 1)
			cout << endl;
		chain[0] = 1;
		taken[17] = {0};
		cout << "Case " << i << ":" << endl;
		backTracking(1);
		i++;
	}

	return 0;
}

