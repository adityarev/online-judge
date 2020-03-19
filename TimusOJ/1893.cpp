#include <algorithm>
#include <cstdio>
#include <vector>

bool
is_in_range(int val, int start, int end) {
	return (start <= val && val <= end);
}

template<typename T> bool
is_in_list(std::vector<T> arr, T val) {
	return (std::find(arr.begin(), arr.end(), val) != arr.end());
}

bool
is_premium_class(int number) {
	return is_in_range(number, 1, 2);
}

bool
is_bussiness_class(int number) {
	return is_in_range(number, 3, 20);
}

bool
is_economy_class(int number) {
	return is_in_range(number, 21, 65);
}

bool
is_window(int &number, char &letter) {
	std::vector<char> my_list;
	
	if (is_premium_class(number))
		my_list = {'A', 'D'};
	if (is_bussiness_class(number))
		my_list = {'A', 'F'};
	if (is_economy_class(number))
		my_list = {'A', 'K'};
	
	return is_in_list(my_list, letter);
}

bool
is_aisle(int &number, char &letter) {
	std::vector<char> my_list;
	
	if (is_premium_class(number))
		my_list = {'B', 'C'};
	if (is_bussiness_class(number))
		my_list = {'B', 'C', 'D', 'E'};
	if (is_economy_class(number))
		my_list = {'C', 'D', 'G', 'H'};
	
	return is_in_list(my_list, letter);
}

void
solve(int &number, char &letter) {
	if (is_window(number, letter))
		puts("window");
	else if (is_aisle(number, letter))
		puts("aisle");
	else
		puts("neither");
}

int
main() {
	int number;
	char letter;
	
	scanf("%d%c", &number, &letter);
	solve(number, letter);
	
	return 0;
}

