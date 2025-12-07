/**
 * https://adventofcode.com/2025/day/1
 * 
 * calculate number of times dial lands on 0 (at the end of a rotation OR during a rotation)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handleRightTurn(char* str, int value, int *currentDialValueRef, int *counterRef) {
    int currentValue = *currentDialValueRef;
    int fullRotations = 0;
    int passedBy = 0;
    
    if (value > 100) {
        fullRotations = value / 100;
        printf("%s%i%s", "Full rotations: ", fullRotations, "\n");
        value = atoi(str += 1);
    } else if (value == 100) {
        value = 0;
    }

    int newValue = currentValue + value;

    if (newValue > 100) {
        if (currentValue != 100) {
            passedBy++;
            printf("%s", "passedBy\n");
        }

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
    
    *counterRef = *counterRef + fullRotations + passedBy;
}

void handleLeftTurn(char* str, int value, int *currentDialValueRef, int *counterRef) {
    int currentValue = *currentDialValueRef;
    int fullRotations = 0;
    int passedBy = 0;
    
    if (value > 100) {
        fullRotations = value / 100;
        printf("%s%i%s", "Full rotations: ", fullRotations, "\n");
        value = atoi(str += 1);
    } else if (value == 100) {
        value = 0;
    }

    int newValue = currentValue - value;

    if (newValue < 0) {
        if (currentValue != 0) {
            passedBy++;
            printf("%s", "passedBy\n");
        }

        *currentDialValueRef = 100 + newValue;
    } else {
        *currentDialValueRef = newValue;
    }

    printf("%s%i%s", "Current dial value after left turn: ", *currentDialValueRef, "\n");

    if (*currentDialValueRef == 0) {
        *counterRef = *counterRef + 1;
    }
    
    *counterRef = *counterRef + fullRotations + passedBy;
}

int main() {
    FILE *file = fopen("../input.txt", "r");
    //FILE *file = fopen("../smallInput.txt", "r");

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
