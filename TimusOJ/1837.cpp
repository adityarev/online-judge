#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <vector>

void
create_team(std::vector<std::string> &members) {
	const int n_member = 3;
	
	for (int i = 0; i < n_member; i++) {
		std::string member;
		std::cin >> member;
		
		members.push_back(member);
	}
}

void
mark_team(
	std::map<std::string, std::vector<std::string> > &team_mates,
	std::vector<std::string> &members
) {
	auto contains = [&](std::string &highlighted, std::string &member) -> bool {
		std::vector<std::string> *vec = &team_mates[highlighted];
		auto it = std::find(vec->begin(), vec->end(), member);
		
		return (it != vec->end());
	};
	
	int n = members.size();
	
	for (int i = 0; i < n; i++) {
		std::string highlighted = members[i];
		
		for (std::string member: members) {
			if (member != highlighted) {
				if (!contains(highlighted, member))
					team_mates[highlighted].push_back(member);
			}
		}
	}
}

void
set_team_mates(std::map<std::string, std::vector<std::string> > &team_mates) {
	int n_team;
	std::cin >> n_team;
	
	for (int i = 0; i < n_team; i++) {
		std::vector<std::string> members;
		create_team(members);
		
		mark_team(team_mates, members);
	}
}

std::map<std::string,int>
get_ans(
	std::string root,
	std::map<std::string, std::vector<std::string> > &team_mates
) {
	std::map<std::string,int> ans;
	std::map<std::string,bool> taken;
	
	if (team_mates.find(root) != team_mates.end()) {
		std::list<std::pair<std::string,int> > que;
		
		que.push_back(std::make_pair(root, 0));
		taken[root] = true;
		
		while (!que.empty()) {
			std::pair<std::string,int> curr = que.front();
			que.pop_front();
			
			std::string key = curr.first;
			int val = curr.second;
			
			ans[key] = val;
			for (std::string mate: team_mates[key]) {
				if (!taken[mate]) {
					que.push_back(std::make_pair(mate, val + 1));
					taken[mate] = true;
				}
			}
		}
	}
	
	// Set undefined ans
	for (auto it = team_mates.begin(); it != team_mates.end(); it++) {
		std::string key = it->first;
		
		if (!taken[key]) {
			ans[key] = -1;
			taken[key] = true;
		}
	}
	
	return ans;
}

void
show_ans(std::map<std::string,int> &ans) {
	for (auto it = ans.begin(); it != ans.end(); it++) {
		std::string key = it->first;
		int val = it->second;
		
		if (val != -1)
			std::cout << key << " " << val << std::endl;
		else
			std::cout << key << " undefined" << std::endl;
	}
}

int
main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL);
	
	std::map<std::string, std::vector<std::string> > team_mates;
	set_team_mates(team_mates);
	
	const std::string root = "Isenbaev";
	
	std::map<std::string,int> ans = get_ans(root, team_mates);
	show_ans(ans);
	
	return 0;
}

