#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // SIGNAL valuChanged() do componente horizontalSlider -> SLOT setVelocidade() do widget Plotter

    connect(ui->horizontalSliderVelocidade,
            SIGNAL(valueChanged(int)),
            ui->widget,
            SLOT(setVelocidade(int)));

    // SIGNAL mudouX() do widget Plotter -> SLOT display(int) do objeto lcdNumberX

    connect(ui->widget,
            SIGNAL(mudouX(int)),
            ui->lcdNumberX,
            SLOT(display(int)));

    // SIGNAL mudouY() do widget Plotter -> SLOT display(int) do objecto lcdNumberY

    connect(ui->widget,
            SIGNAL(mudouY(int)),
            ui->lcdNumberY,
            SLOT(display(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

