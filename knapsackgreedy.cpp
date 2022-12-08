

#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
	double r1 = (double)a.first / (double)a.second;
	double r2 = (double)b.first / (double)b.second;
return r1 > r2;
}
double fractionalKnapsack(int W, vector<pair<int,int>> arr, int N)
{
	sort(arr.begin(),arr.end(),sortbysec);

	double finalvalue = 0.0;

	for (int i = 0; i < N; i++) {
		
		if (arr[i].second <= W) {
			W -= arr[i].second;
			finalvalue += arr[i].first;
		}

		else {
			finalvalue
				+= arr[i].first
				* ((double)W / (double)arr[i].second);
			break;
		}
	}

	return finalvalue;
}

int main()
{
	int W = 50;
//	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
   vector<pair<int,int>> arr;
   arr.push_back({60,10});
   arr.push_back({100,20});
   arr.push_back({120,30});
	int N = arr.size();


	cout << fractionalKnapsack(W, arr, N);
	return 0;
}
