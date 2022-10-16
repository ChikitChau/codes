#ifndef RGB2HSVMAINWINDOW_H
#define RGB2HSVMAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class rgb2hsvMainWindow; }
QT_END_NAMESPACE

class rgb2hsvMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    rgb2hsvMainWindow(QWidget *parent = nullptr);
    ~rgb2hsvMainWindow();
    float retmax(float a, float b, float c);
    float retmin(float a, float b, float c);
    void rgb_to_hsv(float* h, float* s, float* v, float r, float g, float b);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::rgb2hsvMainWindow *ui;
};
#endif // RGB2HSVMAINWINDOW_H
