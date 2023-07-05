#ifndef OBJECTS_H
#define OBJECTS_H

#pragma once
#include <QGraphicsItem>
#include <string>
#include <QPainter>
#include <QPixmap>


class objects: public QGraphicsItem
{
public:
  objects();
  virtual objects* clone() const = 0;
private:

};

class Planet : public objects
{
public:
  Planet(std::string Name, int Size, QColor Color)
    : name(Name),
      size(Size),
      color(Color)
  {}

   Planet* clone() const override;
   QRectF boundingRect() const override;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

   std::string get_name();
   int get_size();

   void set_size(int Size);
   void set_name(std::string Name);
   void set_color(QColor Color);

private:
   std::string name;
   int size;
  QColor color;
};

#endif // OBJECTS_H
