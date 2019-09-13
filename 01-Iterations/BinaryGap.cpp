#include <bitset>
#include <algorithm>

using namespace std;

/*
My first impression here is to have an array of binary representaion of N.
e.g.
N = 9 ; will have an array of { 1, 0, 0, 1 }

With that, I can use std::bitset, std::bitset<64> nBit (N);

NOTE:
N is from [1..2,147,483,647], so 32-bit long will suffice. I've used 64 to to be sure.

Now, I'll just to need iterate through each bit.

Time complexity: O(N)
*/

int solution(int N) {
	int binGap = 0;
	bitset<64> nBit(N);

	bool start = false; //flag telling me i have encountered 1, also acts as an end
	int gap = 0; //current gap size holder

	for (unsigned int i = 0; i < nBit.size(); i++) {
		if (start) {
			//start counting
			if (nBit[i] == 1) {
				//it reached the end of the current gap
				binGap = max(binGap, gap);
				gap = 0;
			}
			else {
				gap++;
			}
		}
		else {
			if (nBit[i] == 1) {
				start = true;
			}
		}
	}

	return binGap;
}
