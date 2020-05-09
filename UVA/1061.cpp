#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int N_BLOOD = 3;

const string END = "E N D";
const string IMPOSSIBLE = "IMPOSSIBLE";
const string UNKNOWN = "?";
const string NOT_FOUND = "";

enum {
	PARENT1 = 0,
	PARENT2,
	CHILD
};

const string TYPE_A = "A";
const string TYPE_B = "B";
const string TYPE_AB = "AB";
const string TYPE_O = "O";
map<string,string> type_result;
map<string,vector<string>> type_alleles;

void
init_type_db() {
	type_result["AA"] = TYPE_A;
	type_result["AO"] = TYPE_A;
	type_result["OA"] = TYPE_A;
	type_result["BB"] = TYPE_B;
	type_result["BO"] = TYPE_B;
	type_result["OB"] = TYPE_B;
	type_result["AB"] = TYPE_AB;
	type_result["BA"] = TYPE_AB;
	type_result["OO"] = TYPE_O;
	
	type_alleles[TYPE_A] = {TYPE_A, TYPE_O};
	type_alleles[TYPE_B] = {TYPE_B, TYPE_O};
	type_alleles[TYPE_AB] = {TYPE_A, TYPE_B};
	type_alleles[TYPE_O] = {TYPE_O};
}

const string RH_MIN = "-";
const string RH_PLUS = "+";
map<string,string> rh_result;
map<string,vector<string>> rh_alleles;

void
init_rh_db() {
	rh_result["++"] = RH_PLUS;
	rh_result["+-"] = RH_PLUS;
	rh_result["-+"] = RH_PLUS;
	rh_result["--"] = RH_MIN;
	
	rh_alleles[RH_PLUS] = {RH_PLUS, RH_MIN};
	rh_alleles[RH_MIN] = {RH_MIN};
}

struct Blood {
	string type;
	string rh;
};

void
init_db() {
	init_type_db();
	init_rh_db();
}

Blood
get_blood(string s) {
	if (s == UNKNOWN)
		return {UNKNOWN, UNKNOWN};
	
	int len = (int)s.length();
	string type = s.substr(0, len - 1);
	string rh = s.substr(len - 1);
	
	return {type, rh};
}

string
get_blood_str(const Blood& blood) {
	return blood.type + blood.rh;
}

vector<Blood>
get_bloods(string s) {
	int len = (int)s.length();
	
	function<Blood(int&)>
	get_next_blood = [&](int& i) -> Blood {
		string blood_str = "";
		while (i < len && s[i] != ' ')
			blood_str += s[i++];
		return get_blood(blood_str);
	};
	
	vector<Blood> bloods;
	
	for (int i = 0; i < len && (int)bloods.size() < N_BLOOD; i++) {
		if (s[i] != ' ') {
			Blood blood = get_next_blood(i);
			bloods.push_back(blood);
		}
	}
	
	return bloods;
}

vector<string>
get_child_type_possibilities(const Blood& parent1, const Blood& parent2) {
	map<string,bool> taken;
	vector<string> type_possibilities;
	
	for (string& type1: type_alleles[parent1.type]) {
		for (string& type2: type_alleles[parent2.type]) {
			string type = type_result[type1 + type2];
			if (!taken[type]) {
				type_possibilities.push_back(type);
				taken[type] = true;
			}
		}
	}
	
	return type_possibilities;
}

vector<string>
get_child_rh_possibilities(const Blood& parent1, const Blood& parent2) {
	if (parent1.rh == RH_PLUS || parent2.rh == RH_PLUS)
		return rh_alleles[RH_PLUS];
	return rh_alleles[RH_MIN];
}

vector<Blood>
get_child_possibilities(const Blood& parent1, const Blood& parent2) {
	vector<string> type_possibilities = get_child_type_possibilities(parent1, parent2);
	vector<string> rh_possibilities = get_child_rh_possibilities(parent1, parent2);
	
	map<string,bool> taken;
	vector<Blood> possibilities;
	
	for (string& type: type_possibilities) {
		for (string& rh: rh_possibilities) {
			string blood_str = type + rh;
			Blood blood = get_blood(blood_str);
			
			if (!taken[blood_str]) {
				possibilities.push_back(blood);
				taken[blood_str] = true;
			}
		}
	}
	
	return possibilities;
}

