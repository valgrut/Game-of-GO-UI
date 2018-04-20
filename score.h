#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>

class Score : public QFrame
{
    Q_OBJECT
public:
    explicit Score(QWidget *parent = 0);
    QLabel *_scoreLabel;

protected:
    void paintEvent(QPaintEvent * event);

signals:

public slots:
    void changeScore(int score);
};

#endif // SCORE_H
