#include <algorithm>
#include <cstdio>
#include <climits>
#include <functional>
#include <vector>

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)
#define endline pc('\n')

struct FastIO {
	int
	getnumb() {
		int c = gc();
		int val = 0;
		
		for (; c < 48 || c > 57; c = gc());
		for (; c > 47 && c < 58; c = gc())
			val = (val << 1) + (val << 3) + c - 48;
		
		return val;
	}
	
	void
	printnumb(int val) {
		if (val == 0) {
			pc('0'); endline;
			return;
		}
		
		std::function<void(int)> _print = [&](int x) -> void {
			if (x == 0)
				return;
			
			_print(x / 10);
			pc('0' + (x % 10));
		};
		
		_print(val); endline;
	}
} fio;

void
set_arr(std::vector<int> &arr) {
	for (int &x: arr)
		x = fio.getnumb();
}

int
get_ans(std::vector<int> &arr, int &k) {
	if (k == 1)
		return 0;
	std::sort(arr.begin(), arr.end());
	
	int ans = INT_MAX;
	int l = 0;
	int r = k - 1;
	
	while (r < arr.size()) {
		ans = std::min(ans, arr[r] - arr[l]);
		l++;
		r++;
	}
	
	return ans;
}

int
main() {
	int n = fio.getnumb();
	int k = fio.getnumb();
	
	std::vector<int> arr(n);
	set_arr(arr);
	
	int ans = get_ans(arr, k);
	fio.printnumb(ans);
	
	return 0;
}

