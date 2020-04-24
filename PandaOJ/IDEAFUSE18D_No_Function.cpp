#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <map>
#include <queue>

typedef long long LL;

using namespace std;

void runInput(int x[], int y[], int &N) {
	for (int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
	}
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &y[i]);
	}
}


int getAns(int x[], int y[], int &N) {
	// Variables declaration
	double m;
	
	int delta_x;
	int delta_y;
	
	priority_queue<pair<double,pair<int,int> > > m_list;
	for (int i = 0; i < (N - 1); i++) {
		for (int j = i + 1; j < N; j++) {
			delta_x = x[i] - x[j];
			delta_y = y[i] - y[j];
			
			m = (delta_x == 0 ? (double)INT_MAX : ((double)delta_y / (double)delta_x));
			m_list.push(make_pair(m, make_pair(x[i], y[i])));
		}
	}
	
	pair<double,pair<int,int> > m_top;
	pair<int,int> point;
	
	double constant;
	
	int ans = 0;
	double temp = (double)INT_MIN;
	
	map<double,int> counter;
	counter.clear();
	
	int count;
	while (!m_list.empty()) {
		m_top = m_list.top();
		m_list.pop();
		
		m = m_top.first;
		point = m_top.second;
		
//		printf("m = %lf; a = (%d,%d); b = (%d,%d)\n", m, a.first, a.second, b.first, b.second);
		
		constant = ((double)point.second - (m * (double)point.first));
		if (temp == m) {
			counter[constant]++;
		} else {
			count = counter.size();
			if (count > 1) {
				ans = max(ans, count);
			}
			
			counter.clear();
			counter[constant]++;
			
			temp = m;
		}
	}
	count = counter.size();
	if (count > 1) {
		ans = max(ans, count);
	}
	
	return ans;
}

int main()
{
	int N;
	scanf("%d", &N);
	
	int x[2005];
	int y[2005];
	runInput(x, y, N);
	
	int ans = getAns(x, y, N);
	printf("%d\n", ans);
	
	return 0;
}
