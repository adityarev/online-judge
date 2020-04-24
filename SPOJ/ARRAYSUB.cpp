#include <cstdio>
#include <queue>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

int arr[1000005];
list<int> sub;
map<int,int> ct;
vector<int> max_vec;

int main()
{
	int n, k;
	scanf ("%d", &n);
	for (int i=0; i<n; i++)
		scanf ("%d", &arr[i]);
	
	scanf ("%d", &k);
	for (int i=0; i<k; i++) {
		if (!ct[arr[i]]) {
			max_vec.push_back(arr[i]);
			int p = max_vec.size()-1;
			while (p>0 && max_vec[p-1] < max_vec[p]) {
				max_vec[p] ^= max_vec[p-1];
				max_vec[p-1] ^= max_vec[p];
				max_vec[p] ^= max_vec[p-1];
				p--;
			}
		}
		sub.push_back(arr[i]);
		ct[arr[i]]++;
	}
	printf("%d", max_vec[0]);
	
	for (int i=k; i<n; i++) {
		if (!ct[arr[i]]) {
			max_vec.push_back(arr[i]);
			int p = max_vec.size()-1;
			while (p>0 && max_vec[p-1] < max_vec[p]) {
				max_vec[p] ^= max_vec[p-1];
				max_vec[p-1] ^= max_vec[p];
				max_vec[p] ^= max_vec[p-1];
				p--;
			}
		}
		sub.push_back(arr[i]);
		ct[arr[i]]++;
		
		ct[sub.front()]--;
		if (!ct[sub.front()]) max_vec.erase(remove(max_vec.begin(), max_vec.end(), 8), max_vec.end());
		sub.pop_front();
		
		printf(" %d", max_vec[0]);
	}
	puts("");
	
	return 0;
}
