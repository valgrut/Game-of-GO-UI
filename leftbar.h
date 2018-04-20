#ifndef LEFTBAR_H
#define LEFTBAR_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "score.h"

class LeftBar : public QFrame
{
    Q_OBJECT
public:
    explicit LeftBar(QWidget *parent = 0);

    Score *_scoreBoard;

signals:

public slots:

private:

};

#endif // LEFTBAR_H
