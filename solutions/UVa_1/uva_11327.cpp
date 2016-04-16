/* UVa problem: 11327 - Enumerating Rational Numbers
 * Topic: Number Theory
 * Brief problem description:
 *    Given a number X, find the Xth fraction in a sequence of 
 *    increasing rational numbers/
 *
 * Solution Summary:
 *    Similar to 10706. Precalculate Euler Phi function up to
 *    200000 numbers. Each number you calculate with phi will give you 
 *    the total amount of fractions that that number will produce. Store
 *    these in an array for later lookup. As you're doing this, add this number
 *    to the total sum of fractions. 
 *    
 *    When finding the correct fraction, you need to first find which euler
 *    'bucket' the fractions will be in. 
 *    
 *    EX) WE want to find the 9th fraction
 *    
 *    		   0    1    2      3        4            5
 *    		  0/1  1/1  1/2  1/3 2/3  1/4 3/4  1/5 2/5 3/5 4/5
 *    sum	   1    2    3      5        7			  11
 *    bucket   1    1    1      2        2	          4	
 *    
 *    From our earlier sum, we know that bucket 5 has the fractions that we want
 *    However, bucket 5 has 4 fractions to choose from. Just take the bucket count
 *    - the total sum - the digit we're looking for 4 - (11 - 9) = 2. So we know that
 *    we want the second gcd of 5. Compute GCD with some small checks and print. 
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

const int MAXN = 200003;
long long eulerCount[MAXN + 1];
long long eulerSum[MAXN + 1];

long long gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

//Geeksforgeeks
long long phi(long num) {
	long long result = num;

	for (long long i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			while (num % i == 0)
				num /= i;
			result -= result / i;
		}
	}

	if (num > 1) {
		result -= result / num;
	}

	return result;
}

int main() {

	long long index, sum = 2, bucket = 0, bucketNums = 0, ans = 0;
	eulerCount[0] = 1;
	eulerSum[0] = 1;
	eulerCount[1] = 1;
	eulerSum[1] = 2;

	for (long long i = 2; i <= MAXN; i++) {
		eulerCount[i] = phi(i);
		sum += eulerCount[i];
		eulerSum[i] = sum;
	}

	while (cin >> index && index != 0) {
		bucket = 0;
		if (index == 1) {
			cout << "0/1" << endl;
		} else if (index == 2) {
			cout << "1/1" << endl;
		} else {
			for (long long i = 2; i < MAXN; i++) {
				if (index > eulerSum[i - 1] && index <= eulerSum[i]) {
					bucket = i;
					bucketNums = eulerCount[i];
					ans = bucketNums - (eulerSum[i] - index);
					break;
				}
			}
			long long z = 0;
			for (long long i = 0; i <= bucket; i++) {
				if (gcd(i, bucket) == 1) {
					z++;
					if(z == ans){
						cout << i << "/" << bucket << endl;
						break;
					}

				}
			}
		}

	}
	//12158598919

	return 0;
}
