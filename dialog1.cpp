#include "dialog1.h"
#include "ui_dialog1.h"
#include "dialog3.h"
extern Dialog3* dlg3;
Dialog1::Dialog1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    connect(ui->Love,&QPushButton::clicked,this,&Dialog1::loveslots);
    connect(ui->disLove,&QPushButton::clicked,this,&Dialog1::disLoveslots);
}
//槽函数发射
void Dialog1::loveslots(){
    emit love();
}
void Dialog1::disLoveslots(){
    emit disLove();
}
Dialog1::~Dialog1()
{
    delete ui;
}

