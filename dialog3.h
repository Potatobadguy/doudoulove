#ifndef DIALOG3_H
#define DIALOG3_H

#include <QDialog>

namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT
protected:
    // 重写关闭事件
    void closeEvent(QCloseEvent *event) override;
public:
    explicit Dialog3(QWidget *parent = nullptr);
    ~Dialog3();
signals:
    void Love();
    void disLove();
public slots:
    void Loveslots();
    void disLoveslots();
private:
    bool love_close = false;
    Ui::Dialog3 *ui;
};

#endif // DIALOG3_H
