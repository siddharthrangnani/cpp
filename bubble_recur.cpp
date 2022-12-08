#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &vi,int n)
{
    if(n==1) return;
    int cnt=0;
    for(int i=0;i<vi.size();i++)
    {
        if(vi[i]>vi[i+1])
        {
            swap(vi[i],vi[i+1]);
        }
    }
   
    solve(vi,n-1);
}
int main()
{
    int n=0,i=0,j=0;
cin>>n;
    vector<int> vi(n);
    for(int i=0;i<n;i++)
    {
        cin>>vi[i];
    }
    solve(vi,vi.size());
    cout<<"the answer is";
    for(auto it:vi)
    {
        cout<<it<<" ";
    }
 return 0;
}