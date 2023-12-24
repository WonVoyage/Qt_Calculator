#include "mainwindow.h"
#include "ui_mainwindow.h"

//------------------------------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), First_Number(0.0)
{
    ui->setupUi(this);
    connect(ui->Button_0, SIGNAL(clicked()), SLOT(Digit_Numbers()));
    connect(ui->Button_1, SIGNAL(clicked()), SLOT(Digit_Numbers()));
    connect(ui->Button_2, SIGNAL(clicked()), SLOT(Digit_Numbers()));
    connect(ui->Button_3, SIGNAL(clicked()), SLOT(Digit_Numbers()));
    connect(ui->Button_4, SIGNAL(clicked()), SLOT(Digit_Numbers()));
    connect(ui->Button_5, SIGNAL(clicked()), SLOT(Digit_Numbers()));
    connect(ui->Button_6, SIGNAL(clicked()), SLOT(Digit_Numbers()));
    connect(ui->Button_7, SIGNAL(clicked()), SLOT(Digit_Numbers()));
    connect(ui->Button_8, SIGNAL(clicked()), SLOT(Digit_Numbers()));
    connect(ui->Button_9, SIGNAL(clicked()), SLOT(Digit_Numbers()));

    connect(ui->Button_Plus_Minus, SIGNAL(clicked()), SLOT(Operations()));

    connect(ui->Button_Plus, SIGNAL(clicked()), SLOT(Math_Operations()));
    connect(ui->Button_Minus, SIGNAL(clicked()), SLOT(Math_Operations()));
    connect(ui->Button_Divide, SIGNAL(clicked()), SLOT(Math_Operations()));
    connect(ui->Button_Multiply, SIGNAL(clicked()), SLOT(Math_Operations()));

    ui->Button_Plus->setCheckable(true);
    ui->Button_Minus->setCheckable(true);
    ui->Button_Divide->setCheckable(true);
    ui->Button_Multiply->setCheckable(true);
}
//------------------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::Digit_Numbers()
{
    QPushButton *button;
    QString new_label;
    double all_numbers;

    button = (QPushButton *)sender();

    if (ui->Label_Result->text().contains(".") && button->text() == "0")
    {
        new_label = ui->Label_Result->text() + button->text();
    }
    else
    {
        all_numbers = (ui->Label_Result->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
    }

    ui->Label_Result->setText(new_label);
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::on_Button_Dot_clicked()
{
    if (!(ui->Label_Result->text().contains('.')))
        ui->Label_Result->setText(ui->Label_Result->text() + '.');
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::Operations()
{
    QPushButton *button;
    QString new_label;
    double all_numbers;

    button = (QPushButton *)sender();

    if (button->text() == "+/-")
    {
        all_numbers = (ui->Label_Result->text()).toDouble();
        all_numbers *= -1;
        new_label = QString::number(all_numbers, 'g', 15);
    }
    else
    {
        if (button->text() == "%")
        {
            all_numbers = (ui->Label_Result->text()).toDouble();
            all_numbers *= 0.01;
            new_label = QString::number(all_numbers, 'g', 15);
        }

    }
    ui->Label_Result->setText(new_label);
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::Math_Operations()
{
    QPushButton *button;

    button = (QPushButton *)sender();
    First_Number = ui->Label_Result->text().toDouble();
    ui->Label_Result->setText("");
    button->setChecked(true);
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::on_Button_Equel_clicked()
{
    double label_number, num_second;
    QString new_label;

    num_second = ui->Label_Result->text().toDouble();

    if (ui->Button_Plus->isChecked())
    {
        label_number = First_Number + num_second;
        new_label = QString::number(label_number, 'g', 15);
        ui->Label_Result->setText(new_label);
        ui->Button_Plus->setChecked(false);
    }
    else
    {
        if (ui->Button_Minus->isChecked())
        {
            label_number = First_Number - num_second;
            new_label = QString::number(label_number, 'g', 15);
            ui->Label_Result->setText(new_label);
            ui->Button_Minus->setChecked(false);
        }
        else
        {
            if (ui->Button_Divide->isChecked())
            {
                if (num_second == 0)
                    ui->Label_Result->setText("0");
                else
                {
                    label_number = First_Number / num_second;
                    new_label = QString::number(label_number, 'g', 15);
                    ui->Label_Result->setText(new_label);
                    ui->Button_Divide->setChecked(false);
                }
            }
            else
            {
                if (ui->Button_Multiply->isChecked())
                {
                    label_number = First_Number * num_second;
                    new_label = QString::number(label_number, 'g', 15);
                    ui->Label_Result->setText(new_label);
                    ui->Button_Multiply->setChecked(false);
                }
            }
        }
    }
}
//------------------------------------------------------------------------------------------------------------
void MainWindow::on_Button_Clear_clicked()
{
    ui->Button_Plus->setChecked(false);
    ui->Button_Minus->setChecked(false);
    ui->Button_Divide->setChecked(false);
    ui->Button_Multiply->setChecked(false);

    ui->Label_Result->setText("0");
}
//------------------------------------------------------------------------------------------------------------
