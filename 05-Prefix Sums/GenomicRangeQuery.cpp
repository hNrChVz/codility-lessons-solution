/*
create a unordered_map of these:
A = 1
C = 2
G = 3
T = 4

convert S to its impact factor

S = C A G C C T A
I = 2 1 3 2 2 4 1

int getMinImpactFactor(vector<int> I, int startIdx, int endIdx)

Time Complexity: O(N*M)
Score: 62% (due to timeout)

Solution 2:
It took me a while, to figure out how to use prefix sums to solve this problem.

Going back to the problem, we only need to get the minimal, or the smallest in the slice.
So in the given slice, we need to check if there's A, then C, then G, then T. With that, 
why not make a set of arrays, derived from S, contaning only A, then only C, only G and only T.
Do a prefix of sum for each, then compare P[n] and Q[n], to each set, starting with A, then C, so 
on and so forth, if Q[n] > P[n], it means that nucleotide, is present.
With the given example:
from:
S[] = C A G C C T A

we will have:
A[] = 0 A 0 0 0 0 A
C[] = C 0 0 C C 0 0
G[] = 0 0 G 0 0 0 0
T[] = 0 0 0 0 0 T 0

Change it to its impact factor value (or you can just 0s or 1s) then compute it prefix sums:
Aps[] = 0 0 1 1 1 1 1 2
Cps[] = 0 2 2 2 4 6 6 6
Gps[] = 0 0 0 3 3 3 3 3
Tps[] = 0 0 0 0 0 0 4 4

Check with our given P and Q
	P[0] = 2    Q[0] = 4
check with A: Aps[5] > Aps[2] = 1 > 1 = false (we do not have A)
check with C: Cps[5] > Cps[2] = 6 > 2 = true (we have C, return 2)
NOTE: we do not need to check the rest of set since we are only looking for the minimal impact factor

	P[1] = 5    Q[1] = 5
Aps[6] > Aps[5] = 1 > 1 = false
Cps[6] > Cps[5] = 6 > 6 = false
Gps[6] > Gps[5] = 3 > 3 = false
Tps[6] > Tps[5] = 4 > 0 = true (we have T, return 4)

	P[2] = 0    Q[2] = 6
Aps[7] > Aps[0] = 2 > 0 = true (we have A, return 1)

Time Complexity: O(N+M)
Score: 100%
*/

#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> factorValues({ {'A', 1}, {'C', 2}, {'G', 3}, {'T', 4} });

//you can use std::partial_sum instead of writing your own
vector<int> computePrefixSum(vector<int>& I) {
	int N = I.size();
	vector<int> P(N + 1, 0);

	for (int i = 1; i < (int)P.size(); i++) {
		P[i] = P[i - 1] + I[i - 1];
	}

	return P;
}

//get nucleotide then convert to its impact factor
vector<int> extractNucleotide(string& S, char nucleotide) {
	int N = S.length();
	vector<int> R(N, 0);

	for (int i = 0; i < N; i++) {
		if (S[i] == nucleotide) {
			R[i] = factorValues[nucleotide];
		}
	}

	return R;
}

vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {
	//computer each nucleotide's prefix sum
	vector<int> Z = extractNucleotide(S, 'A');
	vector<int> A = computePrefixSum(Z);

	Z = extractNucleotide(S, 'C');
	vector<int> C = computePrefixSum(Z);

	Z = extractNucleotide(S, 'G');
	vector<int> G = computePrefixSum(Z);

	Z = extractNucleotide(S, 'T');
	vector<int> T = computePrefixSum(Z);

	int M = P.size();
	vector<int> R(M, 0);
	for (int i = 0; i < M; i++) {
		int l = P[i], r = Q[i] + 1;
		if (A[r] > A[l]) {
			R[i] = factorValues['A'];
		}
		else if (C[r] > C[l]) {
			R[i] = factorValues['C'];
		}
		else if (G[r] > G[l]) {
			R[i] = factorValues['G'];
		}
		else if (T[r] > T[l]) {
			R[i] = factorValues['T'];
		}
	}

	return R;
}