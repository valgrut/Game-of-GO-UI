#include "virtualgoban.h"

QString VirtualGoban::nextColor = "black";

VirtualGoban::VirtualGoban(QWidget *parent) : QFrame(parent), _index(0), _lastPlacedStone(NULL), _options(0)
{
}

/*
 * vytvori a inicializuje potrebne casti pro kameny a pod..
 */
void VirtualGoban::generateBoard(unsigned int size)
{
    this->_sizeOfGoban = size;

    for(unsigned int i = 0; i < (size*size); i++)
    {
        StoneSocket *stoneSocket = new StoneSocket(i%size, i/size);
        stoneSocket->hideStone();
        _pieces.push_back(stoneSocket);
        _layout->addWidget(stoneSocket, i%size, i/size);
    }

    for(unsigned int i = 0; i < size*size; i++)
    {
        connect(_pieces.at(i), SIGNAL(clickedOnPos(uint,uint)), this, SLOT(addNewMove(uint,uint)));
    }
}

void VirtualGoban::cleanBoard()
{
    for(unsigned int i = 0; i < _pieces.size(); i++)
    {
        disconnect(_pieces.at(i), SIGNAL(clickedOnPos(uint,uint)), this, SLOT(addNewMove(uint,uint)));
    }

    //nextColor = "black";

    this->_index = 0;
    StoneSocket::setNextColor("black");
    this->nextColor = "black";

    for(int index = 0; index < _pieces.size(); index++)
    {
        StoneSocket *s = _pieces.at(index);
        s->setEmpty(true);
        s->setColor("NONE");
        s->hideStone();
    }

    _moves.clear();
    _pieces.clear();

}

/* TOHLE JE DULEZITA FUNKCE */
void VirtualGoban::addNewMove(unsigned int x, unsigned int y)
{
    /* pokud jsem na poslednim odehranem tahu */
    if(this->_index == _moves.size())
    {
        _moves.push_back(QPair<int,int>(x,y));

        StoneSocket *m = static_cast<StoneSocket*>(_layout->itemAtPosition(_moves[_index].first, _moves[_index].second)->widget());
        m->setColor(this->nextColor);

        // TODO udelat funkci oznacPosledniho()
        //ulozime si pozici posledniho polozeneho kamene, abysme mohli vykreslit kolecko
        //_lastPlacedStone->setForeground("none");
        //m->setForegroundKolecko();
        //_lastPlacedStone = m;

        this->_index++;

        playSound();

        /* nastavi se nasledujici barva polozeneho kamene a barva, kterou vidi vsechny sloty */
        if(blackOnlyOption())
        {
            this->nextColor = "black";
            StoneSocket::setNextColor("black");
            m->setColor(this->nextColor);
        }
        else if(whiteOnlyOption())
        {
            this->nextColor = "white";
            StoneSocket::setNextColor("white");
            m->setColor(this->nextColor);
        }
        else
        {
            if(this->nextColor == "black")
            {
                this->nextColor = "white";
                StoneSocket::setNextColor("white");
            }
            else
            {
                this->nextColor = "black";
                StoneSocket::setNextColor("black");
            }
        }
    }

    //qDebug() << this->_index;
    //qDebug() << _moves.size();
    //qDebug() << "........";
}

void VirtualGoban::playSound()
{
    //QSound::play("/home/valgrut/Dokumenty/Projekty/QtProjects/GoGame/go_sounds/click_a.wav");
}

void VirtualGoban::toStart()
{
    for(int i = 0; i < _index; i++)
    {
        StoneSocket *m = static_cast<StoneSocket*>(_layout->itemAtPosition(_moves[i].first, _moves[i].second)->widget());
        m->hideStone();

        //qDebug() << _index;
    }
    _index = 0;
}

void VirtualGoban::toEnd()
{
    for(int i = 0; i < _moves.size(); i++)
    {
        StoneSocket *m = static_cast<StoneSocket*>(_layout->itemAtPosition(_moves[i].first, _moves[i].second)->widget());
        m->showStone();

        //qDebug() << _index;
    }

    _index = _moves.size();
}

void VirtualGoban::nextMove()
{
    if(_index < _moves.size())
    {
        StoneSocket *m = static_cast<StoneSocket*>(_layout->itemAtPosition(_moves[_index].first, _moves[_index].second)->widget());
        m->showStone();
        playSound();
        ++_index;

        //qDebug() << _index;
    }
}

void VirtualGoban::prevMove()
{
    if(_index > 0)
    {
        --_index;
        StoneSocket *m = static_cast<StoneSocket*>(_layout->itemAtPosition(_moves[_index].first, _moves[_index].second)->widget());
        m->hideStone();
        //qDebug() << _index;
    }
}

/*****************************************************/

void VirtualGoban::setSequence(bool b)
{
    if(b)
        _options.set(0, 1);
    else
        _options.set(0, 0);

    //qDebug() << _options.to_ulong();

    emit uncheckAllExcept(0);
}

void VirtualGoban::setTriangle(bool b)
{
    if(b)
        _options.set(1, 1);
    else
        _options.set(1, 0);

    emit uncheckAllExcept(1);

    //qDebug() << _options.to_ulong();
}

void VirtualGoban::setSquare(bool b)
{
    if(b)
        _options.set(2, 1);
    else
        _options.set(2, 0);

    emit uncheckAllExcept(2);

    //qDebug() << _options.to_ulong();
}

void VirtualGoban::setBlackOnly(bool b)
{
    if(b)
        _options.set(3, 1);
    else
        _options.set(3, 0);

    emit uncheckAllExcept(3);

    //qDebug() << _options.to_ulong();
}

void VirtualGoban::setWhiteOnly(bool b)
{
    if(b)
        _options.set(4, 1);
    else
        _options.set(4, 0);

    emit uncheckAllExcept(4);

    //qDebug() << _options.to_ulong();
}

void VirtualGoban::setErase(bool b)
{
    if(b)
        _options.set(5, 1);
    else
        _options.set(5, 0);

    emit uncheckAllExcept(5);

    //qDebug() << _options.to_ulong();
}

/********************************************/

bool VirtualGoban::sequenceOption()
{
    return _options.test(0);
}

bool VirtualGoban::triangleOption()
{
    return _options.test(1);
}

bool VirtualGoban::squareOption()
{
    return _options.test(2);
}

bool VirtualGoban::blackOnlyOption()
{
    return _options.test(3);
}

bool VirtualGoban::whiteOnlyOption()
{
    return _options.test(4);
}

bool VirtualGoban::eraseOption()
{
    return _options.test(5);
}
