#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

std::vector<std::vector<std::string> >
cs_names = {
	{
		"Alice", "Ariel", "Aurora",
		"Phil", "Peter", "Olaf",
		"Phoebus", "Ralph", "Robin",
	},
	{
		"Bambi", "Belle", "Bolt",
		"Mulan", "Mowgli", "Mickey",
		"Silver", "Simba", "Stitch",
	},
	{
		"Dumbo", "Genie", "Jiminy",
		"Kuzko", "Kida", "Kenai",
		"Tarzan", "Tiana", "Winnie",
	}
};

std::map<std::string,int> pos;

void
init_pos() {
	for (int i = 0; i < cs_names.size(); i++) {
		for (std::string name: cs_names[i]) {
			pos[name] = i;
		}
	}
}

int
count_steps(std::vector<std::string> &names) {
	int curr = 0;
	int count = 0;
	
	for (std::string name: names) {
		count += abs(curr - pos[name]);
		curr = pos[name];
	}
	
	return count;
}

int
main() {
	init_pos();
	
	int n;
	std::cin >> n;
	
	std::vector<std::string> names;
	
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		
		names.push_back(s);
	}
	
	int ans = count_steps(names);
	std::cout << ans << std::endl;
	
	return 0;
}
