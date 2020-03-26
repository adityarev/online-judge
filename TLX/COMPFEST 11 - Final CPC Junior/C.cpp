#include <algorithm>
#include <cstdio>
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

const int ALPH_SIZE = 26;

void
set_hash_count(
	int &n,
	std::vector<int> &hash_count
) {
	for (int i = 0; i < n; i++)
		hash_count[(int)(gc() - 'a')]++;
}

char
get_ans(std::vector<int> &hash_count, int &k) {
	int count = 0;
	
	for (int i = 0; i < ALPH_SIZE; i++) {
		count += hash_count[i];
		if (count >= k)
			return (char)('a' + i);
	}
	
	return '-';
}

int
main() {
	int n = fio.getnumb();
	int k = fio.getnumb();
	
	std::vector<int> hash_count(ALPH_SIZE, 0);
	set_hash_count(n, hash_count);
	
	char ans = get_ans(hash_count, k);
	pc(ans); endline;
	
	return 0;
}

