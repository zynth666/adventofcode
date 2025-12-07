#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    const int lineBufferLength = 1000;
    char inputString[lineBufferLength];
    
    fgets(inputString, lineBufferLength, file);

    char* idRange;
    if ((idRange = strtok(inputString, ",")) != NULL) {
        puts(idRange);

        while ((idRange = strtok(NULL, ",")) != NULL) {
            puts(idRange);
        }
    }

    fclose(file);

    return 0;
}
