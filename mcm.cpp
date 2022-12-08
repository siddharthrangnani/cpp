
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];


int memoization(int* p, int i, int j)
{
	if (i == j)
	{
		return 0;
	}
	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	dp[i][j] = INT_MAX;
	for (int k = i; k < j; k++)
	{
		dp[i][j] = min(
			dp[i][j], memoization(p, i, k)
					+ memoization(p, k + 1, j)
					+ p[i - 1] * p[k] * p[j]);
	}
	return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
	int i = 1, j = n - 1;
	return memoization(p, i, j);
}

int main()
{
	int arr[] = { 10,30,5,60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(dp, -1, sizeof dp);

	cout << "Answer "
		<< MatrixChainOrder(arr, n);
}


