#include <stdio.h>
#include <stdlib.h>

#include "bf.h"

void bf_increment_cell(int cellPointer, int *cells) {
    cells[cellPointer] += 1;
}

void bf_decrement_cell(int cellPointer, int *cells) {
    cells[cellPointer] -= 1;
}

void bf_move_pointer_left(int *cellPointer) {
    *cellPointer -= 1;
    if (*cellPointer < 0) {
        *cellPointer = CELLS_SIZE - 1;
    }
}

void bf_move_pointer_right(int *cellPointer) {
    *cellPointer += 1;
    if (*cellPointer >= CELLS_SIZE) {
        *cellPointer = 0;
    }
}

void bf_output_cell(int cellPointer, int *cells) {
    putchar(cells[cellPointer]);
}

char *bf_read_file(const char *fileName) {
    FILE *fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return NULL;
    }

    size_t capacity = 128;
    size_t length = 0;

    char *fileString = malloc(capacity);

    if (fileString == NULL) {
        fclose(fp);
        return NULL;
    }

    int ch;

    while ((ch = fgetc(fp)) != EOF) {

        // Make room for the next character and '\0'
        if (length + 1 >= capacity) {
            capacity *= 2;

            char *temp = realloc(fileString, capacity);

            if (temp == NULL) {
                printf("Failed to allocate memory for string.\n");
                free(fileString);
                fclose(fp);
                return NULL;
            }

            fileString = temp;
        }

        fileString[length++] = (char)ch;
    }

    fileString[length] = '\0';

    fclose(fp);

    return fileString;
}
