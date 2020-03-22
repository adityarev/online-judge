#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

enum {
	UNIDENTIFIED = -1,
	ZERO = 0,
	NEGATIVE,
	POSITIVE
};

enum {
	FIRST = 0,
	SECOND,
	THIRD
};

struct Group {
	int id;
	std::vector<int> values;
	
	Group() {
		this->id = UNIDENTIFIED;
		this->values = std::vector<int>();
	}
	
	Group(int id, std::vector<int> &values) {
		this->id = id;
		this->values = values;
	}
};

std::vector<int> get_filtered_array(std::vector<int>&, const int);
void set_arr(std::vector<int>&);
std::vector<int> get_ans(std::vector<int>&);
void show_ans(std::vector<int>&);

int
main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	std::function<void()> run_case = [&]() -> void {
		std::vector<int> arr;
		set_arr(arr);
		
		std::vector<int> ans = get_ans(arr);
		show_ans(ans);
	};
	
	int tc;
	std::cin >> tc;
	
	for (int i = 0; i < tc; i++)
		run_case();
	
	return 0;
}

std::vector<int>
get_filtered_array(
	std::vector<int> &arr,
	const int sign
) {
	std::function<bool(int)> valid = [&](int val) -> bool {
		switch(sign) {
			case NEGATIVE:
				return val < 0;
			case ZERO:
				return val == 0;
			case POSITIVE:
				return val > 0;
			default:
				break;
		}
		return true;
	};
	
	std::vector<int> filtered_arr;
	for (int &val: arr) {
		if (valid(val))
			filtered_arr.push_back(val);
	}
	
	return filtered_arr;
}

void
set_arr(std::vector<int> &arr) {
	int n;
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		arr.push_back(x);
	}
}

std::vector<int>
get_ans(std::vector<int> &arr) {
	int arr_len = (int)arr.size();
	int half_len = arr_len / 2;
	
	std::function<std::vector<int>(std::vector<int>&, std::vector<int>&)>
	concate = [&](std::vector<int> &odd, std::vector<int> &even) -> std::vector<int> {
		int lim = std::max((int)odd.size(), (int)even.size());
		std::vector<int> result;
		
		for (int i = 0; i < lim; i++) {
			if (i < (int)odd.size())
				result.push_back(odd[i]);
			if (i < even.size())
				result.push_back(even[i]);
		}
		
		return result; 
	};
	
	std::vector<int> ans;
	
	if (arr.size() <= 2) {
		ans = arr;
	} else {
		std::vector<int> zeros = get_filtered_array(arr, ZERO);
		std::vector<int> negatives = get_filtered_array(arr, NEGATIVE);
		std::vector<int> positives = get_filtered_array(arr, POSITIVE);
		
		if (zeros.size() >= half_len) {
			std::vector<int> pos_neg_arr = positives;
			pos_neg_arr.insert(pos_neg_arr.end(), negatives.begin(), negatives.end());
			
			ans = concate(pos_neg_arr, zeros);
		} else {
			struct Group zero_group = Group(ZERO, zeros);
			struct Group negative_group = Group(NEGATIVE, negatives);
			struct Group positive_group = Group(POSITIVE, positives);
			
			std::function<bool(const struct Group&, const struct Group&)>
			comp = [&](const struct Group &a, const struct Group &b) -> bool {
				return a.values.size() == b.values.size() ? a.id < b.id
					: a.values.size() > b.values.size();
			};
			
			std::vector<struct Group> groups = {zero_group, negative_group, positive_group};
			sort(groups.begin(), groups.end(), comp);
			
			if (groups[FIRST].values.size() == arr_len) {
				ans = groups[FIRST].values;
			} else {
				if (groups[THIRD].id == ZERO) {
					if (groups[THIRD].values.size() == 0) {
						if ((groups[FIRST].values.size() - groups[SECOND].values.size()) <= 1) {
							ans = concate(groups[FIRST].values, groups[SECOND].values);
						} else {
							// Impossible
						}
					} else {
						// Impossible
					}
				} else {
					// Impossible
				}
			}
		}
	}
	
	return ans;
}

void
show_ans(std::vector<int> &ans) {
	if (ans.size() == 0) {
		std::cout << "mustahil" << std::endl;
		return;
	}
	
	bool first = true;
	for (int &x: ans) {
		if (first)
			first = false;
		else
			std::cout << " ";
		std::cout << x;
	}
	std::cout << std::endl;
}

