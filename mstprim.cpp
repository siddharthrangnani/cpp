#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int, int>> adj[], int u,
             int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
int main()
{

    vector<int> vis(6, 0);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int sum=0;

    int V = 6;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 3);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 0, 3, 4);
    addEdge(adj, 1, 0, 3);
    addEdge(adj, 1, 3, 5);
    addEdge(adj, 1, 4, 3);
    addEdge(adj, 2, 0, 1);
    addEdge(adj, 2, 3, 5);
    addEdge(adj, 3, 2, 5);
    addEdge(adj, 3, 5, 6);
    addEdge(adj, 3, 1, 5);
    addEdge(adj, 3, 0, 4);
    addEdge(adj, 4, 1, 3);
    addEdge(adj, 4, 5, 2);
    addEdge(adj, 5, 2, 3);
    addEdge(adj, 5, 3, 6);
    addEdge(adj, 5, 4, 2);
    pq.push({0,0});
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int wt=it.first;
        if(vis[node]==1) continue;
        vis[node]=1;
        sum+=wt;
        for(auto it: adj[node])
        {
            int anode=it.first;
            int ed=it.second; //edge weight
            if(!vis[anode])
            {
                pq.push({ed,anode});
            }
        }
    }
    cout<<"Total sum of weight is"<<sum<<endl;
    return 0;
}