#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_alphabet(char &c) {
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

int c_hash(char &c) {
	if ('A' <= c && c <= 'Z')
		return (int)(c - 'A');
	if ('a' <= c && c <= 'z')
		return (int)(c - 'a');
	
	return -1;
}

int
main() {
	char c;
	int hash_count[]
	return 0;
}
