/* UVa problem: 10026 - Shoemaker's Problem
 * Topic: Sorting
 
 * Brief problem description:
 *   A shoemaker needs to decide what order to finish shoemaking jobs so as to minimize fines.
 * 
 * Solution Summary:
 *  This is a greedy problem. We want to finish the jobs in the order that will minimize fines. To calculate
 *  this, and to avoid rounding errors, find the highest ratio of fines per day per job by multiplying
 *  the time it took job A by the fine of job B and vice versa. (Ex: job A = 2 days and 3 fines, job B
 *  = 4 days and 7 fines. If we did 3/2 & 7/4 we'd have 1.5 and 1.75 so job 2 would come first
 * 	However, this could lead to rounding errors for large numbers so cross multiply instead. 
 *  3*4=12 < 7*2=14 is the same answer)
 *
 * 	The you output the number of the highest to lowest fine/day job
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

struct Greedy{
	int fine;
	int time;
	int job;
};

struct compareBiggestRatio {
	/*j = fine/time
	 * a/b > c/d -> a*d > c*b
	 * To get rid of decimals
     */
	bool operator()(const Greedy& shoe1, const Greedy& shoe2) {
		return (shoe1.fine * shoe2.time) > (shoe2.fine * shoe1.time);
	}
};

int main() {

	int cases;
	cin >> cases;
	while (cases--) {
		int jobs;
		cin >> jobs;

		vector<Greedy> shoes;
		double time, fine;

		for (int key = 1; key <= jobs; key++) {
			Greedy ratio;
			cin >> time >> fine;
			ratio.time = time; ratio.fine = fine; ratio.job = key;
			shoes.push_back(ratio);
		}

		stable_sort(shoes.begin(), shoes.end(), compareBiggestRatio());
		vector<Greedy>::iterator it = shoes.begin();

		cout << it->job;
		it++;

		for (; it != shoes.end(); it++) {
			cout << " " << it->job;
		}
		cout << endl;
		if(cases) cout << endl;
	}
	return 0;
}

