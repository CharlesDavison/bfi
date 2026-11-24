#include <stdio.h>
#include <stdlib.h>

#include "bf.h"

int main(int argc, char *argv[])
{
    int *cells = calloc(CELLS_SIZE, 1);
    int cellPointer = 0;

    if (argc < 2) {
        printf("Invalid usage: bfi [input file]\n");
        return EXIT_FAILURE;
    }

    char *inputFile = bf_read_file(argv[1]);

    if (inputFile == NULL) {
        free(inputFile);
        return EXIT_FAILURE;
    }

    int counter = 0;
    char ch = inputFile[counter];
    int stack[CELLS_SIZE];
    int stackPointer = -1;

    // Main loop
    while (ch != '\0') {
        switch (ch) {
            case '<':
                bf_move_pointer_left(&cellPointer);
                break;
        
            case '>':
                bf_move_pointer_right(&cellPointer);
                break;

            case '+':
                bf_increment_cell(cellPointer, cells);
                break;

            case '-':
                bf_decrement_cell(cellPointer, cells);
                break;

            case '.':
                bf_output_cell(cellPointer, cells);
                break;

            // Loops fuckery
            case '[':
                if (cells[cellPointer] == 0) {
                    int depth = 1;

                    while (depth > 0) {
                        counter++;

                        if (inputFile[counter] == '[') {
                            depth++;
                        } else if (inputFile[counter] == ']') {
                            depth--;
                        }
                    }
                } else {
                    stack[++stackPointer] = counter;
                }
                break;

            case ']':
                if (cells[cellPointer] != 0) {
                    counter = stack[stackPointer];
                } else {
                    stackPointer--;
                }
                break;
                    }
                    counter++;
                    ch = inputFile[counter];
                }

    free(cells);
    free(inputFile);
    return EXIT_SUCCESS;
}
