/*

First we have to check if there is a leader, if none, then there is no equileader.
Once we have leader and its count, we can simply do a look-up.
To do a one pass look-up, split the leader count to a left and right (or 1st and 2nd) array,
as you go, increment left and decrement right leader count accordingly and 
incrementing equiLeader counter as required.

Score: 100%
Detected Time Complexity: O(N) -- should be O(N*logN) due to sorting
*/

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& A) {
	int N = A.size();

	//check if we have a leader and get its count
	vector<int> temp(A);
	sort(temp.begin(), temp.end());
	int leader = temp[N / 2]; //possible leader
	int leadCount = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] == leader) {
			leadCount++;
		}
	}
	if (leadCount <= N / 2) {
		return 0; //we do not have a leader, thus no equileader
	}

	//now count the equileaders
	int equiLeaders = 0;
	int leftCount = 0;
	int rightCount = leadCount;
	for (int S = 0; S < N - 1; S++) {
		if (A[S] == leader) {
			leftCount++;
			rightCount--;
		}

		//check for leader/equileader for each section
		if (leftCount > (S + 1) / 2 && rightCount > (N - (S + 1)) / 2) {
			equiLeaders++;
		}
	}

	return equiLeaders;
}