#ifndef GOLFIELD_H_
#define GOLFIELD_H_

#include <QBasicTimer>
#include <QFrame>

class GolGrid;

class GolField : public QFrame {
  Q_OBJECT

 public:
    GolField(QWidget *parent = 0);
    QSize sizeHint() const;
    double ratioLiveCells();

public slots:
   void start();
   void pause();
   void reset();

signals:
   void changeIterationsLabel(QString);
   void changeLiveCellsLabel(QString);

 protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);


 private:
    int cellSize;
    int fieldHeight;
    int fieldWidth;

    int timeStep;
    int iteration;
    double popRatio;

    QBasicTimer timer;
    GolGrid *grid;

    void populate();
    void iterate();

};

#endif  // GOLFIELD_H_
