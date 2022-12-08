#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int dp[13][10001];
vector<int> store_deno;
int greedy(int amt)
{
    int counter = 0;
    vector<int> den = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int den_size = den.size() - 1;
    for (int i = den_size; i >= 0; i--)
    {
        while (den[i] <= amt)
        {
            store_deno.push_back(den[i]);
            counter++;
            amt -= den[i];
        }
    }
    return counter;
}
int recur(int idx, vector<int> c, int amt)
{
    if (idx == 0)
    {
        return INT_MAX - 1;
    }
    if (amt <= 0)
    {
        return 0;
    }
    if (c[idx - 1] <= amt)
    {
        return min(1 + recur(idx, c, amt - c[idx - 1]), recur(idx - 1, c, amt));
    }
    else
    {
       return recur(idx - 1, c, amt);
    }
}

int memoization(int idx, vector<int> c, int amt)
{
    if (idx == 0)
    {
        return INT_MAX - 1;
    }
    if (amt <= 0)
    {
        return 0;
    }
    if (dp[idx][amt] != -1)
    {
        return dp[idx][amt];
    }

    if (c[idx - 1] <= amt)
    {
        return dp[idx][amt] = min(1 + memoization(idx, c, amt - c[idx - 1]), memoization(idx - 1, c, amt));
    }
    else
    {
        return dp[idx][amt] = memoization(idx - 1, c, amt);
    }
}
int main()
{
    cout << "************************************************************" << endl;
    cout << "COIN CHANGE PROBLEM" << endl;

    cout << "************************************************************" << endl;
    vector<int> coins;
    int n, a, amt, ans_memo = 0, ans_recur = 0;

    memset(dp, -1, sizeof(dp));
    start:
    cout << "Enter the Algo you would like to perform" << endl;
    cout << "1.Memoization" << endl
         << "2.Recursion" << endl
         << "3.Greedy" << endl
         <<"4. Exit"<<endl;
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        cout << "Enter No of coins" << endl;
        cin >> n;
        cout << "Enter the denomenation of coins" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            coins.push_back(a);
        }
        cout << "Enter Amount" << endl;
        cin >> amt;

        auto start_1 = high_resolution_clock::now();
        ans_memo = memoization(coins.size(), coins, amt);
        auto stop_1 = high_resolution_clock::now();
        auto duration_1 = duration_cast<microseconds>(stop_1 - start_1);
        if (ans_memo == INT_MAX - 1)
        {
            cout << "Cannot Able to form minimum number of coins" << endl;
        }
        else
        {
            cout << "The Number of Minimum coin Required is:-   " << ans_memo << endl;
            cout << "Time Required to Perform Memoization is   " << duration_1.count();
        }
    }
    break;
    case 2:
    {
        cout << "Enter No of coins" << endl;
        cin >> n;
        cout << "Enter the denomenation of coins" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            coins.push_back(a);
        }
        cout << "Enter Amount" << endl;
        cin >> amt;
        auto start_2 = high_resolution_clock::now();
        ans_recur = recur(coins.size(), coins, amt);
        auto stop_2 = high_resolution_clock::now();
        auto duration_2 = duration_cast<microseconds>(stop_2 - start_2);
        if (ans_recur == INT_MAX - 1)
        {
            cout << "Cannot Able to form minimum number of coins" << endl;
        }
        else
        {
            cout << "The Number of Minimum coin Required is:-  " << ans_recur << endl;
            cout << "Time Required to Perform Recursion is  " << duration_2.count();
        }
    }
    break;
    case 3:
    {
        int amt1 = 0;
        cout << "Enter the amount" << endl;
        cin >> amt1;
        auto start_2 = high_resolution_clock::now();
        cout << "Minimum Coins Required Are:-   " << greedy(amt1) << endl;
        auto stop_2 = high_resolution_clock::now();
        auto duration_2 = duration_cast<microseconds>(stop_2 - start_2);
        cout << "Denominations of coins are:-   " << endl;

        for (auto c : store_deno)
        {
            cout << c << " " << endl;
        }
        cout << "Time Required to Perform Greedy is  " << duration_2.count();
    }

    break;
    case 4:
    {
        break;
    }
    default:
        cout << "Choose Appropriate Option" << endl;
        goto start;
        break;
    }
}