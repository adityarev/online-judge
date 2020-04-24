#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <climits>

#define oo INT_MAX
typedef long long LL;
using namespace std;

class Graph {
	int V;
	vector<vector<pair<double,int> > > adj;
	vector<double> dist;
public :
	Graph(int V) {
		this->V = V;
		for (int i=0; i<V+2; i++) {
			adj.push_back(vector<pair<double,int> >());
			dist.push_back(oo);
		}
	}
	
	void addEdge (int v, int w, double dist) {
		adj[v].push_back(make_pair(dist,w));
	}
	
	double dijkstra (int from, int to) {
		priority_queue <pair <double, int>, vector <pair <double, int> >, greater<pair <double,int> > > que;
		dist[from] = 0.0;
		que.push(make_pair(0.0, from));
		
		while (!que.empty()) {
			pair <double, int> curr = que.top();
			que.pop();
			
			double ftemp = curr.first;
			int stemp = curr.second;
			if (stemp == to) return dist[to];
			int adj_size = adj[stemp].size();
			for (int i=0; i<adj_size; i++) {
				double cost = adj[stemp][i].first;
				int next = adj[stemp][i].second;
				if (cost+ftemp < dist[next]) {
					dist[next] = cost+ftemp;
					que.push(make_pair(dist[next],next));
				}
			}
		}
		return -1.0;
	}
};

int main()
{
	int tc;
	
	cin >> tc;
	while (tc--)
	{
		int n, m, a, b, dist;
		cin >> n >> m;
		
		Graph graf(n+2);
		while (m--) {
			cin >> a >> b >> dist;
			graf.addEdge(a,b,(double)dist);
		}
		
		cin >> a >> b;
		double res = graf.dijkstra(a,b);
		if (res == -1.0) puts("NO");
		else printf ("%.0lf\n", res);
	}
	
	return 0;
}
