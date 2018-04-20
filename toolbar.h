#ifndef SPECIALBAR_H
#define SPECIALBAR_H

#include <QWidget>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpacerItem>

class ToolBar : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBar(QWidget *parent = 0);

    QPushButton *_numbersButton;
    QPushButton *_triangleButton;
    QPushButton *_squareButton;
    QPushButton *_blackButton;
    QPushButton *_whiteButton;
    QPushButton *_eraseButton;
signals:

public slots:
    void uncheckAllExcept(uint opt);

private:
    QHBoxLayout *_layout;
    QSpacerItem *_spacer;
};

#endif // SPECIALBAR_H
