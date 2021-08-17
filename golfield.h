#ifndef GOLFIELD_H_
#define GOLFIELD_H_

#include <QBasicTimer>
#include <QFrame>


class GolField : public QFrame {
  Q_OBJECT

 public:
    GolField(QWidget *parent = 0);
    QSize sizeHint() const;

public slots:
   void start();
   void pause();
   void reset();

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
    QVector<bool> grid;
    QVector<bool> tmpGrid;

    void populate();
    int neighborCount(int cellNo);
    void iterate();

};

#endif  // GOLFIELD_H_
