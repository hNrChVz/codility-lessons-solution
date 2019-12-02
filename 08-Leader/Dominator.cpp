/*

Since it needs to return an index of the array, elements cannot be sorted.
Instead, use the approach describe in the lesson, eliminating a pair that is not equal,
and keeping track of the index. Note that we only need to return one of the indices 
of the "Dominator" value;

Score: 100%
Detected Time Complexity: O(n)
*/

#include <vector>

using namespace std;

int solution(vector<int>& A) {
	int size = 0;
	int val = -1;

	//pair elimination, keeping track pair occurences
	for (unsigned int i = 0; i < A.size(); i++) {
		if (size == 0) {
			val = A[i];
			size++;
		}
		else {
			if (A[i] != val) {
				size--;
			}
			else {
				size++;
			}
		}
	}

	if (size > 0) {
		/* check for a possible dominator; we will just return the last index of
		   the dominator */
		int count = 0;
		int idx = -1;
		for (unsigned int i = 0; i < A.size(); i++) {
			if (val == A[i]) {
				idx = i;
				count++;
			}
		}

		if (count > (int)A.size() / 2) {
			return idx;
		}
		else {
			return -1;
		}
	}
	else {
		return -1; //no dominator
	}
}