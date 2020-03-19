#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)

using namespace std;

int scanint() {
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc());
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return val;
}

void printint(int n) {
	if (n == 0)
		return;
	printint(n / 10);
	pc('0' + n % 10);
}

bool is_feasible(vector<int> &arr, int &dist, int &k) {
	int curr = arr[0];
	int count = 1;
	
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] - curr >= dist) {
			curr = arr[i];
			count++;
			
			if (count == k)
				return true;
		}
	}
	
	return false;
}

int largest_minimum_distance(vector<int> &arr, int &k) {
	sort(arr.begin(), arr.end());
	
	int n = arr.size();
	int l = arr[0];
	int r = arr[n - 1];
	int res = -1;
	
	while (l < r) {
		int dist = (l + r) >> 1;
		
		if (is_feasible(arr, dist, k)) {
			res = max(res, dist);
			l = dist + 1;
		} else {
			r = dist;
		}
	}
	
	return res;
}

int main()
{
	int tc = scanint();
	
	while (tc--) {
		int n = scanint();
		int k = scanint();
		
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			arr[i] = scanint();
		
		int ans = largest_minimum_distance(arr, k);
		printint(ans); pc('\n');
	}
	
	return 0;
}

