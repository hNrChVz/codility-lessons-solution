/*
This is basically the same as Lesson 07 - Stacks and Queues, Brackets,
except you only need to check for open and close parenthesis, '(' and ')'

Score: 100%
Detected Time Complexity: O(N)
*/

#include <string>
#include <stack>

using namespace std;

int solution(string& S) {
	stack<char> P;

	for (unsigned int i = 0; i < S.length(); i++) {
		if (S[i] == '(') {
			P.push('(');
		}
		else if (S[i] == ')') {
			if (!P.empty()) {
				P.pop();
			}
			else {
				return 0;
			}
		}
	}

	return P.empty() ? 1 : 0;
}