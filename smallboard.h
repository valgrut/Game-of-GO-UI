#ifndef SMALLBOARD_H
#define SMALLBOARD_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "stonesocket.h"
#include "virtualgoban.h"

class SmallBoard : public VirtualGoban
{
    Q_OBJECT
public:
    explicit SmallBoard(QWidget *parent = 0, unsigned int size = 0);
    ~SmallBoard();

public slots:


};

#endif // SMALLBOARD_H
