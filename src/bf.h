#ifndef BF_H
#define BF_H

// The amount of cells to initialise. I got this value from: https://gist.github.com/roachhd/dce54bec8ba55fb17d3a
#define CELLS_SIZE 30000

void bf_increment_cell(int cellPointer, int *cells); // +
void bf_decrement_cell(int cellPointer, int *cells); // -
void bf_move_pointer_left(int *cellPointer); // <
void bf_move_pointer_right(int *cellPointer); // >
void bf_output_cell(int cellPointer, int *cells); // .
void bf_get_cell(int cellPointer, int *cells); // ,
char *bf_read_file(const char *fileName);

#endif // BF_H
