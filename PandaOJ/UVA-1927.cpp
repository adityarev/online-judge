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
	vector<vector<pair<int,int> > > adj;
	vector<int> dist;
public :
	Graph(int V) {
		this->V = V;
		for (int i=0; i<V+2; i++) {
			adj.push_back(vector<pair<int,int> >());
			dist.push_back(oo);
		}
	}
	
	void addEdge (int v, int w, int dist) {
		adj[v].push_back(make_pair(dist,w));
	}
	
	int dijkstra (int from, int to) {
		priority_queue <pair <int, int>, vector <pair <int, int> >, greater<pair <int,int> > > que;
		dist[from] = 0.0;
		que.push(make_pair(0.0, from));
		
		while (!que.empty()) {
			pair <int, int> curr = que.top();
			que.pop();
			
			int ftemp = curr.first;
			int stemp = curr.second;
			if (stemp == to) return dist[to];
			int adj_size = adj[stemp].size();
			for (int i=0; i<adj_size; i++) {
				int cost = adj[stemp][i].first;
				int next = adj[stemp][i].second;
				if (cost+ftemp < dist[next]) {
					dist[next] = cost+ftemp;
					que.push(make_pair(dist[next],next));
				}
			}
		}
		return -1;
	}
};

int main()
{
	int tc, ct = 1;
	scanf("%d", &tc);
	
	while (tc--)
	{
		int V, E, from, to;
		scanf("%d%d%d%d", &V, &E, &from, &to);
		
		Graph *myPath = new Graph(V);
		int a, b, w;
		
		while (E--) {
			scanf("%d%d%d", &a, &b, &w);
			myPath->addEdge(a, b, w);
			myPath->addEdge(b, a, w);
		}
		
		int dist = myPath->dijkstra(from, to);
		if (dist != -1)
			printf ("Case #%d: %d\n", ct++, dist);
		else
			printf ("Case #%d: unreachable\n", ct++);
	}
	
	return 0;
}
