/*

We can use std::sort or std:stable_sort

We have to consider that a product of 2 negative numbers is a posistive number.
With that, after sorting, possible maximum product of three numbers can be;
the 3 largest numbers or the 2 smallest negative numbers and the largest number.

Time complexity: O(N*log(N))    <- we got this because of sorting
Score: 100%
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& A) {
	int N = A.size();
	sort(A.begin(), A.end());
	return max(A[0] * A[1] * A[N - 1], A[N - 1] * A[N - 2] * A[N - 3]);
}