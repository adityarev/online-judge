#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iterator>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>

#define gc(x) getchar(x)
#define pc(x) putchar(x)
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
			return c == '\n' || (c == ' ' && !line_scan) || c == EOF;
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
		std::function<void(T)> _print = [&](T x) -> void {
			if (x == 0)
				return;
			
			_print(x / 10);
			pc('0' + (x % 10));
		};
		
		if (val != 0) {
			if (val < 0) {
				pc('-');
				val = -val;
			}
			_print(val);
		} else {
			pc('0');
		}
		printstr(suffix);
	}
	
	void
	printstr(std::string &str) {
		for (char &c: str)
			pc(c);
	}
} fio;


struct Plate {
	int number;
	LL price;
};

struct Stock {
	int number;
	LL count;
};

struct Answer {
	LL len;
	std::string first50;
	std::string last50;
};

void
set_plates(std::vector<Plate>& plates, int& n) {
	for (int i = 0; i <= n; i++) {
		int price = fio.getnumb<LL>();
		plates.push_back({i, price});
	}
	std::reverse(plates.begin(), plates.end());
}

void
set_stocks(
	std::vector<Stock>& stocks,
	std::vector<Plate>& plates,
	LL money
) {
	for (Plate& plate: plates) {
		if (money >= plate.price) {
			LL count = (plate.price == 0 ? (LL)INT_MAX : (money / plate.price));
			
			stocks.push_back({plate.number, count});
			money -= count * plate.price;
		}
	}
}

Answer
get_ans(
	std::vector<Plate>& plates,
	LL& money
) {
	std::vector<Stock> stocks;
	set_stocks(stocks, plates, money);
	
	LL counter;
	int sz = (int)stocks.size();
	
	if (sz == 0)
		return {0, "", ""};
	if (sz == 1 && stocks[0].number == 0)
		return {1, "0", "0"};
	
	std::function<std::string(char,int)>
	_repeated_char = [&](char c, int len) -> std::string {
		std::string str = "";
		while (len--)
			str += c;
		return str;
	};
	
	LL len = 0LL;
	
	for (Stock& stock: stocks)
		len += stock.count;
	
	std::string first50 = "";
	counter = 50LL;
	
	for (int i = 0; i < sz; i++) {
		if (counter == 0LL)
			break;
		
		Stock stock = stocks[i];
		LL freq = std::min(counter, stock.count);
		
		first50 = first50 + _repeated_char(('0' + stock.number), (int)freq);
		counter -= freq;
	}
	
	std::string last50 = "";
	counter = 50LL;
	
	for (int i = sz - 1; i >= 0; i--) {
		if (counter == 0LL)
			break;
		
		Stock stock = stocks[i];
		LL freq = std::min(counter, stock.count);
		
		last50 = _repeated_char(('0' + stock.number), (int)freq) + last50;
		counter -= freq;
	}
	
	return {len, first50, last50};
}

int
main() {
	int n = fio.getnumb<int>();
	
	std::vector<Plate> plates;
	set_plates(plates, n);
	
	LL money = fio.getnumb<LL>();
	Answer ans = get_ans(plates, money);
	
	fio.printnumb<LL>(ans.len, "\n");
	if (ans.len != 0) {
		fio.printstr(ans.first50); endline;
		fio.printstr(ans.last50); endline;
	}
	
	return 0;
}

