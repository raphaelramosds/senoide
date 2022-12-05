#define PI 3.1415

#include <cmath>

#include "plotter.h"

#include <QPainter>// pintor
#include <QBrush> // preenchimento
#include <QPen>  // contorno
#include <QMouseEvent>

Plotter::Plotter(QWidget *parent)
    : QWidget{parent}
{
    amplitude = 1;
    frequencia = 1;
    angulo = 0;
    velocidade = 0;

    // chama o método timerEvent a cada 100 ms

    startTimer(100);

    // habilitar o movimento de rastreio do mouse (naturalmente desabilitada pelo Qt)

    setMouseTracking(1);
}

void Plotter::timerEvent(QTimerEvent *event)
{
    if (angulo > 2*PI) angulo = 0;
    angulo += velocidade; // a cada pulso do timer, desloque a onda 0.1 rad
    repaint();
}

void Plotter::mousePressEvent(QMouseEvent *event)
{
    // o SIGNAL mudouX() emite a posição x do mouse da tela do Widget ao clicar na tela do Widget Plotter
    emit mudouX(event->x());
    emit mudouY(event->y()); // daí conectamos esse SIGNAL com o SLOT dos LCDs
}

void Plotter::mouseMoveEvent(QMouseEvent *event)
{
    emit mudouX(event->x());
    emit mudouY(event->y());
}

void Plotter::paintEvent(QPaintEvent *event)
{
    int x1,x2,y1,y2;

    QPainter painter(this); // o painter deve pintar no espaço de tela do widget Plotter
    QBrush brush;
    QPen pen;

    // lata de tinta (preenchimento)

    brush.setColor(QColor(0,0,0));
    brush.setStyle(Qt::SolidPattern);

    // caneta (contorno)

    pen.setColor(QColor(0,255,0));
    pen.setWidth(2);

    // pintor, desenhe um retangulo com a largura e altura do componente

    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0,0,width(),height());

    // Desenha linha no meio

    pen.setColor(QColor(0,150,0));
    painter.setPen(pen);
    painter.drawLine(0,height()/2,width(),height()/2);

    // Desenhar o seno

    x1 = 0;
    y1 = height()/2;

    for (int j = 1; j < width(); j++) {
        x2 = j;
        y2 = 0.5*height() - 0.5*amplitude*height()*std::sin((2*PI*frequencia/width())*x2 + angulo);
        painter.drawLine(x1,y1,x2,y2);
        x1 = x2;
        y1 = y2;
    }
}

void Plotter::setAmplitude(int _amplitude)
{
    amplitude = (float) _amplitude/99.0;
    repaint(); // forçar pintura ao modificar amplitude
}

void Plotter::setFrequencia(int _frequencia)
{
    frequencia = (float) _frequencia;
    repaint();
}

void Plotter::setVelocidade(int _velocidade)
{
    velocidade = (float) _velocidade/99.0;
}

