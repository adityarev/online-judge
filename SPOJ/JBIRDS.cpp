#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int arr[10001];
	int sum = 0;
	
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr+n);
	
	int groupSum = sum >> 1;
	int leftSum = 0;
	int rightSum = 0;
	for (int i=n-1; i>=0; i--) {
		if (groupSum - arr[i] >= 0) {
			leftSum += arr[i];
			groupSum -= arr[i];
		} else {
			rightSum += arr[i];
		}
	}
	
	cout << abs(leftSum - rightSum) << endl;
	
	return 0;
}
