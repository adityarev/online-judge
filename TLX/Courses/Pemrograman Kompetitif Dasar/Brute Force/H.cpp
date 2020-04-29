#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

void
set_arr(vector<int>& arr) {
	for (int& x: arr)
		cin >> x;
	sort(arr.begin(), arr.end());
}

vector<int>
create_borders(
	vector<bool>& flags,
	int& max_size
) {
	int n = (int)flags.size();
	int curr = 0;
	vector<int> borders;
	
	for (int i = 0; i < n; i++) {
		curr += max_size;
		if (!flags[i])
			curr--;
		borders.push_back(curr);
	}
	
	return borders;
}

bool
is_valid_borders(
	vector<int>& borders,
	vector<int>& arr
) {
	for (int& border: borders) {
		if (border > 0 && arr[border] == arr[border - 1])
			return false;
	}
	return true;
}

vector<int>
get_filtered_arr(
	vector<int>& arr,
	vector<int>& indices
) {
	vector<int> filtered_arr;
	
	for (int& index: indices)
		filtered_arr.push_back(arr[index]);
	return filtered_arr;
}

vector<int>
get_ans(
	vector<int>& arr,
	int& k
) {
	int n = (int)arr.size();
	int max_size = (int)ceil((double)n / (double)k);
	
	int big_count = (n % k == 0 ? k : (n % k));
	int small_count = k - big_count;
	vector<bool> flags;
	
	bool found = false;
	vector<int> ans;
	
	function<void(int)>
	_dfs = [&](int len) -> void {
		if (!found && len == k - 1) {
			vector<int> borders = create_borders(flags, max_size);
			
			if (is_valid_borders(borders, arr)) {
				ans = get_filtered_arr(arr, borders);
				found = true;
			}
			
			return;
		}
		
		function<void(bool,int&)>
		_trace = [&](bool value, int& counter) -> void {
			flags.push_back(value);
			counter--;
			_dfs(len + 1);
			counter++;
			flags.pop_back();
		};
		
		if (!found) {
			if (big_count > 0)
				_trace(true, big_count);
			if (small_count > 0)
				_trace(false, small_count);
		}
	};
	_dfs(0);
	
	return ans;
}

void
show_arr(vector<int>& arr) {
	int n = (int)arr.size();
	
	for (int i = 0; i < n; i++)
		cout << arr[i] << (i == n - 1 ? "\n" : " ");
}

int
main() {
	int n;
	cin >> n;
	
	vector<int> arr(n);
	set_arr(arr);
	
	int k;
	cin >> k;
	
	vector<int> ans = get_ans(arr, k);
	show_arr(ans);
	
	return 0;
}

