#include <algorithm>
#include <iostream>
#include <vector>

struct Edge {
	int src;
	int dest;
	int weight;
};

struct Subset {
	int parent;
	int rank;
};

class MST {
private:
	int V;
	int E;
	std::vector<Edge> edges;
	std::vector<Subset> subsets;
	int cost;
	std::vector<Edge> tree;
	
public:
	MST();
	MST(int V, int E);
	void add_edge(int src, int dest, int weight);
	void build();
	void reset(int V, int E);
	int get_cost();
	std::vector<Edge> get_tree();

private:
	int find_parent(int i);
	void unite(int x, int y);
};

int
main() {
	// Your code gose here
	
	return 0;
}

MST::MST() {
	reset(0, 0);
}

MST::MST(int V, int E) {
	reset(V, E);
}

void
MST::build() {
	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
		return a.weight < b.weight;
	});
	
	subsets = std::vector<Subset>(V);
	tree = std::vector<Edge>(V - 1);
	
	for (int v = 0; v < V; v++) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	
	int i = 0;
	int e = 0;
	
	while (e < (V - 1) && i < E) {
		Edge edge = edges[i++];
		
		int x = find_parent(edge.src);
		int y = find_parent(edge.dest);
		
		if (x != y) {
			tree[e++] = edge;
			unite(x, y);
			cost += edge.weight;
		}
	}
}

void
MST::reset(int V, int E) {
	this->V = V;
	this->E = E;
	(this->edges).clear();
	(this->subsets).clear();
	this->cost = 0;
	(this->tree).clear();
}

void
MST::add_edge(int src, int dest, int weight) {
	edges.push_back({src, dest, weight});
}

int
MST::find_parent(int i) {
	if (subsets[i].parent != i)
		subsets[i].parent = find_parent(subsets[i].parent);
	return subsets[i].parent;
}

void
MST::unite(int x, int y) {
	int xroot = find_parent(x);
	int yroot = find_parent(y);
	
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int
MST::get_cost() {
	return this->cost;
}

std::vector<Edge>
MST::get_tree() {
	return this->tree;
}

