#ifndef IBOARD_H
#define IBOARD_H

#include <QObject>
#include <QWidget>

class iBoard : public QWidget
{
    Q_OBJECT
public:
    explicit iBoard(QWidget *parent = 0);

signals:

public slots:
};

#endif // IBOARD_H