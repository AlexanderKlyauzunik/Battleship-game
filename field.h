#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QWidget>

class Field : public QWidget
{
    Q_OBJECT
public:
    Field(QWidget *parent = nullptr);
    Field(int size, QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
 //   void mousePressEvent(QMouseEvent *event) override;
 //   void mouseMoveEvent(QMouseEvent *event) override;;
 //   void mouseReleaseEvent(QMouseEvent *event) override;;

private:
    int CheckEnd(std::pair<int, int> index);
   // int CheckEndLight(std::pair<int, int> index);
    std::pair<QPoint, QPoint> final;

    int sizeMultiplier = 150;
    int size;
   // float sqXSize;
   // float sqYSize;
   // int mode;
    QVector<QVector<int>> field;

   // std::pair<int, int> ComputersTurn();
    //std::pair<int, int> RandomTurn();
   // std::pair<std::pair<int, int>, int> HardTurn(int depth);
   // std::pair<int, int> HardTurn();
   // QVector<std::pair<int, int>> findVacant();
signals:

};

#endif // FIELD_H
