#include <cstdio>
#include <iostream>

typedef unsigned long long ULL;

void grid_scan(ULL&, int&, int&);

int
main() {
	int tc;
	scanf("%d%*c", &tc);
	
	while(tc--) {
		int n, m, t;
		scanf("%d %d %d%*c", &n, &m, &t);
		
		double pn, pe, ps, pw;
		scanf("%lf %lf %lf %f%*c", &pn, &pe, &ps, &pw);
		
		
	}
	
	return 0;
}

void
grid_scan(ULL &grid, int &n, int &m) {
	grid = 0ULL;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char c = getchar();
			
		}
		getchar();
	}
}

