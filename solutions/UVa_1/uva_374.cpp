/* UVa problem: 374 - Big Mod
 * Topic: Number Theory
 * Brief problem description:
 *  We want to calculate the remainder of B^P mod M when these numbers are
 *  sufficiently big that they make traditional data types too small to hold the result.
 *

 */
#include <iostream>

using namespace std;

int bigMod(int B, int P, int M){

	if(P == 0) //end of recursive call or if p starts out as 0
		return 1;

	if(P % 2 == 0){  //even power
		int even = bigMod(B, P/2, M);
		return ((even * even) % M );
	}
	else{ //odd power
		int odd = bigMod(B, P-1, M);
		return ((odd * (B%M)) % M);
	}
}

int main() {
	int Bigint, Power, Mod;
	while(cin >> Bigint >> Power >> Mod){
		int Remainder = bigMod(Bigint, Power, Mod);
		cout << Remainder << endl;
	}
	return 0;
}
