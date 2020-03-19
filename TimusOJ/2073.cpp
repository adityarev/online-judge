#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#define NAME_SIZE 30
#define DATE_SIZE 8
#define PROBLEM_SIZE 13

using namespace std;

struct Contest {
	string name;
	string date;
	int n;
	int verdict[PROBLEM_SIZE];
	
	Contest(string name, string date, int n) {
		this->name = name;
		this->date = date;
		this->n = n;
		for (int i = 0; i < PROBLEM_SIZE; i++)
			this->verdict[i] = -1;
	}
};

void printHeader() {
	puts("+------------------------------+--------+-------------+");
	puts("|Contest name                  |Date    |ABCDEFGHIJKLM|");
	puts("+------------------------------+--------+-------------+");
}

void printContestResult(const struct Contest &contest) {
	cout << "|" << contest.name;
	for (int i = contest.name.length(); i < NAME_SIZE; i++) cout << " ";
	
	cout << "|" << contest.date;
	for (int i = contest.date.length(); i < DATE_SIZE; i++) cout << " ";
	
	cout << "|";
	for (int i = 0; i < contest.n; i++) {
		if (contest.verdict[i] == 1)
			cout << "o";
		else if (contest.verdict[i] == 0)
			cout << "x";
		else
			cout << ".";
	}
	for (int i = contest.n; i < PROBLEM_SIZE; i++) cout << " ";
	cout << "|" << endl;
	
	puts("+------------------------------+--------+-------------+");
}

int main()
{
	int tc;
	scanf("%d%*c", &tc);
	
	vector<struct Contest> contests;
	
	while (tc--) {
		string name;
		getline(cin, name);
		
		string date;
		getline(cin, date);
		
		int n, tries;
		scanf("%d%*c%d%*c", &n, &tries);
		
		struct Contest contest(name, date, n);
		
		while (tries--) {
			char prob;
			string verdict;
			cin >> prob; getchar(); getline(cin, verdict);
			
			int i = (int)(prob - 'A');
			contest.verdict[i] = max(contest.verdict[i], (verdict == "Accepted" ? 1 : 0));
		}
		
		contests.push_back(contest);
	}
	
	printHeader();
	for (struct Contest contest : contests)
		printContestResult(contest);
	
	return 0;
}

