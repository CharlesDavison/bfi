#include <stdlib.h>

#include "bf.h"

int main(int argc, char *argv[])
{
    int *cells = calloc(CELLS_SIZE, sizeof(int));
    int cellPointer = 0;

    for (int i = 0; i < 65; i++)
        bf_increment_cell(cellPointer, &cells);

    bf_output_cell(cellPointer, &cells);
    return EXIT_SUCCESS;
}
