#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

map<pair<int,int>, bool> stars;
map<pair<int,int>, bool> taken;

int countingStars(int n) {
	int ans = 0;
	for (map<pair<int,int>, bool>::iterator it1 = stars.begin(); it1 != stars.end(); it1++) {
		pair<int,int> star1 = it1->first;
		for (map<pair<int,int>, bool>::iterator temp = it1, it2 = ++temp; it2 != stars.end(); it2++) {
			pair<int,int> star2 = it2->first;
			
			if (star1.first-star2.first == star1.second-star2.second) {
				pair<int,int> star3 = make_pair(star1.first, star2.second),
							  star4 = make_pair(star2.first, star1.second);
				if (stars[star3] && stars[star4]) {
					if (!taken[star1]) {
						ans++;
						taken[star1] = 1;
					}
					if (!taken[star2]) {
						ans++;
						taken[star2] = 1;
					}
					if (!taken[star3]) {
						ans++;
						taken[star3] = 1;
					}
					if (!taken[star4]) {
						ans++;
						taken[star4] = 1;
					}
				}
			}
		}
	}
	return ans;
}

void debug(int n) {
	cout << "---" << endl;
	for (map<pair<int,int>, bool>::iterator it = stars.begin(); it != stars.end(); it++)
		cout << "(" << (it->first).first << "," << (it->first).second << ")" << endl;
	cout << "---" << endl;
}

int main()
{
	int tc, cases=1;
	cin >> tc;
	while (tc--) {
		stars.clear(); taken.clear();
		
		int n, x, y;
		cin >> n;
		
		for (int i=0; i<n; i++) {
			cin >> x >> y;
			stars[make_pair(x,y)] = 1;
		}
		debug(n);
		cout << "Case #" << cases++ << ": " << countingStars(n) << endl;
	}
	return 0;
}

