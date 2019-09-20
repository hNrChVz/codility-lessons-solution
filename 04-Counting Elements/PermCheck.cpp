
/*
Note: we can use the solution at Time Complexity - PermMissingElement. BUT, the lesson
is about Counting Elements, so will use that approach.

We need a container or array, B, to flag or monitor the values that is in A.
As we iterate through A, we check each against B. Note: B is just a flagger that the number is present in A.
e.g.
A[0] = 5 we set B[5-1] = true
This will tell us that if B[4] == true, 5 is present in A. 
B[0] == true, 1 is present in A.
B[1] == true, 2 is present in A so on and so forth.

Also, we do NOT have to look for the missing number in the permutation. We just need to watch out
for any duplicate number or value > N.

Time Complexity: O(N)

*/

#include <vector>

using namespace std;

int solution(vector<int>& A) {
	int N = A.size();
	vector<bool> B(N, 0);

	for (int i = 0; i < N; i++) {
		int value = A[i];

		if (value > N) {
			//valid numbers are 1..N; not a permutation
			return 0;
		}

		if (B[value - 1]) {
			//we have a duplicate number; not a permutation
			return 0;
		}

		B[value - 1] = true;
	}

	return 1;
}