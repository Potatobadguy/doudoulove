#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog1.h"
#include "dialog3.h"
#include "dialog2.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private:
    Ui::MainWindow *ui;
    Dialog1* dlg1;
    Dialog2* dlg2;
    Dialog3* dlg3;

};
#endif // MAINWINDOW_H
