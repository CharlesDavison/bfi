#ifndef BF_H
#define BF_H

#define CELLS_SIZE 30000

void bf_increment_cell(int cellPointer, int **cells); // +
void bf_decrement_cell(int cellPointer, int **cells); // -
void bf_move_pointer_left(int *cellPointer); // <
void bf_move_pointer_right(int *cellPointer); // >
void bf_output_cell(int cellPointer, int **cells); // .
void bf_get_cell(int cellPointer, int **cells); // ,

#endif // BF_H
