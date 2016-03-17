/* UVa problem: 10608 - Friends
 * Topic: Data Structures
 * Brief problem description:
 *    The "Friend of my friend is my friend". Given a list of pairs, find out the biggest
 *    set of friends in a town.
 *
 * Solution Summary:
 *    The disjoint set code starts out but making N number of disjointed elements,
 *    each with a parent vector and a rank vector. Then we read in pairs of elements 
 *    and make union sets with them. To do this we find the parent of each element 
 *    and check their rank. Depending on the rank, you assign the lesser ranked element 
 *    the parent of the greater ranked element. By the end of the input, each element is 
 *    joined to the top "parent" of the rest of it's friends and you've made separate sets 
 *    of friends.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSets {
public:
	DisjointSets(int N) :
			parent(vector<int>(N)), rank(vector<int>(N)) {
	}
	void MakeSet(int i) {
		parent[i] = i;
		rank[i] = 0;
	}
	void Union(int i, int j) {
		int iRoot = Find(i);
		int jRoot = Find(j);
		if (iRoot == jRoot)
			return;
		if (rank[iRoot] < rank[jRoot])
			parent[iRoot] = jRoot;
		else if (rank[iRoot] > rank[jRoot])
			parent[jRoot] = iRoot;
		else {
			parent[jRoot] = iRoot;
			rank[iRoot] += 1;
		}
	}
	int Find(int i) {
		if (parent[i] != i)
			parent[i] = Find(parent[i]);
		return parent[i];
	}
private:
	vector<int> parent;
	vector<int> rank;
};

// Demonstration of Disjoint Set data structure.
int main() {
	int cases;
	cin >> cases;

	while (cases--) {
		int citizens, pairs, a, b, max = 0, temp = 0;
		cin >> citizens >> pairs;
		DisjointSets DS(citizens);
		vector<int> sets;
		vector<int>::iterator it;

		for (int i = 1; i <= citizens; i++) {
			DS.MakeSet(i);
		}

		if (pairs > 0) {
			for (int i = 0; i < pairs; i++) {
				cin >> a >> b;
				DS.Union(a, b);
			}
			//check size of sets and output largest
			for (int i = 1; i <= citizens; i++) {
				sets.push_back(DS.Find(i));
			}

			for (int i = 1; i <= citizens; i++) {
				temp = count(sets.begin(), sets.end(), i);
				if (temp > max)
					max = temp;
			}
		}
		cout << max << endl;
	}

	return 0;
}
