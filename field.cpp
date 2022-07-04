#include <QPainter>
#include<QBrush>
#include<QPen>
#include "field.h"

Field::Field(QWidget *parent)
    : Field(10, parent)
{

}

Field::Field(int size, QWidget *parent): QWidget(parent)
{
    this->size = size;
 //this->resize(size*sizeMultiplier,size*sizeMultiplier);
    // sqXSize = this->width() / size;
    // sqYSize = this->height() / size;
    QVector<int> str;
    str.fill(-1, size);
    this->field.fill(str, size);
    final.first = QPoint(0, 0);
    final.second = QPoint(0, 0);
}

void Field::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

   QRect widgetRect=this->rect();
   QPainter painter(this);
   QPen pen(Qt::black,2.5);
   QPen redPen(Qt::red, 5);
   painter.setPen(pen);
   QColor lighter(256,256,256);
   QColor darker(200, 200, 200);
   QBrush brush(lighter);
   QBrush DarkerBrush(darker);
   int dy = widgetRect.height()/size;
   int dx = widgetRect.width()/size;

   for(int i = 0; i < this->size; i++){
       for(int j = 0; j < this->size; j++){
           i % 2 == j % 2 ? painter.setBrush(brush) : painter.setBrush(DarkerBrush);
           painter.setPen(pen);
         painter.drawRect(i * dx, j*dy, dx ,dy);
   }

       int num;
       painter.setPen(redPen);
       for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                num = this->field[i][j];

      switch(num){
      case -1:
          break;
       case 0:
          painter.drawEllipse(i * dx + dx/3,  j*dy + dy / 3 , dy/3,dy/3);
          break;
      case 1:
          painter.drawLine(i * dx + dx/3, j*dy + dy / 3, i * dx + dx - dx/3, j*dy +dy - dy/3);
          painter.drawLine(i * dx + dx/3,j*dy +dy - dy/3 , i * dx + dx - dx/3, j*dy + dy / 3 );
          break;
      }
      }
       }
   }
}

  // void Field::mousePressEvent(QMouseEvent *event)
  // {

  // }

  // void Field::mouseMoveEvent(QMouseEvent *event){}

  // void Field::mouseReleaseEvent(QMouseEvent *event){}
