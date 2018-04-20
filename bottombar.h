#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

class BottomBar : public QWidget
{
    Q_OBJECT
public:
    explicit BottomBar(QWidget *parent = 0);

    QPushButton *_nextMoveButton;
    QPushButton *_prevMoveButton;
    QPushButton *_endButton;
    QPushButton *_beginButton;
signals:

public slots:

private:
    QHBoxLayout *_layout;
    QSpacerItem *_spacer;


};

#endif // BOTTOMBAR_H
