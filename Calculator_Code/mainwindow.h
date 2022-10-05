#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

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
    void Buttons_Num();

    void on_pushButton_Dot_clicked();

    void Operation();

    void on_pushButton_AC_clicked();

    void on_pushButton_Equal_clicked();

    void Math_Operation();

    void on_pushButton_Delete_clicked();

private:
    Ui::MainWindow *ui;
    double first_num;
    double calculate(double second_num);

};
#endif // MAINWINDOW_H
