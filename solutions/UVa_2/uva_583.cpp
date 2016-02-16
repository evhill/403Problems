/* UVa problem: 583 - Prime Factors
 * Topic: Number Theory
 *
 * Brief problem description:
 *   Given a number, find all of its prime factors.
 *
 * Solution Summary:
 *  What this algorithm does is takes a number and finds if X is a prime factor through
 *  modulo arithmetic and then replaces that number with NUM / PRIME. If it is divisible,
 *  then I print out that number (as opposed to storing them since that's not needed).
 *  And by replacing the number with NUM / PRIME I don't waste time checking numbers that wouldn't
 *  work anyway. If I get to the end of the prime array and my NUM is greater, then it is also a prime
 *  and I print that out. 
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

#define MAXN 46340
#define MAXP 5000

int primes[MAXP];
int psize;

//UALBERTA 403 Code Archive
void getPrimes() {
	int i, j, isprime;

	psize = 0;
	primes[psize++] = 2;
	for (i = 3; i <= MAXN; i += 2) {
		for (isprime = j = 1; j < psize; j++) {
			if (i % primes[j] == 0) {
				isprime = 0;
				break;
			}
			if (1.0 * primes[j] * primes[j] > i)
				break;
		}
		if (isprime)
			primes[psize++] = i;
	}
}

int main() {
	getPrimes();

	int num;

	while (cin >> num) {
		if (num == 0)
			return 0;

		cout << num << " = ";

		if (num < 0) {
			cout << "-1 x ";
			num = num * -1;
		}

		for (int i = 0; i < psize; i++) {
			while (num % primes[i] == 0) {
				cout << primes[i];
				num /= primes[i];
				if (num != 1)
					cout << " x ";
			}
		}
		if(num > 46337){
			cout << num;
		}
		cout << endl;
	}
	cout << endl;

}
