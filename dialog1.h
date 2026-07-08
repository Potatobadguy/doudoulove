#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();
signals:
    void disLove();
    void love();
private slots:
    void loveslots();
    void disLoveslots();

private:
    Ui::Dialog1 *ui;
};

#endif // DIALOG1_H
