#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ALPH_SIZE 26
#define ALPH_COUNT (ALPH_SIZE << 1)
#define MAX_LEN 1005

bool
is_alphabet(char c) {
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

int
c_hash(char c) {
	if ('A' <= c && c <= 'Z')
		return (int)(c - 'A');
	if ('a' <= c && c <= 'z')
		return ((int)(c - 'a') + ALPH_SIZE);
	
	return -1;
}

int
main() {
	char str[MAX_LEN];
	int i;
	
	while (gets(str)) {
		bool hash_flag[ALPH_COUNT];
		memset(hash_flag, false, sizeof(hash_flag));
		
		int len = strlen(str);
		for (i = 0; i < len; i++) {
			char c = str[i];
			if (is_alphabet(c))
				hash_flag[c_hash(c)] = true;
		}
		
		int count = 0;
		for (i = 0; i < ALPH_COUNT; i++) {
			if (hash_flag[i])
				count++;
		}
		
		printf("%d\n", count);
	}

	return 0;
}
