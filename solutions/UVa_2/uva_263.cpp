/* UVa problem: 263 - Number Chains
 * Topic: Number Theory
 
 * Brief problem description:
 *   Given a number X, make a chain of math operations by sorting X into descending
 *   order A and ascending order B and then subtracting A from B. See how many chains
 *   it takes you to get to 0.
 
 * Solution Summary:
 *  I started out by separating a read in number into digits and placing them in a
 *  vector for easy sorting. Then I changed those vectors back into ints and subtracted
 *  the ascending number from the descending number. Once I got the remainder
 *  I added the result to another vector so I could check future values and stop
 *  once I'd found a remainder I'd already seen, I exited the loop.
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void printThis(int a, int d, int diff) {
	cout << a << " - " << d << " = " << diff << endl;
}


int main() {
	int orig;

	while ((cin >> orig) != 0) {
		int count = 0;
		cout << "Original number was " << orig << endl;

		while (true) {
			vector<int> ascend, descend, chains;
			int diff = 0, AA = 0, DD = 0;

			chains.push_back(orig);

			for (; orig > 0; orig /= 10) {
				ascend.push_back(orig % 10);
				descend.push_back(orig % 10);
			}

			sort(ascend.begin(), ascend.end(), greater<int>());
			sort(descend.begin(), descend.end(), less<int>());
			vector<int>::iterator it = ascend.begin();
			vector<int>::iterator on = descend.begin();

			while (it != ascend.end() && on != descend.end()) {
				AA = (AA * 10) + *it;
				DD = (DD * 10) + *on;
				it++, on++;
			}

			diff = AA - DD;
			printThis(AA, DD, diff);

			if (find(chains.begin(), chains.end(), diff) != chains.end()) { //found
				cout << "Number of chains " << ++count << endl;
				break;
			} else {
				chains.push_back(diff);
				count++;
			}

			orig = diff;
		}

	}

	return 0;
}
