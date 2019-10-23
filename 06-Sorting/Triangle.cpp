/*

The trick is given by the lesson, sorting. We only need to know if there is a triangle
in the given set (not the positions).

Once sorted, check the triangle conditions.
From the example:
  A[0] = 10    A[1] = 2    A[2] = 5  A[3] = 1     A[4] = 8    A[5] = 20
after sorting:
1 2 5 8 10 20 
1 + 2 > 5 is false, next three
2 + 5 > 8 is false, next three
5 + 8 > 10 is true, check the rest
5 + 10 > 8 is true
8 + 10 > 5 is true
we have a triangle

Note: the numbers are sorted so if the first check is false, the next numbers are false as well
because the rest of the number are greater than the current numbers. 
Example
1 + 2 > 5 is false, next numbers will all be > 5, so the condition will still be false
1 + 2 > 8 is false
1 + 2 > 10 is false
1 + 2 > 20 is false
That's why if the conditions failed, check the next 3 numbers straight away

Time complexity: O(N*log(N))
Score: 100%

NOTE: notice on my isTriangle(), i use long (or long int), that is to handle arithmetic overflow.
One of the test cases have 3 MAXINTs
*/

#include <vector>
#include <algorithm>

using namespace std;

bool isTriangle(long x, long y, long z) {
	return (x + y > z) && (x + z > y) && (y + z > x);
}

int solution(vector<int>& A) {
	int N = A.size();
	sort(A.begin(), A.end());

	for (int i = 0; i <= N - 3; i++) {
		if (isTriangle(A[i], A[i + 1], A[i + 2])) {
			return 1;
		}
	}

	return 0;
}