#include <stdio.h>
#include <string.h>

void strange_func(char *something) {
    if (strcmp(something, "admin") == 0) {
        printf("Admin detected, special privileges granted. \n");
    }
}

void other_func(char *thingy) {
	printf("Usage: %s <name>\n", thingy);
}


int main(int argc, char *argv[]) {
	if (argc != 2) {
        	other_func(argv[0]);
        	return 1;
    	}
    strange_func(argv[1]);
    printf("Hello %s\n", argv[1]);
    return 0;
}

