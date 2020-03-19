#include <cstring>
#include <iostream>

#define MAX 1005

int
main() {
	int arr[MAX];
	memset(arr, 0, sizeof arr);
	
	int n;
	std::cin >> n;
	
	for (int i = 1; i <= n; i++)
		std::cin >> arr[i];
	
	int max_val = INT_MIN;
	int mid = 0;
	
	for (int i = 1; i <= n; i++) {
		int val = arr[i - 1] + arr[i] + arr[i + 1];
		
		if (val > max_val) {
			max_val = val;
			mid = i;
		}
	}
	
	std::cout << max_val << " " << mid << std::endl;
	
	return 0;
}
