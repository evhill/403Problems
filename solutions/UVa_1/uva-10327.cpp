/* UVa problem: 10327 - Flip Sort
 * Topic: Sorting
 *
 * Brief problem description:
 *   Given a series of numbers, display the minimum number of steps it would take to sort if you
 *   can only exchange adjacent numbers.
 *
 * Solution Summary:
 *  This is a simple bubble sort problem.
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
	int tests;

	while (cin >> tests) {
		int count = 0;
		int toFlip[tests];
		for (int i = 0; i < tests; i++) {
			cin >> toFlip[i];
		}

		for (int i = 0; i < tests; i++) {
			int temp;
			for(int j = 0; j < tests - 1; j++) {
				if (toFlip[j] > toFlip[j + 1]) {
					temp = toFlip[j];
					toFlip[j] = toFlip[j + 1];
					toFlip[j + 1] = temp;
					count ++;
				}
			}
		}
		cout << "Minimum exchange operations : " << count << endl;
	}
	return 0;
}


