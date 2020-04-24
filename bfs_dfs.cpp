#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

typedef long long LL;
using namespace std;

class Graph {
	int V;
	list<int> *adj;
public :
	Graph(int V) {
		this->V = V;
		adj = new list<int>[V];
	}
	
	addEdge (int v, int w) {
		adj[v].push_back(w);
	}
	
	BFS(int root) {
		printf ("BFS :");
		bool *visited = new bool [V];
		for (int i=0; i<V; i++)
			visited[i] = false;
		
		list<int> queue;
		visited[root] = true;
		queue.push_back(root);
		
		list<int>::iterator it;
		while (!queue.empty()) {
			int curr = queue.front();
			cout << " " << curr;
			queue.pop_front();
			
			for (it = adj[curr].begin(); it != adj[curr].end(); it++) {
				if (!visited[*it]) {
					visited[*it] = true;
					queue.push_back(*it);
				}
			}
		}
		puts("");
	}
	
	DFS (int root) {
		
	}
};


int main()
{
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
	return 0;
}
