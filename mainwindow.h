#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); // prioridade do objeto
    ~MainWindow();

// Slots: funções que capturam signals (eventos) de click, hover, etc..

public slots:
    // void quit();

private:
    Ui::MainWindow *ui; // ponteiro para os objetos da interface
};
#endif // MAINWINDOW_H
