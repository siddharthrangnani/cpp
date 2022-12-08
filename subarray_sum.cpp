#include<bits/stdc++.h>
using namespace std;
int max(int a, int b, int c) { return max(max(a, b), c); }


int solve1(vector<int> arr, int l, int m, int h)
{

    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
 
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
 
    return max(left_sum + right_sum - arr[m], left_sum, right_sum);
}
int solve(vector<int> &arr,int l , int r)
{
      if(l==r) return arr[l];
    if(l>r) return INT_MIN;
    int mid=(l+r)/2;
    return max(solve(arr,l,mid-1),solve(arr,mid+1,r),solve(arr,l,r));
  
}
int main()
{
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l=0,r=arr.size();
    
    int ans=solve(arr,l,r);
    cout<<ans;

 return 0;
} 