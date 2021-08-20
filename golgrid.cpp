#include "./golgrid.h"
#include <stdlib.h>

GolGrid::GolGrid(int gridWidth, int gridHeight)
	:Grid(gridWidth, gridHeight)
{
}

int GolGrid::countLiveCells() const
{
	int cellsAlive = 0;
    for (int i = 0; i < gridWidth; i++) {
        for (int j = 0; j < gridHeight; j++)
            if ((*this)(i, j)) cellsAlive++;
    }
    return cellsAlive;
}

int GolGrid::neighborCount(int xGrid, int yGrid) {
    int nbrCount = 0;

    /*Counts neighbours on the row above*/

    if (yGrid > 0) {
        if (xGrid > 0 && (*this)((xGrid - 1), (yGrid - 1))) nbrCount++;
        if ((*this)(xGrid, (yGrid - 1))) nbrCount++;
        if ((xGrid + 1) < gridWidth && (*this)((xGrid + 1), (yGrid - 1))) nbrCount++;
    }

    /*Counts neighbours on the same row*/

    if (xGrid > 0 && (*this)((xGrid - 1), yGrid)) nbrCount++;
    if (((xGrid + 1)) < gridWidth && (*this)((xGrid + 1), yGrid)) nbrCount++;

    /*Counts neighbours on the row below*/

    if (yGrid + 1 < gridHeight) {
        if (xGrid > 0 && (*this)((xGrid - 1), (yGrid + 1))) nbrCount++;
        if ((*this)(xGrid, (yGrid + 1))) nbrCount++;
        if (xGrid + 1 < gridWidth && (*this)((xGrid + 1), (yGrid + 1))) nbrCount++;
    }

    return nbrCount;
}


void GolGrid::populate(double popRatio) {
    reset();

    for (int i = 0; i < gridWidth; i++) {
        for (int j = 0; j < gridHeight; j++)
            (*this)(i, j) = ((double)rand() / (double)RAND_MAX < popRatio);
    }
 }

void GolGrid::iterate() {
    Grid tmpGrid(gridWidth, gridHeight);
    tmpGrid.reset();

    for (int i = 0; i < gridWidth; i++) {
        for (int j = 0; j < gridHeight; j++) {
            int nbrCount = neighborCount(i, j);

            /*Any live cell with two or three live neighbours survives.*/
            /*Any dead cell with three live neighbours becomes a live cell.*/

            if (((*this)(i, j) && (nbrCount == 2 || nbrCount == 3)) || (!(*this)(i, j) && (nbrCount == 3)))
                tmpGrid(i, j) = true;
        }
    }

    for (int i = 0; i < gridWidth; i++) {
        for (int j = 0; j < gridHeight; j++) {
            (*this)(i, j) = tmpGrid(i, j);
        }
    }
}