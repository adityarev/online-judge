#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

vector<LL> get_line_numbers(string&);
vector<LL> get_queue(vector<string>&);
void run_input(vector<string>&);
void show_ans(vector<LL>&);

int
main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<string> lines;
	run_input(lines);
	
	vector<LL> que = get_queue(lines);
	show_ans(que);
	
	return 0;
}


vector<LL>
get_line_numbers(string &s) {
	auto is_integer = [](char &c) -> bool {
		return (('0' <= c) && (c <= '9'));
	};
	
	auto scanll = [&](int &i) -> LL {
		LL val = 0LL;
		while (i < s.length() && is_integer(s[i])) {
			val *= 10LL;
			val += (LL)s[i] - (LL)'0';
			i++;
		}
		
		return val;
	};
	
	vector<LL> numbers;
	numbers.clear();
	
	int i = 0;
	while (i < s.length()) {
		if (is_integer(s[i])) {
			LL number = scanll(i);
			numbers.push_back(number);
			continue;
		}
		i++;
	}
	
	return numbers;
}

vector<LL>
get_queue(vector<string> &lines) {
	vector<LL> que;
	que.clear();
	
	for (string line: lines) {
		vector<LL> line_numbers = get_line_numbers(line);
		que.insert(que.end(), line_numbers.begin(), line_numbers.end());
	}
	
	reverse(que.begin(), que.end());
	return que;
}

void
run_input(vector<string> &lines) {
	string line;
	while (getline(cin, line)) {
		lines.push_back(line);
	}
}

void
show_ans(vector<LL> &que) {
	for (LL num: que) {
		double ans = sqrt((double) num);
		printf("%.4lf\n", ans);
	}
}

