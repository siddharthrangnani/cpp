#include<bits/stdc++.h>
using namespace std;
void sorter(vector<int> &arr,int beg,int end,int mid)
{
int n1=end-beg+1;
int n2=mid-end;
int a1[n1],a2[n2];
for(int i=0;i<n1;i++)
{
    a1[i]=arr[beg+i];
}
for(int i=0;i<n1;i++)
{
    a2[i]=arr[end+i+1];
}
 int i, j, k;
  i = 0;
  j = 0;
  k = beg;
  while (i < n1 && j < n2) {
    if (a1[i] <= a2[j]) {
      arr[k] = a1[i];
      i++;
    } else {
      arr[k] = a2[j];
      j++;
    }
    k++;
  }
   while (i < n1) {
    arr[k] = a1[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = a2[j];
    j++;
    k++;
  }
}


void merge(vector<int> &ip,int beg,int end)
{
    int mid=(beg+end)/2;
    if(beg>end)
    {
        return;
    }
    merge(ip,beg,mid);
    merge(ip,mid+1,beg);
    sorter(ip,beg,mid,end);

}
int main()
{
    int n=0;
    cout<<"Enter the size of array";
    cin>>n;
    vector<int> ip(n);
    cout<<"Enter elements";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ip.push_back(x);
    }
int beg=0;
int end=ip.size()-1;

merge(ip,beg,end);    
for(auto X:ip)
{
    cout<<X<<endl;
}
 return 0;
}