#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <map>
#include <queue>

typedef long long LL;

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
	map<float, map<float,int> > m_list;
	m_list.clear();
	
	for (int i = 0; i < (N - 1); i++) {
		for (int j = i + 1; j < N; j++) {
			pair<int,int> a = make_pair(x[i], y[i]);
			pair<int,int> b = make_pair(x[j], y[j]);
			
			float m = getM(a, b);
			float constant = getConstant(a, m);
			
			m_list[m][constant]++;
		}
	}
	
	int ans = 0;
	for (map<float, map<float,int> >::iterator it = m_list.begin(); it != m_list.end(); it++) {
		int count = (it->second).size();
		if (count > 1) {
			ans = max(ans, count);
		}
	}
	m_list.clear();
	
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
