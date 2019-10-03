/*
*** THE LESSON: PREFIX SUM ***

A = [5 6 8 10 5 2 99 7 5 34]

n = size of A

create prefix of sums: that will be an array P with size n+1

		a0			a1				a2					...		an−1	
p0 =0	p1 = a0		p2 = a0 +a1		p3 = a0 +a1 +a2		...		pn = a0 +a1 +...+an−1

P = [0 5 11 19 29 34 36 135 142 147 181]

P[k] = P[k-1] + A[k-1]
e.g.
P[2] = P[2-1] + A[2-1]
P[2] = P[1] + A[1]
P[2] = 5 + 6
p[2] = 11

to get a slice total using prefix sums [x..y] use:
P[y+1] - P[x]

e.g.
slice of A[3..7]
A[3..7] = 10 + 5 + 2 + 99 + 7
A[3..7] = 123

A[3..7] = P[y+1] - P[x]
x = 3; y = 7

A[3..7] = P[8] - P[x]
A[3..7] = 142 - 19
A[3..7] = 123
*/

/*
Getting all pairs of [0,1] will give you a time complexity of O(N²).

Looking at it, you only need to find a 0, then count how many 1 after that, so on and so forth.
Using prefix sums, we can easily do that by [x..N-1] slice, where x is an index with 0 values.
With the given example A = [0, 1, 0, 1, 1], its prefix sums is S = [0, 0, 1, 1, 2, 3].
There are two 0s at A indexed 0 and 2, thus giving us:
A[0..4] + A[2..4]
(S[5] - S[0]) + (S[5] - S[2])
(3 - 0) + (3 - 1)
3 + 2
5 passing cars

Time complexity: O(N)

NOTE: you can also use std::partial_sum, you just need to adjust the index:
A[x..y] = P[y] - P[x-1] where 0 < x <= y < N

*/

#include <vector>

using namespace std;

int solution(vector<int>& A) {
	int N = A.size();
	int count = 0;

	//computer prefix sums
	vector<int> S(N + 1, 0);
	for (int i = 1; i < (int)S.size(); i++) {
		S[i] = S[i - 1] + A[i - 1];
	}

	//get all index with 0 value
	for (int x = 0; x < N; x++) {
		if (A[x] == 0) {
			//get [x..N-1]
			count = count + (S[N] - S[x]);
			if (count > 1000000000) {
				return -1;
			}
		}
	}

	return count;
}