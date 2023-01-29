// A C++ program to count the number of ways
// to reach n'th stair when user
// climb 1 .. m stairs at a time.
#include <iostream>
using namespace std;

// Returns number of ways
// to reach s'th stair
int countWays(int n, int m)
{
	int res[n + 1];
	int temp = 0;
	res[0] = 1;
	for (int i = 1; i <= n; i++) // to reach ith step
	{
		int s = i - m - 1; // window start // to remove
		int e = i - 1;     // window end   // to add
		if (s >= 0){ // when full window size is reached
			temp -= res[s]; // remove leftmost element from window each iteration
		}
		temp += res[e]; // add rightmost element to window each iteration
		res[i] = temp;  // temp has the sum of way from steps within window range
	}
	return res[n];
}

// Driver Code
int main()
{
	int n = 3, m = 2;
	cout << "Number of ways = "<< countWays(n, m);
	return 0;
}

