/*

NOTE: I think the challenge here is a solution using prefix sums 

Solution 1:
Time complexity: O(1)
Score: 100%

*/

int solution(int A, int B, int K) {
	int ret = (B / K) - (A / K);
	if (A % K == 0) {
		ret++; //to include A in the count
	}
	return ret;
}