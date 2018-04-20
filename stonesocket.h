#ifndef STONESOCKET_H
#define STONESOCKET_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QPair>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

class StoneSocket : public QFrame
{
    Q_OBJECT
public:
    explicit StoneSocket(QWidget *parent = 0);
    StoneSocket(int x, int y);
    ~StoneSocket();

    QString static nextColor;

    void setEmpty(bool empty);
    bool isEmpty() const;

    void setPosition(unsigned int x, unsigned int y) {_coord.first = x; _coord.second = y;}
    void setPosition(QPair<unsigned int, unsigned int> &c) {_coord = c;}

    void showStone();
    void hideStone();

    void setForegroundKolecko();
    void setForeground(QString path);
    void showForeground();
    void hideForeground();

    void mouseReleaseEvent ( QMouseEvent * event );
    void mouseMoveEvent( QMouseEvent * event );

    // static
    void static setNextColor(QString next) {nextColor = next;}
    QString static getNextColor() {return nextColor;}

signals:
    void clickedOnPos(unsigned int x, unsigned int y);

public slots:
    void setColor(QString color);

private:
    QString color;
    QPair<int, int> _coord;
    bool empty;
    QLabel *_foreground;
};

#endif // STONESOCKET_H
