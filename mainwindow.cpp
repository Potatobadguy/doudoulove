#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog1.h"
#include "dialog2.h"
#include "dialog3.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dlg1 = new Dialog1(this);


    dlg2 = new Dialog2(this);


    dlg3 = new Dialog3(this);
    // 全局应用模态：锁定主窗口，子窗口之间可自由切换
    dlg1->setWindowModality(Qt::ApplicationModal);
    dlg2->setWindowModality(Qt::ApplicationModal);
    dlg3->setWindowModality(Qt::ApplicationModal);

    // 窗口关闭后自动释放内存，避免内存泄漏
    dlg1->setAttribute(Qt::WA_DeleteOnClose);
    dlg2->setAttribute(Qt::WA_DeleteOnClose);
    dlg3->setAttribute(Qt::WA_DeleteOnClose);
    connect(dlg1,&Dialog1::love,dlg3,&Dialog3::Loveslots);
    connect(dlg2,&Dialog2::love,dlg3,&Dialog3::Loveslots);
    connect(dlg3,&Dialog3::Love,dlg1,&Dialog1::close);
    connect(dlg3,&Dialog3::Love,dlg2,&Dialog2::close);
    connect(dlg3,&Dialog3::Love,dlg3,&Dialog3::close);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::close);
    connect(dlg1,&Dialog1::disLove,dlg1,&Dialog1::close);
    connect(dlg2,&Dialog2::disLove,dlg2,&Dialog2::close);
    dlg1->exec();
    dlg2->exec();
    dlg3->exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
