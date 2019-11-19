/*

Not sure why it is painless, it took me a quite sometime.

With the exception of the first height, everytime a height increases, a block will be "open".
when the height decreases, "open" a new one and all the previous "open" blocks that is 
greater than the current will be "closed", thus making a whole block.

with the example:
  H[0] = 8    H[1] = 8    H[2] = 5
  H[3] = 7    H[4] = 9    H[5] = 8
  H[6] = 7    H[7] = 4    H[8] = 8

  H[0] "open" a block
  H[1] same height, do nothing
  H[2] the height decrease, so "close" H[1], thus making a block. "open" a new one
  H[3] increases, "open"
  H[4] increases, "open"
  H[5] decrease, "close" all "open" that is greater than the current value, "close" H[4], making a block, "open" a new one
  H[6] decrease, "close" H[5], we do not have to open a new as the latest open has height 7 too
  H[7] decrease, "close H[3] and H[2], open new one.
  H[8] increase, "open", since it is the last one, "close" all "open" blocks, "close" H[7] and H[8]

And giving us a total of 7 blocks

I think it is still best to use stack as we need to compare it with the previous height.
whenever a height increases, we push that height.
whenever a height decreases, pop all heights that is greater than the current height, each pop is a block, and then
push the current height. after reaching the last, pop all remaining values in th stack.

Score: 100%
Detected Time Complexity: O(N);

*/

#include <vector>
#include <stack>

using namespace std;

int solution(vector<int>& H) {
	stack<int> openBlocks;
	openBlocks.push(H[0]);
	int blocks = 0;

	for (unsigned int i = 0; i < H.size(); ++i) {
		int prevH = openBlocks.top();

		while (H[i] < prevH) {
			//close a block
			openBlocks.pop();
			blocks++;

			if (openBlocks.empty()) {
				break;
			}

			prevH = openBlocks.top();
		}

		if (H[i] != prevH) {
			openBlocks.push(H[i]);
		}
	}

	//return all closed blocks + an openBlocks that needed closing
	return blocks + openBlocks.size();
}