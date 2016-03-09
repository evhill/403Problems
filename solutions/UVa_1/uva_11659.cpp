/* UVa problem: 11659 - Informants!
 * Topic: Backtracking
 * Brief problem description:
 * 	  Given a list of informants and answers, determine the maximum number
 * 	  of informants who are reliable.
 * Solution Summary:
 *    Read in the answers, if the answer is a negative, and that informant
 *    was previously reliable, then they are no longer reliable and we don't
 *    care about what they have to say in the future. If another reliable
 *    informant says that that an unreliable informant is reliable, we don't
 *    care about that either since the input is only that their testimony 'may'
 *    be considered reliable, not necessarily that it is 'always' true.
 */
#include <iostream>
#include <stack>
#include <queue>

using namespace std;



int main(){
	int k, a;
	while((cin >> k >> a)){

		int reliable[k+1], notreliable[k+1];
		int inf, ans, num =0, lie=0;
		reliable[0] = 0; notreliable[0] = 0;

		if(k == 0 && a == 0)
			break;

		for(int i = 1; i <= k; i++){
			reliable[i] = 1;
			notreliable[i] = 0;
		}

		while(a--){
			cin >> inf >> ans;
			if(ans < 0)
				//we only care about the answer if they are reliable
				if(reliable[-1*ans] == 1){
					notreliable[-1*ans] = 1;
					reliable[-1*ans]    = 0;
				}
		}

		for(int i = 0; i <= k; i++){
			if(reliable[i])
				num += 1;
			if(notreliable[i])
				lie += 1;
		}

		cout << num << endl;

	}


	return 0;
}
