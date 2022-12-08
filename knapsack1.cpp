// To Implement Knapsack problem based Greedy Algorithm, Dynamic
// Programming and Branch and Bound Method
#include <bits/stdc++.h>
using namespace std;

int solve(int idx, int bwt, vector<int> wt, vector<int> val)
{
  if(wt==0 || idx==0)
  {
    return 0;
  }
    if (dp[wt][bwt] != -1)
    {
        return dp[wt][bwt];
    }
    if (wt[idx] <= bwt)
    {
        dp[wt][bwt] = min(val[idx - 1] + solve(idx - 1, bwt - wt[idx], wt, val), solve(idx - 1, bwt, wt, val));
    }
    else
    {
        solve(idx - 1, bwt, wt, val);
    }
    return dp[wt][bwt];
}
int main()

{
    vector<int> wt = {10, 20, 30}, val = {60, 100, 120};
    int bwt = 50;
    vector<vector<int>> dp(bwt + 1, vector<int>(3 + 1, -1));
    cout << solve();

    return 0;
}