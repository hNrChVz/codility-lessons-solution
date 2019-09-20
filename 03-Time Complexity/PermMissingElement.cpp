#include <algorithm>
#include <vector>

using namespace std;

/*
Again, my trick here is to sort first, then iterate looking for the missing number;
*/

int solution(vector<int>& A) {
	int missing = A.size() + 1;

	//sort it first
	sort(A.begin(), A.end());

	//look for the missing number
	for (int i = 0; i < (int)A.size(); i++) {
		if (A[i] != i + 1) {
			return (i + 1);
		}
	}

	return missing;
}