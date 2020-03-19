#include <iostream>
#include <vector>

enum {
	NAMED = 0,
	HIGH,
	COMMON,
	NONE
};

void
run_input(std::vector<int> &marks) {
	int n;
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		marks.push_back(x);
	}
}

int
get_result(std::vector<int> &marks) {
	int sum = 0;
	int three_count = 0;
	
	for (int mark: marks) {
		if (mark == 3)
			three_count++;
		sum += mark;
	}
	
	int n = marks.size();
	double avg = (double)sum / (double)n;
	
	if (three_count > 0)
		return NONE;
	if (avg == 5.0)
		return NAMED;
	if (avg >= 4.5)
		return HIGH;
	return COMMON;	
}

void
show_result(std::vector<int> &marks) {
	int result = get_result(marks);
	
	switch (result) {
		case NAMED:
			std::cout << "Named" << std::endl;
			break;
		case HIGH:
			std::cout << "High" << std::endl;
			break;
		case COMMON:
			std::cout << "Common" << std::endl;
			break;
		default:
			std::cout << "None" << std::endl;
			break;
	}
}

int
main() {
	std::vector<int> marks;
	
	run_input(marks);
	show_result(marks);
	
	return 0;
}

