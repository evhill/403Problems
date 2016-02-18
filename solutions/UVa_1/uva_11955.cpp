/* UVa problem: 11955 - Binomial Theorem
 * Topic: Arithmetic
 * Brief problem description:
 *   Given a polynomial equation, print out it's expanded form.
 *
 * Solution Summary:
 *   Generate Pascal's Triangle. Then format the output.
 
 *   The power we read in from input corresponds to the 'row' of the earlier generated 
 *   triangle so print out the 'row' and then just increase and decrease the power of 
 *   the two variables with two ints.
 *
 * --- Elyse Hill
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

#define MAXN 50
long long bin[MAXN+1][MAXN+1];

//UALBERTA Code archive
//Generating pascal's triangle
void getBinCoeff(){
  int i, k;
  for(k = 0; k <= MAXN; k++){
    bin[k][0] = bin[k][k] = 1;
    for(i = 1; i < k; i++)
      bin[k][i] = bin[k-1][i-1]+bin[k-1][i];
  }
}

//Get rid of unnecessary characters
string parseString(string e) {
	replace(e.begin(), e.end(), '(', ' ');
	replace(e.begin(), e.end(), '+', ' ');
	replace(e.begin(), e.end(), ')', ' ');
	replace(e.begin(), e.end(), '^', ' ');
	return e;
}

//Output formatting
void printBinomial(string a, string b, int p){
	int i, k = (p-1), m = 1;

	if(p == 1)
		cout << a << "+" << b << endl;

	if(p > 1)
		cout << a << "^" << p;

	for(i=1; i < p; i++, m++, k--){
		//p is the 'row' of the pascal's triangle we're getting our coeffs from
		cout << "+" << bin[p][i] << "*" << a;
		if(k > 1)
			cout << "^" << k;
		cout << "*" << b;
		if(m > 1)
			cout << "^" << m;
	}

	if(p > 1)
		cout << "+" << b << "^" << p << endl;

}

int main() {
	getBinCoeff();

	int cases;
	cin >> cases;
	string eqn, A, B;
	int K;

	for(int i = 1; i <= cases; i++) {
		cin >> eqn;
		string e = parseString(eqn);
		istringstream iss(e);
		iss >> A >> B >> K;
		cout << "Case " << i << ": ";
		printBinomial(A,B,K);
	}

	return 0;
}
