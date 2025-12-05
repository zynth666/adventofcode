#include <stdio.h>
/**
 * https://adventofcode.com/2025/day/1
 * 
 * calculate number of times dial lands exactly on 0
 * write a clamping function that subtracts 100 from currentValue if it goes above 100
 * i.e. currentValue = 95; input is R6 -> 101 - 100 = 1
 * and for negative values do 100 + -currentValue i.e 100 - 1 = 99
 * 
 * landing directly on 100 should be treated as 0
 */
int main() {
    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int lineBufferLength = 10;
    char lineBuffer[lineBufferLength];

    while(fgets(lineBuffer, lineBufferLength, file)) {
        puts(lineBuffer);
    }

    fclose(file);

    return 0;
}