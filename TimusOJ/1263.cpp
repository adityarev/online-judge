#include <cstdio>
#include <vector>

int
main() {
	int n_candidate, n_voter;
	scanf("%d %d", &n_candidate, &n_voter);
	
	std::vector<int> count(n_candidate + 1, 0);
	
	for (int i = 0; i < n_voter; i++) {
		int vote;
		scanf("%d", &vote);
		
		count[vote]++;
	}
	
	for (int i = 1; i <= n_candidate; i++) {
		double percentage = ((double)count[i] / (double)n_voter) * 100.00;
		printf("%.2lf%%\n", percentage);
	}
	
	return 0;
}
