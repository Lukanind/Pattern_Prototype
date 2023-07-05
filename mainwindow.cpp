#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include <QString>

#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
      scene = new QGraphicsScene(this);
      scene->setItemIndexMethod(QGraphicsScene::NoIndex);


      ui->graphicsView->setScene(scene);

      Planet basic_planet("Planet1", 1, Qt::gray);

      for (int i = 0; i<length; i++){
          planets[i] = basic_planet.clone();
        }
      for (int i = 0; i<length; i++){
          scene->addItem(planets[i]);
          planets[i]->hide();
        }
}

MainWindow::~MainWindow()
{
  delete ui;
}



void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
  Q_UNUSED(item);
ID_planet = ui->listWidget->currentRow();
qDebug() << ID_planet;

QString a = QString::fromStdString(planets[ID_planet]->get_name());
ui->lineEdit->setText(a);
int b =planets[ID_planet]->get_size();
ui->horizontalSlider->setValue(b);
scene->update();
for (int i = 0; i<length; i++){
    planets[i]->hide();
    if (i == ID_planet) planets[ID_planet]->show();
  }
scene->update();
}

void MainWindow::on_lineEdit_editingFinished()
{
  QString Name = ui->lineEdit->text();
  planets[ID_planet]->set_name(Name.toStdString());
  scene->update();
  for (int i = 0; i<length; i++){
      planets[i]->hide();
      if (i == ID_planet) planets[ID_planet]->show();
    }
}

void MainWindow::on_red_button_clicked()
{
    planets[ID_planet]->set_color(Qt::red);
    scene->update();
    for (int i = 0; i<length; i++){
        planets[i]->hide();
        if (i == ID_planet) planets[ID_planet]->show();
      }
}

void MainWindow::on_gray_button_clicked()
{
  planets[ID_planet]->set_color(Qt::gray);
  scene->update();
  for (int i = 0; i<length; i++){
      planets[i]->hide();
      if (i == ID_planet) planets[ID_planet]->show();
    }
}

void MainWindow::on_yellow_button_clicked()
{
  planets[ID_planet]->set_color(Qt::yellow);
  scene->update();
  for (int i = 0; i<length; i++){
      planets[i]->hide();
      if (i == ID_planet) planets[ID_planet]->show();
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
  Q_UNUSED(value);
  int a = ui->horizontalSlider->value();
    planets[ID_planet]->set_size(a);
    scene->update();
    for (int i = 0; i<length; i++){
        planets[i]->hide();
        if (i == ID_planet) planets[ID_planet]->show();
      }
}

void MainWindow::on_pushButton_clicked()
{
    if (ID_buffer == 10) QMessageBox::critical(this, "Хватит!", "Столько планет тебе не нужно!");
        else {
    delete planets[ID_buffer];
    planets[ID_buffer] = planets[ID_planet]->clone();
    scene->addItem(planets[ID_buffer]);
    planets[ID_buffer]->hide();
    QString a = QString::fromStdString(std::to_string(ID_buffer+1));
    ui->listWidget->addItem(a);
    ID_buffer++;
    scene->update();
    for (int i = 0; i<length; i++){
        planets[i]->hide();
        if (i == ID_planet) planets[ID_planet]->show();
      }
    }
}
