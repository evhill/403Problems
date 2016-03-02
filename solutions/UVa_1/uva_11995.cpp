/* UVa problem: 11995 - I Can Guess the Data Structure!
 * Topic: Data Structure
 * Brief problem description:
 * 	   Given a list of instructions (put in element, take element out) determine if the 
 * 	   mystery data structure is a stack, queue or priority queue. 
 * Solution Summary:
 *     Pretty simple. Just make  a stack, a queue and a priority queue and follow the
 *     instructions. If the output is not the same for one of the structures (ie: it says to 
 *     take out a 2 and you get a 1) it is not that structure. Need to be careful on flags 
 *     If you've already said a structure is FALSE don't add anything to it or take anything 
 *     away or you'll get incorrect flags. Check if empty or you'll run into Runtime Errors. 
 */
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
	int cases;
	while(cin >> cases){
		stack<int> testS;
		queue<int> testQ;
		priority_queue<int> testP;
		bool ST = true, QE = true, PQ = true;
		int instruction, element;

		while(cases--){
			cin >> instruction >> element;
			if(instruction == 1){
				if(ST == true)
					testS.push(element);
				if(QE == true)
					testQ.push(element);
				if(PQ == true)
					testP.push(element);
			}
			if(instruction == 2){
				if(ST == true){
					if(!testS.empty() && element == testS.top())
						testS.pop();
					else
						ST = false;
				}
				if(QE == true){
					if(!testQ.empty() && element == testQ.front())
						testQ.pop();
					else
						QE = false;
				}
				if(PQ == true){
					if(!testP.empty() && element == testP.top())
						testP.pop();
					else
						PQ = false;
				}

			}

		}
		if(ST && !QE && !PQ)
			cout << "stack" << endl;
		else if(!ST && QE && !PQ)
			cout << "queue" << endl;
		else if(!ST && !QE && PQ)
			cout << "priority queue" << endl;
		else if(!ST && !QE && !PQ)
			cout << "impossible" << endl;
		else
			cout << "not sure" << endl;

	}


	return 0;
}
