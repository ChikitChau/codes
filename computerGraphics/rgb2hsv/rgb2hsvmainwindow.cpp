#include "rgb2hsvmainwindow.h"
#include "ui_rgb2hsvmainwindow.h"

rgb2hsvMainWindow::rgb2hsvMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::rgb2hsvMainWindow)
{
    ui->setupUi(this);
}

rgb2hsvMainWindow::~rgb2hsvMainWindow()
{
    delete ui;
}



void rgb2hsvMainWindow::on_pushButton_clicked()
{
    QString R=ui->lineEdit->text();
    QString G=ui->lineEdit_2->text();
    QString B=ui->lineEdit_3->text();
    float r=R.toFloat();
    float g=G.toFloat();
    float b=B.toFloat();
    float h = 0.0, s = 0.0, v = 0.0;
    r=r/255;
    g=g/255;
    b=b/255;

    float max=r;
    float min=r;
    //最大值
    if (max < g)
        max=g;
    if (max < b)
        max=b;
    //最小值
    if (min > g)
        min=g;
    if (min > b)
        min=b;

    float delta=max-min;
    v = max;

    if (max == 0)
        s = 0;
    else
        s = delta / max;

    if (delta == 0)
        h = 0;
    else if (max == r && g >= b)
        h = 60 * ((g - b) / delta);
    else if (max == r && g < b)
        h = 60 * ((g - b) / delta) + 360;
    else if (max == g)
        h = 60 * ((b - r) / delta) + 120;
    else if (max == b)
        h = 60 * ((r - g) / delta) + 240;
    v = v * 100;
    s = s * 100;

    R=R.sprintf("%.0f",h);
    G=G.sprintf("%.0f",s);
    B=B.sprintf("%.0f",v);

    ui->lineEdit_4->setText(R);
    ui->lineEdit_5->setText(G);
    ui->lineEdit_6->setText(B);
}

void rgb2hsvMainWindow::on_pushButton_3_clicked()
{
    QString H=ui->lineEdit_4->text();
    QString S=ui->lineEdit_5->text();
    QString V=ui->lineEdit_6->text();
    float h=H.toFloat();
    float s=S.toFloat();
    float v=V.toFloat();

    float r=0.0, g=0.0, b=0.0;
    float c = 0.0, x = 0.0, y = 0.0, z = 0.0;
    int i = 0;
    s = s / 100.0;
    v = v / 100.0;
    if (s == 0)
        r = g = b = v;
    else
    {
        h = h / 60;
        i = (int)h;
        c = h - i;
        x = v * (1 - s);
        y = v * (1 - s * c);
        z = v * (1 - s * (1 - c));

        switch (i) {
        case 0:
            r = v;
            g = z;
            b = v;
            break;
        case 1:
            r = y;
            g = v;
            b = x;
            break;
        case 2:
            r = x;
            g = v;
            b = z;
            break;
        case 3:
            r = x;
            g = y;
            b = v;
            break;
        case 4:
            r = z;
            g = x;
            b = v;
            break;
        case 5:
            r = v;
            g = x;
            b = y;
            break;
        }
    }
    r = r * 255;
    g = g * 255;
    b = b * 255;

    H=H.sprintf("%.0f",r);
    S=S.sprintf("%.0f",g);
    V=V.sprintf("%.0f",b);

    ui->lineEdit->setText(H);
    ui->lineEdit_2->setText(S);
    ui->lineEdit_3->setText(V);
}





