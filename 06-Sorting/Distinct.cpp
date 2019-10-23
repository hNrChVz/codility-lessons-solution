/*

Solution 01:
Direct approach, sort the data. Count how many distinct values.

Time Complexity: O(N*log(N))
Score: 100%
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& A) {
	int N = A.size();
	int distinct = 0;

	if (N > 0) {
		sort(A.begin(), A.end());
		int currVal = A[0];
		distinct++;

		for (int i = 1; i < N; i++) {
			if (currVal != A[i]) {
				distinct++;
				currVal = A[i];
			}
		}
	}

	return distinct;
}