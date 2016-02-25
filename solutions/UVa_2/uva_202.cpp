/* UVa problem: 202 - Repeating Decimals
 * Topic: Arithmetic
 * Brief problem description:
 *  Given two numbers A and B, find the decimal cycle when you divide A by B *
 *
 * Solution Summary:
 *	 Simulate long division and found cycles by comparing remainders keep track 
 *   of the remainders since once we've found a remainder we've seen before,
 *	 we will be repeating arithmetic we've already 'calculated' (ie: cycles)
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> remainders;
vector<int> quotients;

bool checkRemainders(int x) {
	vector<int>::iterator it = remainders.begin();

	for (; it != remainders.end(); it++) {
		if (find(remainders.begin(), remainders.end(), x) != remainders.end())
			return true;
	}

	return false;
}

int findCycle(int x) {
	vector<int>::iterator on;
	bool start = false;
	int c = 0;

	//We know the remainder that starts the cycle, now count from
	//there to the end of the remainder vector
	for (on = remainders.begin(); on != remainders.end(); on++) {
		if (*on == x && start == false) {
			c++;
			start = true;
		}
		if (*on != x && start == true)
			c++;
	}

	return c;
}

void printDecimals(int c, int cycle) {
	vector<int>::iterator it = quotients.begin();
	vector<int>::iterator on = remainders.begin();
	int i;
	bool start = false;

	cout << *it << ".";
	it++;

	for (i = 0; it != quotients.end() && i < 50; it++, on++, i++) {
		if (*on == cycle && start == false)
			cout << "(";

		cout << *it;

		if (i + 1 == 50)
			cout << "...)" << endl;
	}
	if(i < 50)
		cout << ")" << endl;

	cout << "   " << c << " = number of digits in repeating cycle" << endl;
	cout << endl;

}

int main() {
	int nom, den, rem, quo, cycle;
	bool cycleFound;
	vector<int>::iterator it;

	while (cin >> nom >> den) {
		remainders.clear();
		quotients.clear();
		cycleFound = false;
		cycle = 0;

		cout << nom << "/" << den << " = ";

		//'long division'
		while (!cycleFound) {
			quo = nom / den;
			rem = nom % den;
			quotients.push_back(quo);

			if (checkRemainders(rem * 10)) {
				cycleFound = true;
				cycle = rem * 10; //Remainder that begins the cycle
			}

			remainders.push_back(rem * 10);
			nom = rem * 10;
		}

		//find cycle and print
		int cycleLength = findCycle(cycle);
		printDecimals(cycleLength, cycle);
	}

	return 0;
}