vector<string>
get_parent_type_possibilies(const Blood& parent1, const Blood& child) {
	if (child.type == TYPE_AB) {
		if (parent1.type == TYPE_A)
			return {TYPE_AB, TYPE_B};
		else if (parent1.type == TYPE_B)
			return {TYPE_AB, TYPE_A};
		else if (parent1.type == TYPE_AB)
			return {TYPE_A, TYPE_B, TYPE_AB};
		else
			return {};
	} else if (child.type == TYPE_A) {
		if (parent1.type == TYPE_B || parent1.type == TYPE_O)
			return {TYPE_A, TYPE_AB};
	} else if (child.type == TYPE_B) {
		if (parent1.type == TYPE_A || parent1.type == TYPE_O)
			return {TYPE_B, TYPE_AB};
	} else {
		if (parent1.type == TYPE_AB)
			return {};
		else
			return {TYPE_A, TYPE_B, TYPE_O};
	}
	
	return {TYPE_A, TYPE_B, TYPE_O, TYPE_AB};
}

vector<string>
get_parent_rh_possibilities(const Blood& parent1, const Blood& child) {
	if (child.rh == RH_PLUS && parent1.rh == RH_MIN)
		return {RH_PLUS};
	return {RH_PLUS, RH_MIN};
}

vector<Blood>
get_parent_possibilities(const Blood& parent1, const Blood& child) {
	vector<string> type_possibilities = get_parent_type_possibilies(parent1, child);
	vector<string> rh_possibilities = get_parent_rh_possibilities(parent1, child);
	
	map<string,bool> taken;
	vector<Blood> possibilities;
	
	for (string& type: type_possibilities) {
		for (string& rh: rh_possibilities) {
			string blood_str = type + rh;
			Blood blood = get_blood(blood_str);
			
			if (!taken[blood_str]) {
				possibilities.push_back(blood);
				taken[blood_str] = true;
			}
		}
	}
	
	return possibilities;
}

string
get_possibilities_str(vector<Blood>& possibilities) {
	int n = (int)possibilities.size();
	
	if (n == 0)
		return IMPOSSIBLE;
	if (n == 1)
		return get_blood_str(possibilities[0]);
	
	string str = "";
	
	for (int i = 0; i < n; i++)
		str += get_blood_str(possibilities[i]) + (i != n - 1 ? ", " : "");
	
	return "{" + str + "}";
}

void
run_case(string s) {
	static int case_num = 0;
	vector<Blood> bloods = get_bloods(s);
	
	Blood parent1 = bloods[PARENT1];
	Blood parent2 = bloods[PARENT2];
	Blood child = bloods[CHILD];
	
	vector<Blood> possibilities;
	
	if (parent1.type == UNKNOWN)
		possibilities = get_parent_possibilities(parent2, child);
	else if (parent2.type == UNKNOWN)
		possibilities = get_parent_possibilities(parent1, child);
	else
		possibilities = get_child_possibilities(parent1, parent2);
	
	cout << "Case " << ++case_num << ": ";
	if (parent1.type != UNKNOWN)
		cout << get_blood_str(parent1);
	else
		cout << get_possibilities_str(possibilities);
	cout << " ";
	if (parent2.type != UNKNOWN)
		cout << get_blood_str(parent2);
	else
		cout << get_possibilities_str(possibilities);
	cout << " ";
	if (child.type != UNKNOWN)
		cout << get_blood_str(child);
	else
		cout << get_possibilities_str(possibilities);
	cout << endl;
}

int
main() {
	init_db();
	
	string a, b, c;
	
	while (cin >> a >> b >> c) {
		string s = a + " " + b + " " + c;
		if (s == END)
			break;
		run_case(s);
	}
	
	return 0;
}

