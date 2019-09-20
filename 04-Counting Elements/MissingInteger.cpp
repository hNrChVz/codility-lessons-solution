/*
My initial solution here is to sort the input, then iterate to find the smallest missing positive integer, BUT
of course the lesson Counting Elements so we will use that approach.

My initial solution in case you're wondering:
int solution(vector<int> &A) {
	int missing = 1;

	//sort it first
	sort(A.begin(), A.end());

	//look for the missing number
	for (int i = 0; i < (int)A.size(); i++) {
		//ignore negative number
		if(A[i] > 0) {
			if (A[i] > missing) {
				return missing;
			} else if (A[i] == missing) {
			   missing++;
			}
		}
	}

	return missing;
}

Solution using counting elements:
Monitor all positive integer in A, flag it to B. Then just look for the smallest missing number (or index) in B.

Time Complexity: O(N) (But I think it should be O(N + M) since A and B can have different size)
*/

#include <vector>

using namespace std;

int solution(vector<int>& A) {
	vector<bool> B(1, false);

	for (int a : A) {
		//ignore negative numbers
		if (a > 0) {
			//resize B, if needed
			if (a > (int)B.size()) {
				B.resize(a);
			}

			B[a - 1] = true; //set a in B as found
		}
	}

	for (int i = 0; i < (int)B.size(); i++) {
		if (!B[i]) {
			return i + 1;
		}
	}

	//all is true
	return B.size() + 1;
}