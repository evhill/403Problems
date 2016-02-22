/* UVa problem: 488 - Triangle Wave
 * Topic: Output formatting
 * Brief problem description:
 *    Given an amplitude and a frequency, build triangles. Amplitude is the max height.
 *
 * Solution Summary:
 *    Amplitude isn't going to be greater than 9. Construct a static array, 
 *    and printed off based on the index.
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> triangle;

int main(){
	int triangle[] = {1,22,333,4444,55555,666666,7777777,88888888,999999999}; //amplitude never greater than 9
	int cases;
	cin >> cases;
	while(cases--){
		int amp, fre;
		cin >> amp >> fre;
		for(int i = 0; i < fre; i++){
			for(int j = 0; j < amp; j++){
				cout << triangle[j] << endl;
			}
			for(int k = amp-2;k >= 0; k--){
				cout << triangle[k] << endl;
			}
			if((i+1 < fre))
				cout << endl;
		}
		if(cases)
			cout << endl;
	}


	return 0;
}
