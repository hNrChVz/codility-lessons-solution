
/*

I have multiple solutions here, 3 to be exact. All are correct but 2 of them did not get 100%
because some test cases timed out. Note that I am only sharing the one that got a 100% score.

My approach here is setting a number to look for in A. When found, get the next number to look
for in B.

Time complexity: O(N)

*/

#include <vector>

using namespace std;

int solution(int X, vector<int>& A) {
	int N = A.size();
	vector<bool> B(X, false);
	int num = 1; //first trick, start the number to look for with 1

	//go through A
	for (int i = 0; i < N; i++) {
		int index = A[i] - 1;
		B[index] = true;

		//if the number we are looking
		if (A[i] == num) {
			bool complete = true;

			//now get the next number to look for
			//the second trick, j = num
			//we do not have to check B[0]..B[num-1] because somewhere along, 
			//it has been found and set to true already
			for (int j = num; j < X; j++) {
				if (!B[j]) {
					num = j + 1;
					complete = false;
					break;
				}
			}

			if (complete) {
				return i;
			}
		}
	}

	return -1;
}