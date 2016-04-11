/* UVa problem: 11330 - Andy's Shoes
 * Topic: Combinatorics
 * Brief problem description:
 *    Given a list of shoes, determine the minimum number of swaps
 *    needed to match all of the shoes (ex: 123321 -> 113322 with one
 *    swap).
 *
 * Solution Summary:
 *    Split the shoes and then swap whenever you come across an inconsistency.
 *
 *    To do this I made two arrays of left and right shoes, where each
 *    left and right shoe is read in as pairs (it 123123 -> is read in
 *    as L:1 R:2 L:3 R:1 L:2 R:3 where the leftshoes would be [1 3 2] and
 *    rightshoes would be [2 1 3]). Then, once you have the two arrays,
 *    you check if position (i) of both arrays are equal, if they're not
 *    you run through rightshoes and find the correct shoe, swap it and
 *    increment a counter.
 *
 *    This would not work if the pairs were random (ie: 1212) but we are
 *    assured by the problem that each left shoe has a right shoe, and that
 *    right and left shoes alternate.
 *
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

int leftshoes[10000], rightshoes[10000];

int main() {
	int cases;
	cin >> cases;

	while (cases--) {
		int pairs, temp, count = 0;
		cin >> pairs;

		for (int i = 0; i < pairs; i++) {
			cin >> leftshoes[i] >> rightshoes[i];
		}

		for(int i = 0; i < pairs; i++){
			if(leftshoes[i] != rightshoes[i]){
				for(int j = i; j < pairs; j++){
					if(leftshoes[i] == rightshoes[j]){
						temp = rightshoes[i];
						rightshoes[i] = rightshoes[j];
						rightshoes[j] = temp;
						count++;
					}
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}
