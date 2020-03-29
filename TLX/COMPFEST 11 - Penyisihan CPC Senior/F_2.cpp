/*
 * Credit to: https://github.com/panks/BigInteger
 */

#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

typedef long long LL;

const int BIG_INT_LEN = 10000;

class BigInteger {
private:
	bool negative;
	std::string number;

public:
	BigInteger();
	BigInteger(std::string s);
	BigInteger(std::string s, bool negative);
	BigInteger(LL n);
	void set_number(std::string number);
	const std::string& get_number();
	void set_negative(bool negative);
	const bool& is_negative();
	BigInteger absolute();
	void operator = (BigInteger b);
    bool operator == (BigInteger b);
    bool operator != (BigInteger b);
    bool operator > (BigInteger b);
    bool operator < (BigInteger b);
    bool operator >= (BigInteger b);
    bool operator <= (BigInteger b);
    BigInteger& operator ++();
    BigInteger operator ++(int);
    BigInteger& operator --();
    BigInteger operator --(int);
    BigInteger operator + (BigInteger b);
    BigInteger operator - (BigInteger b);
    BigInteger operator * (BigInteger b);
    BigInteger operator / (BigInteger b);
    BigInteger operator % (BigInteger b);
    BigInteger& operator += (BigInteger b);
    BigInteger& operator -= (BigInteger b);
    BigInteger& operator *= (BigInteger b);
    BigInteger& operator /= (BigInteger b);
    BigInteger& operator %= (BigInteger b);
    BigInteger& operator [] (int n);
    BigInteger operator -();
    operator std::string();

private:
	bool equals(BigInteger b1, BigInteger b2);
	bool less(BigInteger b1, BigInteger b2);
	bool greater(BigInteger b1, BigInteger b2);
	std::string add(std::string n1, std::string n2);
	std::string subtract(std::string n1, std::string n2);
	std::string multiply(std::string n1, std::string n2);
	std::pair<std::string, LL> divide(std::string n, LL divider);
	std::string to_string(LL n);
	LL to_int(std::string s);
};

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)
#define endline pc('\n')

struct FastIO {
	template <typename T> T
	getnumb() {
		T c = gc();
		
		std::function<bool()> is_negative = [&]() -> bool {
			for (; c < '0' || c > '9'; c = gc()) {
				if (c == '-') {
					c = gc();
					if (c >= '0' && c <= '9')
						return true;
				}
			}
			return false;
		};
		
		bool negative = is_negative();
		T val = 0;
		
		for (; c >= '0' && c <= '9'; c = gc())
			val = (val << 1) + (val << 3) + c - (T)'0';
		
		return negative ? -val : val;
	}
	
	std::string
	getstr(bool line_scan = false) {
		std::function<bool(char&)> is_separator = [&](char &c) -> bool {
			return c == '\n' || (c == ' ' && !line_scan);
		};
		
		char c;
		std::string str = "";
		
		while ((c = gc()) && is_separator(c));
		do {
			str += c;
		} while ((c = gc()) && !is_separator(c));
		
		return str;
	}
	
	template <typename T> void
	printnumb(T val, std::string suffix = "") {
		if (val == 0) {
			pc('0');
			return;
		}
		if (val < 0) {
			pc('-');
			val = -val;
		}
		
		std::function<void(T)> _print = [&](T x) -> void {
			if (x == 0)
				return;
			
			_print(x / 10);
			pc('0' + (x % 10));
		};
		
		_print(val);
		printstr(suffix);
	}
	
	void
	printstr(std::string &str) {
		for (char &c: str)
			pc(c);
	}
} fio;

BigInteger
get_ans(std::string &s, int &q) {
	std::function<int(char&)> c_hash = [&](char &c) {
		return (int)(c - 'A');
	};
	
	const int ALPH_SIZE = 26;
	std::vector<BigInteger> counter(ALPH_SIZE, BigInteger(0));
	
	std::function<void(std::string&, char)>
	set_counter = [&](
		std::string &str,
		char poc
	) -> void {
		BigInteger prev = BigInteger(1);
		
		if (poc != '\0')
			prev = counter[c_hash(poc)];
		
		std::vector<int> hash_count(ALPH_SIZE, 0);
		
		for (char &c: str)
			hash_count[c_hash(c)]++;
		
		for (int i = 0; i < ALPH_SIZE; i++)
			counter[i] += BigInteger(hash_count[i]) * prev;
		
		if (poc != '\0')
			counter[c_hash(poc)] -= prev;
	};
	
	std::function<void()> init_counter = [&]() -> void {
		set_counter(s, '\0');
	};
	
	std::function<void()> do_query = [&]() -> void {
		char c = fio.getstr()[0];
		std::string changer = fio.getstr();
		
		set_counter(changer, c);
	};
	
	init_counter();
	for (int i = 0; i < q; i++)
		do_query();
	
	BigInteger ans(0);
	
	for (BigInteger &b: counter) {
		ans += b;
	}
	
	return ans;
}

