#include <algorithm>
#include <cstdio>
#include <list>
#include <queue>

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)

using namespace std;

struct Paint {
	int start;
	int end;
	int value;
	int priority;
};

bool comp (struct Paint &a, struct Paint &b) {
	return a.start == b.start ? a.priority > b.priority : a.start < b.start;
}

const int MAX = 200005;

int color[MAX];
struct Paint paint[MAX];

int scanint() {
	int c = getchar(), x = 0;
	for (;c<48||c>57; c=getchar());
	for (;c>47&&c<58; c=getchar()) x = (x<<1)+(x<<3)+c-48;
	return x;
}

void printint(int x) {
	if (x == 0) {
		return;
	}
	
	printint(x / 10);
	putchar('0' + (x % 10));
}

int main()
{
	int n = scanint();
	int que = scanint();
	
	// Run input
	for (int i = 0; i < que; i++) {
		paint[i].start = scanint() - 1;
		paint[i].end = scanint();
		paint[i].value = scanint();
		paint[i].priority = i;
	}
	
	// Run coloring
	int curr = 0;
	
	sort(paint, paint + que, comp);
	for (int i = 0; i < que; i++) {
		int next_start = paint[i].start;
		int limit;
		
		curr = max(curr, next_start);
		
		if (i != que - 1) {
			limit = min(paint[i].end, paint[i + 1].start);
		} else {
			limit = paint[i].end;
		}
		
		while (curr < limit) {
			color[curr] = paint[i].value;
			curr++;
		}
	}
	
	// Show color
	for (int i = 0; i < n; i++) {
		if (color[i] == 0) {
			puts("0");
		} else {
			printint(color[i]); putchar('\n');
		}
	}
	
	return 0;
}

