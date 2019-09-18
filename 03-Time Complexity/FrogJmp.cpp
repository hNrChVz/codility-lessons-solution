/*
I use this formula:

n = number of jumps

X + (D*n) >= Y
X + (D*n) = Y  //remove >, will take care of it later
D*n = Y - X;
n = (Y - X) / D
n += ((Y - X) % D == 0 ? 0 : 1)  //coz jump can be > Y

e.g.
n = (85 - 10) / 30
n = 75 / 30
n = n + (75 % 30 == 0 ? 0 : 1) //since we have > and jump can exceed Y, add 1 if there's a remainder

Time complexity: O(1)
*/

int solution(int X, int Y, int D) {
	int distance = Y - X; //distance to jump
	int numJumps = distance / D;
	numJumps += (distance % D == 0 ? 0 : 1); //add 1 if there is remainder
	return numJumps;
}