int
main() {
	int n = fio.getnumb<int>();
	int q = fio.getnumb<int>();
	std::string s = fio.getstr();
	
	BigInteger ans = get_ans(s, q);
	std::cout << std::string(ans) << std::endl;
	
	return 0;
}

/* BigInteger Implemetation */

// Empty constructor initializes zero
BigInteger::BigInteger() {
	set_number("0");
	set_negative(false);
}

// "string" constructor
BigInteger::BigInteger(std::string s) {
	if (std::isdigit(s[0])) {
		set_number(s);
		set_negative(false);
	} else {
		set_number(s.substr(1));
		set_negative(true);
	}
}

// "string" constructor
BigInteger::BigInteger(std::string s, bool negative) {
	set_number(s);
	set_negative(negative);
}

// "number" constructor
BigInteger::BigInteger(LL n) {
	std::stringstream ss;
	ss << n;
	
	std::string s;
	ss >> s;
	
	if (std::isdigit(s[0])) {
		set_number(s);
		set_negative(false);
	} else {
		set_number(s.substr(1));
		set_negative(true);
	}
}

void
BigInteger::set_number(std::string number) {
	this->number = number;
}

const
std::string& BigInteger::get_number() {
	return number;
}

void
BigInteger::set_negative(bool negative) {
	this->negative = negative;
}

const bool&
BigInteger::is_negative() {
	return negative;
}

BigInteger
BigInteger::absolute() {
	return BigInteger(get_number());
}

void
BigInteger::operator = (BigInteger b) {
	set_number(b.get_number());
	set_negative(b.is_negative());
}

bool
BigInteger::operator == (BigInteger b) {
	return equals(*this, b);
}

bool
BigInteger::operator != (BigInteger b) {
	return !equals(*this, b);
}

bool
BigInteger::operator > (BigInteger b) {
	return greater(*this , b);
}

bool
BigInteger::operator < (BigInteger b) {
	return less(*this , b);
}

bool
BigInteger::operator >= (BigInteger b) {
	return greater(*this , b) || equals(*this , b);
}

bool
BigInteger::operator <= (BigInteger b) {
	return less(*this , b) || equals(*this , b);
}

// Prefix increment
BigInteger&
BigInteger::operator ++() {
	*this = *this + 1;
	return *this;
}

// Postfix increment
BigInteger
BigInteger::operator ++(int) {
	BigInteger prev = *this;
	*this = *this + 1;
	return prev;
}

// Prefix decrement
BigInteger&
BigInteger::operator --() {
	*this = *this - 1;
	return *this;
}

// Postfix decrement
BigInteger
BigInteger::operator --(int) {
	BigInteger prev = *this;
	*this = *this - 1;
	return prev;
}

BigInteger
BigInteger::operator + (BigInteger b) {
	bool neg;
	std::string num;
	
	if (this->is_negative() == b.is_negative()) {
		num = add(this->get_number(), b.get_number());
		neg = this->is_negative();
	} else {
		if (this->absolute() > b.absolute()) {
			num = subtract(this->get_number(), b.get_number());
			neg = this->is_negative();
		} else {
			num = subtract(this->get_number(), b.get_number());
			neg = b.is_negative();
		}
	}
	
	BigInteger res = BigInteger(num, neg);
	
	if (res.get_number() == "0")
		res.set_negative(false);
	
	return res;
}

BigInteger
BigInteger::operator - (BigInteger b) {
	b.set_negative(!b.is_negative());
	return *this + b;
}

BigInteger
BigInteger::operator * (BigInteger b) {
	bool neg = (this->is_negative() != b.is_negative());
	std::string num = multiply(this->get_number(), b.get_number());
	
	BigInteger res = BigInteger(num, neg);
	
	if (res.get_number() == "0")
		res.set_negative(false);
	
	return res;
}

BigInteger
BigInteger::operator / (BigInteger b) {
	LL divider = to_int(b.get_number());

	bool neg = (this->is_negative() != b.is_negative());
	std::string num = divide(this->get_number(), divider).first;
	
	BigInteger res = BigInteger(num, neg);
	
	if (res.get_number() == "0")
		res.set_negative(false);
	
	return res;
}

BigInteger
BigInteger::operator % (BigInteger b) {
	LL divider = to_int(b.get_number());

	bool neg = (this->is_negative() != b.is_negative());
	LL rem = divide(this->get_number(), divider).second;
	std::string num = to_string(rem);
	
	BigInteger res = BigInteger(num, neg);
	
	if (res.get_number() == "0")
		res.set_negative(false);
	
	return res;
}

BigInteger&
BigInteger::operator += (BigInteger b) {
	*this = *this + b;
	return *this;
}

BigInteger&
BigInteger::operator -= (BigInteger b) {
	*this = *this - b;
	return *this;
}

BigInteger&
BigInteger::operator *= (BigInteger b) {
	*this = *this * b;
	return *this;
}

BigInteger&
BigInteger::operator /= (BigInteger b) {
	*this = *this / b;
	return *this;
}

BigInteger&
BigInteger::operator %= (BigInteger b) {
	*this = *this % b;
	return *this;
}

BigInteger&
BigInteger::operator [] (int n) {
	return *(this + (n * sizeof(BigInteger)));
}

