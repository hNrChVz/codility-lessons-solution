#include <vector>

using namespace std;

/*
new index position formula: 

newIndex = (currentIndex + K) % A.size();

*/

vector<int> solution(vector<int>& A, int K) {
	vector<int> B(A); //copy A to B

	for (unsigned int i = 0; i < A.size(); i++) {
		int newIdx = (i + K) % A.size();
		B[newIdx] = A[i];
	}

	return B;
}