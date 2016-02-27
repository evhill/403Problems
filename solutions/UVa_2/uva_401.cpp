/* UVa problem: 401 - Palindromes
 * Topic: Strings
 * Brief problem description:
 *   Given a string determine if it is a palindrome, mirrored palindrome, mirrored string
 *   or none of the above.
 *
 * Solution Summary:
 *   Take the string and check both front and back until you reach the middle, if there are no 
 *   differences it is a palindrome. For mirrored check, make a reversed copy of the string 
 *   you're checking using the map, then check the front of the original to the back of the
 *   copy until the end. If same, mirrored. 
 */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

string s;
map<char, char> mirror;

void buildMap() {
	mirror['A'] = 'A'; mirror['H'] = 'H'; mirror['I'] = 'I'; mirror['E'] = '3';
	mirror['J'] = 'L'; mirror['L'] = 'J'; mirror['M'] = 'M'; mirror['O'] = 'O';
	mirror['T'] = 'T'; mirror['U'] = 'U'; mirror['V'] = 'V'; mirror['W'] = 'W';
	mirror['X'] = 'X'; mirror['S'] = '2'; mirror['Y'] = 'Y'; mirror['Z'] = '5';
	mirror['1'] = '1'; mirror['2'] = 'S'; mirror['3'] = 'E'; mirror['5'] = 'Z';
	mirror['8'] = '8';

}

bool checkPalindrome(string a) {
	int i = 0, j = a.length() - 1; //index
	int length = (int) a.length();

	for (; i < length / 2; i++, j--) { //checking back and front simultaneously
		if (a[i] != a[j])
			return false;
	}
	return true;
}

bool checkMirrored(string b) {
	int i = 0, j = b.length() - 1;
	int length = (int) b.length();

	string m;

	for (; i < length; i++) {
		m += mirror[b[i]];
	}

	for (i = 0; i < length, j >= 0; i++, j--) {
		if (b[i] != m[j]) { //check front and back of both. If same, mirrored
			return false;
		}
	}

	return true;
}

int main() {
	buildMap();

	while (cin >> s) {
		bool palindrome, mirrored;

		palindrome = checkPalindrome(s);
		mirrored = checkMirrored(s);

		if (palindrome && mirrored)
			cout << s << " -- is a mirrored palindrome." << endl;
		if (palindrome && !mirrored)
			cout << s << " -- is a regular palindrome." << endl;
		if (!palindrome && mirrored)
			cout << s << " -- is a mirrored string." << endl;
		if (!palindrome && !mirrored)
			cout << s << " -- is not a palindrome." << endl;

		cout << endl;
	}

	return 0;
}
