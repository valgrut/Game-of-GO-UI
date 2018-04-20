#include "score.h"

Score::Score(QWidget *parent) : QFrame(parent)
{
    setFixedSize(250, 250);
    //setStyleSheet("border-radius: 50px; background-color: gray;");
    //setStyleSheet("border-radius: 50px;");
    //setStyleSheet("background: transparent;"); // toto nastaví pozadí úplně průhledné

    setStyleSheet("font-weight: bold;\
            font-family: palatino;\
            font-size: 40px;\
    ");

    QVBoxLayout *l = new QVBoxLayout;
    setLayout(l);
    _scoreLabel = new QLabel("<center>SCORE</center><center>0</center>", this);
    l->setAlignment(_scoreLabel, Qt::AlignHCenter);
    l->addWidget(_scoreLabel);

    setAttribute(Qt::WA_TranslucentBackground, true);

    hide();
}

void Score::paintEvent(QPaintEvent *event)
{
    /*
    QColor backgroundColor = palette().light().color();
    backgroundColor.setAlpha(150);
    QPainter customPainter(this);
    customPainter.fillRect(rect(), backgroundColor);
    */
}

void Score::changeScore(int score)
{

}
