/*
	index = center; value = radius

				point of intersection
  A[0] = 1		         -1 0 1
  A[1] = 5      -4 -3 -2 -1 0 1 2 3 4 5 6
  A[2] = 2		            0 1 2 3 4
  A[3] = 1		                2 3 4
  A[4] = 4                  0 1 2 3 4 5 6 7 8
  A[5] = 0                            5

  left edge  = index - radius
  right edge = index + radius 

  Looking at disc 1, A[0], we can easily tell that there are 3 discs intersecting it because
  the left edges of those discs are <= the right edge of disc A[0]. We can do the same with other
  discs and it will give us:
  
  disc   intersections
  1 =		3
  2 =		4
  3 =		2
  4 =		1
  5 =		1
  6 =		0
  Total =	11 intersections

  Solution 01:
  Direct approach. Using the observation above, check each disc and count how many other discs intersected with it.

	for (long i = 0; i < N; i++) {
		for (long j = i + 1; j < N; j++) {
			if (i + A[i] >= j - A[j]) {
				discIntersections++;
			}

			if (discIntersections > 10000000) {
				return -1;
			}
		}
	}

Time Complexity: O(N^2)
Score: 81% (100% correctness and 62% performance)

Solution 02:
Now we know our observation is correct, now we just need to optimize the performance. Here comes sorting.
We get each discs left and right edges, then sort them separately. Then we check every right edges against
left edges, for left edge <= right edge. But remember, we sort both separately, pairing are now unordered.
To handle that, we need to remove the left edge of the current right edge and the other left edges
that has been counted already from the intersections count, thus:
	intersections = count - 1 - i //i = current index of right edge

But still the time complexity is O(N^2). To reduce this, since left edges are sorted, we can do a binary search.

Sorted left and right edges:
 left  = [-4, -1, 0, 0, 2, 5]
 right = [ 1,  4, 4, 5, 6, 8]
 
Time Complexity: O(N^2) //this was codility detected, not sure why
Score: 81% (100% correctness and 62% performance) // our binary search only reduce the execution time by 0.2s, still not enough

Solution 03:
We can use std::upper_bound instead of my binary search.

Time complexity: O(N*log(N)) or O(N)
Score: 100% //finally!!!

NOTE: std::upper_bound is basically a binary search, my binary search needs optimizing.
*/

//NOTE: we are using long to handle arithmetic overflow
#include <vector>
#include <algorithm>

using namespace std;

//this is the binary search
//this will search the first index in L, where v < L[index]
//int countintersections(vector<long> l, long v) {
//	int idx = 0;
//	int start = 0, end = l.size() - 1;
//
//	while (start <= end) {
//		idx = (start + end) / 2;
//		if (l[idx] <= v) {
//			start = idx + 1;
//		}
//		else if (l[idx] > v) {
//			end = idx - 1;
//		}
//	}
//
//	return start;
//}

int solution(vector<int>& A) {
	int N = A.size(), totalIntersections = 0;

	//get our left and right edges, sort it after
	//use long to handle arithmetic overflow
	vector<long> rightEdges(N), leftEdges(N);
	for (int i = 0; i < N; i++) {
		leftEdges[i] = (long)i - A[i];
		rightEdges[i] = (long)i + A[i];
	}
	sort(leftEdges.begin(), leftEdges.end());
	sort(rightEdges.begin(), rightEdges.end());

	//now we count the intersections
	for (int i = 0; i < N; i++) {
		int intersections = upper_bound(leftEdges.begin(), leftEdges.end(), rightEdges[i]) - leftEdges.begin();

		totalIntersections += intersections - 1 - i;

		if (totalIntersections > 10000000) {
			return -1;
		}
	}

	return totalIntersections;
}