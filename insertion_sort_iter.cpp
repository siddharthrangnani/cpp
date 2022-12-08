#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int ip;
    cin >> n;
    vector<int> vi;
    for (int i = 0; i < n; i++)
    {
        cin >> ip;
        vi.push_back(ip);
    }
    for(int i=1;i<vi.size();i++)
    {
        int key=vi[i];
        int j=i-1;
        while(key<=vi[i] and j>=0)
        {
            vi[j+1]=vi[j];
            j--;
        }
    vi[j+1]=key;
    }
for(auto it:vi)
{
    cout<<it;
}
    return 0;
}