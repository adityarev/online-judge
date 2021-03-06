#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#include <map>
#include <queue>

#define MAX 2005
#define LL long long
#define GRADIENT pair<bool,pair<int,int> >

using namespace std;

int N;
int x[MAX];
int y[MAX];


GRADIENT getM(bool sign, int a, int b) {
	if (a == 0) {
		return make_pair(true, make_pair(0, INT_MAX));
	} else if (b == 0) {
		return make_pair(sign, make_pair(INT_MAX, 0));
	} else {
		return make_pair(sign, make_pair(a, b));
	}
}


LL getConstant(GRADIENT &m, int &temp_x, int &temp_y) {
	bool sign = m.first;
	int a = m.second.first;
	int b = m.second.second;
	
	if (b == 0) {
		bool new_sign = (false ^ !(temp_x > 0) ^ sign);
		return new_sign ? LLONG_MAX : LLONG_MIN;
	}
	
	LL value = (LL)temp_y - ((LL)temp_x * (LL)a / (LL)b);
	
	return sign ? value : -value;
}


void runInput() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &y[i]);
	}
}


int gcd (int a, int b) {
	int c;
	while ( a != 0 ) {
		c = a;
		a = b % a;
		b = c;
	}
	
	return b;
}


bool isEqual(GRADIENT &a, GRADIENT &b) {
	if (a.first == b.first) {
		if (a.second.first == b.second.first) {
			return a.second.second == b.second.second;
		}
		return false;
	}
	return false;
}


int getAns() {
	priority_queue<pair<GRADIENT,LL> > m_list;
	for (int i = 0; i < (N - 1); i++) {
		for (int j = i + 1; j < N; j++) {
			int delta_x = x[i] - x[j];
			int delta_y = y[i] - y[j];
			int greatest_div = gcd(delta_x, delta_y);
			
			bool sign = !((delta_x > 0) ^ (delta_y > 0));
			int a = delta_x / greatest_div;
			int b = delta_y / greatest_div;
			
			GRADIENT m = getM(sign, a, b);
			LL constant = getConstant(m, x[i], y[i]);
			
//			printf("%c (%d,%d) -> %lld\n", sign ? '+' : '-', a, b, constant);
			
			m_list.push(make_pair(m, constant));
		}
	}
	
	int ans = 0;
	GRADIENT temp = make_pair(true, make_pair(0, 0));
	
	map<LL,int> counter;
	counter.clear();
	
	while (!m_list.empty()) {
		pair<GRADIENT,LL> curr = m_list.top();
		m_list.pop();
		
		GRADIENT m = curr.first;
		LL constant = curr.second;
		
		if (isEqual(temp, m)) {
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
	runInput();
	
	int ans = getAns();
	printf("%d\n", ans);
	
	return 0;
}
