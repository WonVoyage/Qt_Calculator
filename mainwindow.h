#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double First_Number;

    QStack<QString> Stack_Operations;

private slots:
    void Digit_Numbers();
    void Operations();
    void Math_Operations();
    void on_Button_Dot_clicked();
    void on_Button_Equel_clicked();
    void on_Button_Clear_clicked();

};
#endif // MAINWINDOW_H
