
/*
My initial solution here is using vector::assign, but one of the test case timed out by 0.004s:
(running time: 0.104 sec., time limit: 0.100 sec.)

So what I did was, rather than assigning maxCounter to my vector (or array), I just saved it, prevMax.
Then just update other element in the output as we iterate through A.

Time Complexity: O(N+M)
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int>& A) {
	vector<int> B(N, 0);
	int prevMax = 0, maxCounter = 0;

	for (int a : A) {
		if (a == N + 1) {
			//just saved the maxCounter
			prevMax = maxCounter;
		}
		else {
			//check first if we already assign prevMax, 
			//if no then update its value first before increasing it by 1
			//if it's < prevMax, it means we have not assign prevMax yet
			//using max(a, b) will give the same result
			B[a - 1] = max(B[a - 1], prevMax) + 1;
			maxCounter = max(maxCounter, B[a - 1]); //update maxCounter;
		}
	}

	//make sure that we have assign prevMax to all element in our output
	for (int i = 0; i < N; i++) {
		if (B[i] < prevMax) {
			B[i] = prevMax;
		}
	}

	return B;
}