#include <bits/stdc++.h>
using namespace std;
int dp(int idx, int weight, vector<int> wt, vector<int> val)
{

    if (idx == 0 or weight == 0)
    {
        return 0;
    }
    if (wt[idx - 1] < weight)
    {
        return max(val[idx] + dp(idx - 1, weight - wt[idx], wt, val), dp(idx - 1, weight, wt, val));
    }
    else
    {
        return dp(idx - 1, weight, wt, val);
    }
    
}

int main()
{
    vector<int> wt = {1, 2, 3};
    vector<int> val = {6, 10, 12};
    int weight = 5;
    cout << dp(wt.size() - 1, weight, wt, val);
}