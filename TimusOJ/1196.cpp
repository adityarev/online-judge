#include <iostream>
#include <map>

void
set_hash(std::map<int,int> &hash) {
	hash.clear();
	
	int n;
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		
		hash[x]++;
	}
}

int
get_ans(
	std::map<int,int> &prof_hash,
	std::map<int,int> &student_hash
) {
	int ans = 0;
	
	for (auto it = prof_hash.begin(); it != prof_hash.end(); it++) {
		int key = it->first;
		ans += student_hash[key];
	}
	
	return ans;
}

int
main() {
	std::map<int,int> prof_hash;
	set_hash(prof_hash);
	
	std::map<int,int> student_hash;
	set_hash(student_hash);
	
	int ans = get_ans(prof_hash, student_hash);
	std::cout << ans << std::endl;
	
	return 0;
}

