#ifndef GOLGRID_H_
#define GOLGRID_H_

#include "./grid.h"

class GolGrid : public Grid {

public:
	GolGrid(int gridWidth, int gridHeight);
	void populate(double popRatio);
	int neighborCount(int xGrid, int yGrid);
	int countLiveCells() const;
	void iterate();
private:
};

#endif //GOLGRID_H_
