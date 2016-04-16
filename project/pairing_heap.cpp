#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <iterator>
using namespace std;

class pair_node {
public:
	int key;
	pair_node * parent;
	vector<pair_node*> children;
	vector<pair_node*>::iterator it;

	//basic constructor for a node
	pair_node(int x) :
			key(x), parent(NULL), children(vector<pair_node*>()) {
	}

	//destructor recursively deletes all children and children's nodes
	~pair_node() {
		while (!children.empty()) {
			delete children.back();
			children.pop_back();
		}
	}

};

class pair_heap {
public:
	pair_node * root;
	int size;
	//Basic Constructor
	pair_heap() :
			root(0), size(0) {
	}

	//Basic Copy Constructor
	pair_heap(const pair_heap & rhs) {
		root = NULL;
		*this = rhs;
	}
	//Need AO

	//Implicit destructor
	~pair_heap() {
		clear();
	}

	//explicit clear method
	void clear() {
		if (root != 0)
			delete root;
	}

	//check if the heap is empty
	bool isEmpty() {
		return root == 0;
	}

	//get the size of the heap
	int getSize() {
		return size;
	}

	//get the minimum element of the heap
	int getMin() {
		return root->key;
	}

	//delete the root of the heap and recombine it's children
	int deleteMin() {
		if (root == 0)
			return 0;
		size--;

		int min = root->key;
		root = mergePairs(root->children, 0);
		return min;
	}

	//Insert a single integer into the pairing heap.
	void insert(int x) {
		size++;
		root = merge(root, new pair_node(x));
	}

	/**
	 * Merge by comparing the the key value of one node with another
	 * this is why it runs in O(1) Time since we are only comparing the
	 * keys of two nodes instead of many nodes. Whichever has a larger value,
	 * assign it as a child of the smaller node. Sorting comes later.
	 */
	pair_node * merge(pair_node * a, pair_node * b) {

		if (a == 0)
			return b;
		if (b == 0)
			return a;
		if (a->key < b->key) {
			a->children.push_back(b);
			b->parent = a;
			return a;
		} else {
			b->children.push_back(a);
			b->parent = a->parent;
			a->parent = b;
			return b;
		}
	}

	/**
	 * Future work: combine two existing heaps. Currently doesn't work
	 */
	void combineHeaps(pair_heap * a, pair_heap * b){
		merge(a->root, b->root);
	}

	/**
	 * MergePairs is the bulk of the time complexity of this algorithm.
	 */
	pair_node * mergePairs(vector<pair_node*> &children, int x) {
		int cs = children.size();
		if (cs < 1)
			return 0;
		if (x >= cs)
			return 0;
		else if (x == cs - 1)
			return children[x];
		else {
			return merge(merge(children[x], children[x + 1]),
					mergePairs(children, x + 2));
		}
	}

	/**
	 * Decrease key: not complete. Allows someone to remove a heap at a specific
	 * key. In essence you can prune the tree where ever you like.
	 *
	 */
	pair_node * decrease_key(pair_node * badNode, vector<pair_node*> & nodes) {
		vector<pair_node*>::iterator it;
		for (it = nodes.begin(); it != nodes.end(); it++) {
		}
		return 0;
	}

};

int main() {

	int min;
	bool passSimple = true;
	//=======Basic Test=========
	pair_heap p = pair_heap();
	cout << "Basic Test: Inserting 20 numbers " << endl;
	cout << "     Inserting #: 4 5 7 2 3 1 0 6 9 8 14 15 17 12 13 11 10 16 19 18" << endl;
	p.insert(4);
	p.insert(5);
	p.insert(7);
	p.insert(2);
	p.insert(3);
	p.insert(1);
	p.insert(0);
	p.insert(6);
	p.insert(9);
	p.insert(8);

	p.insert(14);
	p.insert(15);
	p.insert(17);
	p.insert(12);
	p.insert(13);
	p.insert(11);
	p.insert(10);
	p.insert(16);
	p.insert(19);
	p.insert(18);

	cout << "     Remove Mins: ";
	for (int i = 0; i < 20; i++) {
		min = p.getMin();
		if(min != i)
			passSimple = false;
		else
			cout << min << " ";

		p.deleteMin();

	}
	cout << endl;
	if(passSimple == true)
		cout << "Simple test passes!" << endl;
	cout << endl;
	//=======Stress Test=========

	cout << "Stress Test: Inserting 175000 randomly generated numbers into a Priority Queue and Pairing Heap" << endl;
	cout << "     175000 getMin() operations for both PQ and PH. If they don't match the test fails!" << endl;
	cout << "     Here are the first 10 values" << endl;
	pair_heap PHtest;
	vector<int> randomNums;
	vector<int>::iterator it;
	priority_queue<int, vector<int>, greater<int>> PQtest;
	for (long i = 0; i < 175000; i++) {
		int r = rand() % 175000;
		randomNums.push_back(r);
		//cout << r << " " << endl;
	}

	for (it = randomNums.begin(); it != randomNums.end(); it++) {
		PHtest.insert(*it);
		PQtest.push(*it);
	}

	int phmin, pqmin;
	bool pass = true;
	for (long i = 0, j = 0; i < 175000; i++, j++) {
		phmin = PHtest.getMin();
		pqmin = PQtest.top();
		if (phmin != pqmin){
			cout << "Not the same!" << endl;
			pass = false;
		}
		if(j < 10){
			cout << "     PH " << phmin << " PQ " << pqmin << endl;
		}

		PHtest.deleteMin();
		PQtest.pop();
	}
	if(pass == true)
		cout << "Stress Test Pass!" << endl;

	//======= Dijkstra test ======

	return 0;
}

