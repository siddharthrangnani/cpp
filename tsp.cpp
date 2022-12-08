#include <iostream>
using namespace std;
const int n = 4;
const int MAX = 1000000;
int dist[n + 1][n + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },
	{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
	{ 0, 20, 25, 30, 0 },
};

int dp[n + 1][1 << (n + 1)];

int solve(int i, int mk)
{

	if (mk == ((1 << i) | 3))
		return dist[1][i];

	if (dp[i][mk] != 0)
		return dp[i][mk];

	int res = MAX; 


	for (int j = 1; j <= n; j++)
		if ((mk & (1 << j)) && j != i && j != 1)
			res = std::min(res, solve(j, mk & (~(1 << i)))
									+ dist[j][i]);
	return dp[i][mk] = res;
}

int main()
{
	int ans = MAX;
	for (int i = 1; i <= n; i++)
		
		ans = std::min(ans, solve(i, (1 << (n + 1)) - 1)
								+ dist[i][1]);

	printf("cost = %d", ans);

	return 0;
}


