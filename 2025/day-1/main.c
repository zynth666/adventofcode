/**
 * https://adventofcode.com/2025/day/1
 * 
 * calculate number of times dial lands exactly on 0
 * write a clamping function that subtracts 100 from currentValue if it goes above 100
 * i.e. currentValue = 95; input is R6 -> 101 - 100 = 1
 * and for negative values do 100 + -currentValue i.e 100 - 1 = 99
 * if inputValue is above 100, only take first 2 digits of the value, i.e R156 -> 56 L156 -> -56
 * 
 * landing directly on 100 should be treated as 0
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handleRightTurn(char* str, int value, int *currentDialValueRef, int *counterRef) {
    int currentValue = *currentDialValueRef;
    
    if (value > 100) {
        value = atoi(str += 1);
    } else if (value == 100) {
        value = 0;
    }

    int newValue = currentValue + value;

    if (newValue > 100) {
        *currentDialValueRef = newValue - 100;
    } else if (newValue == 100) {
        *currentDialValueRef = 0;
    } else {
        *currentDialValueRef = newValue;
    }

    printf("%s%i%s", "Current dial value after right turn: ", *currentDialValueRef, "\n");

    if (*currentDialValueRef == 0) {
        *counterRef = *counterRef + 1;
    }
}

void handleLeftTurn(char* str, int value, int *currentDialValueRef, int *counterRef) {
    int currentValue = *currentDialValueRef;
    
    if (value > 100) {
        value = atoi(str += 1);
    } else if (value == 100) {
        value = 0;
    }

    int newValue = currentValue - value;

    if (newValue < 0) {
        *currentDialValueRef = 100 + newValue;
    } else {
        *currentDialValueRef = newValue;
    }

    printf("%s%i%s", "Current dial value after left turn: ", *currentDialValueRef, "\n");

    if (*currentDialValueRef == 0) {
        *counterRef = *counterRef + 1;
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    //FILE *file = fopen("smallInput.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int lineBufferLength = 10;
    char line[lineBufferLength];

    int dialValue = 50;
    int counter = 0;

    while(fgets(line, lineBufferLength, file)) {
        if (strchr(line, 'L')) {
            printf("%s", "Handling left turn with value: ");
            char* token = strtok(line, "L");
            if (token != NULL) {
                int value = atoi(token);
                printf("%i%s", value, "\n");
                handleLeftTurn(token, value, &dialValue, &counter);
            }
        }

        if (strchr(line, 'R')) {
            printf("%s", "Handling right turn with value: ");
            char* token = strtok(line, "R");
            if (token != NULL) {
                int value = atoi(token);
                printf("%i%s", value, "\n");
                handleRightTurn(token, value, &dialValue, &counter);
            }
        }
    }

    printf("%s%i", "The password is: ", counter);

    fclose(file);

    return 0;
}
