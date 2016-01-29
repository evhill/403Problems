/* UVa problem: 11462 - Age Sort
 * Topic: Sorting
 * Brief problem description: 
 *   Given a list of ages, sort them in order from least to greates.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

	int population;
	int age;

	for(;;){
		cin >> population;

		if(population == 0){
			break;
		}
		else {
			vector<int> allAges;
			for(int i = 0; i < population; i++){
				cin >> age;
				allAges.push_back(age);
			}

			sort(allAges.begin(), allAges.end());
			for(int i = 0; i < population; i++){
				cout << allAges[i];
				if(i + 1 < population) cout << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
