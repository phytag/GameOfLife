#ifndef GOLMAIN_H_
#define GOLMAIN_H_

#include <QWidget>

class GolField;
class QPushButton;
class QLabel;

class GolMain : public QWidget {
	Q_OBJECT

public:
	GolMain(QWidget* parent = 0);

private:
	GolField *field;
	QPushButton *startButton;
	QPushButton *pauseButton;
	QPushButton *resetButton;

    QLabel *liveCellsLabel;
    QLabel *iterationLabel;
};

#endif  // GOLMAIN_H_
