#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QListWidgetItem>
#include <QMessageBox>

#include <objects/objects.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:


  void on_listWidget_itemClicked(QListWidgetItem *item);

  void on_lineEdit_editingFinished();

  void on_red_button_clicked();

  void on_gray_button_clicked();

  void on_yellow_button_clicked();

  void on_horizontalSlider_valueChanged(int value);

  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;
  int ID_planet, ID_buffer = 5;
  const int length = 10;
  Planet *planets[10];
};
#endif // MAINWINDOW_H
