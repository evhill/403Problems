/* UVa problem: 729 - The Hamming Distance Problem
 * Topic: Combinatorics 
 * Brief problem description:
 *   Hamming distance is the number of differing bits between two strings of bits. Given
 *   the length of a bit string X and a Hamming distance Y, compute all permutations of
 *   bit string X where at most Y bits are 'on'.
 
 * Solution Summary:
 *   Pretty simple permutation question. Need to make sure that you are appending the
 *   0s and 1s correctly, as this needs to be in lexographical order. Then use next_permutation
 *   to get all the different bit 'strings'.
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
	int cases, length, hams;
	cin >> cases;
	vector<int> hamming;
	vector<int>::iterator it;

	while(cases--){
		cin >> length >> hams;

		//Appending the 1s to the end lets us get away with not sorting.
		for(int i = 0, k = length; i < length; i++, k--){
			if(k > hams)
				hamming.push_back(0);
			else
				hamming.push_back(1);
		}

		do{ //do{} because next_permutation will miss the first word if not
			for(it = hamming.begin(); it != hamming.end(); it++){
				cout << *it;
			}
			cout << endl;
		}while(next_permutation(hamming.begin(), hamming.end()));

		if(cases)
			cout << endl;

		hamming.clear();
	}


	return 0;
}
