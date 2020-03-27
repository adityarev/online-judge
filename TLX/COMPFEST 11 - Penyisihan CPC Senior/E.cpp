#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)
#define endline pc('\n')

typedef long long LL;

struct FastIO {
	template <typename T> T
	getnumb() {
		T c = gc();
		
		std::function<T()> is_negative = [&]() -> T {
			for (; c < '0' || c > '9'; c = gc()) {
				if (c == '-') {
					c = gc();
					if (c >= '0' && c <= '9')
						return true;
				}
			}
			return false;
		};
		
		bool negative = is_negative();
		T val = 0;
		
		for (; c >= '0' && c <= '9'; c = gc())
			val = (val << 1) + (val << 3) + c - (T)'0';
		
		return negative ? -val : val;
	}
	
	template <typename T> void
	printnumb(T val, std::string suffix = "") {
		if (val == 0) {
			pc('0');
			return;
		}
		if (val < 0) {
			pc('-');
			val = -val;
		}
		
		std::function<void(T)> _print = [&](T x) -> void {
			if (x == 0)
				return;
			
			_print(x / 10);
			pc('0' + (x % 10));
		};
		
		_print(val);
		for (char &c: suffix)
			pc(c);
	}
} fio;

void
set_arr(std::vector<int> &arr) {
	for (int &x: arr)
		x = fio.getnumb<int>();
}

std::string
get_ans(std::vector<int> &arr, int &k) {
	std::sort(arr.begin(), arr.end());
	
	for (int i = 1; i < arr.size(); i += 2)
		if ((arr[i] - arr[i - 1]) > k)
			return "Tidak";
	
	return "Ya";
}


int
main() {
	int n = fio.getnumb<int>();
	int k = fio.getnumb<int>();
	
	std::vector<int> arr(2 * n);
	set_arr(arr);
	
	std::string ans = get_ans(arr, k);
	std::cout << ans << std::endl;
	
	return 0;
}

