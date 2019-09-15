#include <vector>
#include <algorithm>

using namespace std;

/*
My trick here, assuming that all the assumptions are always true, is that sort the array first:

std::sort (A.begin(), A.end());

After sorting, iterate until it finds an unmatched pair.

Time complexity: O(N)

NOTE: (trust that) std:sort will use the best sorting algorithm

*/

int solution(vector<int>& A) {
	sort(A.begin(), A.end());

	for (unsigned int i = 0; i < A.size(); i += 2) {
		if (A[i] != A[i + 1]) {
			return A[i];
		}
	}

	return -1;
}