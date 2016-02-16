/* UVa problem: 374 - Big Mod
 * Topic: Number Theory
 *
 * Brief problem description:
 *  We want to calculate the remainder of B^P mod M when these numbers are
 *  sufficiently big that they make traditional data types too small to hold the result.
 *
 * Solution Summary:
 *
 *   Modular exponentiation problem/repeated squaring. Use property: [a^b % c = ((a^b/2 % c) * (a^b/2 %c)) % c ].
 *   The theory is that you recursively compute smaller and smaller bs for [a^b mod c] and
 *   then return the calculated mod back up the recursive call. Therefore instead of having to use
 *   enormous numbers that don't fit into our largest data types, you do simple math on small remainders.
 *
 *   ex: 5^20 mod 9 is easier to compute as a series of repeated squares then multiplying out the whole
 *   exponent chain
 *       5^1 mod 9 = 5
 *       5^2 mod 9 = 7
 *       5^4 mod 9 = 7^2 mod 9 = 4
 *       5^8 mod 9 = 4^2 mod 9 = 7
 *       5^16 mod 9 = 7^2 mod 9 = 4
 *       then: 5^20 mod 9 = (5^16 mod 9)(5^4 mod 9) mod 9 = 4 * 4 mod 9 = 5

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
