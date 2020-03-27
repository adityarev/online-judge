#include <algorithm>
#include <cstdio>
#include <climits>
#include <functional>
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

template <typename T> void
set_arr(std::vector<T> &arr) {
	for (int i = 1; i < arr.size(); i++) {
		T x = fio.getnumb<T>();
		arr[i] = arr[i - 1] + x;
	}
}

LL
get_ans(std::vector<LL> &arr, int &k) {
	int l = 0;
	int r = k + 1;
	
	LL ans = LLONG_MIN;
	while (r < arr.size()) {
		ans = std::max(ans, arr[r] - arr[l]);
		l++;
		r++;
	}
	
	return ans;
}

int
main() {
	int n = fio.getnumb<int>();
	int k = fio.getnumb<int>();
	
	std::vector<LL> arr(n + 1, 0LL);
	set_arr<LL>(arr);
	
	LL ans = get_ans(arr, k);
	fio.printnumb<LL>(ans, "\n");
	
	return 0;
}

