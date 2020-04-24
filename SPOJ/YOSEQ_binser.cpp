#include <cstdio>
#include <iostream>
#include <string>
#include <list>
using namespace std;

int index[10][100005],
	index_size[10] = {0};

bool digitAtIndex (int num, int ind) {
	int l = 0,
		r = index_size[num] - 1,
		mid;
	
	while (l <= r) {
		mid = (l+r) >> 1;
		if (index[num][mid] == ind)
			return true;
		else if (index[num][mid] < ind)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	return false;
}

bool exist (int n) {
	int digits[11] = {0},
		n_digits = 0;
	
	while(n) {
		digits[n_digits++] = n%10;
		n /= 10;
	}
	
	int lead = digits[n_digits-1],
		lim = index_size[lead];
		
	for (int i=0; i<lim; i++) {
		bool found = true;
		int	 ind = index[lead][i] + 1;
		
		for (int j = n_digits-2; j>=0; j--) {
			if (!digitAtIndex(digits[j], ind)) {
				found = false;
				break;
			} else {
				ind++;
			}
		}
		
		if (found)
			return true;
	}
	
	return false;
}

int main()
{
	char x;
	int ind = 0;
	
	while (x=getchar_unlocked()) {
		if (x>='0' && x<='9') {
			index[(int)x-'0'][index_size[(int)x-'0']++] = ind++;
		} else {
			break;
		}
	}
	
	if (index_size[0] == 0) {
		puts("0");
	} else {
		for (int i=1; ; i++) {
			if (!exist(i)) {
				printf("%d\n", i);
				break;
			}
		}
	}
	
	return 0;
}
