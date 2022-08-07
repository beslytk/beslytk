// C++ program to count number of ways to reach Nth stair
#include <bits/stdc++.h>
using namespace std;

// A simple recursive program to find N'th fibonacci number
int countWaysUtil(int n, int dp[])
{
	if (n <= 1)
		return dp[n] = 1;

	if (dp[n] != -1) {
		return dp[n];
	}
	dp[n] = countWaysUtil(n - 1, dp) + countWaysUtil(n - 2, dp); // recursion
	return dp[n];
}

// Returns number of ways to reach s'th stair
int countWays(int n)
{
	int dp[n + 1];
	memset(dp, -1, sizeof dp);
	countWaysUtil(n, dp);
	return dp[n];
}

int main()
{
	int n = 3;
	cout << "Number of ways = " << countWays(n);
	return 0;
}
