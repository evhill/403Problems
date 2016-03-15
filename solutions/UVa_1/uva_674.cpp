/* UVa problem: 674 - Coin Change
 * Topic: Dynamic Programming
 * Brief problem description:
 *    Given a number, determine how many ways you can make a subset sum with the set
 *    1,5,10,25,50.
 *
 * Solution Summary:
 *     Subset sum problem. If I have a sum of 5 and coins 1,2, and 3 I get this table:
 *
 *    	bool array[set][sum] or [i][j]
 *  	 ________________sum________
 *		 |_|_0_|_1_|_2_|_3_|_4_|_5_|
 *		 |1| 1   1   1   1   1   1
 *	set	 |2| 1   1   2   2   3   3
 *element|3| 1   1   2   3   4   5
 
 *    This table says how many times I can make a sum by only taking the total
 *	  of the above cell I'm in (if my coin is greater than the sum) or the total
 *    of the cell above plus cell-n cells back. For example, when I am using coin 2 
 *    and looking at sum 4, I look at the total of the above cell. It is 1. Now 
 *    since my coin 2 is less than 4, I look back 2 cells to determine how many 
 *    times I can make 2. There are 2 ways, so there are 1+2=3 ways to make sum 4.
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

const int maxCoins = 5;
const int maxSum = 7489;
int change[maxCoins] = {1, 5, 10, 25, 50};
int ways[maxCoins][maxSum+1]; //7489 + 0


// make the whole table since it's never changing
void count()
{
	//sum is 0 therefore only one way to get
	for(int i = 0; i < maxCoins; i++){
		ways[i][0] = 1;
	}

	//coin 1 will always make 1 way for all sums
	for(int j = 0; j <= maxSum; j++){
		ways[0][j] = 1;
	}


	for(int i = 1; i < maxCoins; i++){
		for(int j = 1; j <= maxSum; j++){
			if(change[i] <= j)
				//if coin is less or equal to sum, take the value in cell above
				//and the value coin-steps back in current row
				ways[i][j] = ways[i-1][j] + ways[i][j-change[i]];
			else
				//coin is greater than sum, just take above cell value
				ways[i][j] = ways[i-1][j];
		}
	}
}

int main() {
	count();
	int cents;
	while(cin >> cents){
		cout << ways[maxCoins-1][cents] << endl;
	}

	return 0;
}
