#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int n;
	scanf ("%d",&n);
	
	pair<int,int> curr;
	priority_queue <pair<int,int> > pq;
	
	int x;
	for (int i=0; i<n; i++) {
		scanf ("%d", &x);
		pq.push(make_pair(-x,i+1));
	}
	
	while (!pq.empty()) {
		curr = pq.top();
		pq.pop();
		printf ("%d%c", curr.second, !pq.empty()?' ':'\n');
	}
	
	return 0;
}

