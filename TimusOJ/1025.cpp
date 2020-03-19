#include <algorithm>
#include <iostream>
#include <vector>

void
set_n_voters(std::vector<int> &n_voters) {
	int n;
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		int n_voter;
		std::cin >> n_voter;
		
		n_voters.push_back(n_voter);
	}
}

int
get_ans(std::vector<int> &n_voters) {
	int ans = 0;
	int lim = (n_voters.size() + 1) / 2;
	
	for (int i = 0; i < lim; i++) {
		int n_voter = n_voters[i];
		int min_voter = (n_voter + 2) / 2;
		
		ans += min_voter;
	}
	
	return ans;
}

int
main() {
	std::vector<int> n_voters;
	set_n_voters(n_voters);
	
	std::sort(n_voters.begin(), n_voters.end());
	
	int ans = get_ans(n_voters);
	std::cout << ans << std::endl;
	
	return 0;
}

