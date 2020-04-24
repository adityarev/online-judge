#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

float getM(pair<int,int> &a, pair<int,int> &b) {
	int delta_x = a.first - b.first;
	int delta_y = a.second - b.second;
	
	return delta_x == 0 ? (float)INT_MAX : ((float)delta_y / (float)delta_x);
}

float getConstant(pair<int,int> &point, float &m) {
	return ((float)point.second - (m * (float)point.first));
}

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
	pair<int,int> a;
	pair<int,int> b;
	
	float m;
	
	priority_queue<pair<float,pair<int,int> > > m_list;
	for (int i = 0; i < (N - 1); i++) {
		for (int j = i + 1; j < N; j++) {
			a = make_pair(x[i], y[i]);
			b = make_pair(x[j], y[j]);
			m = getM(a, b);
			
			m_list.push(make_pair(m, a));
		}
	}
	
	pair<float,pair<int,int> > m_top;
	pair<int,int> point;
	
	float constant;
	
	int ans = 0;
	float temp = (float)INT_MIN;
	
	map<float,int> counter;
	counter.clear();
	
	while (!m_list.empty()) {
		m_top = m_list.top();
		m_list.pop();
		
		m = m_top.first;
		point = m_top.second;
		
//		printf("m = %lf; a = (%d,%d); b = (%d,%d)\n", m, a.first, a.second, b.first, b.second);
		
		constant = getConstant(point, m);
		if (temp == m) {
			counter[constant]++;
		} else {
			int count = counter.size();
			if (count > 1) {
				ans = max(ans, count);
			}
			
			counter.clear();
			counter[constant]++;
			
			temp = m;
		}
	}
	int count = counter.size();
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
