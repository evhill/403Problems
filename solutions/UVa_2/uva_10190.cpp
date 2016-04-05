/* UVa problem: 10190 - Divide, But Not Quite Conquer!
 * Topic: Arithmetic
 * Brief problem description:
 *    Given 2 numbers x and y, continuously divide x by y and determine if the sequence
 *    of numbers generated is boring or not.
 *
 * Solution Summary:
 *    This is a pretty straight forward problem. There are three rules to follow to see
 *    if a sequence of numbers is boring or not.
 *    	1) A sequence is boring if y > x
 *    	2) If either x or y are 1 or 0
 *    	3) If x mod y does not equal 0
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
	bool boring;
	vector<int> conquer;
	vector<int>::iterator it;

	int x, y;

	while (cin >> x >> y) {
		conquer.clear();
		boring = false;

		if (y > x || x <= 1 || y <= 1)
			boring = true;

		if (boring == false) {
			while (x > 1) {
				if (x % y != 0)
					boring = true;
				else
					conquer.push_back(x);
				x /= y;
			}
			conquer.push_back(1);
		}

		if (boring == true)
			cout << "Boring!" << endl;
		else {
			it = conquer.begin();
			cout << *it;
			it++;
			for (; it != conquer.end(); it++) {
				cout << " " << *it;
			}
			cout << endl;
		}

	}

	return 0;
}
