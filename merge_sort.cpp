#include <iostream>
#include <vector>

template<typename T> void
merge(
	std::vector<T>& arr,
	int l,
	int m,
	int r
) {
	std::vector<T> arr1;
	std::vector<T> arr2;
	
	for (int i = l; i <= m; i++)
		arr1.push_back(arr[i]);
	for (int i = m + 1; i <= r; i++)
		arr2.push_back(arr[i]);
	
	int len1 = (int)arr1.size();
	int len2 = (int)arr2.size();
	int p = l;
	int p1 = 0;
	int p2 = 0;
	
	while (p1 < len1 && p2 < len2) {
		if (arr1[p1] <= arr2[p2])
			arr[p++] = arr1[p1++];
		else
			arr[p++] = arr2[p2++];
	}
	
	while (p1 < len1)
		arr[p++] = arr1[p1++];
	while (p2 < len2)
		arr[p++] = arr2[p2++];
}

template<typename T> void
merge_sort(std::vector<T>& arr, int l, int r) {
	if (l >= r)
		return;
	
	int m = (l + r) / 2;
	
	merge_sort<T>(arr, l, m);
	merge_sort<T>(arr, m + 1, r);
	merge<T>(arr, l, m, r);
}

int
main() {
	// Your code goes here
	
	return 0;
}

