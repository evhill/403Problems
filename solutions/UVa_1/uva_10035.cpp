/* UVa problem: 10035 - Primary Arithmetic
 * Topic: Arithmetic
 * Brief problem description:
 *   Given two numbers, count how many 'carry' operations would happen if we were 
 *   adding on paper. 
 *
 * Solution Summary:
 *   Pretty simple, just separate the individual digits and add them together. If they
 *   equal something greater than 9 then increase the carry counter and set a flag for 
 *   the next pair of digits. 
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
	long a, b, x, y;
	int carry, temp;

	while(cin >> a >> b){
		carry = 0; temp = 0;

		if(a == 0 && b == 0)
			break;

		for(;;){

			x = a%10;
			y = b%10;

			if((x + y + temp) > 9){
				carry++;
				temp = 1;
			} else
				temp = 0;

			a /= 10;
			b /= 10;
			if(a == 0 && b == 0)
				break;
		}

		if(carry == 0)
			cout << "No carry operation." << endl;
		else if(carry == 1)
			cout << "1 carry operation." << endl;
		else if(carry > 1)
			cout << carry << " carry operations." << endl;

	}

	return 0;
}
