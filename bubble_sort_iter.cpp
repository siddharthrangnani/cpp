#include<bits/stdc++.h>
using namespace std;
int main()
{int n=0,i=0,j=0;
cin>>n;
    vector<int> vi(n);
    for(int i=0;i<n;i++)
    {
        cin>>vi[i];
    }

    for( i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
           if(vi[j]>vi[j+1])
           {
                swap(vi[j],vi[j+1]);
           }
        }
            
    }
    cout<<"Answer:";
    for(auto v:vi)
    {
        cout<<v<<" ";
    }
 return 0;
}