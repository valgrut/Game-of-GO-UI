#ifndef BIGBOARD_H
#define BIGBOARD_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "stonesocket.h"
#include "virtualgoban.h"

class BigBoard : public VirtualGoban
{
    Q_OBJECT
public:
    explicit BigBoard(QWidget *parent = 0, unsigned int size = 0);
    ~BigBoard();

public slots:

};

#endif // BIGBOARD_H
