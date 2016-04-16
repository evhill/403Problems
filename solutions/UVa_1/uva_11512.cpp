/* UVa problem: 11512 - GATTACA
 * Topic: Strings
 * Brief problem description:
 * 	  Given a string X, find the longest repeated substring
 * Solution Summary:
 *    Copy the book problem! Start by creating the suffix array, which 
 *    takes a string and determines all of the different suffixes by
 *    taking a substring of X from i to the end of X. 
 *    
 *    Then you sort all the suffixes within that string in lexographical
 *    order (ie: GATAGACA$ -> $, A$, ACA$, AGACA$, ATAGACA$ CA$, GACA$, GATAGACA$, 
 *    TAGACA$). Each of these suffixes have an index of where they begin in a string.
 *    ($ = 8, A$ = 7, ACA$ = 5....) 
 *    
 *    Next compute the Longest Common Prefix, which takes that sorted suffix array and
 *    uses those indices of the sorted suffix array and uses it to compute the longest
 *    length prefix match between two consecutive suffixes. 
 *    
 *    Now that you have the LCP and the SA, search through the LCP to find the max length
 *    and which index it is found at. And then copy that suffix from the SA into a new 
 *    string, and find out where it starts with stringMatching. Then print.  
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 100010
char T[MAXN];
char COPY[MAXN];
int n, m;
int RA[MAXN], tempRA[MAXN];
int SA[MAXN], tempSA[MAXN];
int c[MAXN], Phi[MAXN];
int LCP[MAXN], PLCP[MAXN];
typedef pair<int, int> ii;

//From Competitive Programming 3
void countingSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for (i = 0; i < n; i++)
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void constructSA() {
	int i, k, r;
	for (i = 0; i < n; i++) {
		RA[i] = T[i];
		SA[i] = i;
	}
	for (k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++)
			tempRA[SA[i]] =
					(RA[SA[i]] == RA[SA[i - 1]]
							&& RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (i = 0; i < n; i++)
			RA[i] = tempRA[i];

	}

}

ii stringMatching() {
	int lo = 0, hi = n - 1, mid = lo;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], COPY, m);
		if (res >= 0)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (strncmp(T + SA[lo], COPY, m) != 0)
		return ii(-1, -1);
	ii ans;
	ans.first = lo;
	lo = 0;
	hi = n - 1;
	mid = lo;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		int res = strncmp(T + SA[mid], COPY, m);
		if (res > 0)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (strncmp(T + SA[hi], COPY, m) != 0)
		hi--;
	ans.second = hi;
	return ans;
}

void computeLCP() {
	int i, L;
	Phi[SA[0]] = -1;
	for (i = 1; i < n; i++)
		Phi[SA[i]] = SA[i - 1];
	for (i = L = 0; i < n; i++) {
		if (Phi[i] == -1) {
			PLCP[i] = 0;
			continue;
		}
		while (T[i + L] == T[Phi[i] + L])
			L++;
		PLCP[i] = L;
		L = max(L - 1, 0);
	}
	for (i = 0; i < n; i++)
		LCP[i] = PLCP[SA[i]];
}

int main() {
	int cases = 0, biggestSeq, index_found;
	bool found;
	cin >> cases;

	while (cases--) {
		biggestSeq = 0;
		index_found = -10;
		found = false;
		cin >> T;
		n = (int) strlen(T);
		T[n++] = '$';
		constructSA();
		computeLCP();

		for (int i = 0; i < n; i++) {
			if (LCP[i] > biggestSeq) {
				biggestSeq = LCP[i];
				index_found = i;
				found = true;
			}
		}
		if (found) {

			//empty out the char array
			for(int i = 0; i < MAXN; i++){
				COPY[i] = '\0';
			}

			int LCPlength = LCP[index_found];
			int start = SA[index_found];
			for(int i = 0; i < LCPlength; i++, start++){
				COPY[i] = T[start];
			}

			m = strlen(COPY);
			ii matchesAt = stringMatching();
			int x = matchesAt.second - matchesAt.first + 1;

			cout << COPY << " " << x << endl;
		} else {
			printf("No repetitions found!\n");
		}

	}

}
