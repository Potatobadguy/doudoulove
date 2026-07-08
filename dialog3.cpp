#include "dialog3.h"
#include "ui_dialog3.h"
#include <QCloseEvent>
#include <QMessageBox>
Dialog3::Dialog3(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog3)
{
    ui->setupUi(this);
    connect(ui->Love,&QPushButton::clicked,this,&Dialog3::Loveslots);
    connect(ui->disLove,&QPushButton::clicked,this,[=](){
        ui->disLove->hide();
    });
}
//槽函数发射信号
void Dialog3::Loveslots(){
    love_close = true;
    emit Love();
}
void Dialog3::disLoveslots(){
    emit disLove();
}
#include <QMessageBox>

void Dialog3::closeEvent(QCloseEvent *event)
{   if(love_close){
        event->accept();
        love_close = false;
        return;
    }
    QMessageBox msgBox(this);
    // 2. 分步设置属性
    msgBox.setIcon(QMessageBox::Question);    // 问号图标
    msgBox.setWindowTitle("坏东西");          // 弹窗标题
    msgBox.setText("别想逃避！还想干坏事？");  // 提示文本
    // 3. 添加按钮
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    // 4. 自定义按钮文字
    // 修改 Yes 按钮文字
    msgBox.button(QMessageBox::Yes)->setText("爱豆豆");
    // 修改 No 按钮文字
    msgBox.button(QMessageBox::No)->setText("关不掉的");

    // 弹出窗口并获取点击结果
    int ret = msgBox.exec();
    // // 弹出确认框
    // int ret = QMessageBox::question(this, "坏东西", "别想逃避！还想干坏事？",
    //                                 QMessageBox::Yes | QMessageBox::No);
    if (ret == QMessageBox::Yes)
    {
        // 允许关闭，执行释放资源、保存数据等操作
        event->accept();
    }
    else
    {
        // 忽略关闭，窗口不消失
        event->ignore();
    }
}
Dialog3::~Dialog3()
{
    delete ui;
}
