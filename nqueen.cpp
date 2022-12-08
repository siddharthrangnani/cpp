#include<bits/stdc++.h>
using namespace std;
 void solve(int col,vector<string> &ans,vector<vector<string>> &res,vector<int> &leftrows ,vector<int> &upperrow,vector<int> &lowerrow,int n)
 {
        if(col==n)
        {
            res.push_back(ans);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftrows[row]==0 && upperrow[n-1+col-row]==0 && lowerrow[row+col]==0)
            {
                
            
        ans[row][col]='Q';
        leftrows[row]=1;
        upperrow[n-1+col-row]=1;
        lowerrow[row+col]=1;
        solve(col+1,ans,res,leftrows,upperrow,lowerrow,n);
        ans[row][col]='.';
        leftrows[row]=0;
        upperrow[n-1+col-row]=0;
        lowerrow[row+col]=0;
            }
        }

    }
  
int main()
{
  int  n=4;
vector<vector<string>> res;
        vector<string> ans(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            ans[i]=s;
        }
       
        vector<int> leftrows(n,0) ,upperrow(2*n-1,0),lowerrow(2*n-1,0);
        solve(0,ans,res,leftrows,upperrow,lowerrow,n);
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res.size();j++)
            
                cout<<res[i][j];;
            
            cout<<endl;
        }
 return 0;
}