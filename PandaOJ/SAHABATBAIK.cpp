#include <cstdio>
#include <cstring>

#define MAX 1005

using namespace std;

bool has_group[MAX];
int leader[MAX];

int findLeader(int i, int root) {
	leader[i] = (leader[i] == root) ?
					i : findLeader(leader[i], root);
	has_group[i] = true;
	
	return leader[i];
}

void createGroup(int N) {	
	memset(has_group, false, sizeof(has_group));
	
	for (int i = 1; i <= N; i++) {
		if (!has_group[i]) {
			leader[i] = findLeader(i, i);
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	
	memset(leader, 0, sizeof(leader));
	for (int i = 1; i <= N; i++) {
		scanf("%d", &leader[i]);
	}
	createGroup(N);
	
	int Q;
	scanf("%d\n", &Q);
	
	while (Q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		
		printf("%sapat diketahui\n", leader[a] == leader[b] ? "D" : "Tidak d");
	}
	
	return 0;
}
