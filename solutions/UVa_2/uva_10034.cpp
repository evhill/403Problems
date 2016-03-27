/* UVa problem: 10034 - Freckles
 * Topic: Graph
 * Brief problem description:
 *    Given a set of points, find the minimum amount of 'ink' that would be used
 *    to connect all the dots. Minimum Spanning Tree problem
 *
 * Solution Summary:
 *    Start by reading in all the 'freckles' and then using the distance between two 
 *    points formula:
 *    		sqrt((X1-X2)^2 + (y1-y2)^2). 
 *    Make edges between all points and all other points so that we can find the 'shortest' 
 *    edges later.
 *
 *    Next sort the Points by their edge weight since we only want (or will be using)
 *    the shortest edges. Next we start making sets by taking the points with the
 *    smallest edges and checking if they are part of a set, if they are not, we add
 *    the weight to the amount of 'ink' we're using to connect them, and then make a set
 *    with them. This prevents cycles.

 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <iterator>
#include <complex>

using namespace std;

struct Edge {
	Edge(int freckle1, int freckle2, double weight) :
			freckle1(freckle1), freckle2(freckle2), weight(weight) {
	}
	int freckle1, freckle2;
	double weight;

	bool operator<(const Edge& rhs) const {
		return weight < rhs.weight;
	}
};

vector<complex<double>> freckles;
vector<Edge> edges;

//Competitive Programming 3: page 54
class UnionFind {
private:
	vector<int> p, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] < rank[y])
				p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};

int main() {
	int cases;
	cin >> cases;
	cout << std::setprecision(2) << std::fixed;

	while (cases--) {
		int num_freckles, i, j;
		double x, y, weight, deltaX, deltaY, ink = 0.0;
		vector<complex<double>>::iterator it, on;

		cin >> num_freckles;
		while (num_freckles--) {
			cin >> x >> y;
			freckles.push_back(complex<double>(x, y));
		}

		for (it = freckles.begin(), i = 0; it != freckles.end(); it++, i++) {
			for (on = it + 1, j = i + 1; on != freckles.end(); on++, j++) {
				deltaX = (real(*it) - real(*on)) * (real(*it) - real(*on));
				deltaY = (imag(*it) - imag(*on)) * (imag(*it) - imag(*on));
				weight = sqrt(deltaX + deltaY);
				edges.push_back(Edge(i, j, weight));
			}
		}

		sort(edges.begin(), edges.end());
		
		//Competitive Programming: page 139
		UnionFind UF(freckles.size());
		for(int i = 0; i < edges.size(); i++){ //for each edge
			Edge front = edges[i];
			if(!UF.isSameSet(front.freckle1, front.freckle2)){
				ink += front.weight;
				UF.unionSet(front.freckle1,front.freckle2);
			}
		}

		cout << ink << endl;
		if(!(cases-1 < 0))
				cout << endl;
		freckles.clear();
		edges.clear();
	}

	return 0;
}

