#ifndef GRID_H_
#define GRID_H_

class Grid {
public:
	Grid();
	Grid(int gridWidth, int gridHeight);
	~Grid();

	bool& operator()(int xGrid, int yGrid) const;
	void reset();
	void print() const;

protected:
	int gridWidth;
	int gridHeight;

private:

	bool *gridContainer;


};

#endif //GRID_H_
