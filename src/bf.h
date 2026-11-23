#ifndef BF_H
#define BF_H

#define CELLS_SIZE 30000

void incrementCell(int cellPointer, int *cells); // +
void decrementCell(int cellPointer, int *cells); // -
int movePointerLeft(int *cellPointer); // <
int movePointerRight(int *cellPointer); // >
void outputCell(int cellPointer, int *cells); // .
void getCell(int cellPointer, int *cells); // ,

#endif
