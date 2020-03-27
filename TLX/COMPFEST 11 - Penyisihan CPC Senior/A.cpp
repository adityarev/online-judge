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

struct Range {
	int l;
	int r;
};

void
set_arr(std::vector<struct Range> &arr) {
	for (struct Range &range: arr) {
		range.l = fio.getnumb<int>();
		range.r = fio.getnumb<int>();
	}
}

LL
get_ans(std::vector<struct Range> &arr) {
	std::function<bool(const struct Range&, const struct Range&)>
	comp = [&](const struct Range &a, const struct Range &b) -> bool {
		return a.l == b.l ? a.r < b.r : a.l < b.l;
	};
	std::sort(arr.begin(), arr.end(), comp);
	
	int i = 0;
	int j = 0;
	LL ans = 0LL;
	
	while (j < arr.size()) {
		LL a = (LL)arr[i].l;
		LL un = (LL)arr[i].r;
		
		while (j + 1 < arr.size()) {
			if (a <= arr[j + 1].l && arr[j + 1].l <= un) {
				j++;
				a = std::min(a, (LL)arr[j].l);
				un = std::max(un, (LL)arr[j].r);
				
				continue;
			}
			
			break;
		}
		
		LL n = un - a + 1LL;
		
		ans += (n * (a + un)) >> 1;
		i = j + 1;
		j = i;
	}
	
	return ans;
}

int
main() {
	int n = fio.getnumb<int>();
	
	std::vector<struct Range> arr(n);
	set_arr(arr);
	
	LL ans = get_ans(arr);
	fio.printnumb<LL>(ans, "\n");
	
	return 0;
}

