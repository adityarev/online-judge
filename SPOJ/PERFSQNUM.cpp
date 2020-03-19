#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

#define gc(x) getchar(x)
#define pc(x) putchar(x)

// _unlocked

int
getint() {
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc());
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return val;
}

int
row_scan() {
	char c;
	while ((c = gc()) != '+');
	return getint();
}

void
printint(int val) {
	if (val == 0)
		return;
	printint(val / 10);
	pc('0' + (val % 10));
}

// ---

#define MAX 1000002

vector<int> primes;

void
init_primes() {
	bool is_prime[MAX];
	memset(is_prime, true, sizeof(is_prime));
	
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i < MAX; i++) {
		if (is_prime[i]) {
			for (int j = i + i; j < MAX; j += i)
				is_prime[j] = false;
		}
	}
	
	for (int i = 0; i < MAX; i++) {
		if (is_prime[i])
			primes.push_back(i);
	}
}

// ---
void
create_prime_divisors(int &x, vector<PII> &prime_divisors) {
	int val = x;
	
	for (int prime: primes) {
		if (prime > val)
			break;
		
		if (val % prime == 0) {
			int power = 0;
			while (val % prime == 0) {
				power++;
				val /= prime;
			}
			
			PII prime_divisor = make_pair(prime, power);
			prime_divisors.push_back(prime_divisor);
		}
	}
}

void
trace_divisors(int val, int index, vector<PII> &prime_divisors, vector<int> &divisors) {
	if (index == prime_divisors.size()) {
		divisors.push_back(val);
		return;
	}
	
	PII prime_divisor = prime_divisors[index];
	int prime = prime_divisor.first;
	int power = prime_divisor.second;
	int curr = val;
	
	for (int i = 0; i <= power; i++) {
		trace_divisors(curr, index + 1, prime_divisors, divisors);
		curr *= prime;
	}
}

void
create_divisors(int &x, vector<PII> &prime_divisors, vector<int> &divisors) {
	trace_divisors(1, 0, prime_divisors, divisors);
	sort(divisors.begin(), divisors.end());
}

void
create_answers(vector<int> &divisors, vector<int> &answers) {
	int l = 0;
	int r = divisors.size() - 1;
	
	while (l <= r) {
		int difference = (divisors[r] - divisors[l]);
		if ((difference & 1) == 0) {
			int answer = difference >> 1;
			answers.push_back(answer);
		}
		
		l++;
		r--;
	}
	
	reverse(answers.begin(), answers.end());
}

void
show_answers(vector<int> &answers) {
	if (answers.size() == 0) {
		puts("No Solution");
		return;
	}
	
	bool first = true;
	
	pc('[');
	for (int val: answers) {
		if (first)
			first = false;
		else
			pc(','), pc(' ');
		
		if (val == 0)
			pc('0');
		else
			printint(val);
	}
	pc(']'), pc('\n');
}

int
main() {
	init_primes();
	
	int tc = getint();
	while (tc--) {
		int x = row_scan();

		if (x == 0) {
			puts("Infinitely Many Solutions");
			continue;
		}
		
		vector<PII> prime_divisors;
		create_prime_divisors(x, prime_divisors);
		
		vector<int> divisors;
		create_divisors(x, prime_divisors, divisors);
		
		vector<int> answers;
		create_answers(divisors, answers);
		
		show_answers(answers);
	}
	
	return 0;
}

