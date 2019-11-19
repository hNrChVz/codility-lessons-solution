/*

Solution 01:
To be properly nested, the current close must matched latest open, example:
if I enountered ')' (close parenthesis), the most recent open must be '(', (open parenthesis)
I can use stack here. push all open parenthesis, brackets, and braces. When i see a close,
pop the one on top of my stack, then check if is it the matching open.
At the end, the stack must be empty.

I will use std::stack

Time complexity: O(N)
Score: 100%

*/

#include <string>
#include <stack>

using namespace std;

bool isNested(char openCh, char closeCh) {
	switch (openCh) {
	case '(':
		return (closeCh == ')');

	case '{':
		return (closeCh == '}');

	case '[':
		return (closeCh == ']');

	default:
		return false;
	}
}

int solution(string& S) {
	stack<char> openStack;

	for (int i = 0; i < (int)S.length(); i++) {
		if (S[i] == '(' || S[i] == '{' || S[i] == '[') {
			openStack.push(S[i]);
		}
		else if (S[i] == ')' || S[i] == '}' || S[i] == ']') {
			if (openStack.empty()) {
				return 0;
			}

			if (isNested(openStack.top(), S[i])) {
				openStack.pop();
			}
			else {
				return 0;
			}
		}
	}

	return openStack.empty();
}