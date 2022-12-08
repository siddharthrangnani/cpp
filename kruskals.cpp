#include <bits/stdc++.h>
using namespace std;


class DSU {
	int* ulp;
	int* rank;

public:
	DSU(int n)
	{
		ulp = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++) {
			ulp[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i)
	{
		if (ulp[i] == -1)
			return i;

		return ulp[i] = find(ulp[i]);
	}

	// Union function
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				ulp[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				ulp[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};

class Graph {
	vector<vector<int> > edgelist;
	int V;

public:
	Graph(int V) { this->V = V; }

	void addEdge(int x, int y, int w)
	{
		edgelist.push_back({ w, x, y });
	}

	void kruskals_mst()
	{
		sort(edgelist.begin(), edgelist.end());

		DSU s(V);
		int ans = 0;
		cout << "Following are the edges in the "
				"constructed MST"
			<< endl;
		for (auto edge : edgelist) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			if (s.find(x) != s.find(y)) {
				s.unite(x, y);
				ans += w;
				cout << x << " <---> " << y << " == " << w
					<< endl;
			}
		}

		cout << "Minimum Cost Spanning Tree: " << ans;
	}
};

int main()
{
	Graph g(6);
	g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 4);
    g.addEdge(1, 0, 3);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 5, 6);
    g.addEdge(3, 1, 5);
    g.addEdge(3, 0, 4);
    g.addEdge(4, 1, 3);
    g.addEdge(4, 5, 2);
    g.addEdge(5, 2, 3);
    g.addEdge(5, 3, 6);
    g.addEdge(5, 4, 2);

	g.kruskals_mst();
	return 0;
}
