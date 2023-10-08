// Кафедра программного обеспечения вычислительной техники и автоматизированных систем
// БГТУ им. В.Г. Шухова
// Автор: Осипов О.В.

#include "jscrollbar.h"

namespace bstu {

JScrollBar::JScrollBar(QWidget *parent) : QScrollBar(parent)
{

}



void JScrollBar::setChartRange(double a, double b)
{
  x1 = a;
  x2 = b;
}



void JScrollBar::getVisibleRangeX(double* _x1, double* _x2)
{
  double k = pageStep() / (double) (maximum() - minimum() + pageStep());
  *_x1 = x1 + (x2 - x1) * (1 - k) * (value() - minimum()) / (maximum() - minimum());
  *_x2 = *_x1 + k * (x2 - x1);
}



void JScrollBar::getVisibleRangeY(double* _y1, double* _y2)
{
  double k = pageStep() / (double) (maximum() - minimum() + pageStep());
  *_y1 = x1 + (x2 - x1) * (1 - k) * (maximum() - value()) / (maximum() - minimum());
  *_y2 = *_y1 + k * (x2 - x1);
}



// Процедура устанавливает позицию горизонтального ползунка
void JScrollBar::setBarValue(double p, int wheel_delta)
{
  double k = (wheel_delta > 0) ? 1.2 : 0.8;
  double length = maximum() - minimum();
  double prevPageStep = pageStep();       // Текущая длина страницы
  double newPageStep = prevPageStep*k;    // Новая длина страницы
  if (newPageStep > length*5)
   newPageStep = length*5;
  int pos1 = value();                     // Текущая позиция
  double w1 = length + pageStep();        // Текущая ширина всего поля
  double w2 = length + newPageStep;       // Новая ширина всего поля
  // Вычисляем новую позицию ползунка
  int pos2 = (pos1 + prevPageStep*p) / w1 * w2 - newPageStep*p;
  // Проверить, не вышло ли значение позиции ползунка за границы
  if (pos2 < minimum()) pos2 = minimum();
  if (pos2 > maximum()) pos2 = maximum();
  if (newPageStep > 10 && newPageStep < length*5)
  {
    // Меняем ширину ползунка и его позицию в зависимости от того, что накрутил пользователь
    setPageStep(newPageStep);
    setValue(pos2);
    if (pos1 == pos2) // Если старая и новая позиции совпадают, то всё равно нужно перерисовать окна, так как изменилась ширина ползунка
     valueChanged(pos1);
  }
}

}
