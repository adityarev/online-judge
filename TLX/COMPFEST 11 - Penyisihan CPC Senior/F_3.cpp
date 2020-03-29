// ACCEPTED

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
		
		std::function<bool()> is_negative = [&]() -> bool {
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
	
	std::string
	getstr(bool line_scan = false) {
		std::function<bool(char&)> is_separator = [&](char &c) -> bool {
			return c == '\n' || (c == ' ' && !line_scan);
		};
		
		char c;
		std::string str = "";
		
		while ((c = gc()) && is_separator(c));
		do {
			str += c;
		} while ((c = gc()) && !is_separator(c));
		
		return str;
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
		printstr(suffix);
	}
	
	void
	printstr(std::string &str) {
		for (char &c: str)
			pc(c);
	}
} fio;

LL
get_ans(std::string &s, int &q) {
	std::function<int(char&)> c_hash = [&](char &c) {
		return (int)(c - 'A');
	};
	
	const int ALPH_SIZE = 26;
	std::vector<LL> counter(ALPH_SIZE, LL(0));
	
	std::function<void(std::string&, char)>
	set_counter = [&](
		std::string &str,
		char poc
	) -> void {
		LL prev = (poc != '\0' ? counter[c_hash(poc)] : 1LL);
		std::vector<int> hash_count(ALPH_SIZE, 0);
		
		for (char &c: str)
			hash_count[c_hash(c)]++;
		for (int i = 0; i < ALPH_SIZE; i++)
			counter[i] += (LL)hash_count[i] * prev;
		
		if (poc != '\0')
			counter[c_hash(poc)] -= prev;
	};
	
	std::function<void()> init_counter = [&]() -> void {
		set_counter(s, '\0');
	};
	
	std::function<void()> do_query = [&]() -> void {
		char c = fio.getstr()[0];
		std::string changer = fio.getstr();
		
		set_counter(changer, c);
	};
	
	init_counter();
	for (int i = 0; i < q; i++)
		do_query();
	
	LL ans = 0LL;
	
	for (LL &b: counter)
		ans += b;
	
	return ans;
}

int
main() {
	int n = fio.getnumb<int>();
	int q = fio.getnumb<int>();
	std::string s = fio.getstr();
	
	LL ans = get_ans(s, q);
	fio.printnumb<LL>(ans, "\n");
	
	return 0;
}