BigInteger
BigInteger::operator - () {
	return (*this * -1);
}

BigInteger::operator std::string () {
	return (negative ? "-" : "") + number;
}

// --- Private Methods Section ---
bool
BigInteger::equals(BigInteger b1, BigInteger b2) {
	return b1.get_number() == b2.get_number()
		&& b1.is_negative() == b2.is_negative(); 
}

bool
BigInteger::less(BigInteger b1, BigInteger b2) {
	bool neg1 = b1.is_negative();
	bool neg2 = b2.is_negative();
	
	if (neg1 && !neg2)
		return true;
	if (!neg1 && neg2)
		return false;
	
	int len1 = (int)b1.get_number().length();
	int len2 = (int)b2.get_number().length();
	
	// Both are positives
	if (!neg1) {
		if (len1 < len2)
			return true;
		if (len1 > len2)
			return false;
	}
	
	// Both are negatives
	if (neg1) {
		if (len1 > len2)
			return true;
		if (len1 < len2)
			return false;
	}
	
	return neg1 ? b1.get_number() < b2.get_number()
		: b1.get_number() > b2.get_number();
}

bool
BigInteger::greater(BigInteger b1, BigInteger b2) {
	return !equals(b1, b2) && !less(b1, b2);
}

std::string
BigInteger::add(std::string n1, std::string n2) {
	int len1 = (int)n1.length();
	int len2 = (int)n2.length();
	int len_diff = abs(len1 - len2);
	
	char carry = '0';
	std::string res = (len1 > len2 ? n1 : n2);
	
	if (len1 > len2)
		n2.insert(0, len_diff, '0');
	if (len1 < len2)
		n1.insert(0, len_diff, '0');
	
	for (int i = (len1 - 1); i >= 0; i--) {
		res[i] = '0' + ((carry - '0') + (n1[i] - '0') + (n2[i] - '0'));
		
		if (i != 0) {
			if (res[i] > '9') {
				res[i] -= 10;
				carry = '1';
			} else {
				carry = '0';
			}
		}
	}
	
	if (res[0] > '9') {
		res[0] -= 10;
		res.insert(0, 1, '1');
	}
	
	return res;
}

std::string
BigInteger::subtract(std::string n1, std::string n2) {
	int len1 = (int)n1.length();
	int len2 = (int)n2.length();
	int len_diff = abs(len1 - len2);
	
	std::string res = (len1 > len2 ? n1 : n2);
	
	if (len1 > len2)
		n2.insert(0, len_diff, '0');
	if (len1 < len2)
		n1.insert(0, len_diff, '0');
	
	for (int i = len1 - 1; i >= 0; i--) {
		if (n1[i] < n2[i]) {
			n1[i] += 10;
			if (i - 1 >= 0)
				n1[i - 1]--;
		}
		
		res[i] = '0' + ((n1[i] - '0') - (n2[i] - '0'));
	}
	
	while (res[0] == '0' && res.length() > 1)
		res.erase(0, 1);
	
	return res;
}

std::string
BigInteger::multiply(std::string n1, std::string n2) {
	if (n1.length() > n2.length())
		n1.swap(n2);
	
	int len1 = (int)n1.length();
	int len2 = (int)n2.length();
	int len_diff = abs(len1 - len2);
	
	std::string res = "0";
	
	for (int i = len1 - 1; i >= 0; i--) {
		int curr = (int)(n1[i] - '0');
		int carry = 0;
		
		std::string temp = n2;
		
		for (int j = temp.length() - 1; j >= 0; j--) {
			temp[j] = ((temp[j] - '0') * curr) + carry;
			
			if (temp[j] > 9) {
				carry = temp[j] / 10;
				temp[j] -= carry * 10;
			} else {
				carry = 0;
			}
			
			temp[j] += '0';
		}
		
		if (carry > 0)
			temp.insert(0, 1, (carry + '0'));
		
		temp.append((len1 - i - 1), '0');
		res = add(res, temp);
	}
	
	while(res[0] == '0' && res.length() > 1)
		res.erase(0,1);

	return res;
}

std::pair<std::string, LL>
BigInteger::divide(std::string n, LL divider) {
	int len = (int)n.length();
	LL rem = 0LL;
	std::string res(BIG_INT_LEN, '0');
	
	for (int i = 0; i < len; i++) {
		rem = (rem * 10) + (n[i] - '0');
		res[i] = (rem / divider) + '0';
		rem %= divider;
	}
	res.resize(len);
	
	while (res[0] == '0' && res.length() > 1)
		res.erase(0, 1);
	
	if (res.length() == 0)
		res = "0";
	
	return std::make_pair(res, rem);
}

// --- Converter Methods Section ---
std::string
BigInteger::to_string(LL n) {
	std::stringstream ss;
	ss << n;
	
	std::string s;
	ss >> s;
	
	return s;
}

LL
BigInteger::to_int(std::string s) {
	LL n = 0;
	
	for (int i = 0; i < s.length(); i++)
		n = (n * 10LL) + (LL)(s[i] - '0');
	
	return n;
}

