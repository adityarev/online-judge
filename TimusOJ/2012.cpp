#include <iostream>

using namespace std;

bool is_enable_solve_all(int &task_remaining) {
	static int time_remaining = 240;
	static int cost = 45;
	
	int time_needed = task_remaining * cost;
	return time_needed <= time_remaining;
}

int main()
{
	int task_solved;
	cin >> task_solved;
	
	int task_remaining = 12 - task_solved;
	
	if (is_enable_solve_all(task_remaining))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	return 0;
}

