#include "dialog2.h"
#include "ui_dialog2.h"
#include "dialog3.h"
extern Dialog3* dlg3;
Dialog2::Dialog2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    connect(ui->Love,&QPushButton::clicked,this,&Dialog2::loveslots);
    connect(ui->disLove,&QPushButton::clicked,this,&Dialog2::disLoveslots);
}
//槽函数发射信号
void Dialog2::loveslots(){
    emit love();
}
void Dialog2::disLoveslots(){
    emit disLove();
}
Dialog2::~Dialog2()
{
    delete ui;
}
