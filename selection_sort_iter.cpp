#include<bits/stdc++.h>
using namespace std;
int main()
{   int n=0,i=0,j=0;
cin>>n;

    vector<int> vi(n);
    for(int i=0;i<n;i++)
    {
        cin>>vi[i];
    }

    for( i=0;i<n;i++)
    {int min_idx=i;
        for(j=i+1;j<n;j++)
        {
            if(vi[j]<vi[min_idx])
            {
                min_idx=j;
            }
        }
            swap(vi[i],vi[min_idx]);

    }
    cout<<"Answer:";
    for(auto v:vi)
    {
        cout<<v<<" ";
    }
 return 0;
}