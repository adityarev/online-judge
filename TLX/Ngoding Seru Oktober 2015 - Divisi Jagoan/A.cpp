#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)

int
getint() {
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc());
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return val;
}

void
set_arr(std::vector<int> &arr) {
	for (int &x: arr)
		x = getint();
}

int
get_ans(std::vector<int> &arr, int &dist) {
	std::sort(arr.begin(), arr.end());
	
	int len = arr.size();
	int max_val = arr[len - 1];
	
	int max_move_dist = (dist / max_val) * max_val;
	int remain_dist = dist - max_move_dist;
	
	std::function<int()> get_last_move_dist = [&]() -> int {
		if (remain_dist > 0) {
			for (int &x: arr) {
				if (x >= remain_dist)
					return x;
			}
		}
		return 0;
	};
	
	int last_move_dist = get_last_move_dist();
	int ans = max_move_dist + last_move_dist;
	return ans;
}

int
main() {
	std::function<void()> run_case = [&]() -> void {
		int n = getint();
		int dist = getint();
		
		std::vector<int> arr(n);
		set_arr(arr);
		
		int ans = get_ans(arr, dist);
		printf("%d\n", ans);
	};
	
	int tc = getint();
	for (int i = 0; i < tc; i++)
		run_case();
	
	return 0;
}

