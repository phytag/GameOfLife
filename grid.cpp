#include <iostream>
#include <cassert>
#include "./grid.h"
using namespace std;

Grid::Grid()
{
	gridWidth = 0;
	gridHeight = 0;
	gridContainer = 0;
}

Grid::Grid(int gridW, int gridH) 
{
	gridWidth = gridW;
	gridHeight = gridH;
	gridContainer = new bool[gridWidth * gridHeight];
	assert(gridContainer != 0);
}

Grid::~Grid() 
{
	delete gridContainer;
}


bool& Grid::operator()(int xGrid, int yGrid) const
{
	if (xGrid >= 0 && yGrid >= 0 && xGrid < gridWidth && yGrid < gridHeight) {
		return gridContainer[xGrid + yGrid * gridWidth];
	}
	else {
		cerr << "Wrong index of the grid!" << endl;
		exit(1);
	}
}

void Grid::reset()
{
	for (int i = 0; i < gridWidth * gridHeight; i++)
		gridContainer[i] = false;
}

void Grid::print() const
{
	for (int i = 0; i < gridWidth; i++) {
		for (int j = 0; j < gridHeight; j++)
			cout << i << "\t" << j << "\t" << (*this)(i, j) << "\n";
	}
}


