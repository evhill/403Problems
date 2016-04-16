/* UVa problem: 441 - Lotto
 * Topic: Arithmetic
 * Brief problem description:
 *   Given between 6 and 13 numbers, write out the permutations
 *   of the lotto numbers while keeping lexographical order.
 *
 * Solution Summary:
 *   Six nested loops enumerates over all subsets of length 6 
 *   and the having the various indexes (b, c, d...) be equal to the
 *   loop above lets you make the subsets while keeping lexographical 
 *   order. From Competitive Programming 3
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
	int x, a, b, c, d, e, f, k;
	int lotto[14];
	bool line = false;

	while (cin >> k && k != 0) {
		if(line){
			cout << endl;
		}

		for (int i = 0; i < k; i++) {
			cin >> x;
			lotto[i] = x;
		}
		for (int a = 0; a < k - 5; a++)
			for (int b = a + 1; b < k - 4; b++)
				for (int c = b + 1; c < k - 3; c++)
					for (int d = c + 1; d < k - 2; d++)
						for (int e = d + 1; e < k - 1; e++)
							for (int f = e + 1; f < k; f++)
								cout << lotto[a] << " " << lotto[b] << " "
										<< lotto[c] << " " << lotto[d] << " "
										<< lotto[e] << " " << lotto[f] << endl;
		line = true;
	}

	return 0;
}
