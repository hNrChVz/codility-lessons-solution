/*

Solution 01:
Direct approach using stack. In here I'll have a stack of alive fish(es).
Every fish encountered, check it against the top of the stack.
Repeat the checking until the top fish cannot be eaten or the current fish was eaten or 
there no more fish left to eat:

top fish was eaten; remove it from the stack, check the next fish in the stack
fish cannot eat each other: add the current fish into the stack
current fish was eaten by the top fish: no changes in the stack

With this approach, worst case is that the last fish can eat all the fishes in the stack,
giving us a time complexity of O(N^2)

Score: 100%
Detected Time Complexity: O(N)
*/

#include <vector>
#include <stack>

using namespace std;

int solution(vector<int>& A, vector<int>& B) {
	stack<int> fish;

	for (unsigned int i = 0; i < A.size(); i++) {
		bool isAlive = true;

		while (!fish.empty()) {
			int topIdx = fish.top();
			if (B[topIdx] == 1 && B[i] == 0) {
				if (A[topIdx] < A[i]) {
					fish.pop(); //fish on topstack was eaten
				}
				else {
					isAlive = false; //current fish was eaten
					break;
				}
			}
			else {
				break; //fishes will not meet
			}
		}

		if (isAlive) {
			fish.push(i);
		}
	}

	return fish.size();
}