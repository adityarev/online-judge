#include <algorithm>
#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int> > arr;

void
run_input() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::vector<int> row;
		
		for (int j = 0; j < N; j++) {
			int x;
			std::cin >> x;
			
			row.push_back(x);
		}
		arr.push_back(row);
	}
}

bool
is_in_range(int val) {
	return (0 <= val && val < N);
}

std::vector<int>
get_diagonal_numbers(int i, int j) {
	std::vector<int> numbers;
	
	while (is_in_range(i) && is_in_range(j)) {
		numbers.push_back(arr[i][j]);
		i--;
		j++;
	}
	
	return numbers;
}

std::vector<int>
get_ans() {
	int i = 0;
	int j = 0;
	
	std::vector<int> ans;
	bool move_down = true;
	
	while (true) {
		std::vector<int> diagonals = get_diagonal_numbers(i, j);
		ans.insert(ans.end(), diagonals.begin(), diagonals.end());
		
		i += (int)(move_down);
		j += (int)(!move_down);
		
		if (move_down && i == N) {
			move_down = false;
			j++;
		}
		if (j == N)
			break;
		
		i = std::min(N - 1, i);
		j = std::min(N - 1, j);
	} 
	
	return ans;
}

void
show_ans(std::vector<int> &ans) {
	bool first = true;
	
	for (int num: ans) {
		if (first)
			first = false;
		else
			std::cout << " ";
		std::cout << num;
	}
	std::cout << std::endl;
}

int
main() {
	run_input();
	
	std::vector<int> ans = get_ans();
	show_ans(ans);
	
	return 0;
}

