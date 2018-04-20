#ifndef VIRTUALGOBAN_H
#define VIRTUALGOBAN_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QString>
#include <QSound>
#include <bitset>
#include "stonesocket.h"

class VirtualGoban : public QFrame
{
    Q_OBJECT

public:
    VirtualGoban(QWidget *parent = 0);
    ~VirtualGoban() {}

    void generateBoard(unsigned int size);
    void cleanBoard();

    static QString nextColor;

    enum class ToolOptions {Sequence, Triangle, Square, BlackOnly, WhiteOnly, Erase};

signals:
    void uncheckAllExcept(unsigned int button);

public slots:
    void toStart();  //schova uplne vsechny ctverecky (zmeni vsem barvu napr)
    void toEnd();    // zobrazi uplne vsechny
    void nextMove(); // zobrazi dalsi v poradi _moves
    void prevMove(); // schova predesly v poradi v _moves

    void setSequence(bool b);
    void setTriangle(bool b);
    void setSquare(bool b);
    void setBlackOnly(bool b);
    void setWhiteOnly(bool b);
    void setErase(bool b);

    bool sequenceOption();
    bool triangleOption();
    bool squareOption();
    bool blackOnlyOption();
    bool whiteOnlyOption();
    bool eraseOption();

    //void setStoneOn(unsigned int x, unsigned int y, QString color);
    void addNewMove(unsigned int, unsigned int);
    void playSound();

protected:
    unsigned int _sizeOfGoban;
    QGridLayout* _layout;
    QVector<StoneSocket*> _pieces;
    int _index;

    QVector<QPair<int,int> > _moves;
    StoneSocket* _lastPlacedStone;

    std::bitset<6> _options;
};

#endif // VIRTUALGOBAN_H
