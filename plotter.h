#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>

class Plotter : public QWidget
{
    Q_OBJECT
private:
    float amplitude, frequencia, velocidade, angulo;
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
signals:
    void mudouX(int); // o sinal muxouX emite um inteiro
    void mudouY(int);
public slots:
    void setAmplitude(int _amplitude);
    void setFrequencia(int _frequencia);
    void setVelocidade(int _velocidade);
};

#endif // PLOTTER_H
