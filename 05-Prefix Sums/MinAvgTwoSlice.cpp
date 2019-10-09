/*

Solution 1:
The direct approach, compute the average of every possible combination, then return the start index
that has the lowest.

int solution(vector<int> &A) {
	int index = 0;
	int N = A.size();
	vector<int> P = computePrefixSum(A);

	double curMinAve = P[N] / N;
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			double ave = (P[j+1] - P[i]) / (j - i + 1.0);
			if (ave < curMinAve) {
				curMinAve = ave;
				index = i;
			}
		}
	}

	return index;
}

Time Complexity: O(N²)
Score: 60% (Correctness = 100% ; Performance = 20%)


 Solution 2:
 NOTE: failed on all negative numbers, still need a bit of tweaking

 Starting from 0, look for the index I where the average dropped.
 NOTE: average dropped means that the average is less than the smallest average

 Why? Because when the average dropped, it means that A[I-1] and/or A[I], are significantly small. 
 Hence, we can conclude that the average of A[I-1..I] is smaller from the previous averages, and I-1
 is our new smallest starting position. 
 
 Starting with I-1, look again where the average dropped, so on and so forth.
 
 With the given example: 
 A = [4, 2, 2, 5, 1, 5, 8]

 Initial values will be:
 smlPos = 0
 minAve = A[0..1]/2 = 3
 
 At A[0..2], I = 2, average dropped to 2.67, thus it will give us a new:
 smlPos = I - 1 = 2 - 1 = 1
 minAve = A[1..2]/2 = 2

 From A[1..3]..A[1..6], average didn't drop, so our smlPos = 2

 Another example:
 A = [5, 5, 10, 0, 1, -5, 10]

 Initial values:
 smlPos = 0
 minAve = A[0..1]/2 = 5

 There is an average dropped at I=4, A[0..4]/5 = 4.2, so:
 smlPos = 4-1 = 3
 minAve = A[3..4]/2 = 0.5

 Average dropped again at I=5, A[3..5]/3 = -1.33, so:
 smlPos = 5-1 = 4
 minAve = A[4..5]/2 = -2

 No more average dropped, result is smlPos = 4;

failed on [-3, -5, -8, -4, -10], expected 2, returned 3

int solution(vector<int>& A) {
	int N = A.size();
	vector<int> P = computePrefixSum(A);
	int smlPos = 0;
	double minAve = (double)P[2] / 2; //or (A[0] + A[1]) / 2

	for (int i = 2; i < N; i++) {
		double ave = (double)(P[i + 1] - P[smlPos]) / (i + 1 - smlPos);

		if (ave < minAve) {
			smlPos = i - 1;
			minAve = (double)(P[i + 1] - P[smlPos]) / (i + 1 - smlPos);
		}
	}

	return smlPos;
}

Solution 3:
DISCLAIMER: credits to the person/s who came up with this

Since you only need the starting position of the smallest average, you only need to check the average 
for 2-slice and 3-slice for each position. Doing that is enough to only get the position. Take note
that this approach do not get the actual smallest average, but rather get the position where is the smallest
2-slice or 3-slice average.

But the 4-slice average can be the smallest? TRUE, But:
Let say for position 0, it's smallest average is a slice of 4, A[0..3]. But the average of slice
A[1..2] or A[1..3] or A[2..3] or A[2..4] will be smaller than that, because value in position 1 and/or 2 and/or 3 are
significantly low to make the average dropped. Same applies with a bigger slice, a 2-slice or 3-slice is enough
to know if the position holds the smallest average.

This is based on the assumption that the average of a 2 or 3 part slice is <= to the average of its bigger slice.

Example:
 A = [10, 0, 1, -5]
 for position 0, the smallest average is 4-slice: A[0..3] / 4 = 1.5, but we do not really need to check that, because 
 we already have enough info on 2-slice and 3-slice, average of 5 and 3.67 respectively. Checking A[1..2] average, 
 A[1..2] / 2 = 0.5, we can safely assume position 0 do not hold the smallest average. As a I have mentioned above,
 position 1 and 2 and 3 are significantly small to make the average dropped.
 Answer to the sample abouve is position 2, smallest average is -2, A[2..3] / 2 = -2.

 even when you add another small number:
 A = [10, 0, 1, -5, -1]
 will give position 0's smallest average to 1; A[0..4] / 5 = 1;
 Again, the average slice of A[1..2], which is 0.5, is still smaller.
 Answer here is 3, A[3..4] / 2 = -3

 And of course, this problem does not require to use prefix sums either, but we will use it anyway.

 Time complexity: O(N)
 Score: 100%
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<int> computePrefixSum(vector<int>& I) {
	int N = I.size();
	vector<int> P(N + 1, 0);

	for (int i = 1; i < (int)P.size(); i++) {
		P[i] = P[i - 1] + I[i - 1];
	}

	return P;
}

double averagePrefixSlice(vector<int>& P, int startIndex, int numOfSlice) {
	//slice total = P[j+1] - P[i]
	//make sure our slice will not exceed P.size()
	int endIndex = min((int)P.size() - 1, startIndex + numOfSlice);
	return ((double)P[endIndex] - P[startIndex]) / ((double)endIndex - startIndex);
}

int solution(vector<int>& A) {
	int N = A.size();
	vector<int> P = computePrefixSum(A);
	int smlPos = 0;
	double smlAve = averagePrefixSlice(P, 0, N);

	for (int i = 0; i < N - 1; i++) {
		//get 2 and 3 slice
		double ave = min(averagePrefixSlice(P, i, 2), averagePrefixSlice(P, i, 3));

		if (ave < smlAve) {
			smlAve = ave;
			smlPos = i;
		}
	}

	return smlPos;
}
