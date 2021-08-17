#include <cstdlib>
#include <ctime>
#include <QtWidgets>

#include "./golfield.h"

GolField::GolField(QWidget *parent) : QFrame(parent) {
    std::srand(time(0));
    setFrameStyle(QFrame::Box);
    timeStep = 100;
    fieldHeight = 100;
    fieldWidth = 100;
    cellSize = 8;
    iteration = 0;
    popRatio = 0.4;
    populate();
}

/*******Generates next step distribution********/
/************false means empty cell*************/
/************true means populated cell**********/

void GolField::iterate() {
    tmpGrid.clear();
    for (int i = 0; i < fieldWidth * fieldHeight; i++) {
        tmpGrid << false;
    }
    for (int n = 0; n < fieldWidth*fieldHeight; n++) {
        int nbrCount = neighborCount(n);

        /*Any live cell with two or three live neighbours survives.*/
        /*Any dead cell with three live neighbours becomes a live cell.*/

        if ((grid[n] && (nbrCount == 2 || nbrCount == 3)) || (!grid[n] && (nbrCount == 3)))
            tmpGrid[n] = true;

    }
    grid = tmpGrid;
    iteration++;
}

/**********************************************/
/***Counts the number of populated neighbors***/
/**********************************************/

int GolField::neighborCount(int cellNo) {
    int nbrCount = 0;
    int colNo = cellNo % fieldWidth;
    int rowNo = cellNo / fieldWidth;

   /*Counts neighbours on the row above*/

    if (rowNo > 0) {
        if (colNo > 0 && grid[cellNo - fieldWidth - 1]) nbrCount++;
        if (grid[cellNo - fieldWidth]) nbrCount++;
        if ((colNo + 1) < fieldWidth && grid[cellNo - fieldWidth + 1]) nbrCount++;
    }

   /*Counts neighbours on the same row*/

    if (colNo > 0 && grid[cellNo - 1]) nbrCount++;
    if ((colNo + 1) < fieldWidth && grid[cellNo + 1]) nbrCount++;

   /*Counts neighbours on the row below*/

    if (rowNo + 1 < fieldHeight) {
        if (colNo > 0 && grid[cellNo + fieldWidth - 1]) nbrCount++;
        if (grid[cellNo + fieldWidth]) nbrCount++;
        if (colNo + 1 < fieldWidth && grid[cellNo + fieldWidth + 1]) nbrCount++;
    }

    return nbrCount;
}

/*******Randomly populates Game of Life field********/
/*(double)rand() / (double)RAND_MAX generates [0, 1]*/
/****************************************************/

void GolField::populate() {
    grid.clear();
    iteration = 0;
    for (int i = 0; i < fieldWidth * fieldHeight; i++) {
        grid << ((double)rand() / (double)RAND_MAX < popRatio);
    }
    update();
}

/***************************************************/
/*************Starts the Game of Life***************/
/***************************************************/

void GolField::start() {
    timer.start(timeStep, this);
}

/***************************************************/
/*************Freezes the Game of Life***************/
/***************************************************/

void GolField::pause() {
    timer.stop();
}

/***************************************************/
/*************Resets the Game of Life***************/
/***************************************************/

void GolField::reset() {
    timer.stop();
    populate();
}


/***************************************************/
/*******Updates the field of the Game of Life*******/
/***************************************************/

void GolField::timerEvent(QTimerEvent *event) {
    if (event->timerId() == timer.timerId()) {
        iterate();
        update();
    } else {
        QFrame::timerEvent(event);
    }
}


/***************************************************/
/*********Paints the field of Game of Life**********/
/***************************************************/


void GolField::paintEvent(QPaintEvent* event) {
    QColor color = Qt::darkGreen;
    QPainter painter(this);

    for (int y = 0; y < fieldHeight; y++) {
        for (int x = 0; x < fieldWidth; x++) {
            if (grid[y * fieldWidth + x]) {
                painter.fillRect(x * cellSize, y * cellSize, cellSize, cellSize, color);
            }
        }
    }
}

/***************************************************/
/****Sets the size of field for the Game of Life****/
/***************************************************/

QSize GolField::sizeHint() const {
    return QSize(fieldWidth * cellSize, fieldHeight * cellSize);
}
