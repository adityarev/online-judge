#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)

typedef long long LL;

int
getint() {
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc());
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return val;
}

void
printint(int val) {
	if (val == 0LL)
		return;
	printint(val / 10);
	pc('0' + (val % 10));
}

vector<int>
numbers = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	153, 370, 371, 407,
	1634, 8208, 9474,
	54748, 92727, 93084,
	548834,
	1741725, 4210818, 9800817, 9926315,
	24678050, 24678051, 88593477,
	146511208, 472335975, 534494836, 912985153,
};

int
get_ans(int &val) {
	for (int num: numbers) {
		if (num >= val)
			return num;
	}
	
	return -1;
}

void
print_row(int case_num, int &ans) {
	printf("Case #%d: ", case_num);
	if (ans == 0)
		pc('0'), pc('\n');
	else
		printint(ans), pc('\n');
}

int
main() {
	int tc = getint();
	int countdown = tc;
	
	while (countdown--) {
		int val = getint();
		int ans = get_ans(val);
		
		print_row(tc - countdown, ans);
	}
	
	return 0;
}

