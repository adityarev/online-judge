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
//	int V;
	vector<vector<pair<double,int> > > adj;
	vector<double> dist;
public :
	Graph(int V) {
//		this->V = V;
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
	
	~Graph() {
		adj.clear();
		dist.clear();
	}
};

int main()
{
	int n, m, d;
	while (scanf("%d%d%d", &n, &m, &d)==3)
	{
		if (!n&&!m&&!d) continue;
		Graph spring(n);
		
		while (m--) {
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			double w_ratio = (double)1/w;
			spring.addEdge(a,b,(double)w_ratio);
			spring.addEdge(b,a,(double)w_ratio);
		}
		double result = spring.dijkstra(0,n-1);
		double Fmax = d/result;
		if (Fmax<0.0) Fmax = 0.0;
		printf ("%.2lf\n", Fmax);
	}
	return 0;
}
