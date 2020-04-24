#include <iostream>
#include <cstring>
#include <list>
#include <queue>
#include <climits>

using namespace std;

bool visited[1000005];
int minimumSteps (int maxFloor, int start, int end, int up, int down)
{
	pair<int,int> curr;
	list< pair<int,int> > states;
	
	states.push_back(make_pair(start,0));
	while (!states.empty()) {
		curr = states.front();
		states.pop_front();
		
		int fir = curr.first,
			sec = curr.second;
		if (!visited[fir])
			visited[fir] = true;
		else
			continue; 
		
		if (fir == end) {
			return sec;
		} else {
			if (up != 0 && fir+up <= maxFloor)
				states.push_back(make_pair(fir+up, sec+1));
			if (down != 0 && fir-down > 0)
				states.push_back(make_pair(fir-down, sec+1));
		}
	}
	
	return INT_MAX;
}

int main()
{
	int maxFloor, start, end, up, down;
	cin >> maxFloor >> start >> end >> up >> down;
	
	int result = minimumSteps(maxFloor, start, end, up, down);
	if (result != INT_MAX)
		cout << result << endl;
	else
		cout << "use the stairs" << endl;
	
	return 0;
}
