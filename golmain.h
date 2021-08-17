#ifndef GOLMAIN_H_
#define GOLMAIN_H_

#include <QWidget>

class GolField;
class QPushButton;

class GolMain : public QWidget {
	Q_OBJECT

public:
	GolMain(QWidget* parent = 0);

private:
	GolField *field;
	QPushButton *startButton;
	QPushButton *pauseButton;
	QPushButton *resetButton;

};

#endif  // GOLMAIN_H_
