#ifndef MEDIUMBOARD_H
#define MEDIUMBOARD_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "stonesocket.h"
#include "virtualgoban.h"

class MediumBoard : public VirtualGoban
{
    Q_OBJECT
public:
    explicit MediumBoard(QWidget *parent = 0, unsigned int size = 0);
    ~MediumBoard();

public slots:

};

#endif // MEDIUMBOARD_H
