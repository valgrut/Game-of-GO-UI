#include "stonesocket.h"

StoneSocket::StoneSocket(QWidget *parent) : QFrame(parent)
{
}

QString StoneSocket::nextColor = "black";

StoneSocket::StoneSocket(int x, int y) : _coord(x,y)
{
    setFixedSize(40,40);

    setMouseTracking(true);

    setColor("NONE");
    setEmpty(true);

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(2,3); // 10,10 ???
    shadow->setBlurRadius(10);
    shadow->setColor(QColor(0,0,0,240));
    shadow->boundingRectFor(QRect(10,10,10,10));
    setGraphicsEffect(shadow);

    /*
    QVBoxLayout *l = new QVBoxLayout;
    _foreground = new QLabel(this);
    _foreground->setFixedSize(40,40);
    l->addWidget(_foreground);
    setLayout(l);
    */
}

StoneSocket::~StoneSocket()
{

}

void StoneSocket::setForegroundKolecko()
{
    //_foreground->setText("1");
    //_foreground->setAutoFillBackground(true);
    //QPixmap image(":/images/resources/black-circle.png");
    //_foreground->setPixmap(image);
}

void StoneSocket::setForeground(QString /*path*/)
{
    //_foreground->setText("");
    /*
    QPixmap image(path);
    _foreground->setPixmap(image);
    */
}
void StoneSocket::showForeground()
{
    _foreground->show();
}
void StoneSocket::hideForeground()
{
    _foreground->hide();
}

void StoneSocket::setColor(QString color)
{
    this->color = color;
    showStone();
}


void StoneSocket::setEmpty(bool flag)
{
    this->empty = flag;
}
bool StoneSocket::isEmpty() const
{
    return this->empty;
}

void StoneSocket::showStone()
{
    setStyleSheet("StoneSocket {\
        background-image: url(':/images/resources/" + this->color + ".png');\
        background-repeat: no-repeat;\
        background-position: center;\
        }");
    //showForeground();
}
void StoneSocket::hideStone()
{
    setStyleSheet("StoneSocket {background-image: url('xxx.png');}");
    //hideForeground();
}

void StoneSocket::mouseReleaseEvent ( QMouseEvent * event )
{
    if(event->button() == Qt::LeftButton)
    {
        //qDebug() << "CLICK on " << _coord.first << " " << _coord.second;

        if(isEmpty())
        {
            emit clickedOnPos(_coord.first, _coord.second);
            setEmpty(false);
        }
    }
}

void StoneSocket::mouseMoveEvent( QMouseEvent * /*event*/ )
{
    //QPoint p = mapFromGlobal(QCursor::pos());

    if(isEmpty() == true)
    {
        if(StoneSocket::getNextColor() == "black")
        {
            setStyleSheet("StoneSocket:hover {background-image: url(':/images/resources/black_trans.png');}");
        }
        else
        {
            setStyleSheet("StoneSocket:hover {background-image: url(':/images/resources/white_trans.png');}");
        }

    }
}
