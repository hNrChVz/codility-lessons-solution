/*

First step here is to get the value of the second half, sum of array from 1 to N; Time complexity = O(N-1):
for 1 to N {
	secondHalf += A[i];
}

Get the initial minimal difference:
firstHalf = A[0];
minDiff = |firstHalf - secondHalf|

Then iterate the array again, keep on adding the current element, giving us the first half and keep on
subtracting the current element from the second half until P, that's O(N-2):
for 1 to N-1 {
	firstHalf += A[i]
	secondHalf -= A[i]
	diff = |firstHalf - secondHalf|;
	minDiff = minimumOf(minDiff, diff)
}
Note: iteration is 1 to N-1 because 0 < P < N; minimum is P=1; maximum is P=N-1

Total Time Complexity: O(N)
Note: we omit the constant, see the time complexity reading material

*/

#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int>& A) {
	unsigned int i;
	unsigned int N = A.size();
	int secondHalf = 0;
	int firstHalf = A[0];

	//get the secondHalf
	for (i = 1; i < N; i++) {
		secondHalf += A[i];
	}

	int minDiff = abs(firstHalf - secondHalf); //absolute value

	//iterate again from 1 to N-1
	for (i = 1; i < N - 1; i++) {
		firstHalf += A[i]; //add the current element to our firstHalf
		secondHalf -= A[i]; //subract the current element to our secondHalf
		minDiff = min(minDiff, abs(firstHalf - secondHalf)); //get the minimal difference
	}

	return minDiff;
}