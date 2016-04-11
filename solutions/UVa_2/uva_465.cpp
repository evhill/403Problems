/* UVa problem: 465 - Overflow
 * Topic: Arithmetic
 * Brief problem description:
 *    Given 2 numbers and an operator, determine if they overflow
 *    the max size of a long int.
 *
 * Solution Summary:
 *    Since these numbers can be greater than a long long in size,
 *    read in as strings. Count the number of digits (ignoring leading
 *    zeros). If the string has more than 10 digits it overflows. If
 *    it has 10 or less digits, convert to long long and do basic
 *    math operations.
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

int countDigits(string x, int length) {
	int count = 0;
	bool start = false;
	for (int i = 0; i < length; i++) {
		//leading zeros
		if (x[i] == '0' && start == false) {
			continue;
		}
		if (start == false and x[i] != '0') {
			start = true;
			count++;
		} else
			count++;
	}
	return count;
}

long long from_string(string s) {
    std::stringstream ss(s);
    long long result;
    ss >> result;
    return result;
}

int main() {
	long long x, y;
	char op;
	string a, b, line;

	while (cin >> a >> op >> b) {
		bool aOver = false, bOver = false, rOver = false;
		int aCount = 0, bCount = 0;
		aCount = countDigits(a, a.length());
		bCount = countDigits(b, b.length());

		//if a or b is greater than 10 digits they're over
		if (aCount > 10)
			aOver = true;
		else
			x = from_string(a);
		if (bCount > 10)
			bOver = true;
		else
			y = from_string(b);

		//if a or b have 10 or less digits check
		if(x > 2147483647)
			aOver = true;
		if(y > 2147483647)
			bOver = true;

		//if either a or b is 0 and we're multiplying the result won't be over
		if((aCount == 0 || bCount == 0) && op == '*')
			rOver = false;
		else if(!aOver && !bOver){
			if(op == '*')
				if(x * y > 2147483647)
					rOver = true;
			if(op == '+')
				if(x + y > 2147483647)
					rOver = true;
		}
		else if(aOver || bOver)
			rOver = true;

		cout << a << " " << op << " " << b << endl;
		if(aOver)
			cout << "first number too big" << endl;
		if(bOver)
			cout << "second number too big" << endl;
		if(rOver)
			cout << "result too big" << endl;


	}

	return 0;
}
