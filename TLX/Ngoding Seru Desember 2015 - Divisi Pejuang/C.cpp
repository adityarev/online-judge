#include <climits>
#include <cstdio>
#include <functional>
#include <string>

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)

const int MIN_DIGIT_COUNT = 1;
const int MIN_LOWER_COUNT = 3;

int
main() {
	char c;
	
	std::function<bool(char&)> is_terminator = [&](char &x) -> bool {
		return (x == ' ' || x == '.');
	};
	
	std::function<bool(std::string&)> valid = [&](std::string &s) -> bool {
		int digit_count = 0;
		int upper_count = 0;
		int lower_count = 0;
		
		for (char &x: s) {
			if ('0' <= x && x <= '9')
				digit_count++;
			if ('A' <= x && x <= 'Z')
				upper_count++;
			if ('a' <= x && x <= 'z')
				lower_count++;
		}
		
		return (digit_count >= MIN_DIGIT_COUNT && lower_count >= MIN_LOWER_COUNT);
	};
	
	std::function<void(std::string&)> print_str = [&](std::string &s) -> void {
		for (char &x: s)
			pc(x);
		pc('\n');
	};
	
	std::string s = "";
	std::string ans = "";
	
	while (c = gc()) {
		if (is_terminator(c)) {
			if (valid(s)) {
				if (s.length() > ans.length())
					ans = s;
			}
			s = "";
			
			if (c == '.')
				break;
			continue;
		}
		
		s += c;
	}
	
	if (ans.length() == 0)
		puts("NO");
	else
		print_str(ans),
		printf("%d\n", ans.length());
	
	return 0;
}

