# GameOfLife
This is a small implementation of Conway's Game of Life cellular automaton using Qt framework.

Short rules of the game:
1. Any live cell with two or three live neighbours survives.
2. Any dead cell with three live neighbours becomes a live cell.

https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

QFrame Qt class is used to create the field in which Game of Life takes place.
Qvector is used as a conatainer for the Game of Life cell grid information (true if cell is live, false if cell is dead).
QBasicTimer Qt class is used to implement timer with specified time step lenght.
QPainter Qt class is used to draw the Game of Life field. Initial cell grid is generated randomly with the given population rate.

