#include <stdio.h>

// argc<integer>: represents argument count
// argv<char arr>: represents argument value
int main(int argc, char** argv) {
	for(int i = 0; i < argc; i ++) {
		printf("value: %s\n", argv[i]);
	}
}
