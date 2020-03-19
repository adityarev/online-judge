#include <iostream>
#include <queue>
#include <vector>

void
run_input(std::vector<int> &arr) {
	int n;
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		arr.push_back(x);
	}
}

void
create_ans(
	std::vector<std::pair<int,int> > &ans,
	std::vector<int> &arr
) {
	int i = 0;
	do {
		int count = 0;
		int val = arr[i];
		
		while (i < arr.size() && arr[i] == val) {
			count++;
			i++;
		}
		
		std::pair<int,int> cv = std::make_pair(count, val);
		ans.push_back(cv);
		
	} while (i < arr.size());
}

void
show_ans(std::vector<std::pair<int,int> > &ans) {
	bool first = true;
	for (std::pair<int,int> cv: ans) {
		if (first)
			first = false;
		else
			std::cout << " ";
		std::cout << cv.first << " " << cv.second;
	}
	std::cout << std::endl;
}

int
main() {
	std::vector<int> arr;
	run_input(arr);
	
	std::vector<std::pair<int,int> > ans;
	create_ans(ans, arr);
	
	show_ans(ans);
	
	return 0;
}

