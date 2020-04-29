#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <vector>

typedef long long LL;

using namespace std;

int
count_zero_subarrays(vector<int>& arr) { 
    int counter = 0;
    unordered_set<int> sum_set;
  
    // Traverse through array and store prefix sums 
    int sum = 0; 
    for (int i = 0; i < (int)arr.size(); i++)  { 
        sum += arr[i]; 
  
        // If prefix sum is 0 or it is already present 
        if (sum == 0 || sum_set.find(sum) != sum_set.end()) 
            counter++; 
  
        sum_set.insert(sum);
    } 
    
    return counter; 
} 

int
main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n;
		cin >> n;
		
		vector<int> arr(n);
		for (int& x: arr)
			cin >> x;
		
		LL ans = (n * (n - 1) / 2) - (LL)count_zero_subarrays(arr);
		cout << ans << endl;
	}
	
	return 0;
}

