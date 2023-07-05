#include "objects.h"
#include <QBitmap>
#include <QImage>
#include <QDebug>

Planet *Planet::clone() const
{
  return new Planet(name, size, color);
}

QRectF Planet::boundingRect() const
{
  return QRectF(-50,0,200,200);
}

void Planet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  Q_UNUSED(option);
  Q_UNUSED(widget);

  QPen point_red(Qt::red, 3, Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin);
  QPixmap texture_planet;

  //Определение текстуры
  if (this->color == Qt::gray){
      texture_planet.load(":images/gray_planet.png");
    }
  if (this->color == Qt::red){
      texture_planet.load(":images/red_planet.png");
    }
  if (this->color == Qt::yellow){
      texture_planet.load(":images/planet_texture.png");
    }

  int w;
  int h;
  int x = 0, y = 0;

  if (this->size == 0){
      w = 100;
      h = 100;
      x = 0; y = 0;
    }
  if (this->size == 1){
      w = 150;
      h = 150;
      x = 0; y = 0;
    }
  if (this->size == 2){
      w = 200;
      h = 200;
      x = -50; y = -50;
    }

  QBrush brush(texture_planet);
  painter->setBrush(brush);
  painter->drawEllipse(x, y, w, h);

}

std::string Planet::get_name()
{
  return name;
}

int Planet::get_size()
{
  return size;
}

void Planet::set_size(int Size)
{
  size = Size;
}

void Planet::set_name(std::string Name)
{
  name = Name;
}

void Planet::set_color(QColor Color)
{
  color = Color;
}

objects::objects()
{

}
