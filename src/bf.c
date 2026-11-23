#include <stdio.h>

#include "bf.h"

void bf_increment_cell(int cellPointer, int **cells) {
    (*cells)[cellPointer] += 1;
}

void bf_decrement_cell(int cellPointer, int **cells) {
    (*cells)[cellPointer] -= 1;
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

void bf_output_cell(int cellPointer, int **cells) {
    putchar((*cells)[cellPointer]);
}
