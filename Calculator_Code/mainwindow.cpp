#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(Buttons_Num()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(Buttons_Num()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(Buttons_Num()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(Buttons_Num()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(Buttons_Num()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(Buttons_Num()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(Buttons_Num()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(Buttons_Num()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(Buttons_Num()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(Buttons_Num()));
    connect(ui->pushButton_Negative, SIGNAL(clicked()), this, SLOT(Operation()));
    connect(ui->pushButton_Percent, SIGNAL(clicked()), this, SLOT(Operation()));
    connect(ui->pushButton_Plus, SIGNAL(clicked()), this, SLOT(Math_Operation()));
    connect(ui->pushButton_Minus, SIGNAL(clicked()), this, SLOT(Math_Operation()));
    connect(ui->pushButton_Multi, SIGNAL(clicked()), this, SLOT(Math_Operation()));
    connect(ui->pushButton_Split, SIGNAL(clicked()), this, SLOT(Math_Operation()));

    ui->pushButton_Split->setCheckable(true);
    ui->pushButton_Minus->setCheckable(true);
    ui->pushButton_Plus->setCheckable(true);
    ui->pushButton_Multi->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Buttons_Num()
{
    QPushButton *button = (QPushButton *)sender();
    double num = (ui->Display->text()+button->text()).toDouble();
    QString label = QString::number(num,'g', 12);
    ui->Display->setText(label);
}


void MainWindow::on_pushButton_Dot_clicked()
{
    if(!(ui->Display->text().contains('.')))
        ui->Display->setText(ui->Display->text() + ".");
}

void MainWindow::Operation()
{
    QPushButton *button = (QPushButton *)sender();
    if(button->text() == "+/-")
    {
        double num = (ui->Display->text()).toDouble();
        num *= -1;
        QString label = QString::number(num,'g', 12);
        ui->Display->setText(label);
    }
    if(button->text() == "%")
    {
        double num = (ui->Display->text()).toDouble();
        num *= 0.01;
        QString label = QString::number(num,'g', 12);
        ui->Display->setText(label);
    }

}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->Display_2->clear();
    ui->Display->setText("0");
}


void MainWindow::on_pushButton_Equal_clicked()
{
    if(ui->Display_2->text().isEmpty() == 0)
    {

        first_num = calculate((ui->Display->text()).toDouble());
        QString label = QString::number(first_num, 'q', 12);
        ui->Display->setText(label);
    }
    ui->Display_2->clear();
}

void MainWindow::Math_Operation()
{
    QPushButton *button = (QPushButton *)sender();
    if(ui->Display_2->text().isEmpty() == 1)
    {
        first_num = (ui->Display->text()).toDouble();
        QString label = ui->Display->text() + button->text();
        button->setChecked(true);
        ui->Display_2->setText(label);
        ui->Display->setText("0");
    }
    else
    {
        first_num = calculate((ui->Display->text()).toDouble());
        QString label = QString::number(first_num, 'q', 12) + button->text();
        button->setChecked(true);
        ui->Display_2->setText(label);
        ui->Display->setText("0");
    }
}

double MainWindow::calculate(double second_num)
{
    double answer = NAN;
    if(ui->pushButton_Plus->isChecked() == true)
    {
        answer = first_num+second_num;
        ui->pushButton_Plus->setChecked(false);
    } else if(ui->pushButton_Minus->isChecked())
    {
        answer = first_num-second_num;
        ui->pushButton_Minus->setChecked(false);
    } else if(ui->pushButton_Multi->isChecked())
    {
        answer = first_num*second_num;
        ui->pushButton_Multi->setChecked(false);
    } else if(ui->pushButton_Split->isChecked())
    {
        if(second_num != 0)
            answer = first_num+second_num;
        ui->pushButton_Split->setChecked(false);
    }
    return answer;
}



void MainWindow::on_pushButton_Delete_clicked()
{
    QString label = ui->Display->text();
    ui->Display->setText(label.first(label.length()-1));
}

