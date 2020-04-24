#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<string,int> a, pair<string,int> b) {
	return a.second == b.second ? a.first < b.first : a.second > b.second;
}

int main()
{
	map<string,int> counter;
	counter.clear();
	
	string name;
	for (int i = 0; i < 8; i++) {
		cin >> name;
		counter[name] = 0;
	}
	
	string name1, name2;
	int score1, score2;
	char strip;
	
	for (int i = 0; i < 28; i++) {
		cin >> name1 >> score1 >> strip >> score2 >> name2;
		
		if (score1 > score2) {
			counter[name1]++;
		} else {
			counter[name2]++;
		}
	}
	
	vector<pair<string,int> > out;
	for (map<string,int>::iterator it = counter.begin(); it != counter.end(); it++) {
		out.push_back(make_pair(it->first, it->second));
	}
	
	sort(out.begin(), out.end(), comp);
	for (int i = 0; i < 8; i++) {
		cout << out[i].first << " " << out[i].second << endl;
	}
	
	return 0;
}
