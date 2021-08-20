#include <ctime>
#include <QtWidgets>

#include "./golfield.h"
#include "./golgrid.h"

GolField::GolField(QWidget *parent) : QFrame(parent) {
    std::srand(time(0));
    setFrameStyle(QFrame::Box);
    timeStep = 100;
    fieldHeight = 100;
    fieldWidth = 100;
    cellSize = 8;
    iteration = 0;
    popRatio = 0.4;
    grid = new GolGrid(fieldWidth, fieldHeight);
    populate();
}

/*******Randomly populates Game of Life field********/
/****************************************************/

void GolField::populate() {
    grid->populate(popRatio);
    iteration = 0;
    update();
}

/*******Generates next step distribution********/
/************false means empty cell*************/
/************true means populated cell**********/

void GolField::iterate() {
    grid->iterate();
    iteration++;

    emit changeIterationsLabel(tr("Iterations: %1").arg(iteration));
    emit changeLiveCellsLabel(tr("Ratio of Alive Cells: %1 %").arg(ratioLiveCells(), 4, 'f', 1));
}

/**********************************************/
/*****Calculates the number of cells alive*****/
/**********************************************/

double GolField::ratioLiveCells(){

    return ((float)grid->countLiveCells() / (fieldWidth * fieldHeight)) * 100;
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
    iteration = 0;
    emit changeIterationsLabel(tr("Iterations: %1").arg(iteration));
    emit changeLiveCellsLabel(tr("Ratio of Alive Cells: %1 %").arg(ratioLiveCells(), 4, 'f', 1));
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

    for (int x = 0; x < fieldWidth; x++) {
        for (int y = 0; y < fieldHeight; y++)
            if ((*grid)(x, y)) {
                painter.fillRect(x * cellSize, y * cellSize, cellSize, cellSize, color);
            }
    }

}

/***************************************************/
/****Sets the size of field for the Game of Life****/
/***************************************************/

QSize GolField::sizeHint() const {
    return QSize(fieldWidth * cellSize, fieldHeight * cellSize);
}
