/* UVa problem: 11136 - Hoax or What?
 * Topic: Data structures
 * Brief problem description:
 * 	 Given a series of 'Days' calculate the difference between the highest
 * 	 and lowest bill per day. The lowest and highest bills are taken out of
 * 	 the pot each day, and the leftover bills are used the next day.
 *
 * Solution Summary:
 *   Use a multiset to track the bills per day.
 *   Multisets allow for duplicates while keeping the useful quality of
 *   sets being ordered lowest to highest. Just get the begin and the end
 *   of the multiset (lowest and highest value) calculate the difference
 *   and then discard them from the set.
 */
#include <iostream>
#include <set>

using namespace std;

int main() {
	multiset<long> urn;

	long cases, bill, dayTotal, award, highest, lowest;
	while (cin >> cases) {
		if(cases == 0)
			break;

		urn.clear();
		award = 0;
		for (int i = 0; i < cases; i++) {
			cin >> dayTotal;
			for (int i = 0; i < dayTotal; i++) {
				cin >> bill;
				urn.insert(bill);
			}
			highest = *urn.rbegin();
			lowest = *urn.begin();
			award += highest - lowest;

			urn.erase(urn.find(highest));
			urn.erase(urn.find(lowest));

		}
		cout << award << endl;
	}

	return 0;
}
